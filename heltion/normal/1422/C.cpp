#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    LL n = s.size();
    LL pw = 1, sum = 0, ans = 0;
    for(int i = 0; i < n; i += 1){
        ans = (ans + (n - i - 1) * (n - i) / 2 % mod * pw % mod * (s[i] - '0')) % mod;
        ans = (ans + (s[i] - '0') * sum) % mod;
        sum = (sum + pw * (i + 1)) % mod;
        pw = pw * 10 % mod;
    }
    cout << ans;
    return 0;
}