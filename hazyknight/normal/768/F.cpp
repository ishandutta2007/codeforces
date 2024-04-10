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
#include <complex>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll MOD = 1000000007;

int f,w,h;

ll ok,all;
ll fac[MAXN];
ll inv[MAXN];

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
	fac[0] = 1;
	for (int i = 1;i <= max(f,w);i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[max(f,w)] = power(fac[max(f,w)],MOD - 2);
	for (int i = max(f,w);i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	if (x < y || y < 0)
		return 0;
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	cin >> f >> w >> h;
	if (f == 0)
	{
		cout << (w > h) << endl;
		return 0;
	}
	if (w == 0)
	{
		cout << 1 << endl;
		return 0;
	}
	init();
	for (int i = 1;i <= w;i++)
	{
		(all += C(w - 1,i - 1) * (C(f - 1,i - 2) + 2 * C(f - 1,i - 1) + C(f - 1,i))) %= MOD;
		if ((long long)i * (h + 1) <= w)
			(ok += C(w - i * h - 1,i - 1) * (C(f - 1,i - 2) + 2 * C(f - 1,i - 1) + C(f - 1,i))) %= MOD;
	}
	cout << ok * power(all,MOD - 2) % MOD << endl;
	return 0;
}