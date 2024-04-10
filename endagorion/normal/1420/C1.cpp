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
    i64 ans[2][2];
};

const int maxn = 310000;
int a[maxn];
TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    forn(x, 2) forn(y, 2) n.ans[x][y] = max(t[n.l].ans[x][y], t[n.r].ans[x][y]);
    forn(x, 2) forn(y, 2) forn(z, 2) uax(n.ans[x][z], t[n.l].ans[x][y] + t[n.r].ans[y ^ 1][z]);
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {{-(i64)1e18, -(i64)1e18}, {-(i64)1e18, -(i64)1e18}}};
    if (R - L == 1) {
        n.ans[0][0] = a[L];
        n.ans[1][1] = -a[L];
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void change(int node, int i, int x) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.ans[0][0] = x;
        n.ans[1][1] = -x;
        return;
    }
    change(n.l, i, x);
    change(n.r, i, x);
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

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        forn(i, n) cin >> a[i];
        tc = 0;
        int root = buildTree(0, n);
        cout << max(t[root].ans[0][0], t[root].ans[0][1]) << '\n';
        while (q--) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            swap(a[x], a[y]);
            change(root, x, a[x]);
            change(root, y, a[y]);
            cout << max(t[root].ans[0][0], t[root].ans[0][1]) << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}