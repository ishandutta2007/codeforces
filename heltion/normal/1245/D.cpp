#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2400;
LL x[maxn], y[maxn], c[maxn], k[maxn];
int pa[maxn];
int fpa(int u){
    return pa[u] == u ? u : pa[u] = fpa(pa[u]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> x[i] >> y[i];
    for(int i = 1; i <= n; i += 1) cin >> c[i];
    for(int i = 1; i <= n; i += 1) cin >> k[i];
    vector<pair<LL, pair<int, int>>> e;
    for(int i = 1; i <= n; i += 1) e.push_back({c[i], {0, i}});
    for(int i = 1; i < n; i += 1)
        for(int j = i + 1; j <= n; j += 1)
            e.push_back({(abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]), {i, j}});
    sort(e.begin(), e.end());
    for(int i = 1; i <= n; i += 1) pa[i] = i;
    LL ans = 0;
    vector<int> ansc;
    vector<pair<int, int>> anse;
    for(auto p : e){
        int u = fpa(p.second.first), v = fpa(p.second.second);
        if(u != v){
            pa[u] = v;
            ans += p.first;
            if(p.second.first) anse.push_back(p.second);
            else ansc.push_back(p.second.second);
        }
    }
    cout << ans << "\n";
    cout << ansc.size() << "\n";
    for(int x : ansc) cout << x << " ";
    cout << "\n";
    cout << anse.size() << "\n";
    for(auto p : anse) cout << p.first << " " << p.second << "\n";
    return 0;
}