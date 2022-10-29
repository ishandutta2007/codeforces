#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forab(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

#define FILE_NAME "a"

const int MAXN = 1111;

int n;
vi g[MAXN];
bool is_leaf[MAXN];

bool read() {
	if (!(cin >> n)) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, n - 1) {
		int p;
		cin >> p;
		p--;
		g[p].pb(i + 1);
	}

	return 1;
}

bool solve() {
	memset(is_leaf, 0, sizeof(is_leaf));

	forn(i, n) {
		is_leaf[i] = g[i].empty();
	}

	forn(i, n) {
		int cnt_leaves = 0;
		for (auto j: g[i]) {
			cnt_leaves += is_leaf[j];
		}
		if (!is_leaf[i] && cnt_leaves < 3) {
			return 0;
		}
	}

	return 1;
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
    	cout << (solve() ? "Yes" : "No") << '\n';
    }

    return 0;
}