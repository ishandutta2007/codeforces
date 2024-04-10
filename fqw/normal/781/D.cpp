#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
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
// clang-format on
// }}}

struct Mat {
    vector<bitset<500>> a, ra;

    Mat(int n = 0) : a(n), ra(n) {}

    void set(int i, int j) { a[i][j] = ra[j][i] = 1; }

    int size() const { return sz(a); }

    bool any() const {
        return any_of(all(a), [](const bitset<500>& b) { return b.any(); });
    }

    friend Mat operator*(const Mat& x, const Mat& y) {
        Mat z(x.size());
        repn(i, z.size()) repn(j, z.size()) {
            if((x.a[i] & y.ra[j]).any()) {
                z.set(i, j);
            }
        }
        return z;
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    Mat a[63], b[63];
    a[0] = Mat(n), b[0] = Mat(n);
    repn(i, m) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        --u, --v;
        if(t == 0) {
            a[0].set(u, v);
        } else {
            b[0].set(u, v);
        }
    }
    replr(i, 1, 63) {
        a[i] = a[i - 1] * b[i - 1];
        b[i] = b[i - 1] * a[i - 1];
    }

    Mat cur(n);
    repn(i, n) cur.set(i, i);
    LL ans = 0;
    bool use_a = true;
    irep(i, 62, 0) {
        Mat tmp = use_a ? cur * a[i] : cur * b[i];
        if(tmp.any()) {
            cur = tmp;
            ans += 1ll << i;
            use_a = !use_a;
        }
    }
    if(ans > LL(1e18)) ans = -1;
    printf("%lld\n", ans);

    return 0;
}