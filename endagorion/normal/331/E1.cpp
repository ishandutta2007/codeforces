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

const int maxn = 51;
int adj[2][maxn][maxn];
vi lst[2][maxn][maxn];

int n, m;

bool go(int z, vi &L) {
    int ptr = 0;
    for (; ptr + 1 < L.size(); ++ptr) {
        int v = L[ptr], u = L[ptr + 1];
        if (!adj[z][v][u]) return false;
        if (L.size() + lst[z][v][u].size() > 2 * n) return false;
        L.insert(L.end(), all(lst[z][v][u]));
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m;
    forn(i, m) {
        int u, v, sz;
        cin >> u >> v >> sz;
        --u; --v;
        vi L(sz);
        for (int &x: L) cin >> x, --x;
        forn(z, 2) {
            adj[z][u][v] = 1;
            lst[z][u][v] = L;
            swap(u, v);
            reverse(all(L));
        }
    }

    vi ans;
    forn(v, n) forn(u, n) {
        vi &L = lst[0][v][u];
        if (!adj[0][v][u] || L.size() > 2 * n) continue;

        forn(i, (int)L.size() - 1) {
            if (!ans.empty()) break;
            if (L[i] != v || L[i + 1] != u) continue;
//            cerr << v << ' ' << u << ' ' << i << '\n';
            vi L1(L.rend() - i - 1, L.rend());
            vi L2(L.begin() + i + 1, L.end());
/*            for (int x: L1) cerr << x << ' ';
            cerr << '\n';
            for (int x: L2) cerr << x << ' ';
            cerr << '\n';*/
            if (go(0, L2) && go(1, L1) && L1.size() + L2.size() <= 2 * n) {
                reverse(all(L1));
                ans = L1;
                ans.insert(ans.end(), all(L2));
            }
        }
    }

    cout << ans.size() << '\n';
    for (int x: ans) cout << x + 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}