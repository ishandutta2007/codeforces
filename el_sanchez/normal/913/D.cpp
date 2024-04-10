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

const int MAXN = (int)2e5 + 100;

int n, T;
pair<pii, int> a[MAXN];

bool read() {
	if (scanf("%d%d", &n, &T) != 2) {
		return 0;
	}
	forn(i, n) {
		scanf("%d%d", &a[i].fst.fst, &a[i].fst.snd);
		a[i].snd = i;
	}
	return 1;
}

vi got;

bool try_k(int k) {
	vector<pii> tasks;
	forn(i, n) {
		if (a[i].fst.fst >= k) {
			tasks.pb(mp(a[i].fst.snd, a[i].snd));
		}
	}

	sort(all(tasks));

	if (sz(tasks) < k) {
		return 0;
	}

	ll ct = 0;
	forn(i, k) {
		ct += tasks[i].fst;
	}

	if (ct > T) {
		return 0;
	}

	got.clear();
	forn(i, k) {
		got.pb(tasks[i].snd);
	}

	return 1;
}

void solve() {
	//printf("solving %d %d\n", n, T);
	int L = 0, R = n + 1, M;
	while (R - L > 1) {
		M = (L + R) >> 1;
		if (try_k(M)) {
			L = M;
		} else {
			R = M;
		}
	}

	int opt_k = L;
	assert(try_k(opt_k));

	printf("%d\n", opt_k);
	printf("%d\n", sz(got));

	sort(all(got));
	for (auto id: got) {
		printf("%d ", id + 1);
	}
	printf("\n");
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
    	solve();
    }

    return 0;
}