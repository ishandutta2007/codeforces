#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n;
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for(; b; b >>= 1, res = res * res % mod) if(b & 1) ans = ans * res % mod;
    return ans;
}
int d;
int prod[255];
inline int C(int n, int m) {
    return 1ll * prod[n] * power(prod[m], mod - 2) % mod * power(prod[n - m], mod - 2) % mod;
}
int main() {
    cin >> n >> d;
    prod[0] = 1;
    for(int i = 1; i <= n; i++) prod[i] = 1ll * i * prod[i - 1] % mod;
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            int now = 1ll * power(d, i * j) * C(n, i) % mod * C(n, j) % mod * power(d - 1, n * n - i * j) % mod;
            if((i + j) & 1) ans = (ans - now + mod) % mod;
            else ans = (ans + now) % mod;
        }
    }
    return cout << ans << endl, 0;
}