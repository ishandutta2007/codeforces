#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 105;

int n;

char s[MAXN][MAXN];

int main()
{
	scanf("%d",&n);
	if (n == 5)
	{
		puts(">...v");
		puts("v.<..");
		puts("..^..");
		puts(">....");
		puts("..^.<");
		puts("1 1");
		return 0;
	}
	if (n == 3)
	{
		puts(">vv");
		puts("^<.");
		puts("^.<");
		puts("1 3");
		return 0;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			s[i][j] = '.';
	for (int i = 1;i <= n;i++)
		if (i & 1)
			s[1][i] = '>';
		else
			s[1][i] = 'v';
	for (int i = 2;i < n;i++)
		if (i & 1)
			s[n - 1][i] = '^';
		else
			s[n - 1][i] = '>';
	for (int i = 2;i <= n;i++)
		s[n][i] = '<';
	s[n][1] = '^';
	s[n - 1][1] = '^';
	s[n - 1][n] = 'v';
	for (int i = 1;i <= n;i++)
	{
		if (i & 1)
		{
			for (int j = n - 2;j >= n / 2 + 1;j--)
				s[j][i] = '^';
			for (int j = n / 2 - 1;j > 1;j -= 2)
				s[j][i] = '^';
		}
		else
		{
			for (int j = 2;j < n / 2;j++)
				s[j][i] = 'v';
			for (int j = n / 2 + 1;j <= n - 2;j += 2)
				s[j][i] = 'v';
		}
	}
	for (int i = 1;i <= n;i++,putchar('\n'))
		for (int j = 1;j <= n;j++)
			putchar(s[i][j]);
	printf("%d %d\n",n,1);
	return 0;
}