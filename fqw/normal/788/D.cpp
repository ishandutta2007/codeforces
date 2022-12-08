// 11:00
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
#include <random>
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

const int INF = int(1e8);

int randint() {
    static std::default_random_engine gen;
    static std::uniform_int_distribution<int> distri(-INF, INF);
    return distri(gen);
}

int query(PII p) {
    printf("0 %d %d\n", p.fi, p.se);
    fflush(stdout);
    int d;
    scanf("%d", &d);
    return d;
}

struct Dimension {
    Dimension(bool is_x) : is_x(is_x) { insert_range(mp(-INF, INF)); }

    int pick() {
        if(!finished()) {
            auto r = ranges_by_size.rbegin()->se;
            return (r.fi + r.se) / 2;
        } else {
            if(final_pick >= -INF) return final_pick;
            int last = -INF, r = -INF, rv = -1;
            for(int x : found) {
                if(setmax(rv, x - last)) {
                    r = (last + x) / 2;
                }
                last = x;
            }
            if(setmax(rv, INF - last)) {
                r = (INF + last) / 2;
            }
            return final_pick = r;
        }
    }

    void verify(int x) {
        if(x < -INF || x > INF) return;
        if(found.count(x)) return;
        constexpr int kNum = 5;
        repn(i, kNum) {
            int y = randint();
            int r = query(is_x ? mp(x, y) : mp(y, x));
            if(r != 0) return;
        }
        found.insert(x);
    }

    void erase(PII e) {
        while(1) {
            auto it = ranges.upper_bound(mp(e.se, INF + 1));
            if(it == ranges.begin()) break;
            PII cur = *(--it);
            if(cur.se < e.fi) break;
            erase_range(cur);
            if(cur.fi < e.fi) insert_range(mp(cur.fi, e.fi - 1));
            if(e.se < cur.se) insert_range(mp(e.se + 1, cur.se));
        }
    }

    bool finished() const { return ranges.empty(); }

    VI ans() const { return VI(all(found)); }

private:
    void insert_range(PII range) {
        ranges.insert(range);
        ranges_by_size.insert(mp(range.se - range.fi + 1, range));
    }

    void erase_range(PII range) {
        ranges.erase(range);
        ranges_by_size.erase(mp(range.se - range.fi + 1, range));
    }

    const bool is_x;
    set<int> found;
    set<PII> ranges;
    set<pair<int, PII>> ranges_by_size;
    int final_pick = -INF - 1;
};

int main() {
    Dimension dx(true), dy(false);
    while(!dx.finished() || !dy.finished()) {
        int x = dx.pick(), y = dy.pick();
        int r = query(mp(x, y));
        dx.verify(x - r), dx.verify(x + r);
        dy.verify(y - r), dy.verify(y + r);
        dx.erase(mp(x - r, x + r));
        dy.erase(mp(y - r, y + r));
    }
    VI rx = dx.ans(), ry = dy.ans();
    printf("1 %d %d\n", sz(rx), sz(ry));
    for(int x : rx) printf("%d ", x);
    printf("\n");
    for(int y : ry) printf("%d ", y);
    printf("\n");
    return 0;
}