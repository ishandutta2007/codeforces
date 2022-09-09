#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    LL m = 1;
    for(int i = 1; i <= n; i += 1) m = m * (mod + 1) / 2 % mod;
    if(n <= 2){
        cout << m;
        return 0;
    }
    vector<LL> f(n + 1);
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= n; i += 1){
        f[i] = f[i - 1];
        f[i] = (f[i] + f[i - 2]) % mod;
        if(i == n) cout << f[n] * m % mod;
    }
    return 0;
}