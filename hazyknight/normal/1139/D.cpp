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

const int MAXN = 100005;
const int SQRT = 635;
const int MOD = 1000000007;

int m,Inv,ans,tot,pr;
int F[MAXN];
int val[MAXN];
int mob[MAXN];
int match[MAXN];
int prime[MAXN];
int f[SQRT][MAXN];

bool mark[MAXN];

int power(int a,int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
			res = (ll)res * a % MOD;
		a = (ll)a * a % MOD;
		b >>= 1;
	}
	return res;
}

void init()
{	
	for (int i = m;i >= 1;i--)
		val[++tot] = m / i;
	tot = unique(val + 1,val + tot + 1) - val - 1;
	for (int i = 1;i <= tot;i++)
		match[val[i]] = i;
	mob[1] = 1;
	for (int i = 2;i <= m;i++)
	{
		if (!mark[i])
		{
			prime[++pr] = i;
			mob[i] = -1;
		}
		for (int j = 1;j <= pr && i * prime[j] <= m;j++)
		{
			mark[i * prime[j]] = 1;
			if (i % prime[j] == 0)
			{
				mob[i * prime[j]] = 0;
				break;
			}
			mob[i * prime[j]] = -mob[i];
		}
	}
	for (int i = 1;i <= m;i++)
		if (mob[i])
			for (int j = tot;j >= 1 && val[j] >= i;j--)
			{
				int v = mob[i] * (val[j] / i);
				for (int k = i;k <= m;k += i)
					f[j][k] += v;
			}
}

int main()
{
	cin >> m;
	Inv = power(m,MOD - 2);
	init();
	for (int i = 1;i <= m;i++)
	{
		F[i] = (ll)(F[i] + m / i) * power(m - m / i,MOD - 2) % MOD;
		for (int j = 2;i * j <= m;j++)
			(F[i * j] += (ll)(F[i] + 1) * f[match[m / i]][j] % MOD) %= MOD;
		(ans += F[i] + 1) %= MOD;
	}
	cout << (ll)ans * Inv % MOD << endl;
	return 0;
}