#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<LL> cnt(60), x(n);
        for(LL& _ : x){
            cin >> _;
            for(int i = 0; i < 60; i += 1) if((_ >> i) & 1) cnt[i] += 1;
        }
        LL ans = 0;
        for(LL _ : x){
            LL A = 0;
            for(int i = 0; i < 60; i += 1) if((_ >> i) & 1) (A += (1LL << i) % mod * cnt[i]) %= mod;
            LL B = 0;
            for(int i = 0; i < 60; i += 1)
                if((_ >> i) & 1) (B += (1LL << i) % mod * n) %= mod;
                else (B += (1LL << i) % mod * cnt[i]) %= mod;
            ans = (ans + A * B) % mod;
            //cout << _ << " " << A << " " << B << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}