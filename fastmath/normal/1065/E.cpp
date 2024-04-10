#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int fp(int a, int b) {
    if (b == 0) return 1;
    int t = fp(a, b >> 1);
    if (b & 1) return mod(mod(t * t) * a);
    else return mod(t * t);
}

int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}

const int MAXN = 2e5 + 7;
int b[MAXN];

int get(int len, int a) {
    int t = fp(a, len);
    return mod(t * (t + 1) / 2);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a;
    cin >> n >> m >> a;
    for (int i = 0; i < m; ++i) cin >> b[i];

    int ans = 1;
    int pr = 0;
    for (int i = 0; i < m; ++i) {
        int len = b[i] - pr;
        ans = mod(ans * get(len, a));
        pr = b[i];
    }

    int ost = (n / 2 - b[m - 1]) * 2 + (n & 1);
    ans = mod(ans * fp(a, ost));

    cout << ans << '\n';
    return 0;
}