#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef mt19937 RNG;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		if (abs(a[i] - a[i-1]) > 1) {
			cout << "NO" << nl;
			return 0;
		}
	}

	while (n--) {
		int m = 0;
		for (int i = 0; i <= n; i++) {
			m = max(m, a[i]);
		}
		for (int i = 0, pos = 0; i <= n; i++) {
			if (a[i] == m) {
				m = 0;
			} else {
				b[pos++] = a[i];
			}
		}
		for (int i = 1; i < n; i++) {
			if (abs(b[i] - b[i-1]) > 1) {
				cout << "NO" << nl;
				return 0;
			}
		}
	}

	cout << "YES" << nl;

	return 0;
}