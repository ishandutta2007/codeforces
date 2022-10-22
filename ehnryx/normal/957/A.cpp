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
	string s;
	cin >> s;

	for (int i = 1; i < n; i++) {
		if (s[i] != '?' && s[i] == s[i-1]) {
			cout << "No" << nl;
			return 0;
		}
	}

	int last = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != '?') {
			if (i - last > 1) {
				cout << "Yes" << nl;
				return 0;
			}
			if (i - last > 0 && (last == 0 || s[last-1] == s[i])) {
				cout << "Yes" << nl;
				return 0;
			}
			last = i+1;
		}
	}
	if (n - last > 0) {
		cout << "Yes" << nl;
		return 0;
	}

	cout << "No" << nl;

	return 0;
}