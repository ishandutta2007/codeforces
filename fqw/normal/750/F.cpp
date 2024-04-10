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

map<int, VI> cache;

VI ask(int x) {
    if(cache.count(x)) {
        return cache[x];
    }
    printf("? %d\n", x);
    fflush(stdout);
    int k;
    scanf("%d", &k);
    VI r(k);
    repn(i, k) scanf("%d", &r[i]);
    cache[x] = r;
    return r;
}

VI ask_next(int x, int fa) {
    VI r;
    for(int y : ask(x)) {
        if(y != fa)
            r.pb(y);
    }
    return r;
}

int ask_up(int x, int son1, int son2) {
    for(int y : ask(x)) {
        if(y != son1 && y != son2)
            return y;
    }
    return -1;
}

void answer(int x) {
    printf("! %d\n", x);
    fflush(stdout);
}

VI go(int x, int fa) {
    VI r;
    while(1) {
        r.pb(x);
        auto nxt = ask_next(x, fa);
        if(nxt.empty())
            break;
        fa = x, x = nxt[0];
    }
    return r;
}

VI getchain() {
    VI init = ask(1), r;
    if(sz(init) == 1) {
        r = go(init[0], 1);
        r.insert(r.begin(), 1);
    } else {
        auto p1 = go(init[0], 1);
        auto p2 = go(init[1], 1);
        r = p1;
        reverse(all(r));
        r.pb(1);
        r.insert(r.end(), all(p2));
    }
    return r;
}

void solve() {
    cache.clear();
    int h;
    scanf("%d", &h);
#define check(x)          \
    if(sz(ask(x)) == 2) { \
        answer(x);        \
        return;           \
    }

    VI chain = getchain();
    assert(sz(chain) % 2 == 1);
    while(1) {
        int d = h - sz(chain) / 2 - 1;
        int center = chain[sz(chain) / 2];
        int up =
            ask_up(center, chain[sz(chain) / 2 - 1], chain[sz(chain) / 2 + 1]);
        //cout << d << " " << center << " " << up << " " << chain << endl;
        if(d == 0) {
            answer(center);
            return;
        }
        if(d == 1) {
            answer(up);
            return;
        }
        if(d == 2) {
            VI t = ask_next(up, center);
            check(t[0]);
            answer(t[1]);
            return;
        }
        if(d == 3) {
            VI xs = ask_next(up, center), ys;
            for(int x : xs) {
                VI r = ask_next(x, up);
                ys.insert(ys.end(), all(r));
            }
            repn(i, sz(ys) - 1) check(ys[i]);
            answer(ys.back());
            return;
        }
        auto path = go(up, center);
        chain = VI(h - d, center);
        chain.insert(chain.end(), all(path));
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}