#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2e5 + 7, MOD = 998244353;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int n, k, h[N];
int f[N];
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   
int C(int n, int k) {
    if (n < k) return 0;
    else return dv(f[n], mod(f[k] * f[n - k]));
}   
int get0(int n) {
    if (n & 1) return 0;
    else return C(n, n >> 1);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mod(f[i - 1] * i);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> h[i];
    int cnt = 0, neu = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        if (h[i] != h[j]) ++cnt;
        else ++neu;
    }   
    int ans = 0;        
    for (int i = 0; i <= cnt; ++i) {
        int t = mod(fp(2, i) - get0(i));
        ans = mod(ans + mod(C(cnt, i) * fp(k - 2, cnt - i)) * dv(t, 2));
    }   
    for (int i = 0; i < neu; ++i) ans = mod(ans * k);
    cout << ans << '\n';
}