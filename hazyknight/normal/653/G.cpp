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

const int MAXN = 300005;
const ll MOD = 1000000007;

int n,tot,a;
int pr[MAXN];
int MIN[MAXN];

ll CON,ans;
ll fac[MAXN];
ll inv[MAXN];

bool mark[MAXN];

vector<int> cnt[MAXN];

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
	for (int i = 1;i <= n;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[n] = power(fac[n],MOD - 2);
	for (int i = n;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
	for (int i = 2;i <= 300000;i++)
	{
		if (!mark[i])
		{
			pr[++tot] = i;
			MIN[i] = i;
		}
		for (int j = 1;j <= tot && i * pr[j] <= 300000;j++)
		{
			mark[i * pr[j]] = 1;
			MIN[i * pr[j]] = pr[j];
			if (i % pr[j] == 0)
				break;
		}
	}
}

ll C(int x,int y)
{
	return x < 0 || y < 0 || x < y ? 0 : fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	scanf("%d",&n);
	init();
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		while (a > 1)
		{
			int p = MIN[a],e = 0;
			while (a % p == 0)
			{
				a /= p;
				e++;
			}
			cnt[p].push_back(e);
		}
	}
	CON = power(2,n - 2);
	for (int i = 1;i <= 300000;i++)
		if (!mark[i] && cnt[i].size())
		{
			sort(cnt[i].begin(),cnt[i].end());
			int sum = 0,pos = n - cnt[i].size() + 1;
			for (int j = 0;j < cnt[i].size();j++,pos++)
			{
				(ans -= sum * (C(n - 1,pos) + C(n - 1,pos - 1)) + cnt[i][j] * (C(n - 1,pos) + C(n - 2,pos - 1) + C(n - 2,pos - 2))) %= MOD;
				sum += cnt[i][j];
			}
			(ans += 2 * sum * CON) %= MOD;
		}
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}