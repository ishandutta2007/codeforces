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



//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n;
	cin >> n;

	int a[n+4], pref[n+4], suff[n+4];
	pref[0] = pref[1] = suff[n+2] = suff[n+3] = 0;
	for (int i=2; i<=n+1; i++) {
		cin >> a[i];
		pref[i] = pref[i-2] + a[i];
	}
	for (int i=n+1; i>=2; i--) {
		suff[i] = suff[i+2] + a[i];
	}

	int ans = 0;
	for (int i=2; i<=n+1; i++) {
		if (pref[i-2] + suff[i+1] == pref[i-1] + suff[i+2]) {
			ans++;
		}
	}
	cout << ans << nl;

	return 0;
}