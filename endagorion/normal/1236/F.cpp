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
vi e[maxn];
int tin[maxn], up[maxn];
int vis[maxn];
int T = 0;

vector<pii> st;
vvi cycles;

void dfs(int v, int p) {
    tin[v] = up[v] = T++;
    vis[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        if (vis[u] == 1) {
            uin(up[v], tin[u]);
            st.pb({v, u});
        }
        if (vis[u]) continue;
        st.pb({v, u});
        dfs(u, v);
        uin(up[v], up[u]);
        if (up[u] >= tin[v]) {
            vi cycle;
            while (st.back() != mp(v, u)) {
                cycle.pb(st.back().fi);
                st.pop_back();
            }
            cycle.pb(st.back().fi);
            st.pop_back();
            if (cycle.size() > 1) cycles.pb(cycle);
        }
    }
    vis[v] = 2;
}

i64 di2[maxn];
const i64 P = 1000000000 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    i64 i2 = (P + 1) / 2;
    di2[0] = 1;
    forn(i, maxn - 1) di2[i + 1] = di2[i] * i2 % P;

    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(0, -1);

    i64 EV = n * i2 % P;
    i64 EE = m * di2[2] % P;
    i64 EC = 0;
    i64 EVC = 0;
    i64 EEC = 0;
    i64 sc2 = 0;
    for (auto &c: cycles) {
        int l = c.size();
        (EC += di2[l]) %= P;
        (EVC += di2[l] * (l + (n - l) * i2 % P)) %= P;
        (sc2 += di2[2 * l]) %= P;

        i64 sd = 0;
        for (int v: c) sd += e[v].size() - 2;
        (EEC += di2[l] * (l + sd * i2 % P + (m - l - sd) * di2[2] % P)) %= P;
    }

    i64 EVV = EV + 1LL * n * (n - 1) % P * di2[2] % P;
    EVV %= P;
    i64 adjE = 0;
    forn(v, n) {
        i64 d = e[v].size();
        adjE += d * (d - 1);
    }

    i64 EEE = EE + adjE * di2[3] + (1LL * m * (m - 1) - adjE) % P * di2[4];
    EEE %= P;

    i64 EVE = 2 * m * di2[2] + 1LL * m * (n - 2) % P * di2[3];
    EVE %= P;

    vvi cbyv(n);
    forn(i, cycles.size()) for (int v: cycles[i]) cbyv[v].pb(i);

    i64 ECC = EC;
    (ECC += EC * EC - sc2) %= P;
//    cerr << ECC << '\n';

    forn(v, n) {
        i64 svc = 0, svc2 = 0;
        for (int ci: cbyv[v]) {
            int l = cycles[ci].size();
            (svc += di2[l]) %= P;
            (svc2 += di2[2 * l]) %= P;
        }
        (ECC += (svc * svc - svc2)) %= P;
    }

//    cerr << EV << ' ' << EE << ' ' << EC << '\n';
//    cerr << EVV << ' ' << EEE << ' ' << ECC << ' ' << EVE << ' ' << EVC << ' ' << EEC << '\n';

    i64 ans = EVV + EEE + ECC - 2 * EVE + 2 * EVC - 2 * EEC;
    ans -= EV * EV + EE * EE + EC * EC - 2 * EV * EE + 2 * EV * EC - 2 * EE * EC;
    ans %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}