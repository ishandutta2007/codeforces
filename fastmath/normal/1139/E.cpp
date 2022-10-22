#include<bits/stdc++.h>
using namespace std;

const int N = 5001;

vector <int> g[N];
int u[N], v[N];

int p[N];
bool used_[N];

bool dfs(int u) {
    used_[u] = 1;
    for (int v : g[u]) {
        if (p[v] == -1) {
            p[v] = u;
            return 1;
        }   
    }   
    for (int v : g[u]) {
        if (!used_[p[v]] && dfs(p[v])) {
            p[v] = u;
            return 1;
        }   
    }   
    return 0;
}   

int ans = 0;
void add(int i) {
    g[u[i]].push_back(v[i]);
    while (1) {
        memset(used_, 0, sizeof used_);
        if (dfs(ans)) ++ans;
        else break;
    }
}   

int ans_mem[N];
int del[N];
bool used[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 0; i < N; ++i) p[i] = -1;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> u[i];
    for (int i = 0; i < n; ++i) {
        cin >> v[i]; --v[i];
    }   
    int d;
    cin >> d;
    for (int i = 0; i < d; ++i) {
        cin >> del[i];
        --del[i];
        used[del[i]] = 1;
    }   
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            add(i);
        }   
    }   
    for (int i = d - 1; i >= 0; --i) {
        ans_mem[i] = ans;
        add(del[i]);
    }   
    for (int i = 0; i < d; ++i) {
        cout << ans_mem[i] << '\n';
    }
}