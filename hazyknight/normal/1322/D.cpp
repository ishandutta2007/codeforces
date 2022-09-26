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

const int MAXN = 2005;

int n,m,ans;
int l[MAXN];
int s[MAXN];
int c[MAXN << 1];
int cnt[MAXN << 1];

vector<int> v[MAXN << 1];
vector<int> f[2][MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&l[i]);
		cnt[l[i]]++;
	}
	for (int i = 1;i <= n;i++)
		scanf("%d",&s[i]);
	for (int i = 1;i <= n + m;i++)
		scanf("%d",&c[i]);
	for (int j = 1;j <= n + 1;j++)
		f[0][j].push_back(0);
	for (int i = 1;i <= n + m;i++)
	{
		cnt[i] += cnt[i - 1] >> 1;
		for (int j = 1;j <= n + 1;j++)
		{
			f[i & 1][j].resize(cnt[i] + 1);
			for (int k = 0;k <= cnt[i];k++)
				f[i & 1][j][k] = -1e9;
		}
		f[i & 1][n + 1][0] = 0;
		for (int j = n;j >= 1;j--)
			for (int k = 0;k <= cnt[i];k++)
			{
				f[i & 1][j][k] = max(f[i & 1][j][k],f[i & 1][j + 1][k]);
				if (k * 2 < f[~i & 1][j + 1].size())
					f[i & 1][j][k] = max(f[i & 1][j][k],f[~i & 1][j][k * 2] + k * c[i]);
				if (k * 2 + 1 < f[~i & 1][j + 1].size())
					f[i & 1][j][k] = max(f[i & 1][j][k],f[~i & 1][j][k * 2 + 1] + k * c[i]);
				if (l[j] == i && k > 0)
					f[i & 1][j][k] = max(f[i & 1][j][k],f[i & 1][j + 1][k - 1] + c[i] - s[j]);
				if (k <= 1)
					ans = max(ans,f[i & 1][j][k]);
			}
	}
	printf("%d\n",ans);
	return 0;
}