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

const int MOD = 1000 * 1000 * 1000 + 7;
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

const int N = 2e5 + 7;
int f[N], inv[N];

int C(int n, int k) {
    if (n < k)
        return 0;
    else
        return mod(f[n] * mod(inv[k] * inv[n - k]));
}   

int get1(int l, int r) {
    return C(l + r, l);
}   
int get(int l, int r) {
    if (min(l, r) == 0)
        return 0;
    return mod(get1(l, r) - get1(l - 1, r));
}

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    f[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = mod(f[i - 1] * i);
        inv[i] = fp(f[i], MOD - 2);
    }
    string s; cin >> s;
    int l = 0, r = 0;
    for (char c : s)
        r += c == ')';
    int ans = 0;
    for (char c : s) {
        if (c == '(') {
            ++l;
            ans = mod(ans + get(l, r));
        }
        else
            --r;
    }
    cout << ans << endl;     
}