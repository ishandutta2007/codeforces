#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> base;

const double PI = acos(-1.0);
base wlen_pow[524300];

void fft(vector<base>& a, bool invert) {
    int n = (int)a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 1; len < n; len <<= 1) {
        double angle = PI / len;
        if (invert)
            angle = -angle;
        base wlen(cos(angle), sin(angle));
        wlen_pow[0] = base(1);
        for (int i = 1; i < (n >> 1); ++i)
            wlen_pow[i] = wlen_pow[i - 1] * wlen;
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; ++j) {
                base u = a[i + j];
                base v = a[i + j + len] * wlen_pow[j];
                a[i + j] = u + v;
                a[i + j + len] = u - v;
            }
        }
    }

    if (invert)
        for (int i = 0; i < n; ++i)
            a[i] /= n;
}

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res) {
    size_t max_size = max(a.size(), b.size());
    size_t n = 1;
    while (n < max_size)
        n <<= 1;
    n <<= 1;

    vector<base> fa(n), fb(n);
    for (size_t i = a.size(); i--; )
        fa[i] = a[i];
    for (size_t i = b.size(); i--; )
        fb[i] = b[i];
    fft(fa, false);
    fft(fb, false);
    for (size_t i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);

    res.resize(n);
    for (size_t i = 0; i < n; ++i)
        res[i] = (int)round(fa[i].real());
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> va(n + 1), vb(n + 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'V')
                va[i] = 1;
            else if (s[i] == 'K')
                vb[n - i] = 1;
        }
        vector<int> periods(n + 1), ans;
        multiply(va, vb, va);
        for (int i = 1; i < 2 * n; ++i)
            if (va[i])
                periods[abs(n - i)] = 1;
        for (int i = 1; i <= n; ++i) {
            bool good = true;
            for (int j = i; j <= n; j += i) {
                if (periods[j]) {
                    good = false;
                    break;
                }
            }
            if (good)
                ans.push_back(i);
        }

        cout << ans.size() << "\n";
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}