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

const int MAXN = (int)2e5 + 5;
const int ALPH = 20;
const int MAXM = 1 << ALPH;

int n;
vi g[MAXN];
string s;
int a[MAXN];
int used[MAXN];
int cnt[MAXM], tmr[MAXM], T;
bool is_good[MAXM];
ll ans[MAXN];

bool read() {
    if (scanf("%d\n", &n) < 1) {
        return 0;
    }
    forn(i, n) {
    	g[i].clear();
    }
    forn(i, n - 1) {
    	int u, v;
    	scanf("%d%d", &u, &v);
    	u--, v--;
    	g[u].pb(v);
    	g[v].pb(u);
    }
    cin >> s;

    return 1;
}
 
int dfs(int v, int &center, int sz = 0, int p = -1) {
	int sum = 1;
	for (auto w: g[v])
		if (w != p && !used[w])
			sum += dfs(w, center, sz, v);	

	if (center == -1 && 2 * sum >= sz)
		center = v;	
	return sum;
}

int ROOT;

void relax(int mask) {
	if (tmr[mask] != T) {
		tmr[mask] = T;
		cnt[mask] = 0;
	}
}

void add_to(int mask, ll &collector) {
	relax(mask);
	collector += cnt[mask];
}

void inc(int mask) {
	relax(mask);
	cnt[mask]++;
}

ll visit(int v, int mask, int p = -1) {
	mask ^= 1 << a[v];
	ll collector = 0;

	// add all
	int r_mask = mask ^ (1 << a[ROOT]);
	add_to(r_mask, collector);
	forn(i, ALPH) {
		add_to(r_mask ^ (1 << i), collector);
	}

	// iterate
	for (auto to: g[v]) {
		if (to != p && !used[to]) {
			collector += visit(to, mask, v);
		}
	}

	ans[v] += collector;
	return collector;
}

void add(int v, int mask, int p = -1) {
	mask ^= 1 << a[v];

	// inc mask
	inc(mask);

	// iterate
	for (auto to: g[v]) {
		if (to != p && !used[to]) {
			add(to, mask, v);
		}
	}
}

ll apply_root(int v, int mask, int p = -1) {
	mask ^= 1 << a[v];
	ll collector = 0;

	collector += is_good[mask];

	// iterate
	for (auto to: g[v]) {
		if (to != p && !used[to]) {
			collector += apply_root(to, mask, v);
		}
	}

	ans[v] += collector;

	return collector;
}

void print_ans() {
	forn(i, n) {
		printf("%I64d%c", ans[i], " \n"[i == n - 1]);
	}
}

void build(int v) {
	int center;
	dfs(v, center = -1, dfs(v, center));
	used[center] = 1;

	vi lst;
	for (auto to: g[center]) {
		if (!used[to]) {
			lst.pb(to);
		}
	}

	ROOT = center;
	//cerr << "v = " << v << endl;
	//cerr << "CENTER = " << center << endl;

	forn(it, 2) {
		T++;

		for (auto to: lst) {
			ll res = visit(to, 0);
			if (it == 0) {
				ans[center] += res;
			}

			add(to, 0);
		}

		reverse(all(lst));
	}

	apply_root(center, 0);

	//print_ans();

	for (auto w: g[center])
		if (!used[w])
			build(w);		
}

void solve() {
	memset(ans, 0, sizeof(ans));
	memset(cnt, 0, sizeof(cnt));
	memset(tmr, 0, sizeof(tmr));
	memset(used, 0, sizeof(used));

	forn(i, n) {
		a[i] = (s[i] - 'a');
	}	

	T = 1;
	build(0);

	print_ans();
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    memset(is_good, 0, sizeof(is_good));
    is_good[0] = 1;
    forn(i, ALPH) {
    	is_good[1 << i] = 1;
    }

    while (read()) {
        solve();
    }

    return 0;
}