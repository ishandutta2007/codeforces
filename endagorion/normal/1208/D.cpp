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

struct TNode {
    int L, R;
    int l, r;
    pi64 mx;
    i64 val;
};

const int maxn = 210000;
i64 a[maxn];
TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}, 0};
    if (R - L == 1) n.mx = {a[L], -L};
    else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        n.mx = min(t[n.l].mx, t[n.r].mx);
    }
    return node;
}

void addVal(int node, i64 x) {
    dn;
    n.mx.fi += x;
    n.val += x;
}

void push(int node) {
    dn;
    addVal(n.l, n.val);
    addVal(n.r, n.val);
    n.val = 0;
}

void change(int node, int L, int R, i64 d) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addVal(node, d);
        return;
    }
    push(node);
    change(n.l, L, R, d);
    change(n.r, L, R, d);
    n.mx = min(t[n.l].mx, t[n.r].mx);
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
    forn(i, n) cin >> a[i];
    int root = buildTree(0, n);
    vi ans(n, -1);
    forn(i, n) {
        pii res = t[root].mx;
        assert(res.fi == 0);
        int p = -res.se;
        ans[p] = i + 1;
        change(root, p + 1, n, -(i + 1));
        change(root, p, p + 1, 1e18);
    }
    forn(i, n) cout << ans[i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}