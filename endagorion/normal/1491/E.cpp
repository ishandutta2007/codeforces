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

const int maxn = 200001, maxk = 30;
vector<pii> e[maxn];
int ban[maxn];
int fib[maxk];
int w[maxn];

void dfsw(int v, int p, int k, int &c) {
    bool isC = true;
    w[v] = 1;
    for (auto [u, id]: e[v]) {
        if (u == p || ban[id]) continue;
        dfsw(u, v, k, c);
        isC &= 2 * w[u] <= fib[k];
        w[v] += w[u];
    }
    isC &= 2 * (fib[k] - w[v]) <= fib[k];
    if (isC) c = v;
}

void dfsw2(int v, int p, int k, vector<pii> &es) {
    w[v] = 1;
    for (auto [u, id]: e[v]) {
        if (u == p || ban[id]) continue;
        dfsw2(u, v, k, es);
        w[v] += w[u];
        if (w[u] == fib[k - 2]) {
            es.pb({id, u});
        }
    }
}

bool check(int v, int k) {
    if (k <= 3) return true;
    dfsw(v, -1, k, v);
    int trash;
    vector<pii> es;
    dfsw2(v, -1, k, es);
    for (auto [id, u]: es) {
        ban[id] = 1;
        if (check(u, k - 2) && check(v, k - 1)) return true;
    }
    return false;
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
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb({v, i});
        e[v].pb({u, i});
    }
    fib[0] = fib[1] = 1;
    int p;
    for (p = 2; fib[p - 1] < n; ++p) {
        fib[p] = fib[p - 1] + fib[p - 2];
    }
    --p;
    if (n == fib[p] && check(0, p)) cout << "YES\n";
    else cout << "NO\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}