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

void solve(VI a) {
    const int n = sz(a);
    VI s(n + 1);
    repn(i, n) s[i + 1] = s[i] + a[i];

    unordered_map<unsigned, int> memo;
    const function<int(int, int, int, int)> f = [&](int i, int j, int move,
                                                    int who) {
        if(move > j - i) return 0;
        if(move == j - i) return s[j] - s[i];
        unsigned code = (unsigned(i) << 20) + (unsigned(j) << 8) +
                        (unsigned(move) << 1) + who;
        {
            const auto it = memo.find(code);
            if(it != memo.end()) return it->se;
        }
        int& ans = memo[code];
        if(who == 0) {
            ans = max(
                s[i + move] - s[i] - f(i + move, j, move, who ^ 1),
                s[i + move + 1] - s[i] - f(i + move + 1, j, move + 1, who ^ 1));
        } else {
            ans = max(
                s[j] - s[j - move] - f(i, j - move, move, who ^ 1),
                s[j] - s[j - move - 1] - f(i, j - move - 1, move + 1, who ^ 1));
        }
        return ans;
    };

    memo.rehash(6.2e7);
    int ans = f(0, n, 1, 0);
    printf("%d\n", ans);
}

void test() {
    VI a;
    srand(12345);
    repn(i, 4000) a.pb(rand());
    solve(a);
}

int main() {
    // test(); return 0;
    int n;
    scanf("%d", &n);
    VI a(n);
    repn(i, n) scanf("%d", &a[i]);
    solve(a);
    return 0;
}