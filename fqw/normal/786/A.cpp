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

VI read_vec() {
    int n;
    scanf("%d", &n);
    VI a(n);
    for(int& x : a) scanf("%d", &x);
    return a;
}

int f[2][7070], cnt[2][7070];

int main() {
    int n;
    scanf("%d", &n);
    VI a[2];
    a[0] = read_vec();
    a[1] = read_vec();

    fillchar(f, 0);
    fillchar(cnt, 0);
    queue<PII> que;
    const auto push = [&](int i, int p, int c) {
        f[i][p] = c;
        que.push(mp(i, p));
    };
    push(0, 1, -1);
    push(1, 1, -1);
    while(!que.empty()) {
        const int i = que.front().fi, oi = i ^ 1;
        const int p = que.front().se;
        que.pop();
        if(f[i][p] < 0) {
            for(int step : a[oi]) {
                int q = p - step;
                if(q < 1) q += n;
                if(f[oi][q] == 0) push(oi, q, 1);
            }
        } else {
            for(int step : a[oi]) {
                int q = p - step;
                if(q < 1) q += n;
                if((++cnt[oi][q]) == sz(a[oi])) {
                    if(f[oi][q] == 0) push(oi, q, -1);
                }
            }
        }
    }

    repn(i, 2) {
        rep(p, 2, n) {
            if(f[i][p] == 0) {
                printf("Loop ");
            } else if(f[i][p] < 0) {
                printf("Lose ");
            } else {
                printf("Win ");
            }
        }
        printf("\n");
    }

    return 0;
}