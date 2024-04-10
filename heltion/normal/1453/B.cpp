#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<LL> v(n);
        for(LL& x : v) cin >> x;
        LL ans = 0, add = 0;
        for(int i = 1; i < n ; i += 1) ans += abs(v[i] - v[i - 1]);
        for(int i = 0; i < n; i += 1){
            if(i == 0) add = max(add, abs(v[1] - v[0]));
            else if(i == n - 1) add = max(add, abs(v[n - 1] - v[n - 2]));
            else add = max(add, abs(v[i] - v[i - 1]) + abs(v[i + 1] - v[i]) - abs(v[i + 1] - v[i - 1]));
        }
        cout << ans - add << "\n";
    }
    return 0;
}