#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

struct Kek {
    int a, b, c;
};  

int n, m;
vector <int> g[MAXN];

vector <Kek> ans;

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
}

bool used[MAXN];
int par[MAXN];
bool us[MAXN];

int h[MAXN];
void dfs(int u, int parent, int d) {
    h[u] = d;
    par[u] = parent;
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) {
            dfs(v, u, d + 1);
        }   
    }   
    vector <int> a;
    for (int v : g[u]) {
        if (h[v] < h[u]) {
            continue;
        }   
        else if (par[v] == u) {
            if (!us[v]) {
                a.push_back(v);
            }   
        }
        else {
            a.push_back(v);
        }   
    }   
    if (a.size() % 2 == 0) {
        for (int i = 0; i < (int)a.size(); i += 2) {
            ans.push_back({a[i], u, a[i + 1]});
        }   
    }
    else {
        for (int i = 0; i < (int)a.size() - 1; i += 2) {
            ans.push_back({a[i], u, a[i + 1]});
        }
        if (parent != -1) {   
            us[u] = 1;
            ans.push_back({a.back(), u, parent});
        }
    }   
}   

void solve() {
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, -1, 0);
        }
    }   
}

void print() {
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.a + 1 << ' ' << e.b + 1 << ' ' << e.c + 1 << '\n';
    }   
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}