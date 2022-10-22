#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
int f[N];
int fp(int a, int p) {
    int ans = 1, cur = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * cur);
        cur = mod(cur * cur);
    }   
    return ans;
}   
int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   
int C(int n, int k) {
    //cout << "C " << n << ' ' << k << ' ' << mdiv(f[n], mod(f[k] * f[n - k])) << '\n';
    return mdiv(f[n], mod(f[k] * f[n - k]));
}   
int get(int n, int k) {
    //cout << "GET " << n << ' ' << k << ' ' << C(n + k - 1, k - 1) << '\n';
    return C(n + k - 1, k - 1);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    f[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = mod(f[i - 1] * i);
    }   

    int n;
    cin >> n;
    map <int, int> c;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int d = 2; d * d <= x; ++d) {
            while (x % d == 0) {
                ++c[d];
                x /= d;
            }   
        }   
        if (x != 1) ++c[x];
    }   
    int ans = 1;
    for (auto e : c) {
        //cout << e.first << ' ' << e.second << '\n';

        int p = e.second;
        ans = mod(ans * get(p, n));
    }   
    cout << ans << '\n';
}