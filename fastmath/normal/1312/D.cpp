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

const int N = 5e5 + 7;
int f[N];
int C(int n, int k) {
    if (n < k)
        return 0;
    else
        return dv(f[n], mod(f[k] * f[n - k]));
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

    int n, m;
    cin >> n >> m;

    if (n == 2) {
        cout << 0 << endl;
        exit(0);
    }   

    int ans = 0;
    for (int x = 1; x <= m; ++x) {
        ans = mod(ans + mod(C(x - 1, n - 2) * (n - 2)) * fp(2, n - 3));
    }
    cout << ans << endl;
}