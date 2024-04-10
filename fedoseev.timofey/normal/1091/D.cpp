#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 998244353;

inline int mul(int a, int b) {
    return ((ll)a * b) % mod;
}

inline void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

inline int sub(int a, int b) {
    a -= b;
    if (a < 0) a += mod;
    return a;
}

inline int power(int a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(a, res);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a) {
    return power(a, mod - 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = mul(i, fact[i - 1]);
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        add(ans, mul(mul(fact[n], inv(fact[n - i])), sub(fact[n - i], 1)));
    }
    add(ans, 1);
    cout << ans << '\n';
}