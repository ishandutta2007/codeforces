#include <bits/stdc++.h>
#define int long long
#define fr first
#define sc second
#define m_p make_pair
using namespace std;
 
typedef long long ll;
 
const ll llinf = 1e18;
 
const int maxn = 15e4 + 100, inf = 1e9 + 100;
 
struct seg_tree {
    vector<array<ll, 3> > q;
    vector<ll> u;
    vector<int> cl;
 
    int n;
 
    seg_tree (int n_, vector<ll> &dp_) {
        n = n_;
        q.resize(4 * n);
        u.resize(4 * n);
        cl.resize(4 * n);
        build(1, 0, n - 1, dp_);
    }
 
    void build(int v, int l, int r, vector<ll> &dp_) {
        q[v][1] = -llinf;
        q[v][2] = -llinf;
        if (l == r) {
            q[v][0] = dp_[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m, dp_);
        build(2 * v + 1, m + 1, r, dp_);
        q[v][0] = max(q[2 * v][0], q[2 * v + 1][0]);
    }
 
    void push(int v, int l, int r) {
        if (u[v] == 0)
            return;
        for (int t = 0; t < 3; t++)
        if (q[v][t] != -llinf)
            q[v][t] += u[v];
        if (l != r)
            u[2 * v] += u[v], u[2 * v + 1] += u[v];
        u[v] = 0;
    }
 
    void update(int v, int tl, int tr, int l, int r, ll w) {
        push(v, tl, tr);
        if (l > r)
            return;
        if (tl == l && tr == r) {
            u[v] += w;
            push(v, tl, tr);
            return;
        }
        int m = (tl + tr) / 2;
        update(2 * v, tl, m, l, min(r, m), w);
        update(2 * v + 1, m + 1, tr, max(l, m + 1), r, w);
        for (int t = 0; t < 3; t++)
            q[v][t] = max(q[2 * v][max(0ll, t - cl[v])], q[2 * v + 1][max(0ll, t - cl[v])]);
    }
 
    void upd(int v, int tl, int tr, int l, int r, int w) {
        push(v, tl, tr);
        if (l > r)
            return;
        if (tl == l && tr == r) {
            cl[v] += w;
            if (l == r)
                for (int t = 1; t < 3; t++)
                    q[v][t] = (cl[v] >= t ? q[v][0] : -llinf);
            else {
                int m = (tl + tr) / 2;
                push(2 * v, tl, m);
                push(2 * v + 1, m + 1, tr);
                for (int t = 1; t < 3; t++)
                    q[v][t] = max(q[2 * v][max(0ll, t - cl[v])], q[2 * v + 1][max(0ll, t - cl[v])]);
            }
            return;
        }
        int m = (tl + tr) / 2;
        upd(2 * v, tl, m, l, min(r, m), w);
        upd(2 * v + 1, m + 1, tr, max(l, m + 1), r, w);
        for (int t = 0; t < 3; t++)
            q[v][t] = max(q[2 * v][max(0ll, t - cl[v])], q[2 * v + 1][max(0ll, t - cl[v])]);
 
    }
 
    void update(int l, int r, ll w) {
        update(1, 0, n - 1, l, r, w);
    }
 
    void upd(int l, int r, int w) {
        upd(1, 0, n - 1, l, r, w);
    }
};
 
int n;
 
vector<pair<int, int> > e[maxn];
 
pair<int, int> parent[maxn];
 
int sz[maxn];
 
bool vis[maxn];
 
int col[maxn];
 
vector<seg_tree> q[maxn];
 
priority_queue<pair<ll, int> > q_cd;
 
priority_queue<pair<ll, int> > g[maxn][3];
 
vector<pair<pair<int, int>, pair<int, int> > > cid[maxn];
 
void check(int v, int t, int ts = -1) {
    while (1) {
        if (g[v][t].empty())
            return;
        auto o = g[v][t].top();
        if (o.sc != ts && q[v][o.sc].q[1][t] == o.fr)
            break;
        g[v][t].pop();
    }
}
 
ll get_help(int v, int t) {
    check(v, t);
    check(v, 0);
    auto o = g[v][t].top();
    ll w = -llinf;
    if (o.fr != -llinf) {
        if (g[v][0].top().sc == o.sc) {
            auto o1 = g[v][0].top();
            g[v][0].pop();
            check(v, 0, o1.sc);
            w = max(w, o.fr + max(0ll, (g[v][0].empty() ? 0ll : g[v][0].top().fr)));
            g[v][0].push(o1);
        } else {
            w = max(w, o.fr + max(0ll, g[v][0].top().fr));
        }
    }
    o = g[v][0].top();
    if (g[v][t].top().sc == o.sc) {
        auto o1 = g[v][t].top();
        g[v][t].pop();
        check(v, t, o1.sc);
        if (!g[v][t].empty() && g[v][t].top().fr != -llinf)
            w = max(w, max(0ll, o.fr) + g[v][t].top().fr);
        g[v][t].push(o1);
    } else {
        if (g[v][t].top().fr != -llinf)
            w = max(w, max(0ll, o.fr) + g[v][t].top().fr);
    }
    return w;
}
 
ll get_cdval(int v) {
    check(v, 1);
    if (g[v][1].empty())
        return -llinf;
    if (!col[v]) {
        ll w = -llinf;
        auto o = g[v][1].top();
        g[v][1].pop();
        check(v, 1, o.sc);
        if (!g[v][1].empty() && g[v][1].top().fr != -llinf)
            w = max(w, o.fr + g[v][1].top().fr);
        g[v][1].push(o);
        w = max(w, get_help(v, 2));
        return w;
    }
    return get_help(v, 1);
}
 
int LAST = 0;

void check() {
    while (1) {
        auto o = q_cd.top();
        if (o.fr == get_cdval(o.sc))
            break;
        q_cd.pop();
    }
    ll w = q_cd.top().fr;
    if (w == -llinf) {
        cout << "BAD\n";
    }
    else {
        LAST = w;
        cout << w << '\n';
    }
}
 
void calc_sz(int v, int par) {
    sz[v] = 1;
    for (auto i : e[v])
    if (!vis[i.fr] && i.fr != par)
        calc_sz(i.fr, v), sz[v] += sz[i.fr];
}
 
int get_cd(int v, int par, int SZ) {
    for (auto i : e[v])
    if (!vis[i.fr] && i.fr != par && sz[i.fr] * 2 > SZ)
        return get_cd(i.fr, v, SZ);
    return v;
}
 
int tnow;
 
void dfs(int v, int par, int cd, int id, ll ds, vector<pair<pair<int, ll>, int> > &gs) {
    int l = tnow++;
    gs.push_back({{v, ds}, -1});
    for (auto i : e[v])
    if (i.fr != par && !vis[i.fr])
        dfs(i.fr, v, cd, id, ds + i.sc, gs);
    gs[l].sc = tnow - 1;
    cid[v].push_back({{cd, id}, {l, tnow - 1}});
}
 
void make_cd(int start) {
    calc_sz(start, -1);
    int V = get_cd(start, -1, sz[start]);
    for (auto it : e[V])
    if (!vis[it.fr]) {
        vector<pair<pair<int, ll>, int> > gs;
        tnow = 0;
        dfs(it.fr, V, V, q[V].size(), it.sc, gs);
        vector<ll> dp_(gs.size());
        for (int i = 0; i < gs.size(); i++)
            dp_[i] = gs[i].fr.sc;
        q[V].push_back(seg_tree(gs.size(), dp_));
        for (int i = 0; i < gs.size(); i++)
        if (col[gs[i].fr.fr])
            q[V].back().upd(i, gs[i].sc, 1);
        for (int t = 0; t < 3; t++)
            g[V][t].push({q[V].back().q[1][t], q[V].size() - 1});
    }
    q_cd.push({get_cdval(V), V});
    cid[V].push_back({{V, -1}, {-1, -1}});
    vis[V] = 1;
    for (auto it : e[V])
    if (!vis[it.fr])
        make_cd(it.fr);
    /// add V
}
 
const int N = 2e5 + 7;
int down[N];

struct Ed {
    int v, w, i;
};  

vector <Ed> g1[N];
void dfs1(int u, int p) {
    for (auto ed : g1[u]) {
        if (ed.v != p) {
            dfs1(ed.v, u);
            parent[ed.v] = {u, ed.w};
            down[ed.i] = ed.v;
            e[u].push_back({ed.v, ed.w});
            e[ed.v].push_back({u, ed.w});
        }   
    }   
}   

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int zaps, w;
    cin >> n >> zaps >> w;
    for (int i = 0; i < n; i++) {
        col[i] = 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g1[u].push_back({v, w, i});
        g1[v].push_back({u, w, i});
    }   
    dfs1(0, 0);

    /*
    for (int i = 1; i < n; i++) {
        int v, w;
        cin >> v >> w;
        v--;
        parent[i] = {v, w};
        e[i].push_back({v, w});
        e[v].push_back({i, w});
    }
    */

    make_cd(0);
    //check();

    while (zaps--) {

        int D, E;
        cin >> D >> E;
        D = (D + LAST) % (n - 1);
        E = (E + LAST) % w;

        int ts = 3, v = down[D];

        ts--;
        if (ts < 2) {
            ts ^= 1;
            /// swap ts esli che
            /// now ts = 0 means 0, uge net
            for (int it = 0; it < cid[v].size(); it++)
            if (it + 1 == cid[v].size()) {
                ll vs = get_cdval(v);
                col[v] = ts;
                ll cs = get_cdval(v);
                if (cs != vs)
                    q_cd.push({cs, v});
            } else {
                int x, y;
                tie(x, y) = cid[v][it].fr;
                ll vs = get_cdval(x);
                ll old[3];
                for (int t = 0; t < 3; t++)
                    old[t] = q[x][y].q[1][t];
                q[x][y].upd(cid[v][it].sc.fr, cid[v][it].sc.sc, (ts ? 1 : -1));
                for (int t = 0; t < 3; t++)
                    if (old[t] != q[x][y].q[1][t])
                        g[x][t].push({q[x][y].q[1][t], y});
                ll cs = get_cdval(x);
                if (vs != cs)
                    q_cd.push({cs, x});
            }
        } else {
            int u = parent[v].fr;
            int w = E;
            int zwz = w;
            w -= parent[v].sc;
            parent[v].sc = zwz;
            for (int it = 0; it < min(cid[v].size(), cid[u].size()) && cid[v][it].fr.fr == cid[u][it].fr.fr; it++) {
                if (cid[v][it].fr.sc == -1 || (cid[u][it].fr.sc != -1 && cid[v][it].sc.fr < cid[u][it].sc.fr))
                    swap(v, u);
                int x, y;
                tie(x, y) = cid[v][it].fr;
                ll vs = get_cdval(x);
                ll old[3];
                for (int t = 0; t < 3; t++)
                    old[t] = q[x][y].q[1][t];
                q[x][y].update(cid[v][it].sc.fr, cid[v][it].sc.sc, w);
                for (int t = 0; t < 3; t++)
                    if (old[t] != q[x][y].q[1][t])
                        g[x][t].push({q[x][y].q[1][t], y});
                ll cs = get_cdval(x);
                if (vs != cs)
                    q_cd.push({cs, x});
                /// copy pasted part
            }
        }
        check();
    }
    /// add check(v, t) to check(v) ?
    /// add test with 1 col
    /// make assert on -llinf / 2
    /// don't forget about < 0
    /// check both maximums when taking sum of best
    /// p_que when getting second max remove with same index
    /// check(x, y, z) : didn't remove with same index
    /// roflan with branches with 0 and 2
}