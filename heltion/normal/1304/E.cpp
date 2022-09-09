#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 120000;
vector<int> G[maxn];
int p[maxn][20], d[maxn];
int dis(int u, int v){
    int res = 0;
    while(d[u] != d[v]){
        if(d[u] < d[v]) swap(u, v);
        for(int j = 19; ~j; j -= 1)
            if(d[u] - d[v] >= (1 << j)){
                res += 1 << j;
                u = p[u][j];
            }
    }
    if(u == v) return res;
    for(int j = 19; ~j; j -= 1)
        if(p[u][j] != p[v][j]){
            res += (1 << j) * 2;
            u = p[u][j];
            v = p[v][j];
        }
    return res + 2;
}
void DFS(int u){
    for(int i = 1; i < 20; i += 1) p[u][i] = p[p[u][i - 1]][i - 1];
    for(int v : G[u]) if(p[u][0] != v){
        p[v][0] = u;
        d[v] = d[u] + 1;
        DFS(v);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1, u, v; i < n; i += 1){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(1);
    int q;
    for(cin >> q; q; q -= 1){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        bool ok = false;
        int d;
        d = dis(a, b);
        if(d <= k and d % 2 == k % 2) ok = true;
        d = dis(a, x) + dis(y, b) + 1;
        if(d <= k and d % 2 == k % 2) ok = true;
        d += dis(x, y) + 1;
        if(d <= k and d % 2 == k % 2) ok = true;
        d = dis(a, y) + dis(x, b) + 1;
        if(d <= k and d % 2 == k % 2) ok = true;
        d += dis(x, y) + 1;
        if(d <= k and d % 2 == k % 2) ok = true;
        d = dis(a, x) + dis(x, y) + 1 + dis(x, b);
        if(d <= k and d % 2 == k % 2) ok = true;
        d = dis(a, y) + dis(x, y) + 1 + dis(y, b);
        if(d <= k and d % 2 == k % 2) ok = true;
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}