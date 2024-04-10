#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int MOD = 998244353;

int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }

const int N = 1e6 + 7;
int f[N], inv[N];

int C(int n, int k) {
    if (n < k)
        return 0;

    //cout << "C " << n << ' ' << k << " : " << mod(f[n] * mod(inv[k] * inv[n - k])) << endl;

    return mod(f[n] * mod(inv[k] * inv[n - k]));
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = mod(f[i - 1] * i);
    inv[N - 1] = fp(f[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i)
        inv[i] = mod(inv[i + 1] * (i + 1));

    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t = n/i;
        ans = (ans + C(t-1, k-1)) % MOD;
    }   

    cout << ans << endl;
}