#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	multiset <ll> s;
	vector <pair <ll, ll>> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i].first;
	for (ll i = 0; i < n; i++)
		cin >> a[i].second;
	sort(a.begin(), a.end());
	ll sum = 0;
	ll val = 0;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		while (val < a[i].first && !s.empty()) {
			ll x = *--s.end();
			sum -= x;
			s.erase(--s.end());
			ans += sum;
			val++;
		}
		sum += a[i].second;
		s.insert(a[i].second);
		val = a[i].first;
	}
	while (!s.empty()) {
		ll x = *--s.end();
		s.erase(--s.end());
		sum -= x;
		ans += sum;
	}
	cout << ans;
	return 0;
}