#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
const int N = 2e5 + 7;
const int INF = 1e18 + 7;
int n, m, q;
struct Edge {
    int u, v, c;
};
Edge ed[N];
vector <int> g[N];
bool inp[N];
int par[N], le[N];
int dist[N];
vector <int> path;
int pos[N];
void fp() {
    for (int i = 0; i < N; ++i) {
        dist[i] = INF;
        par[i] = -1; le[i] = -1;
    }   
    dist[1] = 0;
    set <ii> ms;
    ms.insert({0, 1});
    while (ms.size()) {
        int u = ms.begin()->second; ms.erase(ms.begin());
        for (int i : g[u]) {
            auto e = ed[i];
            int v = e.u ^ e.v ^ u;
            if (dist[u] + e.c < dist[v]) {
                ms.erase({dist[v], v});
                dist[v] = dist[u] + e.c;
                ms.insert({dist[v], v});
                par[v] = u;
                le[v] = i;
            }   
        }   
    }   
    int c = n;
    while (par[c] != -1) {
        inp[le[c]] = 1;
        path.push_back(le[c]);
        c = par[c];
    }   
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); ++i) {
        pos[path[i]] = i;
    }   
}   
void calc(int S, int T, int *last, int *dist) {
    for (int i = 0; i < N; ++i) {
        dist[i] = INF;
        last[i] = -1;
    }   
    dist[S] = 0;
    set <ii> ms; ms.insert({0, S});
    while (ms.size()) {
        int u = ms.begin()->second; ms.erase(ms.begin());
        for (int i : g[u]) {
            auto e = ed[i];
            int v = e.u ^ e.v ^ u;
            if (dist[u] + e.c < dist[v]) {
                ms.erase({dist[v], v});
                dist[v] = dist[u] + e.c;
                ms.insert({dist[v], v});
                if (inp[i]) last[v] = pos[i];
                else last[v] = last[u];
            }   
        }   
    }   
}   
int dd[2][N];
int l[N], r[N];
int del[N];
vector <pair <bool, int> > ev[N];
void add(int l, int r, int x) {
    if (l <= r) {
        //cout << "add " << l << ' ' << r << ' ' << x << '\n';
        ev[l].push_back({1, x});
        ev[r + 1].push_back({0, x});
    }   
}   
void read() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> ed[i].u >> ed[i].v >> ed[i].c;
        g[ed[i].u].push_back(i); g[ed[i].v].push_back(i);
    }   
}
void solve() { 
    fp();
    calc(1, n, l, dd[0]); calc(n, 1, r, dd[1]);    
    for (int i = 1; i <= n; ++i) {
        if (r[i] == -1) r[i] = path.size();
    }   
    for (int i = 1; i <= m; ++i) {
        if (!inp[i]) {
            auto e = ed[i];
            add(l[e.u] + 1, r[e.v] - 1, dd[0][e.u] + e.c + dd[1][e.v]);
            add(l[e.v] + 1, r[e.u] - 1, dd[0][e.v] + e.c + dd[1][e.u]);
        }
    }   
    multiset <int> ms;
    for (int i = 0; i < (int)path.size(); ++i) {
        for (auto e : ev[i]) {
            if (e.first) {
                ms.insert(e.second);
            }   
            else {
                ms.erase(ms.find(e.second));
            }   
        }   
        del[i] = *ms.begin();
    }   
}   
void print() {
    while (q--) {
        int i, x;
        cin >> i >> x;
        if (inp[i]) {
            cout << min(del[pos[i]], dist[n] - ed[i].c + x) << '\n';
        }
        else {
            int nn = min(dd[0][ed[i].u] + x + dd[1][ed[i].v], dd[0][ed[i].v] + x + dd[1][ed[i].u]);
            cout << min(dist[n], nn) << '\n';
        }   
    }   
}   
signed main() {
    #ifdef HOME 
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    read(); solve(); print();
}