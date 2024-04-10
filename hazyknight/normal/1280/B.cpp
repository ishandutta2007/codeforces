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

const int MAXN = 65;

int T,n,m,ans;

char s[MAXN][MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			scanf("%s",s[i] + 1);
		ans = 5;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				if (s[i][j] == 'A')
					ans = 4;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				if ((i == 1 || i == n || j == 1 || j == m) && s[i][j] == 'A')
					ans = 3;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				if ((i == 1 || i == n) && (j == 1 || j == m) && s[i][j] == 'A')
					ans = 2;
		for (int i = 1;i <= n;i++)
		{
			bool ok = 1;
			for (int j = 1;j <= m;j++)
				if (s[i][j] == 'P')
					ok = 0;
			if (ok)
				ans = 2;
		}
		for (int i = 1;i <= m;i++)
		{
			bool ok = 1;
			for (int j = 1;j <= n;j++)
				if (s[j][i] == 'P')
					ok = 0;
			if (ok)
				ans = 2;
		}
		for (int i = 1;i <= n;i++)
		{
			bool ok = 1;
			for (int j = 1;j <= m;j++)
				if (s[i][j] == 'P')
					ok = 0;
			if (ok && (i == 1 || i == n))
				ans = 1;
		}
		for (int i = 1;i <= m;i++)
		{
			bool ok = 1;
			for (int j = 1;j <= n;j++)
				if (s[j][i] == 'P')
					ok = 0;
			if (ok && (i == 1 || i == m))
				ans = 1;
		}
		bool ok = 1;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				if (s[i][j] == 'P')
					ok = 0;
		if (ok)
			ans = 0;
		if (ans == 5)
			puts("MORTAL");
		else
			printf("%d\n",ans);
	}
	return 0;
}