#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector> 
#include <map>
#include <iomanip>

using namespace std;

const int MAXN = 55;
const int MAXK = 2005;
const int INF = (1 << 30) - 1;

int n,st,k,ans;
int r[MAXN];
int f[MAXK + MAXN][MAXN];

char s[MAXN];

int main()
{
	scanf("%d%d%d",&n,&st,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d",&r[i]);
	for (int i = 0;i < 2050;i++)
		for (int j = 1;j <= n;j++)
			f[i][j] = INF;
	scanf("%s",s + 1);
	for (int i = 1;i <= n;i++)
		f[r[i]][i] = abs(i - st);
	for (int i = 0;i <= 2000;i++)
		for (int j = 1;j <= n;j++)
			if (f[i][j] != INF)
				for (int k = 1;k <= n;k++)
					if (s[j] != s[k] && r[k] > r[j])
						f[i + r[k]][k] = min(f[i + r[k]][k],f[i][j] + abs(j - k));
	ans = INF;
	for (int i = k;i < 2050;i++)
		for (int j = 1;j <= n;j++)
			ans = min(ans,f[i][j]);
	printf("%d\n",(ans == INF ? -1 : ans));
	return 0;
}