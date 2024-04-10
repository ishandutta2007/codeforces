#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1000000007;
constexpr int maxn = 120000;
LL f[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    f[0] = f[1] = 1;
    for(int i = 2; i < maxn; i += 1) f[i] = (f[i - 2] + f[i - 1]) % mod;
    string s;
    cin >> s;
    LL ans = 1;
    for(int L = 0, R = 0; L < (int)s.size(); L = R){
        while(R < (int)s.size() and s[R] == s[L]) R += 1;
        if(s[L] == 'u' or s[L] == 'n') ans = ans * f[R - L] % mod;
        if(s[L] == 'w' or s[L] == 'm') ans = 0;
    }
    cout << ans;
    return 0;
}