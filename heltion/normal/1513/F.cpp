#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    //ai <= aj
    //ai bj aj bi : 2(aj - bj)
    //bj ai bi aj : 2(bi - ai)
    //ai bj bi aj : 2(bi - bj)
    //bj ai aj bi : 2(aj - ai)
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for(auto& [x, y] : vp) cin >> x;
    for(auto& [x, y] : vp) cin >> y;
    LL sum = 0, ans = 0;
    for(auto [x, y] : vp) sum += abs(x - y);
    vector<int> d;
    for(auto [x, y] : vp){
        d.push_back(x);
        d.push_back(y);
    }
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    vector<int> bit(d.size());
    auto update = [&](int x, int v){
        x = lower_bound(d.begin(), d.end(), x) - d.begin();
        for(x += 1; x <= (int)d.size(); x += x & -x) bit[x - 1] = max(bit[x - 1], v);
    };
    auto query = [&](int x){
        int res = 0;
        x = lower_bound(d.begin(), d.end(), x) - d.begin();
        for(x += 1; x; x -= x & -x) res = max(bit[x - 1], res);
        return res;
    };
    auto f = [&](){
        fill(bit.begin(), bit.end(), 0);
        sort(vp.begin(), vp.end());
        for(auto [x, y] : vp){
            if(x > y) {
                int m = query(y);
                if(query(y) >= x) ans = max(ans, 2LL * abs(x - y));
                else if(m > y) ans = max(ans, 2LL * abs(m - y));
            }
            if(x < y) update(x, y);
        }
    };
    f();
    for(auto& [x, y] : vp) swap(x, y);
    f();
    cout << sum - ans;
    return 0;
}