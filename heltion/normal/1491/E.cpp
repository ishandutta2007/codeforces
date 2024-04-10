#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
set<int> G[maxn];
int sz[maxn], par[maxn];
vector<int> ps;
void DFS(int u){
    ps.push_back(u);
    sz[u] = 1;
    for(int v : G[u]) if(v != par[u]){
        par[v] = u;
        DFS(v);
        sz[u] += sz[v];
    }
}
int check(int u, int n){
    if(n <= 3) return 1;
    int A = 1, B = 1;
    while(A + B < n){
        int nA = B, nB = A + B;
        A = nA;
        B = nB;
    }
    if(A + B != n) return 0;
    ps.clear();
    par[u] = -1;
    DFS(u);
    int x = 0, y = 0;
    for(int i : ps)
        if(sz[i] == A or sz[i] == B){
            x = i;
            y = par[i];
        }
    if(x == 0) return 0;
    G[x].erase(y);
    G[y].erase(x);
    if(sz[x] == B) swap(A, B);
    return check(x, A) and check(y, B);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1, u, v; i < n; i += 1){
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    cout << (check(1, n) ? "YES\n" : "NO\n");
    return 0;
}