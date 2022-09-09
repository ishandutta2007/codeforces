#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 10;
LL w[maxn];
int d[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1){
            cin >> w[i];
            d[i] = 0;
        }
        for(int i = 1, u, v; i < n; i += 1){
            cin >> u >> v;
            d[u] += 1;
            d[v] += 1;
        }
        LL ans = 0;
        vector<LL> v;
        for(int i = 1; i <= n; i += 1){
            ans += w[i];
            for(int j = 1; j < d[i]; j += 1) v.push_back(w[i]);
        }
        sort(v.begin(), v.end(), greater<LL>());
        cout << ans << " ";
        for(LL x : v) cout << (ans += x) << " ";
        cout << "\n";
    }
    return 0;
}