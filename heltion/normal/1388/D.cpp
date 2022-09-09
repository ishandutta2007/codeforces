#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
LL a[maxn];
int b[maxn], d[maxn];
vector<int> G[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 1; i <= n; i += 1){
        cin >> b[i];
        if(~b[i]) d[b[i]] += 1;
    }
    queue<int> q;
    for(int i = 1; i <= n; i += 1) if(not d[i]) q.push(i);
    LL ans = 0;
    while(not q.empty()){
        int u = q.front();
        q.pop();
        ans += a[u];
        if(~b[u]){
            if(not (d[b[u]] -= 1)) q.push(b[u]);
            if(a[u] >= 0){
                G[u].push_back(b[u]);
                a[b[u]] += a[u];
            }
            else G[b[u]].push_back(u);
        }
    }
    for(int i = 1; i <= n; i += 1) for(int v : G[i]) d[v] += 1;
    for(int i = 1; i <= n; i += 1) if(not d[i]) q.push(i);
    cout << ans << "\n";
    while(not q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : G[u]) if(not (d[v] -= 1)) q.push(v);
    }
    return 0;
}