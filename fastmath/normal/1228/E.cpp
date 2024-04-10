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
const int N = 301, MOD = 1000 * 1000 * 1000 + 7;
int fp(int c, int p) {
    int ans = 1;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = (ans * c) % MOD;
        c = (c * c) % MOD;
    }   
    return ans;
} 
int n, k, C[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < N; ++i) C[i][0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }   
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            int t = i * n + j * n - i * j;
            int d = (fp(k, n * n - t) * fp(k - 1, t)) % MOD;
            d = (d * C[n][i]) % MOD;
            d = (d * C[n][j]) % MOD;
            if ((i + j) & 1) ans -= d;
            else ans += d;
            ans = (ans % MOD + MOD) % MOD;
        }   
    }   
    cout << ans << '\n';
}