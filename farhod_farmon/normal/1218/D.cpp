//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double dbl;
#define pb push_back
#define eb emplace_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define mp make_pair
#define all(a) a.begin(),a.end()
bool debug = 0;
const int MAXN = 2e5 + 100;
const int LOG = 21;
const int mod = 1000000007;
const int MX = 1e3 + 100;
typedef long long li;
const li MOD = 1000000007;

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &rhs) {
    out << "( " << rhs.first << " , " << rhs.second << " )";
    return out;
}

#define int ll

ll bin_pow(ll a, int n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

ll reverse(ll a) {
    return bin_pow(a, mod - 2);
}

vector<int> FWHT(vector<int> &P, bool inverse) {
    int u, v;
    int deg = P.size();
    int i;
    for (int len = 1; 2 * len <= deg; len <<= 1) {
        for (i = 0; i < deg; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                u = P[i + j];
                v = P[i + len + j];
                P[i + j] = u + v;
                if (P[i + j] >= mod)
                    P[i + j] -= mod;
                P[i + len + j] = u - v;
                if (P[i + len + j] < 0)
                    P[i + len + j] += mod;
            }
        }
    }

    if (inverse) {
        ll mul = reverse(deg);
        for (i = 0; i < deg; i++) {
            P[i] = (P[i] * mul) % mod;
        }
    }
    return P;
}

vector<int> FWHT2(vector<int> &P, bool inverse) {
    int u, v;
    int deg = P.size();
    int i;
    for (int len = 1; 2 * len <= deg; len <<= 1) {
        for (i = 0; i < deg; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                u = P[i + j];
                v = P[i + len + j];
                P[i + j] = u + v;
                P[i + len + j] = u - v;
            }
        }
    }

    return P;
}

vector<pii> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];

int used_bridge[MAXN];

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i].fi;
        int id = g[v][i].se;
        if (to == p) continue;
        if (used[to])
            fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                used_bridge[id] = 1;
            }
        }
    }
}


int n, m;

void find_bridges() {
    timer = 0;
    for (int i = 1; i <= n; ++i)
        used[i] = false;
    for (int i = 1; i <= n; ++i)
        if (!used[i])
            dfs(i);
}

int x[MAXN], y[MAXN], c[MAXN];

vector<int> ids;

void dfs2(int v) {
    used[v] = true;
    for (pii x:g[v]) {
        int to = x.fi;
        int id = x.se;
        if (!used_bridge[id]) {
            used_bridge[id] = 1;
            ids.pb(id);
        }
        if (!used[to]) {
            dfs2(to);
        }
    }
}


void solve() {

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].pb({b, i});
        g[b].pb({a, i});
        x[i] = a;
        y[i] = b;
        cin >> c[i];
    }
    find_bridges();

    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        used[i] = false;
    }
    int val = 0;
    for (int i = 1; i <= m; ++i) {
        if (used_bridge[i]) {
            val = val ^ c[i];
        } else {
            g[x[i]].pb({y[i], i});
            g[y[i]].pb({x[i], i});
        }
    }
    const int MX_C = 1 << 18;

    vector<int> res(MX_C);
    vector<int> res2(MX_C);
    res[val] = 1;
    res2[val] = 1;

    FWHT(res, false);
    FWHT2(res2, false);

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ids.clear();
            dfs2(i);
            if (sz(ids) > 0) {
                vector<int> cur(MX_C);
                int all = 0;
                for (int v:ids) {
                    all ^= c[v];
                }
                for (int v:ids) {
                    cur[all ^ c[v]]++;
                }

                vector<int> cur2 = cur;

                FWHT(cur, false);
                FWHT2(cur2, false);

                for (int i = 0; i < MX_C; ++i) {
                    res[i] = (1ll * res[i] * cur[i]) % mod;

                    res2[i] = res2[i] * cur2[i];
                }

            }
        }
    }

    FWHT(res, true);
    FWHT2(res2, true);
    for (int i = 0; i < MX_C; ++i) {
        if (res2[i] !=0 || res[i] != 0) {
            cout << i << " " << (res[i] % mod) << "\n";
            return;
        }
    }
    cout << "NO";

}

signed main() {
#ifdef zxc
    debug = 1;
    freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#else

#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    int t = 1;
    while (t--)
        solve();
    if (debug)
        cerr << endl << "time : " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
}