#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2007;
int n, m;
char a[N][N];
vector <int> g[N], g1[N];
bool used[N];
int c[N];
void dfs(int u, int cc) {
    used[u] = 1;
    c[u] = cc;
    for (int v : g[u]) {
        if (!used[v]) dfs(v, cc);
    }   
}   
int ans[N];
void dfs1(int u) {
    used[u] = 1;
    ans[u] = 1;
    for (int v : g1[u]) {
        if (!used[v]) dfs1(v);
        ans[u] = max(ans[u], ans[v] + 1);
    }   
}   
void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '=') {
                g[i].push_back(n + j);
                g[n + j].push_back(i);
            }   
        }   
    }       
    int cc = 0;
    for (int i = 0; i < n + m; ++i) {
        if (!used[i]) {
            dfs(i, cc);
            ++cc;
        }   
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '>') {
                g1[c[i]].push_back(c[n + j]);
            }
            else if (a[i][j] == '<') {
                g1[c[n + j]].push_back(c[i]);
            }   
        }   
    }   
    memset(used, 0, sizeof used);
    for (int i = 0; i < cc; ++i) {
        if (!used[i]) {
            dfs1(i);
        }   
    }   
}
int x[N], y[N];
void check() {
    for (int i = 0; i < n; ++i) {
        x[i] = ans[c[i]];
    }   
    for (int i = 0; i < m; ++i) {
        y[i] = ans[c[i + n]];
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '=') {
                if (x[i] != y[j]) {
                    cout << "No\n";
                    exit(0);
                }   
            }
            else if (a[i][j] == '<') {
                if (!(x[i] < y[j])) {
                    cout << "No\n";
                    exit(0);
                }
            }
            else {
                if (!(x[i] > y[j])) {
                    cout << "No\n";
                    exit(0);
                }
            }   
        }   
    }   
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else 
        ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }   
    }   
    solve();
    check();
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << x[i] << ' ';
    }   
    cout << '\n';
    for (int i = 0; i < m; ++i) {
        cout << y[i] << ' ';
    }   
    cout << '\n';
}