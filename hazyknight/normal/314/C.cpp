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

int n;
int a[MAXN];

ll ans;
ll sum[1000005];
ll pre[1000005];

void modify(int p,ll v)
{
	while (p <= 1000000)
	{
		sum[p] += v;
		p += p & -p;
	}
}

ll query(int p)
{
	ll res = 0;
	while (p >= 1)
	{
		(res += sum[p]) %= MOD;
		p -= p & -p;
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
	{
		ll w = query(a[i]) + 1,f = (w - pre[a[i]]) * a[i] % MOD;
		pre[a[i]] = w;
		(ans += f) %= MOD;
		modify(a[i],f);
	}
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}