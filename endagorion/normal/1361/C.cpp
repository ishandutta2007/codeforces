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

const int maxn = 1 << 20;
vector<pii> e[maxn];
vi loops[maxn];
int ptr[maxn], used[maxn];

vi res;

void dfs(int v) {
    while (ptr[v] < e[v].size()) {
//        cerr << v << ' ' << ptr[v] << ' ' << e[v].size() << '\n';
        pii p = e[v][ptr[v]];
        if (used[p.se / 2]) {
            ++ptr[v];
            continue;
        }
        used[p.se / 2] = 1;
//        cerr << v << "->" << p.fi << '\n';
        dfs(p.fi);
        res.pb(p.se ^ 1);
        res.pb(p.se);
//        break;
    }
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
    vector<pii> p(n);
    forn(i, n) cin >> p[i].fi >> p[i].se;
    int L = 0, R = 21;
    vi ans(2 * n);
    iota(all(ans), 0);
    while (R - L > 1) {
        int M = (L + R) / 2;
        int N = 1 << M;
        forn(i, N) e[i].clear(), ptr[i] = 0;
        forn(i, n) used[i] = 0;
        forn(i, n) {
            int a = p[i].fi & (N - 1), b = p[i].se & (N - 1);
            e[a].pb({b, 2 * i}), e[b].pb({a, 2 * i + 1});
        }
        bool ok = true;
        forn(i, N) ok &= e[i].size() % 2 == 0;

        res.clear();
        if (ok) {
            int v = 0;
            while (e[v].empty()) ++v;
            dfs(v);
        }
        if (ok && res.size() == 2 * n) ans = res, L = M;
        else R = M;
    }
    cout << L << '\n';
    for (int x: ans) cout << x + 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}