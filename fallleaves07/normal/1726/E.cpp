#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using poly = vector<int>;
const int M = 998244353;

int qpw(int a, int b) {
    a %= M;
    if (b < 0) {
        (b %= M - 1) += M - 1;
    }
    int c = 1;
    for (; b; b >>= 1, a = 1ll * a * a % M) {
        if (b & 1) {
            c = 1ll * c * a % M;
        }
    }
    return c;
}

int mod(int val) {
    return (val < 0) ? (val + M) : ((val >= M) ? (val - M) : val);
}

namespace Poly {
    const int G = 3;
    vector<int> id;
    int getgl(int len, int tag) {
        return qpw(G, tag * (M - 1) / len);
    }
    int init(int len) {
        int k = 1;
        for (; (1 << k) < len; ++k);
        id.resize(1 << k);
        for (int i = 0; i < (1 << k); i++) {
            id[i] = (id[i >> 1] >> 1) | ((i & 1) << (k - 1));
        }
        return 1 << k;
    }
    void ireverse(poly &a) {
        for (int i = 0; i < (int)a.size(); i++) {
            if (id[i] > i) {
                swap(a[i], a[id[i]]);
            }
            a[i] = mod(a[i]);
        }
    }
    void ntt(poly &a, int tag = 1) {
        int len = a.size();
        ireverse(a);
        for (int l = 1; l < len; l <<= 1) {
            int gl = getgl(l << 1, tag);
            for (int st = 0; st < len; st += (l << 1)) {
                for (int i = st, g = 1; i < st + l; i++, g = 1ll * g * gl % M) {
                    int tmp = 1ll * a[i + l] * g % M;
                    a[i + l] = mod(a[i] - tmp);
                    a[i] = mod(a[i] + tmp);
                }
            }
        }
        if (tag < 0) {
            int inv = qpw(len, -1);
            for (int i = 0; i < len; i++) {
                a[i] = mod(1ll * a[i] * inv % M);
            }
        }
    }
    poly operator*(poly a, poly b) {
        int slen = a.size() + b.size() - 1, len = init(slen);
        a.resize(len, 0), b.resize(len, 0);
        ntt(a), ntt(b);
        for (int i = 0; i < len; i++) {
            a[i] = 1ll * a[i] * b[i] % M;
        }
        ntt(a, -1);
        a.resize(slen);
        return a;
    }
};

vector<int> fct, ifc, dct, val, pw;
void init(int n) {
    fct.resize(n + 1), ifc.resize(n + 1), dct.resize(n + 1), pw.resize(n + 1);
    fct[0] = dct[0] = dct[1] = pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = mod(pw[i - 1] << 1);
        fct[i] = 1ll * fct[i - 1] * i % M;
        if (i > 1) {
            dct[i] = 1ll * dct[i - 2] * i % M;
        }
    }
    ifc[n] = qpw(fct[n], -1);
    for (int i = n - 1; i >= 0; i--) {
        ifc[i] = 1ll * ifc[i + 1] * (i + 1ll) % M;
    }
    {
        using namespace Poly;
        poly x(n + 1), y = ifc;
        x[0] = 1;
        for (int j = 2; j <= n; j += 2) {
            x[j] = 1ll * ifc[j] * dct[j - 1] % M;
        }
        poly z = x * y;
        val.resize(n + 1);
        for (int j = 0; j <= n; j++) {
            val[j] = 1ll * fct[j] * z[j] % M;
        }
    }
}
int C(int n, int m) {
    return 1ll * fct[n] * ifc[m] % M * ifc[n - m] % M;
}

void solve() {
    int n;
    cin >> n;
    int ans = 1ll * C(n, 0) * val[n] % M;
    for (int i = 4; i <= n; i += 4) {
        ans = (ans + 1ll * C(n - i + i / 2, i / 2) * val[n - i] % M * dct[i / 2 - 1] % M * pw[i / 4]) % M;
    }
    printf("%d\n", mod(ans));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    init(3e5 + 5);
    while (T--) {
        solve();
    }
    return 0;
}