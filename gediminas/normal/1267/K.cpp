/*input
3
1
4
11
123456
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll> fing(ll n)
{
	vector<ll>ans;
	for (ll k = 2; n > 0; k++)
	{
		ans.push_back(n % k);
		n /= k;
	}
	sort(ans.begin(), ans.end());
	return ans;
}
ll get(vector<ll> a, ll k)
{
	if (a.empty())
		return 0;
	ll a0 = a[0];
	a.erase(a.begin());
	return a0 + k * get(a, k + 1);
}
ll fac[32];
ll get(vector<ll> f)
{
	ll x = 1;
	ll y = 1;
	int l = 0;
	for (int r = 0; r < f.size(); r++)
	{
		if (f[r] > r + 1)
			return 0;
		int g = 0;
		while (g + 1 < f.size() && f[g + 1] <= r + 1)
			g++;
		x *= g + 1 - r;
		ll G = __gcd(x, y);
		x /= G;
		y /= G;
		if (r == (int)f.size() - 1 || f[r] != f[r + 1])
		{
			y *= fac[r - l + 1];
			l = r + 1;
			G = __gcd(x, y);
			x /= G;
			y /= G;
		}
	}
	return x;
}
int main()
{
	fac[0] = 1;
	for (ll i = 1; i < 32; i++)
		fac[i] = fac[i - 1] * i;
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		if (n == 1)
		{
			cout << "0\n";
			continue;
		}
		vector<ll>f = fing(n);
		auto ff = f;
		ll r = get(f);
		if (f[0] == 0) {
			f.erase(f.begin());
			r -= get(f);
		}
		cout << r - 1 << "\n";
	}
}