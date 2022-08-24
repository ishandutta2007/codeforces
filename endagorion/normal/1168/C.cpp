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

const int B = 19;

struct TNode {
    int reach[19];

    int L, R;
    int l, r;
};

const int maxn = 310000;
int a[maxn];
TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    forn(i, 19) {
        n.reach[i] = t[n.l].reach[i] | t[n.r].reach[i];
        forn(j, 19) if ((t[n.l].reach[i] >> j) & 1) n.reach[i] |= t[n.r].reach[j];
    }
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n.L = L, n.R = R;
    if (R - L == 1) {
        forn(i, B) n.reach[i] = ((a[L] >> i) & 1 ? a[L] : 0);
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void reachMask(int node, int L, int R, int &mask) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        int nmask = mask;
        forn(i, B) if ((mask >> i) & 1) nmask |= n.reach[i];
        mask = nmask;
        return;
    }
    reachMask(n.l, L, R, mask);
    reachMask(n.r, L, R, mask);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q;
    forn(i, n) cin >> a[i];
    buildTree(0, n);
    forn(i, q) {
        int L, R;
        cin >> L >> R;
        --L;
        int mask = a[L];
        reachMask(0, L, R, mask);
        cout << (mask & a[R - 1] ? "Shi" : "Fou") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}