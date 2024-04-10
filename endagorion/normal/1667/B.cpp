#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TRes {
	int maxx, maxp, maxm;

	TRes operator+(TRes r) const {
		uax(r.maxx, maxx);
		uax(r.maxp, maxp);
		uax(r.maxm, maxm);
		return r;
	}
};

struct TNode {
	int L, R;
	int l, r;
	TRes res;
};

const int maxn = 510000;
TNode t[2 * maxn];

int tc = 0;
#define dn TNode &n = t[node]

const int INF = 1e9;

int buildTree(int L, int R) {
	int node = tc++;
	dn;
	n = {L, R, -1, -1, {-INF, -INF, -INF}};
	if (R - L > 1) {
		int M = (L + R) / 2;
		n.l = buildTree(L, M);
		n.r = buildTree(M, R);
	}
	return node;
}

void relax(int node) {
	dn;
	n.res = t[n.l].res + t[n.r].res;
}

void setv(int node, int i, int val, int p) {
	dn;
	if (i < n.L || i >= n.R) return;
	if (n.R - n.L == 1) {
		TRes r = {val, val + p, val - p};
		n.res = n.res + r;
		return;
	}
	setv(n.l, i, val, p);
	setv(n.r, i, val, p);
	relax(node);
}

TRes query(int node, int L, int R) {
	dn;
	if (max(L, n.L) >= min(R, n.R)) return {-INF, -INF, -INF};
	if (L <= n.L && n.R <= R) return n.res;
	return query(n.l, L, R) + query(n.r, L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vi64 a(n);
		forn(i, n) cin >> a[i];
		vi64 pa(n + 1);
		forn(i, n) pa[i + 1] = pa[i] + a[i];
		vi64 cpa = pa;
		sort(all(cpa));
		cpa.erase(unique(all(cpa)), cpa.end());

		auto index = [&](i64 ps) {
			return lower_bound(all(cpa), ps) - cpa.begin();
		};

		tc = 0;
		int root = buildTree(0, cpa.size());
		setv(root, index(0), 0, 0);
		vi dp(n + 1);
		for1(i, n) {
			int dpv = -INF;
			int ind = index(pa[i]);
			uax(dpv, query(root, 0, ind).maxm + i);
			uax(dpv, query(root, ind, ind + 1).maxx);
			uax(dpv, query(root, ind + 1, cpa.size()).maxp - i);
			dp[i] = dpv;
			setv(root, ind, dp[i], i);
		}
		cout << dp[n] << '\n';
	}


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}