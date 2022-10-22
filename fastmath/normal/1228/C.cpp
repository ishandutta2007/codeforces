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
const int MOD = 1000 * 1000 * 1000 + 7;
int fp(int c, int p) {
    int ans = 1;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = (ans * c) % MOD;
        c = (c * c) % MOD;
    }   
    return ans;
}   
int get(int p, int n) {
    int c = 1, sum = 0;
    while (c <= n / p) {
        c *= p;
        sum += n / c;
    }   
    return fp(p, sum);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int x, n; cin >> x >> n;
    int ans = 1;
    for (int d = 2; d * d <= x; ++d) {
        if (x % d == 0) {
            ans *= get(d, n);
            ans %= MOD;
            while (x % d == 0) x /= d;
        }   
    }   
    if (x > 1) {
        ans *= get(x, n);
        ans %= MOD;
    }   
    cout << ans << '\n';
}