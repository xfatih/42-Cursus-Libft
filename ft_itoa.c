/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehyildi <mehyildi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:02:24 by mehyildi          #+#    #+#             */
/*   Updated: 2023/02/02 12:26:16 by mehyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int c)
{
	int	i;

	i = 0;
	if (c <= 0)
		i = 1;
	while (c)
	{
		i++;
		c = c / 10;
		if (c == 0)
			break ;
	}
	return (i);
}

static char	*getnum(int n, int strlen, int num, char *str)
{
	while (strlen >= 0)
	{
		num = n % 10;
		str[strlen--] = num + 48;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		strlen;
	char	*str;
	int		number;
	int		sign;

	strlen = intlen(n);
	number = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * strlen + 1);
	if (!str)
		return (0);
	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	str[strlen--] = '\0';
	getnum(n, strlen, number, str);
	if (sign == -1 && str[0] == '0')
		str[0] = '-';
	return (str);
}	
