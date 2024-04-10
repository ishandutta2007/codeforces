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
int x[MAXN], a[MAXN], f[MAXN], p[MAXN];
int x2[MAXN], d2[MAXN], g2[MAXN];
int s, b;
int n;

ll cost[MAXN];

struct event {
    int type;
    int id;
    int power;

    bool operator<(const event &o) const {
        if (o.power != power)
            return power < o.power;
        return type < o.type;
    }
};

int mx_val[MAXN];

void calc_cost() {
    for (int i = 1; i <= s; ++i) {
        cost[i] = -inf_ll;
    }
    for (int i = 1; i <= n; ++i) {
        mx_val[i] = -1;
    }

    vector<event> events;
    for (int i = 1; i <= s; ++i) {
        event temp;
        temp.type = 1;
        temp.id = i;
        temp.power = a[i];
        events.pb(temp);
    }
    for (int i = 1; i <= b; ++i) {
        event temp;
        temp.type = 0;
        temp.id = i;
        temp.power = d2[i];
        events.pb(temp);
    }
    sort(all(events));

    for (auto &cur:events) {
        int id = cur.id;
        if (cur.type == 0) {
            mx_val[x2[id]] = max(mx_val[x2[id]], g2[id]);
        } else {
            int res = -1;
            for (int to = 1; to <= n; ++to) {
                if (mx_val[to] == -1)
                    continue;
                if (dis[x[id]][to] <= f[id])
                    res = max(res, mx_val[to]);
            }

            if (res == -1)
                continue;
            cost[id] = res - p[id];
        }
    }

    for (int i = 1; i <= s; ++i) {
        dout << i << " -- " << cost[i] << endl;
    }
}

vector<int> g[MAXN];
vector<int> gr[MAXN];

vector<int> g1[MAXN];

int used[MAXN];
vector<int> order;

void def_top_sort(int v) {
    used[v] = 1;
    for (int to:g[v]) {
        if (!used[to]) {
            def_top_sort(to);
        }
    }
    order.pb(v);
}

int comp[MAXN];

void dfs_clr(int v, int clr) {
    comp[v] = clr;
    for (int to:gr[v]) {
        if (!comp[to]) {
            dfs_clr(to, clr);
        }
    }
}

ll new_cost[MAXN];

int k;

void dfs_top(int v) {
    used[v] = 1;
    for (int to:g1[v]) {
        if (!used[to])
            dfs_top(to);
    }
    order.pb(v);
}


int taken[MAXN];

int super_used[MAXN];
int timer = 0;

ll get_val(int v) {
    if (taken[v])
        return 0;
    if(super_used[v] == timer)
        return 0;
    super_used[v] = timer;
    ll res = new_cost[v];
    for (int to:g1[v]) {
        res += get_val(to);
        res = max(res, -inf_ll);
    }
    return res;
}
void dfs_take(int v){
    taken[v] = true;
    for(int to:g1[v]){
        if(!taken[to])
            dfs_take(to);
    }
}

void build_scc() {
    for (int i = 1; i <= k; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        gr[b].pb(a);
    }
    for (int i = 1; i <= s; ++i) {
        if (!used[i])
            def_top_sort(i);
    }
    reverse(all(order));
    int N = 0;
    for (int v:order) {
        if (comp[v] == 0) {
            ++N;
            dfs_clr(v, N);
        }

    }
    for (int i = 1; i <= s; ++i) {
        dout << "ver " << i << " " << comp[i] << endl;
    }

    set<pii> edges;
    for (int v = 1; v <= s; ++v) {
        for (int to:g[v]) {
            int v1 = comp[v], v2 = comp[to];
            if (v1 == v2)
                continue;
            if (edges.count({v1, v2}))
                continue;
            edges.insert({v1, v2});
            g1[v1].pb(v2);
            dout << "add edge " << v1 << " " << v2 << endl;
        }
    }

    for (int v = 1; v <= s; ++v) {
        new_cost[comp[v]] += cost[v];
        new_cost[comp[v]] = max(new_cost[comp[v]], -inf_ll);
    }

    order.clear();
    memset(used, 0, sizeof used);

    for (int v = 1; v <= N; ++v) {
        if (!used[v])
            dfs_top(v);
    }

    ll ans = 0;
    for (int v:order) {
        timer++;
        ll val = get_val(v);
        if(val > 0){
            ans += val;
            dfs_take(v);
        }

    }
    cout << ans;


}

void solve() {
    int m;
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

    cin >> s >> b >> k;
    for (int i = 1; i <= s; ++i) {
        cin >> x[i] >> a[i] >> f[i] >> p[i];
    }
    for (int i = 1; i <= b; ++i) {
        cin >> x2[i] >> d2[i] >> g2[i];
    }

    calc_cost();
    build_scc();


}

signed main() {
#ifdef zxc
    debug = 0;
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