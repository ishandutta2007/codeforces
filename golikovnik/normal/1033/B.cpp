#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int t; cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		bool ok = 1;
		ok &= (a == b + 1);
		a += b;
		for (ll i = 2; i * i <= a; ++i) {
			ok &= (a % i != 0);
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}	
	return 0;
}