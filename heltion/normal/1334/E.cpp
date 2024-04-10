#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 64;
constexpr LL mod = 998244353;
LL f[maxn], g[maxn];
vector<pair<LL, int>> vp;
unordered_map<LL, LL> ump;
unordered_map<LL, LL> umd;
void DFS(LL v, LL sm, LL pd, LL d, int i){
    //cout << v << " " << sm << " " << pd << " " << i << "\n";
    if(i == vp.size()){
        ump[v] = f[sm] * pd % mod;
        umd[v] = d;
        return;
    }
    for(LL r = 0; r <= vp[i].second; r += 1){
        DFS(v, sm + r, pd * g[r] % mod, d * (r + 1), i + 1);
        v *= vp[i].first;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL D;
    cin >> D;
    for(int i = 0; i < 64; i += 1) f[i] = i ? f[i - 1] * i % mod : 1;
    for(int i = 1; i < 64; i += 1) g[i] = i == 1 ? 1 : g[mod % i] * (mod - mod / i) % mod;
    for(int i = 0; i < 64; i += 1) g[i] = i ? g[i - 1] * g[i] % mod : 1;
    for(LL p = 2; p * p <= D; p += 1) if(D % p == 0){
        vp.push_back({p, 0});
        for(; D % p == 0; D /= p) vp.back().second += 1;
    }
    if(D > 1) vp.push_back({D, 1});
    DFS(1, 0, 1, 1, 0);
    int q;
    for(cin >> q; q; q -= 1){
        LL u, v;
        cin >> u >> v;
        LL d = gcd(u, v);
        LL x = ump[u / d] * ump[v / d] % mod;
        LL rd = umd[u] + umd[v] - 2 * umd[d];
        LL rm = 2 * umd[u / d * v] - umd[u] - umd[v];
        cout << ((rd == rm and d != v and d != u) + 1) * x % mod << "\n";
    }
    return 0;
}