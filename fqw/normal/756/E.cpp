#include <algorithm>
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

const LL MOD = LL(1e9) + 7;
const LL B = LL(1e8);

VL read_bigint() {
    static char s[10010];
    scanf("%s", s);
    int len = (int)strlen(s);

    VL ans;
    LL cur = 0, p = 1;
    irepn(i, len) {
        cur += LL(s[i] - '0') * p;
        p *= 10;
        if(p == B) {
            ans.pb(cur);
            cur = 0, p = 1;
        }
    }
    if(cur > 0) ans.pb(cur);
    return ans;
}

LL div(VL& a, LL b) {
    if(b == 1) {
        return 0;
    }
    LL r = 0;
    irepn(i, sz(a)) {
        a[i] += r * B;
        r = a[i] % b, a[i] /= b;
    }
    while(!a.empty() && a.back() == 0) {
        a.pop_back();
    }
    return r;
}

bool parse_to_int(VL a, LL* ans) {
    if(sz(a) >= 2) return false;
    if(a.empty()) {
        *ans = 0;
    } else {
        *ans = a[0];
    }
    if(*ans > 300010) return false;
    return true;
}

bool check(VL ratio, VL a, VL b) {
    const int n = sz(a);
    LL spare = 0;
    repn(i, n) {
        LL d = max(a[i] - b[i], 0ll);
        if(spare < d) return false;
        spare -= d, a[i] -= d;
        if(i + 1 < n) {
            spare = (spare + b[i] - a[i]) / ratio[i];
        }
    }
    return true;
}

LL solve(VL ratio, VL a, VL b) {
    const int n = sz(a);
    if(b[0] - a[0] < 0) return 0;
    if(n == 1) return 1;
    if(!check(ratio, a, b)) return 0;

    static LL s[500010], t[500010];
    LL len = 0;
    s[0] = t[0] = 0;
    for(LL cur = 0; a[0] + ratio[0] * cur <= b[0]; ++cur) {
        s[cur + 1] = s[cur] + 1;
        setmax(len, cur + 1);
    }
    replr(i, 1, n - 1) {
        LL new_len = (len + b[i] - a[i]) / ratio[i] + 1;
        for(LL cur = 0; cur < new_len; ++cur) {
            LL l = max(0ll, a[i] + ratio[i] * cur - b[i]);
            LL r = min(len, a[i] + ratio[i] * cur + 1);
            t[cur + 1] = t[cur] + s[r] - s[l];
            if(t[cur + 1] < 0) t[cur + 1] += MOD;
            if(t[cur + 1] >= MOD) t[cur + 1] -= MOD;
        }
        len = new_len;
        memmove(s, t, sizeof(LL) * (len + 1));
    }
    LL ans = 0;
    repn(cur, len) {
        if(a[n - 1] - cur >= 0 && a[n - 1] - cur <= b[n - 1]) {
            (ans += s[cur + 1] - s[cur] + MOD) %= MOD;
        }
    }
    return ans;
}

void test() {
    VL ratio(300000 - 1, 1);
    for(int i = 10; i < sz(ratio); i += 20) ratio[i] = 2;
    VL a(300000, 0);
    VL b(300000, 0);
    b[0] = 100000;
    for(int i = 1; i < sz(a); i += 5) b[i] = 3, a[i] = 2;
    cout << solve(ratio, a, b) << endl;
}

int main() {
    // test(); return 0;
    int n;
    scanf("%d", &n);
    VL ratio(n - 1);
    repn(i, n - 1) scanf("%lld", &ratio[i]);
    VL b(n);
    repn(i, n) scanf("%lld", &b[i]);
    VL m = read_bigint();

    VL a(n);
    repn(i, n - 1) { a[i] = div(m, ratio[i]); }
    if(!parse_to_int(m, &a[n - 1])) {
        printf("0\n");
        return 0;
    }
    printf("%lld\n", solve(ratio, a, b));

    return 0;
}