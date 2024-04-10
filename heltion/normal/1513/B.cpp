#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& x : a) cin >> x;
        int h = 0;
        for(int i = 0; i < 30; i += 1){
            h |= 1 << i;
            for(int x : a) if(not ((x >> i) & 1)) h &= ~(1 << i);
        }
        int c = count(a.begin(), a.end(), h);
        LL ans = (LL)c * (c - 1) % mod;
        for(int i = 1; i <= n - 2; i += 1) ans = ans * i % mod;
        cout << ans << "\n";
    }
    return 0;
}