#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, x, y;
	cin >> n >> x >> y;

	string s;
	cin >> s;

	int groups = 0;
	bool ones = true;
	for (char c : s) {
		if (c == '1') {
			ones = true;
		} else if (ones) {
			ones = false;
			groups++;
		}
	}

	if (groups == 0) {
		cout << 0 << nl;
	}
	else if (x < y) {
		cout << (ll) x*(groups-1) + y << nl;
	}
	else {
		cout << (ll) y*groups << nl;
	}

	return 0;
}