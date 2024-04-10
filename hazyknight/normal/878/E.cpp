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

const int MAXN = 100005;
const ll MOD = 1000000007;

int n,q,top;
int fa[MAXN][17];
int l[MAXN];

ll ans;
ll pw[MAXN];
ll inv[MAXN];
ll sum[MAXN];
ll depth[MAXN];

pair<ll,bool> a[MAXN];
pair<ll,bool> S[MAXN];

ll getval(int l,int r)
{
	return (sum[r] - sum[l - 1]) * inv[l] % MOD;
}

pair<ll,bool> operator * (const pair<ll,bool> &a,const int &v)
{
	pair<ll,bool> r = a;
	if (r.second)
		return r;
	if (r.first * v > 2e9)
	{
		r.second = 1;
		return r;
	}
	r.first *= v;
	return r;
}

pair<ll,bool> operator + (const pair<ll,bool> &a,const pair<ll,bool> &b)
{
	pair<ll,bool> r;
	if (a.second || b.second)
	{
		r.second = 1;
		return r;
	}
	if (a.first + b.first > 2e9)
	{
		r.second = 1;
		return r;
	}
	r.first = a.first + b.first;
	return r;
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
		scanf("%lld",&a[i].first);
	pw[0] = 1;
	for (int i = 1;i <= n;i++)
		pw[i] = pw[i - 1] * 2 % MOD;
	inv[0] = 1;
	for (int i = 1;i <= n;i++)
		inv[i] = inv[i - 1] * ((MOD + 1) / 2) % MOD;
	for (int i = 1;i <= n;i++)
		sum[i] = (sum[i - 1] + (ll)a[i].first * pw[i]) % MOD;
	for (int i = 1;i <= n;i++)
	{
		fa[i][0] = i - 1;
		while (top >= 1 && (a[i].first > 0 || a[i].second))
		{
			if (fa[i][0] - l[top] + 1 >= 31)
				a[i].second = 1;
			a[i] = a[i] * pw[fa[i][0] - l[top] + 1] + S[top];
			fa[i][0] = l[top] - 1;
			top--;
		}
		l[++top] = fa[i][0] + 1;
		S[top] = a[i];
		depth[i] = (depth[fa[i][0]] + getval(l[top],i)) % MOD;
		for (int j = 1;j <= 16;j++)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	}
	while (q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ans = 0;
		for (int i = 16;i >= 0;i--)
			if (fa[r][i] + 1 > l)
			{
				(ans += 2 * (depth[r] - depth[fa[r][i]])) %= MOD;
				r = fa[r][i];
			}
		(ans += getval(l,r)) %= MOD;
		printf("%lld\n",(ans + MOD) % MOD);
	}
	return 0;
}