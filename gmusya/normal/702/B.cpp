#include <iostream>
#include <vector>
#include <map>

#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <ll> p(40);
	p[0] = 1;
	for (ll i = 1; i < 40; i++)
		p[i] = p[i - 1] * 2;
	map <ll, ll> m;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < 40; j++)
			ans += m[p[j] - a[i]];
		m[a[i]]++;
	}
	cout << ans;
	return 0;
}