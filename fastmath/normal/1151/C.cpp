#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
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
int get(int n) {
    n = mod(n);
    return mdiv(mod(n * (n + 1)), 2);
}   
int get(int l, int len) {
    return mod(get(l + len - 1) - get(l - 1));
}   
int get(bool c, int l, int len) {
    return mod(get(l, len) * 2 - len * c);
}   
int l[2];
int solve(int n) {
    bool c = 1;
    int p = 0;
    int ans = 0;
    l[0] = l[1] = 1;
    for (; (1ll << p) < n; ++p) {
        n -= 1ll << p;
        ans = mod(ans + get(c, l[c], 1ll << p));
        l[c] += 1ll << p;
        c ^= 1;
    }   
    return mod(ans + get(c, l[c], n));
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);                                        
    #endif
    int l, r;
    cin >> l >> r;
    cout << mod(solve(r) - solve(l - 1)) << '\n';
}