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

typedef long long ll;

const int MAXN = 60;
const ll MOD[2] = {1000000000000000009ll,1000000000000000031ll};

int n,q,v;
int B[MAXN];
int R[MAXN];

ll ans;
ll b[MAXN];
ll x[2][MAXN];
ll a[2][MAXN][MAXN];
ll inv[2][MAXN][MAXN];

char s[MAXN];

bool vis[MAXN];

vector<pair<int,int> > swp;

ll mul(ll a,ll b,ll p)
{
	ll v = 1;
	if (b < 0)
	{
		b = -b;
		v = -1;
	}
	ll res = 0;
	while (b)
	{
		if (b & 1)
			(res += a) %= p;
		(a += a) %= p;
		b >>= 1;
	}
	return res * v;
}

ll power(ll a,ll b,ll p)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = mul(res,a,p);
		a = mul(a,a,p);
		b >>= 1;
	}
	return res;
}

void Gauss(int id)
{
	for (int i = 1;i < n;i++)
	{
		if (!a[id][i][i])
		{
			for (int j = i + 1;j < n;j++)
				if (a[j][i])
				{
					swap(a[id][i],a[id][j]);
					swap(inv[id][i],inv[id][j]);
					swp.push_back(make_pair(i,j));
					break;
				}
		}
		ll Inv = power(a[id][i][i],MOD[id] - 2,MOD[id]);
		for (int j = i + 1;j < n;j++)
			if (a[id][j][i])
			{
				ll v = mul(a[id][j][i],Inv,MOD[id]);
				for (int k = 1;k < n;k++)
				{
					(a[id][j][k] -= mul(a[id][i][k],v,MOD[id])) %= MOD[id];
					(inv[id][j][k] -= mul(inv[id][i][k],v,MOD[id])) %= MOD[id];
				}
			}
	}
	for (int i = n - 1;i >= 1;i--)
	{
		ll Inv = power(a[id][i][i],MOD[id] - 2,MOD[id]);
		for (int j = i - 1;j >= 1;j--)
			if (a[id][j][i])
			{
				ll v = mul(a[id][j][i],Inv,MOD[id]);
				for (int k = 1;k < n;k++)
				{
					(a[id][j][k] -= mul(a[id][i][k],v,MOD[id])) %= MOD[id];
					(inv[id][j][k] -= mul(inv[id][i][k],v,MOD[id])) %= MOD[id];
				}
			}
	}
	for (int i = 1;i < n;i++)
		for (int j = 1;j < n;j++)
			inv[id][i][j] = mul(inv[id][i][j],power(a[id][i][i],MOD[id] - 2,MOD[id]),MOD[id]);
	while (swp.size())
	{
		swap(inv[id][swp.back().first],inv[id][swp.back().second]);
		swp.pop_back();
	}
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i < n;i++)
	{
		scanf("%d%d",&B[i],&R[i]);
		a[0][i][i] = 2;
		if (B[i] != n)
			a[0][B[i]][i]--;
		if (R[i] != n)
			a[0][R[i]][i]--;
	}
	memcpy(a[1],a[0],sizeof(a[1]));
	for (int i = 1;i < n;i++)
		inv[0][i][i] = inv[1][i][i] = 1;
	Gauss(0);
	Gauss(1);
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%s",&v,s + 1);
		memset(b,0,sizeof(b));
		memset(x,0,sizeof(x));
		b[1]++;
		b[v]--;
		for (int i = 1;i < n;i++)
			if (s[i] == 'R')
			{
				b[i]++;
				b[B[i]]--;
			}
		for (int k = 0;k <= 1;k++)
			for (int i = 1;i < n;i++)
				for (int j = 1;j < n;j++)
					(x[k][i] += mul(inv[k][i][j],b[j],MOD[k])) %= MOD[k];
		bool ok = 1;
		ans = 0;
		for (int i = 1;i < n;i++)
		{
			(x[0][i] += MOD[0]) %= MOD[0];
			(x[1][i] += MOD[1]) %= MOD[1];
			if (x[0][i] != x[1][i] || x[0][i] - (s[i] == 'R') < 0)
			{
				ok = 0;
				break;
			}
			ll it = x[0][i];
			ans += it + it - (s[i] == 'R');
			if (it + it - (s[i] == 'R') > 0)
			{
				int cur = i;
				memset(vis,0,sizeof(vis));
				while (!vis[cur] && cur != v)
				{
					vis[cur] = 1;
					cur = (s[cur] == 'R' ? R[cur] : B[cur]);
				}
				if (cur != v)
				{
					ok = 0;
					break;
				}
			}
		}
		printf("%lld\n",ok ? ans : -1ll);
	}
	return 0;
}