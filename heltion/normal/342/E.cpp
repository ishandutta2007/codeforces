#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 1;
constexpr int B = 300;
vector<int> G[maxn];
int p[maxn][17], t[maxn], v[maxn], dep[maxn], d[maxn];
void DFS(int u){
    for(int i = 1; i < 17; i += 1) p[u][i] = p[p[u][i - 1]][i - 1];
    for(int v : G[u]) if(v != p[u][0]){
        p[v][0] = u;
        dep[v] = d[v] = d[u] + 1;
        DFS(v);
    }
}
int dis(int u, int v){
    int res = 0;
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 16; i >= 0; i -= 1) if(dep[u] - (1 << i) >= dep[v]){
        res += 1 << i;
        u = p[u][i];
    }
    if(u == v) return res;
    for(int i = 16; i >= 0; i -= 1) if(p[u][i] != p[v][i]){
        u = p[u][i];
        v = p[v][i];
        res += 2 << i;
    }
    return res + 2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1, a, b; i < n; i += 1){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    DFS(1);
    for(int i = 0; i < m; i += 1) cin >> t[i] >> v[i];
    for(int L = 0; L < m; L += B){
        int R = min(L + B, m);
        for(int j = L; j < R; j += 1) if(t[j] == 2){
            int ans = d[v[j]];
            for(int k = L; k < j; k += 1) if(t[k] == 1) ans = min(ans, dis(v[j], v[k]));
            cout << ans  << "\n";
        }
        queue<int> q;
        for(int j = L; j < R; j += 1) if(t[j] == 1){
            d[v[j]] = 0;
            q.push(v[j]);
        }
        while(not q.empty()){
            int u = q.front();
            q.pop();
            for(int v : G[u]) if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}