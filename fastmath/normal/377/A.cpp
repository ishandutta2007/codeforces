#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 501;
int n, m, k;
char a[N][N];
const int V = N * N;
vector <int> g[V];
int num(int i, int j) {
    return i * N + j;
}   
void add(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}   
int par[V];
int pw[V];
bool used[V];
void dfs(int u, int p) {
    used[u] = 1;
    par[u] = p;
    for (int v : g[u]) {
        if (!used[v]) {
            dfs(v, u);
            ++pw[u];
        }
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                if (a[i + 1][j] == '.') {
                    add(num(i, j), num(i + 1, j));
                }   
                if (a[i][j + 1] == '.') {
                    add(num(i, j), num(i, j + 1));
                }   
            }   
        }   
    }   
    int r = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                r = num(i, j);
                break;
            }   
        }   
    }   
    dfs(r, r);
    queue <int> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.' && !pw[num(i, j)]) {
                q.push(num(i, j));
            }   
        }   
    }   
    while (q.size() && k) {
        --k;
        auto u = q.front(); q.pop();
        a[u / N][u % N] = 'X';
        //cout << "del " << u / N << ' ' << u % N << '\n';
        //cout << "par " << par[u] / N << ' ' << par[u] % N << ' ' << pw[par[u]] << '\n';
        --pw[par[u]];
        if (!pw[par[u]]) {
            //cout << "add " << par[u] / N << ' ' << par[u] % N << '\n';
            q.push(par[u]);
        }   
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j];
        }   
        cout << '\n';
    }   
}