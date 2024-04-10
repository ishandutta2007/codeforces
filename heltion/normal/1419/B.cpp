#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -=1){
        LL x, ans = 0;
        cin >> x;
        for(LL n = 1; n * (n + 1) / 2 <= x; n = n * 2 + 1){
            x -= n * (n + 1) / 2;
            ans += 1;
        }
        cout << ans << "\n";
    }
    return 0;
}