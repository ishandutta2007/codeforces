#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200 + 1;
vector<pair<int, int>> G[maxn];
int d[maxn];
int a[maxn], ans = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i += 1){
        int u, v, b;
        cin >> u >> v >> b;
        G[u].push_back({v, b});
        G[v].push_back({u, -b});
    }
    for(int i = 1; i <= n; i += 1){
        for(int i = 1; i <= n; i += 1) d[i] = maxn;
        d[i] = 0;
        for(int i = 1; i <= n; i += 1)
            for(int j = 1; j <= n; j += 1)
                for(auto p : G[j]){
                    if(p.second == 0) d[p.first] = min(d[p.first], d[j] + 1);
                    else d[p.first] = min(d[p.first], d[j] + p.second);
                }
        int ok = 1;
        for(int i = 1; i <= n; i += 1) if(d[i] < 0) ok = 0;
        else for(auto p : G[i]){
            if(p.second == 0) ok &= abs(d[i] - d[p.first])  == 1;
            else ok &= d[i] + p.second == d[p.first];
        }
        if(ok){
            int pans = *max_element(d + 1, d + n + 1);
            if(pans > ans){
                for(int i = 1; i <= n; i += 1) a[i] = d[i];
                ans = pans;
            }
        }
    }
    if(ans == -1) cout << "NO";
    else{
        cout << "YES\n";
        cout << ans << "\n";
        for(int i = 1; i <= n; i += 1) cout << a[i] << " ";
    }
    return 0;
}