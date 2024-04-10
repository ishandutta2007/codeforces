#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
constexpr LL mod = 1'000'000'007;
set<pair<int, int>> s[maxn];
map<int, int> t[maxn];
vector<pair<int, int>> vp[maxn];
int cr[maxn], n, q;
LL ans = 1;
void mul(int i, int p, int r){
    if(t[p].count(i)){
        s[p].erase({t[p][i], i});
        r += t[p][i];
    }
    t[p][i] = r;
    s[p].insert({t[p][i], i});
    int nr = s[p].size() == n ? s[p].begin()->first : 0;
    while(cr[p] < nr){
        cr[p] += 1;
        ans = ans * p % mod;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 2; i < maxn; i += 1)
        if(vp[i].empty())
            for(int j = i; j < maxn; j += i){
                vp[j].push_back({i, 0});
                for(int k = j; k % i == 0; k /= i) vp[j].back().second += 1;
            }
    cin >> n >> q;
    for(int i = 1, a; i <= n; i += 1){
        cin >> a;
        for(auto [p, r] : vp[a]) mul(i, p, r); 
    }
    for(; q; q -= 1){
        int i, x;
        cin >> i >> x;
        for(auto [p, r] : vp[x]) mul(i, p, r);
        cout << ans << "\n";
    }
    return 0;
}