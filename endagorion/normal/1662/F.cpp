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

const int maxn = 210000;

struct TNode {
    int L, R;
    int l, r;
    pii x;
};

int p[maxn];
TNode t[4 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.x = max(t[n.l].x, t[n.r].x);
}

int buildTree(int z, int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) {
        n.x = {p[L] + L * (z ? -1 : 1), L};
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(z, L, M);
        n.r = buildTree(z, M, R);
        relax(node);
    }
    return node;
}

pii segmax(int node, int L, int R) {
    dn;
//    cerr << L << ' ' << R << ' ' << n.L << ' ' << n.R << '\n';
    if (max(L, n.L) >= min(R, n.R)) return {-1e9, -1};
    if (L <= n.L && n.R <= R) return n.x;
    return max(segmax(n.l, L, R), segmax(n.r, L, R));
}

void erase(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.x = {-1e9, -1};
        return;
    }
    erase(n.l, i);
    erase(n.r, i);
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
        int n, a, b;
        cin >> n >> a >> b;
        --a; --b;
        forn(i, n) cin >> p[i];
        tc = 0;
        vi roots(2);
        forn(z, 2) roots[z] = buildTree(z, 0, n);

        vi q = {a};
        vi dist(n, 1e9);
        dist[a] = 0;
        forn(z, 2) erase(roots[z], a);
        
        forn(cur, q.size()) {
            int v = q[cur];
//            cerr << v << ' ' << dist[v] << '\n';
            while (1) {
                auto x = segmax(roots[0], v - p[v], v);
//                cerr << x.fi << ' ' << x.se << '\n';
                if (x.fi < v) break;
                q.pb(x.se);
                dist[x.se] = dist[v] + 1;
                forn(z, 2) erase(roots[z], x.se);
            }
            while (1) {
                auto x = segmax(roots[1], v + 1, v + p[v] + 1);
//                cerr << x.fi << ' ' << x.se << '\n';
                if (x.fi < -v) break;
                q.pb(x.se);
                dist[x.se] = dist[v] + 1;
                forn(z, 2) erase(roots[z], x.se);
            }
        }
        cout << dist[b] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}