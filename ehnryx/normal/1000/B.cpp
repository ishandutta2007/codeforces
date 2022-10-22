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

	int n, m;
	cin >> n >> m;

	int a[n+1];
	int pref[n+1];
	a[n] = m;
	for (int i=0; i<=n; i++) {
		if (i < n) {
			cin >> a[i];
		}
		if (i == 0) {
			pref[i] = a[i];
		} else if (i%2 == 0) {
			pref[i] = pref[i-1] + a[i] - a[i-1];
		} else {
			pref[i] = pref[i-1];
		}
	}

	int ans = pref[n];
	int on, off;
	on = off = 0;
	for (int i=n-1; i>=0; i--) {
		if (i%2 == 0) {
			off += a[i+1] - a[i];
			if (a[i+1] - a[i] > 1) {
				ans = max(ans, pref[i] + off-1);
			}
		} else {
			on += a[i+1] - a[i];
		}
	}

	cout << ans << nl;

	return 0;
}