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

pii operator+(pii a, pii b) {
    return {min(a.fi, b.fi), max(a.se, b.se)};
}

pii shift(pii a, int sh) {
    return {a.fi + sh, a.se + sh};
}

struct TNode {
    int L, R;
    int l, r;
    pii mx;
};

const int maxn = 110000, LOG = 20;
TNode t[2 * LOG * maxn];
pii reach[LOG + 1][maxn];
int tc = 0;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.mx = t[n.l].mx + t[n.r].mx;
}

int buildTree(int j, int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) {
        n.mx = reach[j][L];
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(j, L, M);
        n.r = buildTree(j, M, R);
        relax(node);
    }
    return node;
}

int roots[LOG + 1];
int n;

pii query(int node, int L, int R) {
    dn;
//    cerr << node << ' ' << n.l << ' ' << n.r << ' ' << n.L << ' ' << n.R << ' ' << L << ' ' << R << '\n';
    if (max(L, n.L) >= min(R, n.R)) return {1e9, -1e9};
    if (L <= n.L && n.R <= R) return n.mx;
    return query(n.l, L, R) + query(n.r, L, R);
}

pii get_seg(int node, pii p) {
    auto [L, R] = p;
    if (R - L >= n) return {L, R};
    pii res = query(node, max(0, L), min(n, R));
    if (L < 0) res = res + shift(query(node, L + n, n), -n);
    if (R > n) res = res + shift(query(node, 0, R - n), n);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;
    forn(i, n) {
        int x;
        cin >> x;
        reach[0][i] = mp(i - x, i + x + 1);
    }

    forn(j, LOG) {
        roots[j] = buildTree(j, 0, n);
        forn(i, n) {
            auto [L, R] = reach[j][i];
//            cerr << i << ' ' << j << ' ' << L << ' ' << R << '\n';
            reach[j + 1][i] = get_seg(roots[j], reach[j][i]);
        }
    }

    forn(i, n) {
        pii p = mp(i, i + 1);
        int ans = 0;
        ford(j, LOG) {
            pii np = get_seg(roots[j], p);
            if (np.se - np.fi < n) {
                ans += 1 << j;
                p = np;
            }
        }
        cout << (n == 1 ? 0 : ans + 1) << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}