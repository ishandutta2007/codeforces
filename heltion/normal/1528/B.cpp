#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 1000000 + 1;
LL dp[maxn], sum[maxn], d[maxn];
void add(LL& x, LL y){
    x += y;
    if(x >= mod) x -= mod;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1)
        for(int j = i; j <= n; j += i) d[j] += 1;
    for(int i = 1; i <= n; i += 1){
        dp[i] = sum[i - 1];
        add(dp[i], d[i]);
        sum[i] = sum[i - 1];
        add(sum[i], dp[i]);
        //cout << i << " " << dp[i] << endl;
    }
    cout << dp[n] % mod;
    return 0;
}