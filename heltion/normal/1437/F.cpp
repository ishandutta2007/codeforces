#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 5000 + 2;
constexpr LL mod = 998244353;
int a[maxn];
LL f[maxn], g[maxn], dp[maxn];
LL power(LL a, LL r){
    LL res = 1;
    for(; r; r >>= 1, a = a * a % mod)
        if(r & 1) res = res * a % mod;
    return res;
}
void add(LL& x, LL y){
    x += y;
    if(x >= mod) x -= mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 0; i <= n; i += 1){
        f[i] = i ? f[i - 1] * i % mod : 1;
        g[i] = power(f[i], mod - 2);
    }
    sort(a + 1, a + n + 1, greater<int>());
    for(int i = 2; i <= n; i += 1) if(2 * a[i] > a[1]){
        cout << "0";
        return 0;
    }
    dp[1] = 1;
    for(int i = 1; i <= n; i += 1){
        int p = 0;
        for(int j = i + 1; j <= n + 1; j += 1) if(a[i] >= a[j] * 2){
            int m = j - i - 1 - p;
            //cout << i << " " << j << " " << m << " " << p << endl;
            if(i == 1) add(dp[j], f[j - 2]);
            else{
                //cout << i << " " << j << " " << f[i + m - 2] * g[i - 2] % mod << " " << f[i + m + p - 1] * g[i + m - 1] % mod << endl;
                add(dp[j], dp[i] * f[i + m - 2] % mod * g[i - 2] % mod * f[i + m + p - 1] % mod * g[i + m - 1] % mod);
            }
            p += 1;
        }
    }
    cout << dp[n + 1];
    return 0;
}