#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define f first
#define s second
#define bp __builtin_popcount
#define all(a) a.begin(),a.end()
#define ll long long
#define mp make_pair
const int N = 5e5+7, LG = 20, INF = 1e9; 
int n;
vector <int> g[N]; 
vector <int> eu;
int l[N], r[N], h[N], ptr = 0;
void dfs(int u, int p) {
    l[u] = eu.size();
    eu.app(u);
    for (int v : g[u])
        if (v != p) {
            h[v] = h[u] + 1;
            dfs(v, u);
            eu.app(u);
        }
    r[u] = eu.size();
}
int sp[LG][N], pw[N];
int lca(int u, int v) {
    int tl = l[u], tr = l[v];
    if (tr < tl)
        swap(tl, tr);
    int p = pw[tr - tl + 1];
    return eu[min(sp[p][tl], sp[p][tr - (1 << p) + 1])];
}   
int getr(int u, int v) {
    return h[u] + h[v] - 2 * h[lca(u, v)];
}   
bool comp(int u, int v) {
    return l[u] < l[v];
}
int par[N];
void upd(ii &ans, int i, int w, vector <int> &v, vector <int> &s) {
    if (v[i] == w) {
        ans = mp(0, i);
        return;
    }   
    int d = getr(w, v[i]);
    int t = (d + s[i] - 1) / s[i];
    ans = min(ans, mp(t, i));
}    
bool anc(int u, int v) {
    return l[u] <= l[v] && r[v] <= r[u];
}    

int S[N];
struct Event {
    int u, t, c;
    bool const operator < (const Event e) const {
        int t1 = (t + S[c] - 1) / S[c];
        int t2 = (e.t + S[e.c] - 1) / S[e.c];
        return (t1 < t2) || (t1 == t2 && c < e.c) || (t1 == t2 && c == e.c && u < e.u);
    }   
};  

vector <int> virt[N];
int dist[N], color[N];

void solve() {
    int k, m;
    cin >> k >> m;
    vector <int> v(k), s(k);
    for (int i = 0; i < k; ++i) {
        cin >> v[i] >> s[i];
        S[i] = s[i];
    }
    vector <int> u(m);
    for (int i = 0; i < m; ++i)
        cin >> u[i];
    vector <int> a;
    for (int e : v)
        a.app(e);
    for (int e : u)
        a.app(e);
    sort(all(a), comp);
    int sz = a.size();
    for (int i = 0; i + 1 < sz; ++i)
        a.app(lca(a[i], a[i + 1]));
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    sort(all(a), comp);
    for (int e : a)
        virt[e].clear();
    vector <int> st;
    for (int e : a) {
        while (st.size() && r[st.back()] < l[e]) 
            st.pop_back();
        if (st.size()) {
            par[e] = st.back();
            #ifdef HOME
            cout << "edge " << e << ' ' << st.back() << '\n';
            #endif
            virt[e].app(st.back());
            virt[st.back()].app(e);
        }
        else
            par[e] = 0;
        st.push_back(e);
    }           
    for (int e : a)
        dist[e] = INF;
    set <Event> ms;
    for (int i = 0; i < k; ++i) {
        ms.insert({v[i], 0ll, i});
        dist[v[i]] = 0;
        color[v[i]] = i;
    }
    while (ms.size()) {
        auto e = *ms.begin(); ms.erase(ms.begin());
        #ifdef HOME
        cout << e.u << ' ' << e.t << ' ' << e.c << '\n';
        #endif
        for (int v : virt[e.u]) {
            int len = getr(e.u, v);
            Event e1 = {v, dist[e.u] + len, e.c};
            Event e2 = {v, dist[v], color[v]};
            if (dist[v] == INF || e1 < e2) {
                ms.erase({v, dist[v], color[v]});
                dist[v] = dist[e.u] + len;
                color[v] = e.c;
                ms.insert({v, dist[v], color[v]});
            }
        }   
    }   
    for (int e : u)
        cout << color[e] + 1 << ' ';
    cout << '\n';
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int cur = 0;
    for (int i = 1; i < N; ++i) {
        while ((1 << (cur + 1)) < i)
            ++cur;
        pw[i] = cur;
    }   
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)    
        sort(all(g[i]), comp);
    for (int i = 0; i < eu.size(); ++i)
        sp[0][i] = l[eu[i]];
    for (int p = 1; p < LG; ++p)
        for (int i = 0; i + (1 << p) - 1 < eu.size(); ++i)
            sp[p][i] = min(sp[p - 1][i], sp[p - 1][i + (1 << (p - 1))]);
    int q;
    cin >> q;
    while (q--) 
        solve();
}