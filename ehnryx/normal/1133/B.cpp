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

	int n, k;
	cin >> n >> k;

	int mod[k];
	memset(mod, 0, sizeof mod);
	for (int i=0; i<n; i++) {
		int v;
		cin >> v;
		mod[v%k]++;
	}

	int ans = 0;
	for (int i=0; i<=k/2; i++) {
		if (i == (k-i)%k) {
			ans += mod[i]/2;
		} else {
			ans += min(mod[i],mod[(k-i)%k]);
		}
	}
	cout << ans*2 << nl;

	return 0;
}