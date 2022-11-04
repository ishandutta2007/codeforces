#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll MOD = 998244353;
const ll Inv2 = (MOD + 1) / 2;

int n,m,N;
int SG[MAXN];

ll p[MAXN << 2];
ll q[MAXN << 2];

vector<int> e[MAXN];

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

void dfs(int u)
{
	if (~SG[u])
		return;
	vector<int> nxt;
	for (int i = 0;i < e[u].size();i++)
	{
		dfs(e[u][i]);
		nxt.push_back(SG[e[u][i]]);
	}
	sort(nxt.begin(),nxt.end());
	int i = 0;
	for (int j = 0;j < nxt.size();j++)
		if (i == nxt[j])
			i++;
	SG[u] = i;
}

void FWT(ll *a,bool inv)
{
	for (int i = 1;i < N;i <<= 1)
		for (int j = 0;j < N;j += i << 1)
			for (int k = 0;k < i;k++)
			{
				ll x = a[j + k],y = a[j + k + i];
				a[j + k] = (inv ? (x + y) * Inv2 % MOD : (x + y) % MOD);
				a[j + k + i] = (inv ? (x - y) * Inv2 % MOD : (x - y) % MOD);
			}
}

int main()
{
	scanf("%d%d",&n,&m);
	N = 1;
	while (N - 1 < n)
		N <<= 1;
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
	}
	memset(SG,-1,sizeof(SG));
	for (int i = 1;i <= n;i++)
	{
		dfs(i);
		p[SG[i]]++;
	}
	ll Inv = power(n + 1,MOD - 2);
	for (int i = 0;i < N;i++)
		(p[i] *= Inv) %= MOD;
	p[0]--;
	q[0] = -Inv;
	FWT(p,0);
	FWT(q,0);
	for (int i = 0;i < N;i++)
		q[i] = q[i] * power(p[i],MOD - 2) % MOD;
	FWT(q,1);
	printf("%lld\n",(MOD + 1 - q[0]) % MOD);
	return 0;
}