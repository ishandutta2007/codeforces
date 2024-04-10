#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int n, m, k;
vector <int> g[N];
int h[N];
int par[N];
int want;
bool used[N];
int depth[N];
void dfs(int u, int p, int d) {
    depth[u] = d;
    used[u] = 1;
    par[u] = p;
    h[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) {
            dfs(v, u, d + 1);
            h[u] = max(h[u], h[v] + 1);
        }   
    }   
}   
vector <int> ans;
void print(int u) {
    used[u] = 1;
    if ((int)ans.size() < want) {
        ans.push_back(u);
    }   
    for (int v : g[u]) {
        if (!used[v] && h[v] + 1 == h[u]) {
            print(v);
            return;
        }   
    }   
}   
vector <int> lief;
void ilnr(int u) {
    used[u] = 1;
    bool ch = 1;
    for (int v : g[u]) {
        if (!used[v]) {
            ch = 0;
            ilnr(v);
        }   
    }   
    if (ch && (int)lief.size() < k) {
        lief.push_back(u);
    }   
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    dfs(0, 0, 0);
    want = (n + k - 1) / k;
    if (h[0] >= want) {
        cout << "PATH\n";
        memset(used, 0, sizeof used);
        print(0);
        cout << want << '\n';
        for (int e : ans) cout << e + 1 << ' ';
        cout << '\n';
    }
    else {
        cout << "CYCLES\n";
        memset(used, 0, sizeof used);        
        ilnr(0);
        for (int u : lief) {
            int v = -1, c = -1;
            for (int t : g[u]) {
                if (t != par[u]) {
                    if (v == -1) {
                        v = t;
                    }   
                    else if (c == -1) {
                        c = t;
                    }   
                }   
            }   
            if (depth[v] < depth[c]) swap(v, c);
            vector <int> ans;
            if ((depth[u] - depth[v]) % 3 != 2) {
                int t = u;
                while (1) {
                    ans.push_back(t);
                    if (t == v) break;
                    t = par[t];
                }   
            }
            else if ((depth[u] - depth[c]) % 3 != 2) {
                int t = u;
                while (1) {
                    ans.push_back(t);
                    if (t == c) break;
                    t = par[t];
                }   
            }
            else {
                ans.push_back(u);
                int t = v;
                while (1) {
                    ans.push_back(t);
                    if (t == c) break;
                    t = par[t];
                }   
            }   
            cout << ans.size() << '\n';
            for (auto e : ans) cout << e + 1 << ' ';
            cout << '\n';
        }   
    }   
}