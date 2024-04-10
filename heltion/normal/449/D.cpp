#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1 << 20;
constexpr LL mod = 1'000'000'007;
LL p[maxn];
int sum[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0, a; i < n; i += 1){
        cin >> a;
        sum[a] += 1;
    }
    for(int i = 0; i <= n; i += 1) p[i] = i ? (p[i - 1] * 2) % mod : 1;
    for(int i = 0; i < 20; i += 1)
        for(int j = 0; j < maxn; j += 1)
            if((j >> i) & 1)
                sum[j ^ (1 << i)] += sum[j];
    LL ans = 0;
    for(int i = 0; i < maxn; i += 1)
        if(__builtin_parity(i)) ans -= p[sum[i]];
        else ans += p[sum[i]];
    cout << (ans % mod + mod) % mod;
    return 0;
}