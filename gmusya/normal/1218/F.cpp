#include <iostream>
#include <vector>
#include <set>

#define ll long long

using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll A;
	cin >> A;
	vector <ll> c(n);
	for (ll i = 0; i < n; i++)
		cin >> c[i];
	multiset <ll> s;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		s.insert(c[i]);
		while (!s.empty() && k < a[i]) {
			ll x = *s.begin();
			s.erase(x);
			ans += x;
			k += A;
		}
		if (s.empty() && k < a[i]) {
			cout << "-1";
			return 0;
		}
	}
	cout << ans;
	return 0;
}