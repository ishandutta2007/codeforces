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

const int MAXN = 1000005;
const ll MOD = 1000000007;

ll k,w,ans;
ll fac[MAXN];
ll inv[MAXN];

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

void init()
{
	fac[0] = 1;
	for (int i = 1;i <= k;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[k] = power(fac[k],MOD - 2);
	for (int i = k;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

int main()
{
	cin >> k >> w;
	init();
	for (int i = 1;i <= k;i++)
	{
		if (i <= w - 1)
			(ans += i * fac[k] % MOD * fac[k] % MOD * power(k,w - i - 1) % MOD * inv[k - i] % MOD * inv[k - i]) %= MOD;
		else
			(ans += w * fac[k] % MOD * fac[k - i + w - 1] % MOD * inv[k - i] % MOD * inv[k - i] % MOD) %= MOD;
		if (i < k)
		{
			if (i + 1 <= w - 1)
				(ans += i * fac[k] % MOD * fac[k] % MOD * power(k,w - i - 2) % MOD * inv[k - i] % MOD * inv[k - i - 1]) %= MOD;
			else
				(ans += (w - 1) * fac[k] % MOD * fac[k - i + w - 2] % MOD * inv[k - i] % MOD * inv[k - i - 1]) %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}