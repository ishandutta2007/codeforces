#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
vector<int> G[maxn];
int hs[maxn], sz[maxn], n, par[maxn];
void DFS(int u){
    sz[u] = 1;
    hs[u] = 0;
    for(int v : G[u]) if(v != par[u]){
        par[v] = u;
        DFS(v);
        sz[u] += sz[v];
        if(sz[v] >= hs[u]) hs[u] = max(hs[u], sz[v]);
    }
    hs[u] = max(hs[u], n - sz[u]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        cin >> n;
        for(int i = 1; i <= n; i += 1) G[i].clear();
        for(int i = 1, x, y; i < n; i += 1){
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        par[1] = 0;
        DFS(1);
        int m = *min_element(hs + 1, hs + n + 1);
        vector<int> c;
        for(int i = 1; i <= n; i += 1) if(hs[i] == m) c.push_back(i);
        if(c.size() == 1){
            cout << 1 << " " << G[1][0] << "\n";
            cout << 1 << " " << G[1][0] << "\n";
            continue;
        }
        par[c[0]] = 0;
        DFS(c[0]);
        for(int x : G[c[1]]) if(par[x] == c[1]){
            cout << c[1] << " " << x << "\n";
            cout << c[0] << " " << x << "\n";
            break;
        }
    }
    return 0;
}