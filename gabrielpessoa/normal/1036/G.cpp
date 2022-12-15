#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1e6+5;

vector<int> g[ms];
int saiDe[ms], w = 0;
int sinkIdx[ms], z = 0;
int deg[ms];

void dfs(int u, int par, int &bm) {
    if(~sinkIdx[u]) bm |= (1 << sinkIdx[u]);
    for(int v : g[u]) {
        if(v != par) dfs(v, u, bm);
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        deg[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(g[i].size() == 0) {
            sinkIdx[i] = z++;
        } else {
            sinkIdx[i] = -1;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) {
            dfs(i, -1,  saiDe[w++]);
        }
    }
    for(int i = 1; i < (1 << w) - 1; i++) {
        int bm = 0;
        for(int j = 0; j < w; j++) {
            if(i & (1 << j)) {
                bm |= saiDe[j];
            }
        }
        if(__builtin_popcount(bm) <= __builtin_popcount(i)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}