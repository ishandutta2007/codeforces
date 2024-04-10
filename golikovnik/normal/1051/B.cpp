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
	ll l, r;
	cin >> l >> r;
	cout << "YES\n";
	for (ll i = l; i < r; i += 2) {
		cout << i << " " << i + 1 << "\n";
	}	
	return 0;
}