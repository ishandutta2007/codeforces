#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
constexpr int maxn = 500000 + 1;
int k[maxn], a[maxn], b[maxn];
int par[maxn], t[maxn], sz[maxn];
int getp(int u){
    return u == par[u] ? u : par[u] = getp(par[u]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    for(int i = 1; i <= m; i += 1) par[i] = i;
    for(int i = 1; i <= n; i += 1){
        cin >> k[i];
        if(k[i] == 1){
            cin >> a[i];
            int pa = getp(a[i]), p0 = getp(0);
            if(pa != p0){
                par[pa] = p0;
                ans.push_back(i);
            }
        }
        else{
            cin >> a[i] >> b[i];
            int pa = getp(a[i]), pb = getp(b[i]);
            if(pa != pb){
                par[pa] = pb;
                ans.push_back(i);
            }
        }
    }
    LL res = 1;
    for(int x : ans) res = res * 2 % mod;
    cout << res << " ";
    cout << ans.size() << "\n";
    for(int x : ans) cout << x  << " ";
    return 0;
}