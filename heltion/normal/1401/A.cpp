#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        int ans = abs(n - k);
        if(n >= k) ans = min(ans, (n - k) & 1);
        cout << ans << "\n";
    }
    return 0;
}