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

const int MAXN = 3505;

int T,n,m,k,ans;
int a[MAXN];
int f[MAXN][MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for (int i = 1;i <= n;i++)
			for (int j = i;j <= n;j++)
				f[i][j] = 0;
		k = min(k,m - 1);
		ans = 0;
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		for (int i = 1,j = n - m + 1;j <= n;i++,j++)
			f[i][j] = max(a[i],a[j]);
		for (int len = n - m + 2;len <= n - k;len++)
			for (int i = 1,j = len;j <= n;i++,j++)
				f[i][j] = min(f[i + 1][j],f[i][j - 1]);
		for (int i = 0;i <= k;i++)
			ans = max(ans,f[i + 1][n - k + i]);
		printf("%d\n",ans);
	}
	return 0;
}