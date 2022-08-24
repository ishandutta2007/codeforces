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
    int minx;
};

const int maxn = 210000;
TNode t[2 * maxn];

int tc = 0;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, int(1e9)};

    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

void relax(int node) {
    dn;
    n.minx = min(t[n.l].minx, t[n.r].minx);
}

void setx(int node, int i, int x) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        uin(n.minx, x);
        return;
    }
    setx(n.l, i, x);
    setx(n.r, i, x);
    relax(node);
}

int minseg(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return 1e9;
    if (L <= n.L && n.R <= R) return n.minx;
    return min(minseg(n.l, L, R), minseg(n.r, L, R));
}

int par[maxn];
int minc[maxn], maxc[maxn];

int root(int x) {
    return x == par[x] ? x : par[x] = root(par[x]);
}

void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    uin(minc[x], minc[y]);
    uax(maxc[x], maxc[y]);
    par[y] = x;
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

    forn(i, n + 1) {
        minc[i] = maxc[i] = par[i] = i;
    }

    set<int> hs;
    forn(i, n) hs.insert(i);
    int troot = buildTree(0, n + 1);
    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int L, R, x;
            cin >> L >> R >> x;
            --L;
            if (x == 0) {
                while (1) {
                    auto it = hs.lower_bound(L);
                    if (it == hs.end() || *it >= R) break;
                    unite(*it, *it + 1);
                    hs.erase(it);
                }
            } else {
                setx(troot, L, R);
            }
        } else {
            int j;
            cin >> j;
            --j;

            if (!hs.count(j)) {
                cout << "NO\n";
                continue;
            }

            int L = minc[root(j)];
            int R = maxc[root(j + 1)];
            cout << (minseg(troot, L, j + 1) <= R ? "YES" : "N/A") << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}