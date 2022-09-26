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

const int MAXN = 200005;
const ll MOD = 1000000007;

int n;
int l[MAXN];
int r[MAXN];

ll tot,ans;
ll cnt[MAXN];
ll dif[MAXN];
ll sam[MAXN];
ll pre[MAXN];
ll suf[MAXN];

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

ll calc(ll la,ll ra,ll lb,ll rb)
{
	int MIN = max(la,lb),MAX = min(ra,rb);
	return ((ra - la + 1) * (rb - lb + 1) - max(0,MAX - MIN + 1)) % MOD * power((ra - la + 1) * (rb - lb + 1) % MOD,MOD - 2) % MOD;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&l[i]);
	for (int i = 1;i <= n;i++)
		scanf("%d",&r[i]);
	tot = 1;
	for (int i = 1;i <= n;i++)
	{
		cnt[i] = (r[i] - l[i] + 1);
		(tot *= cnt[i]) %= MOD;
	}
	for (int i = 1;i <= n;i++)
	{
		dif[i] = calc(l[i],r[i],l[i + 1],r[i + 1]);
		sam[i] = (1 - dif[i]) % MOD;
		(ans += dif[i]) %= MOD;
	}
	ans = ans * ans % MOD;
	for (int i = 1;i < n;i++)
	{
		(ans -= 2 * dif[i] * dif[i + 1]) %= MOD;
		int L = max(max(l[i],l[i + 1]),l[i + 2]),R = min(min(r[i],r[i + 1]),r[i + 2]);
		(ans += 2 * (1 - sam[i] - sam[i + 1] + max(0,R - L + 1) * power(cnt[i] % MOD * cnt[i + 1] % MOD * cnt[i + 2] % MOD,MOD - 2)) % MOD) %= MOD;
	}
	for (int i = 1;i <= n;i++)
	{
		(ans -= dif[i] * dif[i]) %= MOD;
		(ans += dif[i]) %= MOD;
	}
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}