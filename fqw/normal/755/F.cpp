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
// clang-format on
// }}}

bool solve(VI lens, int want) {
    const int N = 1000010;
    {
        int sum = accumulate(all(lens), 0);
        if(want * 2 > sum) want = sum - want;
    }
    VPI groups;
    {
        VI tmp = lens;
        lens.clear();
        sort(all(tmp));
        for(int i = 0, j; i < sz(tmp); i = j) {
            for(j = i; j < sz(tmp) && tmp[j] == tmp[i]; ++j)
                ;
            groups.pb(mp(tmp[i], j - i));
        }
    }
    static bool f[N + 1];
    static int valid[N + 1], last[N + 1];
    fillchar(valid, -1);
    fillchar(f, false);
    f[0] = true;
    int maxv = 0;
    for(const auto& p : groups) {
        int len = p.fi, cnt = p.se, span = len * cnt;
        maxv = min(want, maxv + span);
        rep(i, 0, maxv) {
            int id = i % len;
            if(f[i]) {
                valid[id] = len;
                last[id] = i;
            }
            if(!f[i]) {
                if(valid[id] == len && last[id] + span >= i) {
                    f[i] = true;
                }
            }
        }
    }
    return f[want];
}

int main() {
    // cout << solve(VI(250000, 4), 699999) << endl;
    // return 0;

    int n, k;
    scanf("%d%d", &n, &k);
    VI p(n);
    repn(i, n) scanf("%d", &p[i]), --p[i];
    int doubles = 0, singles = 0;
    VI lens;
    repn(i, n) if(p[i] >= 0) {
        int len = 0;
        for(int x = i, y; p[x] >= 0; x = y) {
            y = p[x], p[x] = -1;
            ++len;
        }
        doubles += len / 2;
        singles += len % 2;
        lens.pb(len);
    }
    int ans1 = solve(lens, k) ? k : k + 1;
    int ans2 = 0;
    if(k <= doubles) {
        ans2 = 2 * k;
    } else {
        ans2 = 2 * doubles + min(k - doubles, singles);
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}