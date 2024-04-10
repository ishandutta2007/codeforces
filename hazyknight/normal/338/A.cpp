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

const ll MOD = 1000000009;

ll n,m,k,ans;

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

int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	m = n - m;
	n = n - m;
	if ((m + 1) * (k - 1) >= n)
	{
		printf("%lld\n",n);
		return 0;
	}
	n -= m * (k - 1);
	ans += m * (k - 1);
	ll t = n / k;
	(ans += (power(2,t) - 1) * k * 2) %= MOD;
	(ans += n % k) %= MOD;
	printf("%lld\n",ans);
	return 0;
}