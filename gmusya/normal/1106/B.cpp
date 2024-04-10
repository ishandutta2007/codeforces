#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;
	vector <ll> a(n), c(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
		cin >> c[i];
	vector <pair <ll, ll>> kek(n);
	for (ll i = 0; i < n; i++) {
		kek[i].first = c[i];
		kek[i].second = i;
	}
	sort(kek.begin(), kek.end());
	ll it_kek = 0;
	for (ll i = 0; i < m; i++) {
		ll bill = 0;
		ll t, d;
		cin >> t >> d;
		t--;
		while (it_kek < n && a[kek[it_kek].second] == 0)
			it_kek++;
		if (it_kek == n) {
			cout << "0" << endl;
			continue;
		}
		if (a[t] >= d) {
			cout << c[t] * d << endl;
			a[t] -= d;
			continue;
		}
		bill += c[t] * a[t];
		d -= a[t];
		a[t] = 0;
		while (d > 0 && it_kek < n) {
			if (a[kek[it_kek].second] >= d) {
				bill += c[kek[it_kek].second] * d;
				a[kek[it_kek].second] -= d;
				d = 0;
				break;
			}
			bill += c[kek[it_kek].second] * a[kek[it_kek].second];
			d -= a[kek[it_kek].second];
			a[kek[it_kek].second] = 0;
			it_kek++;
		}
		if (d > 0) {
			cout << "0" << endl;
			continue;
		}
		cout << bill << endl;
	}
	return 0;
}