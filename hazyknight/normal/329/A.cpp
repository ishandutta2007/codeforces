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
	for (int i = 1;i <= n;i++)
		scanf("%s",s[i] + 1);
	bool ok = 1;
	for (int i = 1;i <= n;i++)
	{
		bool fl = 0;
		for (int j = 1;j <= n;j++)
			if (s[i][j] == '.')
				fl = 1;
		if (!fl)
			ok = 0;
	}
	if (ok)
	{
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				if (s[i][j] == '.')
				{
					printf("%d %d\n",i,j);
					break;
				}
		return 0;
	}
	ok = 1;
	for (int i = 1;i <= n;i++)
	{
		bool fl = 0;
		for (int j = 1;j <= n;j++)
			if (s[j][i] == '.')
				fl = 1;
		if (!fl)
			ok = 0;
	}
	if (ok)
	{
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				if (s[j][i] == '.')
				{
					printf("%d %d\n",j,i);
					break;
				}
		return 0;
	}
	printf("-1\n");
	return 0;
}