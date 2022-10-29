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

const int MAXN = 31;

int n, L;
ll c[MAXN];

bool read() {
	if (!(cin >> n >> L)) {
		return 0;
	}
	forn(i, n) {
		cin >> c[i];
	}
	for (int i = n; i < MAXN; i++) {
		c[i] = -1;
	}
	return 1;
}

ll solve() {
	//gen rest
	for (int i = 1; i < MAXN; i++) {
		if (c[i] == -1 || c[i] > c[i - 1] * 2) {
			c[i] = c[i - 1] * 2;
		}
	}
	forn(i, MAXN) {
		assert(c[i] >= 0);
	}

	ll cost = c[MAXN - 1], cur_cost = 0;
	for (int i = MAXN - 1; i >= 0; i--) {
		if (L >= (1ll << i)) {
			L -= 1ll << i;
			cur_cost += c[i];
		} else {
			cost = min(cost, cur_cost + c[i]);
		}
	}
	cost = min(cost, cur_cost);

	return cost;
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
    	cout << solve() << '\n';
    }

    return 0;
}