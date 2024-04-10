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

const int maxn = 2100;
const i64 P = 998244353;
i64 d2[maxn * maxn];
int rx[maxn], cx[maxn];
int px[2 * maxn];
int a[maxn][maxn];
int ban[2 * maxn];
int vis[2 * maxn];
vi e[2 * maxn];

int n, m;

void dfs(int v, vi &par, int &sp) {
    if (vis[v]) return;
    vis[v] = 1;
    if (v < n) par[0] ^= rx[v];
    else par[1] ^= cx[v - n];
    sp += e[v].size() - 2;
    for (int u: e[v]) {
        if (!vis[u]) dfs(u, par, sp);
    }
    vis[v] = 2;
}

using bs = bitset<100>;

void add(vector<bs> &b, bs r) {
    forn(i, b.size()) {
        if (r.none()) return;
        int bi = b[i]._Find_first(), ri = r._Find_first();
        if (bi == ri) r = r ^ b[i];
        if (ri < bi) swap(r, b[i]);
    }
    if (r.any()) b.pb(r);
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
    d2[0] = 1;
    forn(i, n * m) d2[i + 1] = d2[i] * 2 % P;

    int E = 0;

    forn(i, n) {
        string s;
        cin >> s;
        forn(j, m) {
            if (s[j] == '?') {
                a[i][j] = -1;
                e[i].pb(n + j);
                e[n + j].pb(i);
                ++E;
            } else {
                a[i][j] = s[j] - '0';
                rx[i] ^= a[i][j];
                cx[j] ^= a[i][j];
            }
        }
    }

    if (n % 2 == 0 && m % 2 == 0) {
        cout << d2[E] << '\n';
        return 0;
    }

    if (n % 2 == 0) {
        i64 ans = 0;
        forn(z, 2) {
            i64 res = 1;
            forn(i, n) {
                if (e[i].empty()) {
                    if (rx[i] != z) res = 0;
                } else (res *= d2[e[i].size() - 1]) %= P;
            }
            (ans += res) %= P;
        }
        cout << ans << '\n';
        return 0;
    }

    if (m % 2 == 0) {
        i64 ans = 0;
        forn(z, 2) {
            i64 res = 1;
            forn(j, m) {
                if (e[n + j].empty()) {
                    if (cx[j] != z) res = 0;
                } else (res *= d2[e[n + j].size() - 1]) %= P;
            }
            (ans += res) %= P;
        }
        cout << ans << '\n';
        return 0;
    }

    i64 ans = 0;
    forn(z, 2) {
        i64 res = 1;
        forn(i, n + m) vis[i] = 0;
        forn(i, n + m) {
            if (vis[i]) continue;
            vi par(2);
            int sp = 2;
            dfs(i, par, sp);
//            cerr << i << ' ' << par[0] << ' ' << par[1] << ' ' << sp << '\n';
            if (par[0] != par[1]) res = 0;
            else (res *= d2[sp / 2]) %= P;
        }
        (ans += res) %= P;
        
        forn(i, n) rx[i] ^= 1;
        forn(j, m) cx[j] ^= 1;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}