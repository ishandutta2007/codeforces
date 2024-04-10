#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 320000;
constexpr LL mod = 998244353;
LL f[maxn], g[maxn];
int l[maxn], r[maxn];
int d[maxn << 1], sum1[maxn << 1], sum2[maxn << 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, m = 0;
    cin >> n >> k;
    for(int i = 0; i <= n; i += 1) f[i] = i ? f[i - 1] * i % mod : 1;
    for(int i = 1; i <= n; i += 1) g[i] = i == 1 ? 1 : (mod - mod / i) * g[mod % i] % mod;
    for(int i = 0; i <= n; i += 1) g[i] = i ? g[i - 1] * g[i] % mod : 1;
    for(int i = 1; i <= n; i += 1){
        cin >> l[i] >> r[i];
        d[m ++] = l[i];
        d[m ++] = r[i] + 1;
    }
    sort(d, d + m);
    m = unique(d, d + m) - d;
    for(int i = 1; i <= n; i += 1){
        int L = lower_bound(d, d + m, l[i]) - d;
        int R = lower_bound(d, d + m, r[i] + 1) - d;
        sum1[L] += 1;
        sum1[R] -= 1;
        sum2[L + 1] += 1;
        sum2[R] -= 1;
    }
    LL ans = 0;
    for(int i = 1; i < m; i += 1){
        sum1[i] += sum1[i - 1];
        sum2[i] += sum2[i - 1];
    }
    for(int i = 0; i + 1 < m; i += 1){
        if(sum1[i] >= k) ans += f[sum1[i]] * g[k] % mod * g[sum1[i] - k] % mod;
        if(sum2[i] >= k) ans -= f[sum2[i]] * g[k] % mod * g[sum2[i] - k] % mod;
    }
    cout << (ans % mod + mod) % mod;
    return 0;
}