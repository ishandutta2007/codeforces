#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int MAXN = 105;

int T,n,m,k,rice;
int a[MAXN];

char s[MAXN][MAXN];
char ans[MAXN][MAXN];

char get(int id)
{
	if (id <= 26)
		return char('a' + id - 1);
	id -= 26;
	if (id <= 26)
		return char('A' + id - 1);
	id -= 26;
	return char('0' + id - 1);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		rice = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%s",s[i] + 1);
			for (int j = 1;j <= m;j++)
				rice += s[i][j] == 'R';
		}
		for (int i = 1;i <= k;i++)
			a[i] = rice / k;
		for (int i = 1;i <= rice % k;i++)
			a[i]++;
		int r = 1,c = 1;
		for (int i = 1;i <= k;i++)
		{
			while (a[i])
			{
				a[i] -= s[r][c] == 'R';
				ans[r][c] = get(i);
				if (r & 1)
				{
					if (c == m)
						r++;
					else
						c++;
				}
				else
				{
					if (c == 1)
						r++;
					else
						c--;
				}
			}
		}
		while (r <= n)
		{
			ans[r][c] = get(k);
			if (r & 1)
			{
				if (c == m)
					r++;
				else
					c++;
			}
			else
			{
				if (c == 1)
					r++;
				else
					c--;
			}
		}
		for (int i = 1;i <= n;i++,putchar('\n'))
			for (int j = 1;j <= m;j++)
				putchar(ans[i][j]);
	}
	return 0;
}