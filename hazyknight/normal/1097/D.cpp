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

typedef long long ll;

const int MAXP = 55;
const int MAXK = 10005;
const ll MOD = 1000000007;

int k,tot;
int cnt[MAXP];

ll n,ans;
ll p[MAXP];
ll inv[MAXP];
ll f[MAXP][MAXP];
ll g[MAXP][MAXP];
ll h[MAXP][MAXP];

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void init()
{
	for (int i = 1;i <= 50;i++)
		inv[i] = power(i,MOD - 2);
	for (int i = 0;i <= 50;i++)
		f[i][i] = 1;
	for (int i = 0;i <= 50;i++)
	{
		h[i][0] = f[i][0] * inv[1] % MOD;
		for (int j = 1;j <= i;j++)
			h[i][j] = (h[i][j - 1] + f[i][j] * inv[j + 1]) % MOD;
	}
	for (int i = 1;i <= k;i++)
	{
		for (int j = 0;j <= 50;j++)
			for (int k = 0;k <= j;k++)
				g[j][k] = (h[j][j] - (k > 0 ? h[j][k - 1] : 0)) % MOD;
		memcpy(f,g,sizeof(f));
		memset(g,0,sizeof(g));
		for (int j = 0;j <= 50;j++)
		{
			h[j][0] = f[j][0] * inv[1] % MOD;
			for (int k = 1;k <= j;k++)
				h[j][k] = (h[j][k - 1] + f[j][k] * inv[k + 1]) % MOD;
		}
	}
}

void dfs(int now,ll N,ll P)
{
	if (now > tot)
	{
		(ans += N % MOD * P) %= MOD;
		return;
	}
	for (int i = 0;i <= cnt[now];i++)
	{
		dfs(now + 1,N,P * f[cnt[now]][i] % MOD);
		N *= p[now];
	}
}

int main()
{
	cin >> n >> k;
	init();
	ll N = n;
	for (ll i = 2;i * i <= N;i++)
		if (N % i == 0)
		{
			cnt[++tot] = 0;
			p[tot] = i;
			while (N % i == 0)
			{
				cnt[tot]++;
				N /= i;
			}
		}
	if (N != 1)
	{
		cnt[++tot] = 1;
		p[tot] = N;
	}
	dfs(1,1,1);
	cout << (ans + MOD) % MOD << endl;
	return 0;
}