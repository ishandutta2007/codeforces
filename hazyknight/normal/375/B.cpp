#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 5005;

int n,m,ans;
int a[MAXN][MAXN];

char s[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%s",s + 1);
		int lst = 1;
		for (int j = 1;j <= m;j++)
			if (s[j] == '0')
			{
				if (lst < j)
					a[lst][j - 1]++;
				lst = j + 1;
			}
		if (lst < m + 1)
			a[lst][m]++;
	}
	for (int i = 1;i <= m;i++)
		for (int j = m;j >= i;j--)
			a[i][j] = a[i - 1][j] + a[i][j + 1] - a[i - 1][j + 1] + a[i][j];
	for (int i = 1;i <= m;i++)
		for (int j = i;j <= m;j++)
			ans = max(ans,a[i][j] * (j - i + 1));
	printf("%d\n",ans);
	return 0;
}