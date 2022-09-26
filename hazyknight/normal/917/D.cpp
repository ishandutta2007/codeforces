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

using namespace std;

typedef long long ll;

const int MAXN = 105;
const ll MOD = 1000000007;

int n;
int G[MAXN][MAXN];

ll f[MAXN];
ll ans[MAXN];
ll a[MAXN][MAXN];

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

ll Gauss()
{
	bool rev = 0;
	for (int i = 1;i < n;i++)
	{
		if (!a[i][i])
		{
			for (int j = i + 1;j < n;j++)
				if (a[j][i])
				{
					swap(a[i],a[j]);
					rev ^= 1;
					break;
				}
		}
		if (!a[i][i])
			return 0;
		for (int j = i + 1;j < n;j++)
		{
			ll val = power(a[i][i],MOD - 2) * a[j][i] % MOD;
			for (int k = i;k < n;k++)
				(a[j][k] -= a[i][k] * val) %= MOD;
		}
	}
	ll res = (rev ? -1 : 1);
	for (int i = 1;i < n;i++)
		(res *= a[i][i]) %= MOD;
	return res;
}

int main()
{
	cin >> n;
	for (int u,v,i = 1;i < n;i++)
	{
		cin >> u >> v;
		G[u][v] = G[v][u] = 1;
		G[u][u]++;
		G[v][v]++;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
			for (int k = 1;k <= n;k++)
			{
				if (!G[j][k])
					a[j][k] = -1;
				else if (j == k)
					a[j][k] = (i - 1) * G[j][k] + n - 1;
				else
					a[j][k] = -i;
			}
		memset(f,0,sizeof(f));
		f[0] = 1;
		for (int j = 1;j <= n;j++)
			if (i != j)
			{
				ll a = power(i - j,MOD - 2),b = -j * a % MOD;
				for (int k = n - 1;k >= 1;k--)
					f[k] = (f[k] * b + f[k - 1] * a) % MOD;
				(f[0] *= b) %= MOD;
			}
		ll y = Gauss();
		for (int j = 0;j < n;j++)
			(ans[j] += f[j] * y) %= MOD;
	}
	for (int i = 0;i < n;i++)
		cout << (ans[i] + MOD) % MOD << ' ';
	cout << endl;
	return 0;
}