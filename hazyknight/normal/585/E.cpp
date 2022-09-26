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

const int MAXN = 500005;
const int MAX = 10000000;
const int MOD = 1000000007;

int n,tot1,tot2;
int pw2[MAXN];
int f[MAX + 5];
int cnt[MAX + 5];
int sum[MAX + 5];

int main()
{
	scanf("%d",&n);
	pw2[0] = 1;
	for (int i = 1;i <= n;i++)
		pw2[i] = pw2[i - 1] * 2 % MOD;
	int g = 0;
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		cnt[a]++;
		g = __gcd(g,a);
	}
	for (int i = 1;i <= MAX;i++)
		for (int j = i;j <= MAX;j += i)
			sum[i] += cnt[j];
	for (int i = 2;i <= MAX;i++)
		f[i] = pw2[sum[i]] - 1;
	for (int i = MAX;i >= 1;i--)
		if (sum[i])
			for (int j = i + i;j <= MAX;j += i)
				(f[i] -= f[j]) %= MOD;
	for (int i = 2;i <= MAX;i++)
		(tot1 += f[i]) %= MOD;
	for (int i = 1;i <= MAX;i++)
	{
		if (sum[i])
			f[i] = (ll)sum[i] * pw2[sum[i] - 1] % MOD;
		else
			f[i] = 0;
	}
	for (int i = MAX;i >= 1;i--)
		if (sum[i])
			for (int j = i + i;j <= MAX;j += i)
				(f[i] -= f[j]) %= MOD;
	for (int i = 2;i <= MAX;i++)
		(tot2 += f[i]) %= MOD;
	tot1 -= n + (g > 1);
	tot2 -= n + (g > 1) * n;
	printf("%lld\n",(((ll)n * (n - 1) - (g > 1) * n + (ll)n * tot1 - 2 * tot2) % MOD + MOD) % MOD);
	return 0;
}