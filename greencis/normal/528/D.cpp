#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct base {
    double re, im;

    base(double _re = 0, double _im = 0) : re(_re), im(_im) { }
    base operator+(const base& rhs) { return base(re + rhs.re, im + rhs.im); }
    base operator-(const base& rhs) { return base(re - rhs.re, im - rhs.im); }
    base operator*(const base& rhs) { return base(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re); }
    void operator/=(int d) { re /= d; im /= d; }
};

const double PI = acos(-1.0);
const int MX = 1 << 19;
int rev[MX];
base w[MX >> 1];

void init_fft(int n) {
    int log_n = 0;
    while ((1 << log_n) < n)
        ++log_n;

    for (int i = 0; i < n; ++i) {
        rev[i] = 0;
        for (int j = log_n; j--; )
            rev[i] |= ((i >> j) & 1) << (log_n - 1 - j);
        if (rev[i] < i)
            rev[i] = i;
    }
}

void fft(base *a, int n, bool invert) {
    for (int i = 0; i < n; ++i)
        swap(a[i], a[rev[i]]);

    for (int len = 1; len < n; len <<= 1) {
        double angle = PI / len;
        if (invert)
            angle *= -1.0;
        base wlen(cos(angle), sin(angle));
        w[0] = base(1, 0);
        for (int i = 1; i < len; ++i)
            w[i] = w[i - 1] * wlen;

        for (int i = 0; i < n; i += (len << 1)) {
            for (int j = 0; j < len; ++j) {
                base v = a[i + j + len] * w[j];
                a[i + j + len] = a[i + j] - v;
                a[i + j] = a[i + j] + v;
            }
        }
    }

    if (invert)
        for (int i = 0; i < n; ++i)
            a[i] /= n;
}

const string ATGC = "ATGC";
int good[200105];
int n, m, k;
string s, t;
base fa[MX], fb[MX];

int main()
{
    cin >> n >> m >> k >> s >> t;
    int sz = 1;
    while (sz < max(n, m))
        sz <<= 1;
    sz <<= 1;
    for (int z = 0; z < 4; ++z) {
        for (int i = 0; i < sz; ++i) {
            fa[i] = 0;
            fb[i] = 0;
        }
        vector<pii> v;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == ATGC[z]) {
                v.push_back(make_pair(max(i - k, 0), -1));
                v.push_back(make_pair(min(i + k, n - 1), 1));
            }
        }
        sort(v.begin(), v.end());
        int balance = 0;
        int last = 0;
        for (size_t i = 0; i < v.size(); ++i) {
            balance -= v[i].second;
            if (balance == 1 && v[i].second == -1)
                last = v[i].first;
            else if (balance == 0) {
                for (; last <= v[i].first; ++last)
                    fa[last] = 1;
            }
        }
        int cnt_1 = 0;
        for (size_t i = 0; t[i]; ++i)
            fb[m - 1 - i] = (t[i] == ATGC[z]), cnt_1 += (t[i] == ATGC[z]);
        init_fft(sz);
        fft(fa, sz, false);
        fft(fb, sz, false);
        for (int i = 0; i < sz; ++i)
            fa[i] = fa[i] * fb[i];
        fft(fa, sz, true);
        for (int i = 0; i < n; ++i) {
            int cur = (int)round(fa[i + m - 1].re);
            if (cur == cnt_1)
                ++good[i];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += good[i] == 4;
    cout << ans << endl;

    return 0;
}