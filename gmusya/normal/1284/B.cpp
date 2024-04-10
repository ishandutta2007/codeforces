#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <vector <ll>> a(n);
	for (ll i = 0; i < n; i++) {
		ll m;
		cin >> m;
		a[i].resize(m);
		for (ll j = 0; j < m; j++)
			cin >> a[i][j];
	}
	vector <bool> tf(n);
	vector <ll> mi(n), ma(n);
	for (ll i = 0; i < n; i++) {
		tf[i] = false;
		mi[i] = a[i][0];
		ma[i] = a[i][0];
		for (ll j = 0; j < a[i].size(); j++) {
			if (a[i][j] < mi[i])
				mi[i] = a[i][j];
			if (a[i][j] > ma[i])
				ma[i] = a[i][j];
			if (j != a[i].size() - 1 && a[i][j] < a[i][j + 1])
				tf[i] = true;
		}
	}
	ll ans = 0;
	ll cnt = n - 1;
	for (ll i = 0; i < n; i++)
		if (tf[i]) {
			ans += 2 * cnt + 1;
			cnt--;
		}
	vector <ll> summi(10e6 + 2), summa(10e6 + 2);
	for (ll i = 0; i < n; i++)
		if (!tf[i]) {
			summi[mi[i]]++;
			summa[ma[i]]++;
		}
	vector <ll> sumsumma(10e6 + 2);
	sumsumma[0] = 0;
	for (ll i = 1; i < 10e6 + 2; i++)
		sumsumma[i] = sumsumma[i - 1] + summa[i];
	for (ll i = 0; i < n; i++) {
		if (tf[i])
			continue;
		ans += sumsumma[10e6 + 1] - sumsumma[mi[i]];
	}
	cout << ans;
	return 0;
}