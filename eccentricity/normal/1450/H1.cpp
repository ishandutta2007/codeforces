#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998'244'353;
constexpr int maxn = 200000 + 1;
char s[maxn];
LL f[maxn], g[maxn];
LL cnt[3];
LL power(LL a, LL r){
    LL res = 1;
    for(; r; r >>= 1, a = a * a % mod)
        if(r & 1) res = res * a % mod;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m >> (s + 1);
    for(int i = 0; i <= n; i += 1) f[i] = i ? f[i - 1] * i % mod : 1;
    for(int i = 1; i <= n; i += 1) g[i] = i == 1 ? 1 : (mod - mod / i) * g[mod % i] % mod;
    for(int i = 0; i <= n; i += 1) g[i] = i ? g[i - 1] * g[i] % mod : 1;
    for(int i = 1; i <= n; i += 1){
        if(s[i] == '?') cnt[2] += 1;
        else cnt[(s[i] == 'b') ^ (i & 1)] += 1;
    }
    LL p = 0, q = 0;
    for(int i = 0; i <= cnt[2]; i += 1){
        int A = cnt[0] + i, B = cnt[1] + cnt[2] - i;
        if(abs(A - B) % 4 != 0) continue;
        LL C = f[cnt[2]] * g[i] % mod * g[cnt[2] - i] % mod;
        q = (q + C) % mod;
        p = (p + abs(A - B) / 4 * C) % mod;
    }
    cout << p * power(q, mod - 2) % mod;
    return 0;
}