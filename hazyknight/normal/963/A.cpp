#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000009;

ll power(ll a,ll b)
{
	if (!b)
		return 1;
	ll ret = power(a,b >> 1);
	ret = ret * ret % MOD;
	if (b & 1)
		return ret * a % MOD;
	return ret;
}

ll powerl(ll t,ll a,ll b)
{
	if (!t)
		return 1;
	ll ret = powerl((t - 1) >> 1,a,b);
//	cout << "ret:" << t << ' ' << ret << endl;
	if (t & 1)
	{
		ret = (ret * power(a,(t + 1) >> 1)) % MOD;
		return (ret + ret * power(b,(t + 1) >> 1) % MOD * power(power(a,(t + 1) >> 1),MOD - 2)) % MOD;
	}
	ret = (ret * power(a,(t >> 1) + 1)) % MOD;
	return (ret + ret * power(b,(t >> 1) + 1) % MOD * power(power(a,(t >> 1) + 1),MOD - 2) + power(a,t >> 1) * power(b,t >> 1)) % MOD;
}

ll n,a,b,k;
ll pa[100005];
ll pb[100005];

string s;

void force()
{
	ll fc = 0;
	for (int i = 0;i <= n;i++)
	{
		if (s[i % k] == '+')
			(fc += power(a,n - i) * power(b,i)) %= MOD;
		else
			(fc -= power(a,n - i) * power(b,i)) %= MOD;
	}
	cout << "force:" << (fc + MOD) % MOD << endl;
}

int main()
{
	cin >> n >> a >> b >> k >> s;
//	force();
	ll sum = 0;
	pa[k] = 1;
	pb[1] = 1;
	for (int i = k - 1;i >= 1;i--)
		pa[i] = pa[i + 1] * a % MOD;
	for (int i = 2;i <= k;i++)
		pb[i] = pb[i - 1] * b % MOD;
	for (int i = 1;i <= k;i++)
		if (s[i - 1] == '+')
			(sum += pa[i] * pb[i]) %= MOD;
		else
			(sum -= pa[i] * pb[i]) %= MOD;
//	cout << sum << endl;
	ll tim = (n + 1) / k;
	a = power(a,k);
	b = power(b,k);
	ll ans = powerl(tim - 1,a,b) * sum % MOD;
	cout << (ans + MOD) % MOD << endl;
	return 0;
}