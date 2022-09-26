#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const ll MOD = 998244353;

int n;
int c[MAXN];
int p[MAXN];
int geq[MAXN];
int leq[MAXN];
int suml[MAXN];
int sumr[MAXN];

ll ans;

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

void add(int p,int v)
{
	p = n - p + 1;
	while (p <= n)
	{
		suml[p] += v;
		p += (p & -p);
	}
}

int query(int p)
{
	p = n - p + 1;
	int res = 0;
	while (p >= 1)
	{
		res += suml[p];
		p -= (p & -p);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> p[i];
		c[p[i]] = 1;
	}
	ll cntl = 0,cntr = 0;
	for (int i = 1;i <= n;i++)
		cntr += (p[i] == -1);
	for (int i = 1;i <= n;i++)
		leq[i] = leq[i - 1] + (1 - c[i]);
	for (int i = n;i >= 1;i--)
		geq[i] = geq[i + 1] + (1 - c[i]);
	(ans += cntr * (cntr - 1) % MOD * ((MOD + 1) / 2) % MOD * ((MOD + 1) / 2)) %= MOD;
	for (int i = 1;i <= n;i++)
	{
		if (i > 1)
		{
			if (p[i - 1] == -1)
				cntl++;
			else
				add(p[i - 1],1);
		}
		if (p[i] == -1)
			cntr--;
		else
		{
			(ans += query(p[i])) %= MOD;
			(ans += cntl * geq[p[i]] % MOD * power(cntl + cntr,MOD - 2)) %= MOD;
			(ans += cntr * leq[p[i]] % MOD * power(cntl + cntr,MOD - 2)) %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}