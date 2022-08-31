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

const int maxn = 1100000;
using bs = bitset<maxn / 2>;
vi e[maxn];
int w[maxn];

void dfsw(int v, int p) {
    w[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        dfsw(u, v);
        w[v] += w[u];
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
    for1(i, n - 1) {
        int p;
        cin >> p;
        --p;
        e[p].pb(i);
        e[i].pb(p);
    }

    dfsw(0, -1);
    int C = -1;
    forn(v, n) {
        bool ok = true;
        for (int u: e[v]) {
            if (w[u] < w[v]) ok &= 2 * w[u] <= n;
            else ok &= 2 * (n - w[v]) <= n;
        }
        if (ok) C = v;
    }
    assert(C != -1);
    dfsw(C, -1);
    vi cnt(n + 1);
    for (int v: e[C]) ++cnt[w[v]];
    for1(i, n / 2) {
        int z = (cnt[i] - 1) / 2;
        cnt[2 * i] += z;
        cnt[i] -= 2 * z;
//        cerr << i << ' ' << cnt[i] << '\n';
    }
    
    bs b;
    b[0] = 1;
    for1(i, n / 2) forn(y, cnt[i]) b = b | (b << i);
    int x = n / 2;
    while (!b[x]) --x;
//    cerr << C << ' ' << x << '\n';
    i64 ans = 0;
    forn(v, n) ans += w[v];
    ans += 1LL * x * (n - 1 - x);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}