#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n, k, ans = 1;
        cin >> n >> k;
        for(int i = 0; i < k; i += 1) ans = ans * n % mod;
        cout << ans << "\n";
    }
    return 0;
}