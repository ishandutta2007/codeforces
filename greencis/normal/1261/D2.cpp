#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k, a[200200];

const int MOD = 998244353;
inline void add(int& x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

inline int binpow(int x, int deg) {
    int ans = 1;
    while (deg > 0) {
        if (deg & 1)
            ans = (ll)ans * x % MOD;
        deg >>= 1;
        x = (ll)x * x % MOD;
    }
    return ans;
}

inline int inv(int x) { return binpow(x, MOD - 2); }

const int MAXDEG = 20;
const int MAXN = 1 << MAXDEG;

int w[MAXN], bitrev[MAXN];

void init_fft() {
    const int ROOT = binpow(31, 1 << (23 - MAXDEG));
    w[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        w[i] = (ll)w[i - 1] * ROOT % MOD;

    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXDEG; ++j)
            if ((i >> j) & 1)
                bitrev[i] ^= (1 << (MAXDEG - 1 - j));
}

void fft(vector<int>& v, int lvl) {
    for (int i = 0; (i << lvl) < MAXN; ++i)
        if (i < bitrev[i << lvl])
            swap(v[i], v[bitrev[i << lvl]]);
    for (int step = 2, half = 1, shift = MAXDEG - 1; (step << lvl) <= MAXN; step <<= 1, half <<= 1, --shift) {
        for (int i = 0; (i << lvl) < MAXN; i += step) {
            for (int j = 0; j < half; ++j) {
                const int b = (ll)v[i + j + half] * w[j << shift] % MOD;
                const int a = v[i + j] + MOD - b;
                v[i + j + half] = a >= MOD ? a - MOD : a;
                add(v[i + j], b);
            }
        }
    }
}

inline void fft(vector<int>& v) {
    int lvl = 0;
    while ((1 << lvl) < (int)v.size()) ++lvl;
    fft(v, MAXDEG - lvl);
}

inline void ifft(vector<int>& v) {
    fft(v);
    reverse(v.begin() + 1, v.end());
    const int divisor = inv((int)v.size());
    for (int& x : v)
        x = (ll)x * divisor % MOD;
}

struct polynom {
    size_t deg;
    vector<int> v;

    polynom(int k = 0) : deg(2) {
        v = {1, k - 2, 1};
    }

    void combine(polynom& rhs) {
        deg += rhs.deg;
        const size_t max_sz = max(deg + 1, max(v.size(), rhs.v.size()));
        size_t new_sz = 1;
        while (new_sz < max_sz) new_sz <<= 1;
        v.resize(new_sz);
        fft(v);
        rhs.v.resize(new_sz);
        fft(rhs.v);
        for (size_t i = 0; i < new_sz; ++i)
            v[i] = (ll)v[i] * rhs.v[i] % MOD;
        ifft(v);
        rhs.v.clear();
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (*min_element(a + 1, a + n + 1) == *max_element(a + 1, a + n + 1)) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        if (a[i] != a[1]) {
            rotate(a + 1, a + i, a + n + 1);
            break;
        }
    }
    int new_n = int(unique(a + 1, a + n + 1) - (a + 1));
    int mul = 1;
    for (int i = n - new_n; i--; )
        mul = mul * ll(k) % MOD;
    n = new_n;

    init_fft();
    polynom x(k), ans(0);
    ans.deg = 0;
    ans.v = {1};
    int deg = n;
    while (deg > 0) {
        if (deg & 1) {
            auto q = x;
            ans.combine(q);
        }
        deg >>= 1;
        auto q = x;
        x.combine(q);
    }
    int anss = 0;
    for (int i = ans.deg / 2 + 1; i <= ans.deg; ++i)
        add(anss, ans.v[i]);
    anss = anss * (ll)mul % MOD;
    cout << anss << endl;
}