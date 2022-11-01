#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

typedef long long ll;

using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	if (k * (k + 1) / 2 > n) {
		cout << "NO\n";
		return 0;
	}
	if (k == 2) {
		ll a = 0, b = 0;
		if (n % 2 == 0)
			a = n / 2 - 1, b = n / 2 + 1;
		else
			a = n / 2, b = (n + 1) / 2;
		if (2 * a >= b) {
			cout << "YES\n";
			cout << a << ' ' << b;
		}
		else cout << "NO\n";
		return 0;
	}
	ll sum = k * (k + 1) / 2;
	ll diff = (n - sum) / k;
	vector <ll> a(k);
	for (int i = 0; i < k; i++)
		a[i] = (i + 1) + diff;
	ll m = (n - sum) % k;
	if (m > 0 && m == k - 1) {
		a[k - 2]++;
		m--;
	}
	a[k - 1] += m;
	bool tf = true;
	for (ll i = 0; i < k - 1; i++)
		if (a[i] * 2 < a[i + 1] || a[i] >= a[i + 1]) tf = false;
	if (!tf) cout << "NO\n";
	else {
		cout << "YES\n";
		for (auto &now : a)
			cout << now << ' ';
	}
	return 0;
}