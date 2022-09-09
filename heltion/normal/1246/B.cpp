#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
vector<int> d[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 2; i <= 100000; i += 1) if(d[i].empty()) for(int j = i; j <= 100000; j += i) d[j].push_back(i);
    map<vector<int>, int> mp;
    LL ans = 0;
    for(int i = 0, a, b; i < n; i += 1){
        cin >> a;
        b = a;
        vector<int> v;
        for(int x : d[a]){
            int r = 0;
            for(;b % x == 0; b /= x) r = (r + 1) % k;
            if(r){
                v.push_back(x);
                v.push_back(r);
            }
        }
        vector<int> w(v);
        for(int i = 1; i < (int)w.size(); i += 2) w[i] = k - w[i];
        ans += mp[w];
        mp[v] += 1;
    }
    cout << ans;
    return 0;
}