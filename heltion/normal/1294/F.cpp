#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
using LL = long long;
vector<int> G[maxn];
int cnt[maxn];
int d[maxn];
int d2[maxn];
void DFS(int u, int pa = 0){
    if(not pa) d[u] = 0;
    for(int v : G[u]) if(v != pa){
        d[v] = d[u] + 1;
        DFS(v, u);
    }
}
void DFS2(int u, int t, int pa = 0){
    for(int v : G[u]) if(v != pa){
        DFS2(v, t, u);
        if(not d2[v]) d2[u] = 0;
    }
    if(u == t) d2[u] = 0;
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
    int a = max_element(d + 1, d + n + 1) - d;
    DFS(a);
    int b = max_element(d + 1, d + n + 1) - d;
    fill(d2, d2 + n + 1, maxn);
    DFS2(a, b);
    queue<int> q;
    for(int i = 1; i <= n; i += 1) if(not d2[i]) q.push(i);
    while(not q.empty()){
        int u = q.front();
        q.pop();
        for(int v : G[u]) if(d2[v] == maxn){
            d2[v] = d2[u] + 1;
            q.push(v);
        }
    }
    d2[a] = d2[b] = -1;
    int c = max_element(d2 + 1, d2 + n + 1) - d2;
    cout << d[b] + d2[c] << "\n" << a << " " << b << " " << c;
    return 0;
}