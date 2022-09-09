#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000 + 1;
struct{
    int u, v;
}e[maxn];
LL w[maxn];
vector<int> G[maxn];
int vis[maxn];
vector<int> A, B;
LL n, m, x;
void DFS(int u){
    vis[u] = 1;
    for(int i : G[u]){
        int v = e[i].u ^ e[i].v ^ u;
        if(not vis[v]){
            DFS(v);
            if(w[v] + w[u] < x)
                B.push_back(i);
            else{
                A.push_back(i);
                w[u] = w[u] + w[v] - x;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> x;
    LL sum = 0;
    for(int i = 1; i <= n; i += 1){
        cin >> w[i];
        sum += w[i];
    }
    if(sum < (n - 1) * x){
        cout << "NO";
        return 0;
    }
    for(int i = 1; i <= m; i += 1){
        cin >> e[i].u >> e[i].v;
        G[e[i].u].push_back(i);
        G[e[i].v].push_back(i);
    }
    DFS(1);
    cout << "YES\n";
    reverse(B.begin(), B.end());
    for(int i : A) cout << i << "\n";
    for(int i : B) cout << i << "\n";
    return 0;
}