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

const int MOD = 998244353, N = 1e5 + 7;

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

int f[N], inv[N];
int pw(int n, int p) {
    int ans = 0;
    while (n % p == 0) {
        n /= p;
        ++ans;
    }   
    return ans;
}   

vector <int> p;
int solve(int a, int b) {
    int sum = 0, ans = 1;
    for (int e : p) {
        int dif = abs(pw(a, e) - pw(b, e));
        sum += dif;
        ans = mod(ans * inv[dif]);
    }   
    ans = mod(ans * f[sum]);
    return ans;
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
        f[i] = (f[i - 1] * i) % MOD;
    for (int i = 0; i < N; ++i)
        inv[i] = fp(f[i], MOD - 2);

    int D;
    cin >> D;

    for (int i = 2; i * i <= D; ++i) {
        if (D % i == 0) {
            p.app(i);
            while (D % i == 0)
                D /= i;
        }   
    }   
    if (D > 1)
        p.app(D);                

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int to = __gcd(a, b);
        cout << mod(solve(a, to) * solve(b, to)) << endl;
    }   
}