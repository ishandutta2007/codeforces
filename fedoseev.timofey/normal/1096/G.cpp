#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 998244353;

inline int mul(int a, int b) {
    return ((ll)a * b) % mod;
}

inline int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
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

namespace fft {
    const int LOG = 20;
    const int N = 1 << LOG;
    int G = 3;
    int W = -1;
    int rev[N];
    int w[N];
    int lg = -1;
    int nn = -1;

    void init(int n) {
        int kek = 0;
        while ((1 << kek) < n) ++kek;
        lg = kek;
        nn = n;
        W = power(G, (mod - 1) / n);
        int last = 0;
        for (int i = 1; i < n; ++i) {
            if (i == (2 << last)) {
                last += 1;
            }
            rev[i] = rev[i ^ (1 << last)] | (1 << (kek - 1 - last));
        }
        w[0] = 1;
        for (int i = 1; i < n; ++i) {
            w[i] = mul(w[i - 1], W);
        }
    }

    void fft(vector <int> &a) {
        for (int i = 0; i < nn; ++i) {
            if (i < rev[i]) {
                swap(a[i], a[rev[i]]);
            }
        }
        for (int lvl = 0; (1 << lvl) < nn; ++lvl) {
            for (int st = 0; st < nn; st += (2 << lvl)) {
                for (int i = 0; i < (1 << lvl); ++i) {
                    int fir = a[st + i];
                    int sec = mul(a[st + i + (1 << lvl)], w[i << (lg - (lvl + 1))]);
                    a[st + i] = add(fir, sec);
                    a[st + i + (1 << lvl)] = sub(fir, sec);
                }
            }
        }
    }

    void inv_fft(vector <int> &a) {
        fft(a);
        int cn = inv(nn);
        for (auto &x : a) {
            x = mul(x, cn);
        }
        reverse(a.begin() + 1, a.end());
    }

    vector <int> multiply(vector <int> a, vector <int> b) {
        int mx = max(a.size(), b.size());
        int l = 0;
        while ((1 << l) < mx) ++l;
        mx = min(N, (2 << l));
        init(mx);
        a.resize(mx);
        b.resize(mx);
        fft(a);
        fft(b);
        vector <int> c(mx);
        for (int i = 0; i < mx; ++i) {
            c[i] = mul(a[i], b[i]);
        }
        inv_fft(c);
        return c;
    }

};

vector <int> power_poly(vector <int> a, ll b) {
    vector <int> res = {1};
    while (b > 0) {
        if (b & 1) {
            res = fft::multiply(res, a);
        }
        a = fft::multiply(a, a);
        b >>= 1;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> kek(10);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        kek[x] = 1;
    }
    kek = power_poly(kek, n / 2);
    int ans = 0;
    for (int i = 0; i < (int)kek.size(); ++i) {
        ans = add(ans, mul(kek[i], kek[i]));
    }
    cout << ans << '\n';
}