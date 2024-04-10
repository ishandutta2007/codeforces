#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int MOD = 998244353;

int n,m,cnt;
int f[2][36][1 << 17];

ll ans[60];
ll base[60];

int popcount(int v)
{
	return v ? popcount(v - (v & -v)) + 1 : 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	int L = 17;
	for (int i = 1;i <= n;i++)
	{
		ll a;
		scanf("%lld",&a);
		bool ok = 0;
		for (int j = 2 * L;j >= 0;j--)
			if (a >> j & 1)
			{
				if (!base[j])
				{
					ok = 1;
					base[j] = a;
					break;
				}
				a ^= base[j];
			}
		cnt += !ok;
	}
	ll v = 1;
	while (cnt--)
		(v *= 2) %= MOD;
	for (int i = 0;i < (1 << (L + 1));i++)
	{
		bool ok = 1;
		ll x = 0;
		for (int k = 2 * L;k >= L;k--)
			if (i >> (2 * L - k) & 1)
			{
				if (!base[k])
					ok = 0;
				x ^= base[k];
			}
		if (!ok)
			continue;
		f[L & 1][popcount(x >> L)][x & ((1 << L) - 1)]++;
	}
	for (int i = L - 1;i >= 0;i--)
	{
		if (!base[i])
		{
			memcpy(f[i & 1],f[~i & 1],sizeof(f[i & 1]));
			continue;
		}
		memset(f[i & 1],0,sizeof(f[i & 1]));
		for (int j = 0;j <= L + 1;j++)
			for (int k = 0;k < (1 << L);k++)
				f[i & 1][j][k] = (f[~i & 1][j][k] + f[~i & 1][j][k ^ base[i]]) % MOD;
	}
	for (int i = 0;i <= L + 1;i++)
		for (int j = 0;j < (1 << L);j++)
			(ans[i + popcount(j)] += f[0][i][j]) %= MOD;
	for (int i = 0;i <= m;i++)
		printf("%lld ",ans[i] * v % MOD);
	printf("\n");
	return 0;
}