#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        map<int, int> mp;
        LL ans = 0;
        for(int i = 0, x; i < n; i += 1){
            cin >> x;
            ans += mp[__builtin_clz(x)];
            mp[__builtin_clz(x)] += 1;
        }
        cout << ans << "\n";
    }
    return 0;
}