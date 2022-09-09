#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
int a[maxn];
map<vector<int>, int> mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i += 1) cin >> a[i];
    for(int i = 0; i < (1 << 15); i += 1){
        vector<int> vd(n);
        for(int j = 0; j < n; j += 1) vd[j] = __builtin_popcount((a[j] & 32767) ^ i) - __builtin_popcount((a[1] & 32767) ^ i);
        if(not mp.count(vd)) mp[vd] = i;
    }
    for(int i = 0; i < (1 << 15); i += 1){
        vector<int> vd(n);
        for(int j = 0; j < n; j += 1) vd[j] = __builtin_popcount((a[1] >> 15) ^ i) - __builtin_popcount((a[j] >> 15) ^ i);
        if(mp.count(vd)){
            cout << (i << 15) + mp[vd];
            return 0;
        }
    }
    cout << -1;
    return 0;
}