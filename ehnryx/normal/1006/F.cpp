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

const int N = 20+1;
ll grid[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	ll k;
	cin >> n >> m >> k;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}

	const int steps = n-1+m-1;
	const int half = steps/2;

	unordered_map<ll,int> vals[N];
	for (int bm = 0; bm < 1<<half; bm++) {
		int down = __builtin_popcount(bm);
		if (down < n && half-down < m) {
			int x, y;
			x = y = 0;
			ll cur = grid[x][y];
			for (int i=0; i<half; i++) {
				if (bm & 1<<i) x++;
				else y++;
				cur ^= grid[x][y];
			}
			vals[down][cur^k]++;
		}
	}

	ll ans = 0;
	for (int bm = 0; bm < 1<<(steps-half); bm++) {
		int down = __builtin_popcount(bm);
		if (down < n && steps-half-down < m) {
			int x, y;
			x = y = 1;
			ll cur = 0;
			for (int i=0; i<steps-half; i++) {
				cur ^= grid[n-x][m-y];
				if (bm & 1<<i) x++;
				else y++;
			}
			if (vals[n-1-down].count(cur)) {
				ans += vals[n-1-down][cur];
			}
		}
	}

	cout << ans << nl;

	return 0;
}