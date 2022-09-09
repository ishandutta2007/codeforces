#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
constexpr int mod = 1000000007;
LL power(LL a, LL r){
    LL res = 1;
    for(; r; r >>= 1, a = a * a % mod)
        if(r & 1) res = res * a % mod;
    return res;
}
void add(vector<pair<int, int>>& vp, int k, int p){
    if(vp.empty()) vp.push_back({k, 1});
    else if(vp.back().first != k) vp.push_back({k, -1});
    else{
        vp.back().second -= 1;
        if(vp.back().second == 0) vp.pop_back();
        else if(vp.back().second == -p){
            vp.pop_back();
            add(vp, k + 1, p);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, p;
        cin >> n >> p;
        vector<int> v(n);
        for(int &k : v) cin >> k;
        if(p == 1) cout << n % 2 << "\n";
        else{
            vector<pair<int, int>> vp;
            sort(v.begin(), v.end(), greater<int>());
            for(int k : v) add(vp, k, p);
            LL ans = 0;
            for(auto [x, y] : vp) ans += power(p, x) * y % mod;
            ans = (ans % mod + mod) % mod;
            cout << ans << "\n";
        }
    }
    return 0;
}