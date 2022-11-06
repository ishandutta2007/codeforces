#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000005;
const ll MOD = 1000000007;

int T,n,tot;
int p[MAXN];
int c[MAXN];

bool vis[MAXN];
map<int,int> f[MAXN][3];

int solve(int c3,int c2)
{
	int res = 1e9;
	for (int i = 0;i <= n;i++)
		for (int j = 0;j <= 2;j++)
			f[i][j].clear();
	f[0][0][0] = -1e9;
	for (int i = 0;i <= tot;i++)
		for (int j = 0;j <= c2;j++)
		{
			for (map<int,int>::iterator it = f[i][j].begin();it != f[i][j].end();it++)
			{
				int k = it->first,V = it->second;
				if (i == tot)
				{
					if (c2 - j == 0)
					{
						if (k >= 0)
							res = min(res,V + k / 3 * 2);
						if (k < 0)
							res = min(res,V - k);
					}
					if (c2 - j == 1)
					{
						if (k >= 2)
							res = min(res,V + (k - 2) / 3 * 2 + 1);
						if (k <= -1)
							res = min(res,V + (-k - 1));
					}
					if (c2 - j == 2)
					{
						if (k == 1)
							res = min(res,V + 1);
						if (k >= 4)
							res = min(res,V + (k - 4) / 3 * 2 + 2);
						if (k <= -2)
							res = min(res,V + (-k - 2));
					}
					continue;
				}
				for (int l = 0;j + l <= c2;l++)
					if (l * 2 <= c[i + 1])
					{
						int t = (c[i + 1] - l * 2) / 3,el = (c[i + 1] - l * 2) % 3;
						int tim = (l + t + (bool)el - (l == 2) - 1);
						if (!el)
							f[i + 1][j + l][k] = min(f[i + 1][j + l][k],V + tim);
						if (el == 1)
							f[i + 1][j + l][k + 1] = min(f[i + 1][j + l][k + 1],V + tim + (k < 0));
						if (el == 2)
							f[i + 1][j + l][k - 1] = min(f[i + 1][j + l][k - 1],V + tim + (k > 0));
					}
			}
		}
	return res + 1e9;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&p[i]);
			vis[i] = 0;
		}
		tot = 0;
		for (int i = 1;i <= n;i++)
		{
			int u = i,len = 0;
			if (vis[u])
				continue;
			while (!vis[u])
			{
				vis[u] = 1;
				u = p[u];
				len++;
			}
			c[++tot] = len;
		}
		ll ans = 1;
		int ans2 = 0;
		for (int i = 0;i <= 2;i++)
			if ((n - i * 2) % 3 == 0)
			{
				int t = (n - i * 2) / 3;
				for (int j = 1;j <= t;j++)
					(ans *= 3) %= MOD;
				for (int j = 1;j <= i;j++)
					(ans *= 2) %= MOD;
				ans2 = solve(t,i);
			}
		printf("%lld %d\n",ans,ans2);
	}
	return 0;
}