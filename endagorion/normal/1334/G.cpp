#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

typedef complex<double> base;
const double PI = atan2(0, -1);

const int maxn = 1 << 18;
int ans[maxn];
int p[26];
string s, t;
 
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
 
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
 
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*PI/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1);
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, 26) cin >> p[i], --p[i];
    cin >> s >> t;
    int l = 1;
    while (l < t.size()) l *= 2;
    vi ans(t.size() - s.size() + 1);
    forn(i, 13) {
        vector<base> a(l), b(l);
        forn(j, t.size()) {
            int c = t[j] - 'a';
            if (c / 2 != i) continue;
            if (c & 1) a[j] += base(0, 1);
            else a[j] += base(1, 0);
        }
        forn(j, s.size()) {
            int c = s[j] - 'a';
            if (c == 2 * i || p[c] == 2 * i) b[(l - j) % l] += base(0, 1);
            if (c == 2 * i + 1 || p[c] == 2 * i + 1) b[(l - j) % l] += base(1, 0);
        }
        fft(a, false);
        fft(b, false);
        forn(i, l) a[i] *= b[i];
        fft(a, true);
        forn(i, ans.size()) ans[i] += int(a[i].imag() + 0.5);
    }
    forn(i, ans.size()) cout << (ans[i] == s.size() ? '1' : '0');
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}