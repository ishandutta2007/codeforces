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

const int INF = 1e9;

int c[2][2];

template<class T>
void mul(T a, T b) {
    forn(x, 2) forn(y, 2) c[x][y] = INF;
    forn(i, 2) forn(j, 2) if (a[i][j] < INF) forn(k, 2) uin(c[i][k], a[i][j] + b[j][k]);
    forn(x, 2) forn(y, 2) b[x][y] = c[x][y];;
}

struct TNode {
    int L, R;
    int l, r;
    int val[2][2];
};

const int maxn = 210000;
TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

int build_tree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {{0, INF}, {INF, 0}}};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = build_tree(L, M);
        n.r = build_tree(M, R);
    }
    return node;
};

template<class T>
void addval(int node, T a) {
    dn;
    mul(a, n.val);
}

template<class T>
void id(T a) {
    forn(x, 2) forn(y, 2) a[x][y] = (x == y ? 0 : INF);
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    id(n.val);
}

template<class T>
void segmul(int node, int L, int R, T a) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, a);
        return;
    }
    push(node);
    segmul(n.l, L, R, a);
    segmul(n.r, L, R, a);
}

int leafi(int node, int i) {
    dn;
    if (n.R - n.L == 1) return node;
    push(node);
    if (i < t[n.l].R) return leafi(n.l, i);
    return leafi(n.r, i);
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
    vi a(n);
    vvi occ(n + 1);
    forn(i, n) {
        cin >> a[i];
        occ[a[i]].pb(i);
    }

    int root = build_tree(0, n);
    i64 ans = 0;
    int LM[2][2] = {{0, INF}, {1, 1}};
    int RM[2][2] = {{1, 1}, {INF, 0}};
    int BM[2][2] = {{1, 1}, {1, 1}};
    for1(i, n) {
/*        cerr << i << ": ";
        forn(x, n) {
            int leaf = leafi(root, x);
            i64 res = INF;
            forn(z, 2) cerr << *min_element(all(t[leaf].val[z])) << ", "[z];
        }
        cerr << '\n';*/
        for (int x: occ[i]) {
            int leaf = leafi(root, x);
            int res = INF;
            forn(y, 2) forn(z, 2) uin(res, t[leaf].val[y][z]);
//            cerr << i << ' ' << x << ' ' << res + 1 << '\n';
            ans += res + 1;
        }
        if (!occ[i].empty()) {
            segmul(root, 0, occ[i][0], RM);
            segmul(root, occ[i][0], occ[i].back(), BM);
            segmul(root, occ[i].back(), n, LM);
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}