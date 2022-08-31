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

const int maxn = 110000;
vector<pi64> e[maxn];
int laste[maxn];
i64 h[maxn];
vector<pi64> tr[maxn];

void dfs0(int v) {
    for (auto [u, d]: e[v]) {
        h[u] = h[v] + d;
        dfs0(u);
    }
}

vector<pi64> segs;

void add_seg(i64 L, i64 R) {
//    cerr << "seg " << L << ' ' << R << '\n';
    segs.pb({R, L});
}

void set_merge(set<pi64> &a, set<pi64> &b, i64 tinc) {
    if (a.size() < b.size()) {
        set_merge(b, a, tinc);
        a.swap(b);
        return;
    }
    for (auto p: b) a.insert(p);
    for (auto p: b) {
        auto it = a.find(p);
        if (it != a.begin()) {
            auto itp = it;
            --itp;
            if (!b.count(*itp)) add_seg(itp->fi + tinc + 1, it->fi + tinc + 1);
        }
        {
            auto its = it;
            ++its;
            if (its != a.end() && !b.count(*its)) add_seg(it->fi + tinc + 1, its->fi + tinc + 1);
        }
    }
    b.clear();
}

void dfs_merge(int v, set<pi64> &s) {
//    cerr << v << '\n';
    vector<set<pi64>> ss(e[v].size());
    forn(i, e[v].size()) {
//    for (auto [u, d]: e[v]) {
        auto [u, d] = e[v][i];
        dfs_merge(u, ss[i]);
        if (u == laste[v]) ss[i].insert({-h[v], -1});
//        cerr << "M " << v << ' ' << u << '\n';
//        set_merge(s, res, h[v]);
    }
    int li = -1;
    forn(i, e[v].size()) if (li == -1 || ss[i].size() > ss[li].size()) li = i;
    if (li != -1) s.swap(ss[li]);

    map<pi64, int> id;
    forn(i, e[v].size()) {
        if (i == li) continue;
        for (auto p: ss[i]) {
            s.insert(p);
            id[p] = i;
        }
    }

    i64 tinc = h[v];
    forn(i, e[v].size()) {
        if (i == li) continue;
        for (auto p: ss[i]) {
            auto it = s.find(p);
            if (it != s.begin()) {
                auto itp = it;
                --itp;
                if (!id.count(*itp) || i < id[*itp]) add_seg(itp->fi + tinc + 1, it->fi + tinc + 1);
            }
            {
                auto its = it;
                ++its;
                if (its != s.end()) {
                    if (!id.count(*its) || i < id[*its]) add_seg(it->fi + tinc + 1, its->fi + tinc + 1);
                }
            }
        }
    }

    if (laste[v] != -1) s.erase({-h[v], -1});
    for (auto p: tr[v]) {
//        cerr << "+ " << p.fi << ' ' << p.se << '\n';
        s.insert(p);
    }
/*    cerr << "done " << v << '\n';
    for (auto [x, y]: s) cerr << x << ' ' << y << '\n';
    cerr << '\n';*/
}

struct TNode {
    int L, R;
    int l, r;
    i64 mx, val;
};

vi64 xs;

vector<TNode> t;
int tc = 0;

#define dn TNode &n = t[node]

void addval(int node, i64 x) {
    dn;
    n.mx += x;
    n.val += x;
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = 0;
}

void relax(int node) {
    dn;
    n.mx = max(t[n.l].mx, t[n.r].mx);
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, 0, 0};
    if (R - L == 1) n.mx = xs[L];
    else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void seg_add(int node, int L, int R, i64 x) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, x);
        return;
    }
    push(node);
    seg_add(n.l, L, R, x);
    seg_add(n.r, L, R, x);
    relax(node);
}

i64 seg_max(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return 0;
    if (L <= n.L && n.R <= R) return n.mx;
    push(node);
    return max(seg_max(n.l, L, R), seg_max(n.r, L, R));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, n) laste[i] = -1;
    forn(i, n - 1) {
        int from, to, d;
        cin >> from >> to >> d;
        --from; --to;
        e[from].pb({to, d});
        laste[from] = to;
    }

    dfs0(0);

    forn(i, m) {
        int to, T;
        cin >> to >> T;
        --to;
        tr[to].pb({T, i});
    }

    set<pi64> s;
    dfs_merge(0, s);
//    for (auto [l, r]: segs) cerr << l << ' ' << r << '\n';

    xs = {1};
    for (auto [R, L]: segs) xs.pb(L), xs.pb(R);
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    t.resize(2 * xs.size());

    int root = buildTree(0, xs.size());

    auto index = [&](i64 x) {
        return lower_bound(all(xs), x) - xs.begin();
    };

    sort(all(segs));
    int ptr = 0;
    int S = segs.size();
    bool done = false;
    while (ptr < S) {
        int ptr2 = ptr;
        while (ptr2 < S && segs[ptr2].fi == segs[ptr].fi) {
            seg_add(root, 0, index(segs[ptr2].se) + 1, 1);
            ++ptr2;
        }
        if (seg_max(root, 0, index(segs[ptr].fi) + 1) > segs[ptr].fi) {
            cout << segs[ptr].fi - 1 << ' ' << ptr << '\n';
            done = true;
            break;
        }
        ptr = ptr2;
    }

    if (!done) cout << -1 << ' ' << S << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}