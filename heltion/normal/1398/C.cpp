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
        string s;
        cin >> n >> s;
        map<int, LL> mp;
        int sum = 0;
        mp[1] += 1;
        for(int i = 0; i < n; i += 1){
            sum += s[i] - '0';
            mp[sum - i] += 1;
        }
        LL ans = 0;
        for(auto [x, y] : mp) ans += y * (y - 1) / 2;
        cout << ans << "\n";
    }
    return 0;
}