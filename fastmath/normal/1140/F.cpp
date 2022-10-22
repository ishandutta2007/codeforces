#include<bits/stdc++.h>
using namespace std;
#define int long long
#define u first
#define v second
#define Edge pair <int, int>
const int N = 3e5 + 7;
const int V = N << 1;
int q;
map <Edge , int> pr;
Edge e[N];
vector <Edge> tree[N << 2];
void add(int v, int tl, int tr, int l, int r, Edge e) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        tree[v].push_back(e);
        return;
    }   
    int tm = (tl + tr) >> 1;
    add(v * 2 + 1, tl, tm, l, r, e);
    add(v * 2 + 2, tm + 1, tr, l, r, e);
}   
int par[V];
int cnt[V][2];
int root(int u) {
    while (par[u] != u) u = par[u];
    return u;
}   

vector <pair <int&, int> > st;

int get(int u) {
    return cnt[u][0] * cnt[u][1];
}

int ans = 0;
void merge(int u, int v) {
    u = root(u); v = root(v);
    if (u == v) return;

    if (cnt[v][0] + cnt[v][1] < cnt[u][0] + cnt[u][1]) swap(u, v);

    st.push_back({ans, ans});

    ans -= get(u);
    ans -= get(v);

    //cout << "-= " << get(u) << '\n';
    //cout << "-= " << get(v) << '\n';

    st.push_back({par[u], par[u]});
    par[u] = v;

    st.push_back({cnt[v][0], cnt[v][0]});
    st.push_back({cnt[v][1], cnt[v][1]});
    cnt[v][0] += cnt[u][0];
    cnt[v][1] += cnt[u][1];

    //cout << "+= " << get(v) << '\n';
    ans += get(v);
}   
void add(Edge e) {
    merge(e.u, e.v);
}   
void rollback(int sz) {
    while (st.size() > sz) {
        st.back().first = st.back().second;
        st.pop_back();
    }   
}   
void solve(int v, int tl, int tr) {
    int sz = st.size();
    for (auto e : tree[v]) {
        add(e);
    }
    if (tl == tr) {
        cout << ans << ' ';
    }   
    else {
        int tm = (tl + tr) >> 1;
        solve(v * 2 + 1, tl, tm);
        solve(v * 2 + 2, tm + 1, tr);
    }   
    rollback(sz);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);            
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < V; ++i) {
        par[i] = i;
        cnt[i][0] = i < N;
        cnt[i][1] = N <= i;
    }   

    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> e[i].u >> e[i].v;
        e[i].v += N;
        if (pr.find(e[i]) != pr.end()) {
            //cout << "add " << pr[e[i]] << ' ' << i - 1 << ' ' << e[i].u << ' ' << e[i].v - N << '\n';
            add(0, 0, q - 1, pr[e[i]], i - 1, e[i]);
            pr.erase(e[i]);
        }   
        else {
            pr[e[i]] = i;
        }   
    }   
    for (auto e : pr) {
        //cout << "add " << e.second << ' ' << q - 1 << ' ' << e.first.u << ' ' << e.first.v - N << '\n';
        add(0, 0, q - 1, e.second, q - 1, e.first);
    }   
    solve(0, 0, q - 1);
    cout << '\n';
}