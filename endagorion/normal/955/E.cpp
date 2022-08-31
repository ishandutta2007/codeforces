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
    vi t;
    int mint;

    TRes(int st = 0, int tt = 1e9)
        : t(2, 1e9)
        , mint(1e9)
    {
        t[st] = tt;
    }

    TRes operator+(const TRes &r) const {
        TRes res;
        forn(z, 2) res.t[z] = min(t[z], r.t[z]);
        res.mint = min({mint, r.mint, max(t[0], r.t[1])});
        return res;
    }

    void add(int x) {
        forn(z, 2) t[z] += x;
        mint += x;
    }
};

struct TNode {
    int L, R;
    int l, r;
    TRes res;
    int val;
};

const int maxn = 110000;
int a[maxn], tt[maxn], state[maxn];

TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

void addval(int node, int x) {
    dn;
    n.res.add(x);
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
    n.res = t[n.l].res + t[n.r].res;
}

int build_tree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}, 0};
    if (R - L == 1) {
        n.res = TRes(state[L], tt[L]);
    } else {
        int M = (L + R) / 2;
        n.l = build_tree(L, M);
        n.r = build_tree(M, R);
        relax(node);
    }
    return node;
}

void add_seg(int node, int L, int R, int x) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, x);
        return;
    }
    push(node);
    add_seg(n.l, L, R, x);
    add_seg(n.r, L, R, x);
    relax(node);
}

void flip(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        swap(n.res.t[0], n.res.t[1]);
        return;
    }
    push(node);
    flip(n.l, i);
    flip(n.r, i);
    relax(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    vvi evs(n + 1);
    for1(i, n) {
        cin >> a[i];
        tt[i] = a[i] + i;
        state[i] = 0;
        
        int d = i - a[i];
        if (d > 0) {
            auto push = [&](int t) {
                if (t < 0 || t > n) return;
                evs[t].pb(i);
            };
            push(i - d + 1);
            push(i + d);
        }
    }

    int root = build_tree(1, n + 1);
    int ans = 1e9;
    for1(i, n) {
        add_seg(root, 1, i, 1);
        add_seg(root, i, n + 1, -1);
        for (int x: evs[i]) flip(root, x);
        uin(ans, t[root].res.mint);
    }

    if (ans > 1e8) ans = -1;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}