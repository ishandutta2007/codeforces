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

const int MAXN = 1000005;
const ll MOD = 1000000007;

int n,m;

ll ans;
ll fac[MAXN];
ll inv[MAXN];

ll power(ll a,ll b)
{
	if (b < 0)
		b += MOD - 1;
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

void init()
{
	fac[0] = 1;
	for (int i = 1;i <= max(n,m);i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[max(n,m)] = power(fac[max(n,m)],MOD - 2);
	for (int i = max(n,m);i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	return x < y ? 0 : fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

ll A(int x,int y)
{
	return x < y ? 0 : fac[x] * inv[x - y] % MOD;
}

int main()
{
	cin >> n >> m;
	init();
	for (int i = 1;i < n;i++)
		(ans += power(n,n - i - 2) * (i + 1) % MOD * A(n - 2,i - 1) % MOD * C(m - 1,i - 1) % MOD * power(m,n - i - 1)) %= MOD;
	cout << ans << endl;
	return 0;
}