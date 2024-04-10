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

struct Song {
	int t, b;
	bool operator < (const Song& o) const {
		return b > o.b;
	}
};

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

	vector<Song> p;
	for (int i=0; i<n; i++) {
		int t, b;
		cin >> t >> b;
		p.push_back({t,b});
	}
	sort(p.begin(), p.end());

	multiset<int> active;
	ll ans = 0;
	ll len = 0;
	for (const Song& it : p) {
		active.insert(it.t);
		len += it.t;
		if (active.size() > k) {
			auto small = active.begin();
			len -= *small;
			active.erase(small);
		}
		ans = max(ans, len*it.b);
	}
	cout << ans << nl;

	return 0;
}