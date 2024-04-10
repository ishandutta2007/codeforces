#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    LL ans = 0;
    map<int, int> mp;
    for(int i = 0, t; i < n; i += 1){
        cin >> t;
        ans += mp[-t];
        mp[t] += 1;
    }
    cout << ans;
    return 0;
}