#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 600;
int d[maxn], done[maxn], tmp[maxn];
vector<pair<int, int>> G[maxn];
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0, a, b, c; i < m; i += 1){
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < n; j += 1){
            done[j] = 0;
            d[j] = 1E9 + n;
        }
        d[i] = 0;
        for(int j = 0; j < n; j += 1){
            int u = -1;
            for(int k = 0; k < n; k += 1) if(not done[k]){
                if(u == -1 or d[k] < d[u]) u = k;
            }
            done[u] = 1;
            for(int k = 0; k < n; k += 1) tmp[k] = 1E9 + n;
            for(auto& [v, w] : G[u])
                tmp[(d[u] + v) % n] = min(tmp[(d[u] + v) % n], d[u] + w);
            for(int _ = 0; _ < 2; _ += 1) for(int i = 0; i < n; i += 1) tmp[i] = min(tmp[i], tmp[i ? i - 1 : n - 1] + 1);
            for(int k = 0; k < n; k += 1) d[k] = min(d[k], tmp[k]);
            
        }
        for(int j = 0; j < n; j += 1) cout << d[j] << " ";
        cout << "\n";
    }
    return 0;
}