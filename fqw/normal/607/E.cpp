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

typedef long double LD;
typedef vector<LD> VLD;
typedef pair<LD, LD> PLD;
typedef vector<pair<LD, LD>> VPLD;
const LD PI = acosl(-1);

struct Point {
    LD x, y;
};

struct Line {
    LD a, b;
};

struct Tree {
    const int n;
    const bool record;
    VI tr;
    vector<unordered_set<int>> tr2;

    Tree(int _n, bool need_record) : n(_n), record(need_record) {
        if(record) {
            tr2.resize(n + 1);
        } else {
            tr.resize(n + 1);
        }
    }

    int query(int i, function<bool(int)> sink = nullptr) {
        int r = 0;
        if(record) {
            for(; i > 0; i -= i & -i) {
                for(int id : tr2[i]) {
                    ++r;
                    if(!sink(id)) return r;
                }
            }
        } else {
            for(; i > 0; i -= i & -i) r += tr[i];
        }
        return r;
    }

    void add(int i, int id) {
        ++i;
        if(record) {
            for(; i <= n; i += i & -i) tr2[i].insert(id);
        } else {
            for(; i <= n; i += i & -i) tr[i]++;
        }
    }

    void remove(int i, int id) {
        ++i;
        if(record) {
            for(; i <= n; i += i & -i) tr2[i].erase(id);
        } else {
            for(; i <= n; i += i & -i) tr[i]--;
        }
    }
};

LL go(vector<PLD> a, function<void(int, int)> sink = nullptr, int want = 0) {
    const int n = sz(a);
    vector<pair<LD, PII>> es;
    repn(i, n) {
        es.pb(mp(a[i].fi, mp(i, 0)));
        es.pb(mp(a[i].se, mp(i, 1)));
        if(a[i].fi < -PI) {
            es.pb(mp(a[i].fi + PI * 2, mp(i, 2)));
            es.pb(mp(a[i].se + PI * 2, mp(i, 3)));
        }
    }
    sort(all(es));
    vector<VI> where(n, VI(4));
    repn(i, sz(es)) where[es[i].se.fi][es[i].se.se] = i;

    Tree tr(sz(es), sink != nullptr);
    LL ans = 0;
    for(const auto& e : es) {
        if(e.se.se == 0 || e.se.se == 2) {
            int ind = where[e.se.fi][e.se.se + 1];
            if(sink) {
                VI tmp;
                ans += tr.query(ind, [&](int i) {
                    sink(e.se.fi, i);
                    return --want > 0;
                });
            } else {
                ans += tr.query(ind);
            }
        }
        if(e.se.se == 0) {
            tr.add(where[e.se.fi][1], e.se.fi);
        } else if(e.se.se == 1) {
            tr.remove(where[e.se.fi][1], e.se.fi);
        }
    }
    return ans;
}

LL solve(vector<Line> lines, LD radius, function<void(LD)> sink = nullptr,
         int want = 0) {
    vector<PLD> a;
    vector<int> id;
    // cout << endl << "solve " << radius << endl;
    repn(i, sz(lines)) {
        const auto& line = lines[i];
        LD d = fabsl(line.b) / sqrtl(line.a * line.a + 1);
        if(d > radius) continue;
        LD alpha = acosl(d / radius);
        LD ang = line.b > 0 ? atan2(1, -line.a) : atan2(-1, line.a);
        LD ang1 = ang - alpha, ang2 = ang + alpha;
        if(ang2 > PI) ang1 -= PI * 2, ang2 -= PI * 2;
        // cout<<line.a<<" "<<line.b<<endl;
        // cout << alpha / PI << " " << ang / PI << endl;
        // cout << i << " " << ang1 / PI << " " << ang2 / PI << " ("
        //<< (ang2 - ang1) / PI << endl;
        a.pb(mp(ang1, ang2));
        id.pb(i);
    }
    if(sink == nullptr) {
        return go(a, nullptr, 0);
    } else {
        return go(a,
                  [&](int i, int j) {
                      const auto& l1 = lines[id[i]];
                      const auto& l2 = lines[id[j]];
                      LD x = (l2.b - l1.b) / (l1.a - l2.a);
                      LD y = l1.a * x + l1.b;
                      sink(sqrtl(x * x + y * y));
                  },
                  want);
    }
}

void true_main(const vector<Line>& lines, int m) {
    LD le = 0, ri = 1;
    while(solve(lines, ri, nullptr) < m) {
        ri *= 2;
    }
    // cout << ri << endl;
    repn(tt, 100) {
        LD mid = (le + ri) / 2;
        if(solve(lines, mid, nullptr) >= m) {
            ri = mid;
        } else {
            le = mid;
        }
    }
    LD sum = 0;
    int cnt = 0;
    solve(lines, ri, [&](LD val) { sum += val, ++cnt; }, m);
    while(cnt < m) sum += ri, ++cnt;
    while(cnt > m) sum -= ri, --cnt;
    printf("%.9lf\n", double(sum));
}

void test() {
    vector<Line> lines;
    repn(i, 50000) {
        double a = i / 1000.;
        lines.pb({a, 0});
    }
    true_main(lines, 100000);
}

int main() {
    int n;
    int x, y, m;
    scanf("%d", &n);
    scanf("%d%d%d", &x, &y, &m);
    vector<Line> lines;
    repn(i, n) {
        int a0, b0;
        scanf("%d%d", &a0, &b0);
        LD a = a0 / 1000., b = b0 / 1000.;
        LD x0 = x / 1000., y0 = y / 1000.;
        b = b - y0 + a * x0;
        lines.pb({a, b});
    }
    true_main(lines, m);

    return 0;
}