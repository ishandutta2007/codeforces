#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000 + 1;
vector<pair<int, int>> G[maxn];
int c[maxn], d[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v, t; i < m; i += 1){
        cin >> u >> v >> t;
        G[v].push_back({u, t});
    }
    for(int i = 1; i <= n; i += 1){
        d[i] = n;
        c[i] = -1;
    }
    queue<int> q;
    d[n] = 0;
    q.push(n);
    while (not q.empty()){
        int u = q.front();
        q.pop();
        for(auto [v, t] : G[u])
            if(c[v] == -1) c[v] = t ^ 1;
            else if(c[v] == t and d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
    }
    cout << (d[1] == n ? -1 : d[1]) << "\n";
    for(int i = 1; i <= n; i += 1) if(c[i] == -1) cout << "1"; else cout << c[i];
    return 0;
}