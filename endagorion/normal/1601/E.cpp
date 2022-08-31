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

struct Query {
    int l, r, id;
};

const int maxn = 310000, LOG = 20;
int a[maxn];
int sp[LOG + 1][maxn];
int l2[maxn];

int spmin(int L, int R) {
    int j = l2[R - L];
//    cerr << L << ' ' << R << ' ' << j << ' ' << sp[j][L] << ' ' << sp[j][R - (1 << j)] << '\n';
    return min(sp[j][L], sp[j][R - (1 << j)]);
}

struct TNode {
    int L, R;
    int l, r;
    vi mins;
    vi64 ssum;
};

TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

vi vals;

int build_tree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}, {}};
    fore(i, L, R - 1) if (n.mins.empty() || vals[i] < vals[n.mins.back()]) n.mins.pb(i);
    reverse(all(n.mins));
    n.ssum = {0};
    int pi = R;
    for (int i: n.mins) {
        n.ssum.pb(n.ssum.back() + 1LL * (pi - i) * vals[i]);
        pi = i;
    }

    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = build_tree(L, M);
        n.r = build_tree(M, R);
    }
    return node;
}

i64 consider(int node, int &x) {
    dn;
    int ls = lower_bound(all(n.mins), x, [&](int i, int x){return vals[i] <= x;}) - n.mins.begin();
/*    cerr << x << ' ' << n.L << ' ' << n.R << '\n';
    for (auto i: n.mins) cerr << i << ' ';
    cerr << '\n';
    for (auto x: n.ssum) cerr << x << ' ';
    cerr << '\n';
    cerr << ls << '\n';*/
    if (!ls) return 1LL * (n.R - n.L) * x;
    i64 ans = 1LL * (n.mins[ls - 1] - n.L) * x + n.ssum[ls];
    x = vals[n.mins[0]];
    return ans;
}

i64 query(int node, int L, int R, int &x) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return 0;
    if (L <= n.L && n.R <= R) return consider(node, x);
    i64 ans = query(n.l, L, R, x);
    return ans + query(n.r, L, R, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q, k;
    cin >> n >> q >> k;
    forn(i, n) cin >> a[i];
    forn(i, n) sp[0][i] = a[i];
    forn(j, LOG) forn(i, n - (1 << j)) {
        sp[j + 1][i] = min(sp[j][i], sp[j][i + (1 << j)]);
    }
    for1(i, n) while ((2 << l2[i]) <= i) ++l2[i];

    vector<vector<Query> > qs(k);
    forn(i, q) {
        int L, R;
        cin >> L >> R;
        int len = R - L;
        qs[L % k].pb({L / k, L / k + len / k, i});
    }

    vi64 ans(q);
    forn(mod, k) {
        vals.clear();
        for (int i = mod; i + k <= n; i += k) vals.pb(spmin(i, i + k));
/*        cerr << mod << ": ";
        for (auto x: vals) cerr << x << ' ';
        cerr << '\n';*/
        tc = 0;
        int root = build_tree(0, vals.size());
        for (auto q: qs[mod]) {
            int s = q.l * k + mod;
            int x = a[s - 1];
//.            cerr << q.id << ' ' << mod << ' ' << q.l << ' ' << q.r << ' ' << s << ' ' << x << '\n';
            ans[q.id] = x;
            ans[q.id] += query(root, q.l, q.r, x);
        }
    }

    forn(i, q) cout << ans[i] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}