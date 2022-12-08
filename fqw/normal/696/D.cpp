#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// {{{
// clang-format off
#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define irep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define popcount __builtin_popcount
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }
// clang-format on
// }}}

struct Mat {
    vector<VL> a;
    Mat(int n) : a(n, VL(n, -(1ll << 60))) {}
    Mat operator*(const Mat& b) const {
        Mat c(sz(a));
        repn(i, sz(a)) repn(j, sz(a)) repn(k, sz(a)) {
            setmax(c.a[i][j], a[i][k] + b.a[k][j]);
        }
        return c;
    }
    Mat pow(LL b) const {
        Mat t = *this, r(sz(a));
        repn(i, sz(a)) r.a[i][i] = 0;
        for(; b > 0; b >>= 1, t = t * t) {
            if(b & 1) r = r * t;
        }
        return r;
    }
};

Mat make(const VL& val, const VS& str) {
    vector<VI> tr(1, VI(26, -1));
    vector<LL> v(1, 0);
    repn(i, sz(val)) {
        int x = 0;
        for(char c : str[i]) {
            const int ch = int(c - 'a');
            if(tr[x][ch] < 0) {
                tr[x][ch] = sz(tr);
                tr.pb(VI(26, -1));
                v.pb(0);
            }
            x = tr[x][ch];
        }
        v[x] += val[i];
    }

    vector<int> suffix(sz(tr));
    queue<int> que;
    repn(ch, 26) {
        if(tr[0][ch] < 0) {
            tr[0][ch] = 0;
        } else {
            que.push(tr[0][ch]);
            suffix[tr[0][ch]] = 0;
        }
    }
    while(!que.empty()) {
        const int x = que.front();
        que.pop();
        v[x] += v[suffix[x]];
        repn(ch, 26) {
            if(tr[x][ch] < 0) {
                tr[x][ch] = tr[suffix[x]][ch];
            } else {
                que.push(tr[x][ch]);
                suffix[tr[x][ch]] = tr[suffix[x]][ch];
            }
        }
    }

    Mat m(sz(tr));
    repn(x, sz(tr)) repn(ch, 26) { m.a[x][tr[x][ch]] = v[tr[x][ch]]; }
    return m;
}

int main() {
    int n;
    LL len;
    cin >> n >> len;
    VL val(n);
    VS str(n);
    repn(i, n) cin >> val[i];
    repn(i, n) cin >> str[i];

    Mat m = make(val, str);
    m = m.pow(len);

    LL ans = -1;
    repn(i, sz(m.a)) setmax(ans, m.a[0][i]);
    cout << ans << endl;

    return 0;
}