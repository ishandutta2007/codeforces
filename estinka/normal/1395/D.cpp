#ifdef __GNUG__
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <chrono>
#endif
typedef long long ll;
typedef long double ld;
using namespace std;

ll divup(ll a, ll b)
{
	if (a % b == 0) return a / b;
	return a / b + 1ll;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, d, m;
	cin >> n >> d >> m;
	vector<ll> upset, nonup;
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		if (a <= m) nonup.push_back(a);
		else upset.push_back(a);
	}
	sort(nonup.begin(), nonup.end());
	sort(upset.begin(), upset.end());
	upset.push_back(0);
	nonup.push_back(0);
	reverse(nonup.begin(), nonup.end());
	reverse(upset.begin(), upset.end());
	for (int i = 1; i < upset.size(); i++)
	{
		upset[i] += upset[i - 1];
	}
	for (int i = 1; i < nonup.size(); i++)
	{
		nonup[i] += nonup[i - 1];
	}
	ll ans = 0;
	for (ll i = 0; i <= n; i++) // kolko dni sme mu posielali nerozculujuce spravy
	{
		ll nn = (i < nonup.size() ? nonup[i] : nonup.back());
		ll uu = divup(n-i, (d+1ll));
		ans = max(ans, nn + (uu < upset.size() ? upset[uu] : upset.back()));
	}
	cout << ans << endl;
	return 0;
}