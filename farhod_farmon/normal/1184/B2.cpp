//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9;
const ll inf_ll = 1e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double dbl;
#define pb push_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()
bool debug = 0;
const int MAXN = 1e5 + 100;
const int LOG = 22;
const int mod = 1e9 + 7;
const int MX = 1e6 + 100;
typedef long long li;
const li MOD = 1000000000949747713ll;

int dis[128][128];
int x[MAXN], a[MAXN], f[MAXN];
int x2[MAXN], d2[MAXN];

struct edge {
    int a, b, c, flow;
};

struct Flow {
    vector<int> g[MAXN];
    vector<edge> e;

    inline int add_edge(int a, int b, int c) {
        edge e1 = {a, b, c, 0};
        edge e2 = {b, a, 0, 0};
        int id = sz(e);
        g[a].pb(id);
        e.pb(e1);
        g[b].pb(id + 1);
        e.pb(e2);
        return id;
    }

    int s, t, n;
    int ptr[MAXN], dis[MAXN], q[MAXN];

    void init(int S, int T, int N) {
        s = S;
        t = T;
        n = N;
    }


    bool bfs() {
        fill(dis, dis + n, inf_int);
        dis[s] = 0;
        int qh = 0, qt = 1;
        q[0] = s;
        while (qh < qt) {
            int v = q[qh++];
            for (int id:g[v]) {
                edge &r = e[id];
                int to = r.b;
                if (r.c > r.flow && dis[to] > dis[v] + 1) {
                    dis[to] = dis[v] + 1;
                    q[qt++] = to;
                }
            }
        }
        return dis[t] != inf_int;
    }


    int dfs(int v, int flow) {
        if (v == t)
            return flow;
        for (; ptr[v] < sz(g[v]); ++ptr[v]) {
            int id = g[v][ptr[v]];
            edge &r = e[id];
            if (r.c > r.flow && dis[r.b] == dis[v] + 1) {
                int pushed = dfs(r.b, min(flow, r.c - r.flow));
                if (pushed) {
                    e[id].flow += pushed;
                    e[id ^ 1].flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    void delete_all() {
        e.clear();
        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
    }

    void clear() {
        int m = sz(e);
        for (int i = 0; i < m; ++i) {
            e[i].flow = 0;
        }
    }


    int flow() {
        int res = 0;
        while (bfs()) {
            fill(ptr, ptr + n, 0);
            while (int pushed = dfs(s, inf_int)) {
                res += pushed;
            }
        }
        return res;
    }

} flow;

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int e = 1; e <= n; ++e) {
            dis[i][e] = inf_int;
        }
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        dis[a][b] = 1;
        dis[b][a] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int e = 1; e <= n; ++e) {
                dis[i][e] = min(dis[i][e], dis[i][k] + dis[k][e]);
            }
        }
    }

    int s, b, k, h;
    cin >> s >> b >> k >> h;
    for (int i = 1; i <= s; ++i) {
        cin >> x[i] >> a[i] >> f[i];
    }
    for (int i = 1; i <= b; ++i) {
        cin >> x2[i] >> d2[i];
    }

    int ss = 0, tt = s + b + 10;

    flow.init(ss, tt, tt + 5);
    for (int i = 1; i <= s; ++i) {
        flow.add_edge(ss, i, 1);
        for (int e = 1; e <= b; ++e) {
            if (dis[x[i]][x2[e]] <= f[i] && d2[e] <= a[i]) {
                flow.add_edge(i, s + e, 1);
            }
        }
    }
    for (int i = 1; i <= b; ++i) {
        flow.add_edge(s + i, tt, 1);
    }

    int matched = flow.flow();

    ll ans = inf_ll;
    for (int i = 0; i <= s; ++i) {
        ll cur = 1ll * i * h;
        int val = s - matched;
        int fake = i;

        fake -= val;
        fake = max(fake, 0);


        cur += 1ll * max(matched - fake,0) * k;
        ans = min(ans,cur);
    }
    cout << ans;




}

signed main() {
#ifdef zxc
    debug = 1;
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#else
    //freopen("roboherd.in", "r", stdin);
    //freopen("roboherd.out", "w", stdout);

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