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

	int T;
	cin >> T;
	while (T--) {

		int n;
		cin >> n;

		int ans = 0;
		for (int k=0; k<7; k++) {
			vector<int> a, b;
			for (int i=1; i<=n; i++) {
				if (i&1<<k) {
					a.push_back(i);
				} else {
					b.push_back(i);
				}
			}
			if (!a.empty() && !b.empty()) {
				cout << a.size() << " " << b.size() << " ";
				for (int i : a) cout << i << " ";
				for (int i : b) cout << i << " ";
				cout << endl;
				int res;
				cin >> res;
				assert(res != -1);
				ans = max(ans, res);
			}
		}
		cout << -1 << " " << ans << endl;

	}

	return 0;
}