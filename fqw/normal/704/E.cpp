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
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VB> VVB;
typedef vector<VS> VVS;
typedef vector<VPI> VVPI;
typedef vector<VPL> VVPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
VI read_vi(int n = -1) { if (n < 0) scanf("%d", &n); VI a(n); repn(i, n) scanf("%d", &a[i]); return a; }
VL read_vl(int n = -1) { if (n < 0) scanf("%d", &n); VL a(n); repn(i, n) scanf("%lld", &a[i]); return a; }
VPI read_vpi(int n = -1) { if (n < 0) scanf("%d", &n); VPI a(n); repn(i, n) scanf("%d%d", &a[i].fi,&a[i].se); return a; }
VPL read_vpl(int n = -1) { if (n < 0) scanf("%d", &n); VPL a(n); repn(i, n) scanf("%lld%lld", &a[i].fi,&a[i].se); return a; }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }
// clang-format on
// }}}

typedef long double R;

const R EPS = 1e-12;
int sgn(R x) { return x < -EPS ? -1 : x > EPS; }
struct Point {
    R x, y;
    Point() {}
    Point(R _x, R _y) : x(_x), y(_y) {}
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(R b) const { return Point(x * b, y * b); }
    Point operator/(R b) const { return Point(x / b, y / b); }
    void rotate90() {
        swap(x, y);
        x = -x;
    }
    R len() const { return sqrt(x * x + y * y); }
    void normalize() { *this = *this / len(); }
    friend R mult(Point p1, Point p2) { return p1.x * p2.y - p1.y * p2.x; }
    friend R dot(Point p1, Point p2) { return p1.x * p2.x + p1.y * p2.y; }
    friend R mult(Point p0, Point p1, Point p2) {
        return mult(p1 - p0, p2 - p0);
    }
    friend R dot(Point p0, Point p1, Point p2) { return dot(p1 - p0, p2 - p0); }
    friend R dist(Point p1, Point p2) { return (p1 - p2).len(); }
    R lambda(Point s, Point t) const {  // return c: p=s+(t-s)*c
        return dot(s, t, *this) / dot(s, t, t);
    }
};
struct Line {
    R a, b, c;
    Line() {}
    Line(R _a, R _b, R _c) : a(_a), b(_b), c(_c) {}
    Line(Point p1, Point p2) {
        a = p2.y - p1.y, b = p1.x - p2.x;
        c = -(p1.x * a + p1.y * b);
    }
    Point cross(const Line& l) const {
        R t = a * l.b - b * l.a;
        R x = b * l.c - c * l.b;
        R y = c * l.a - a * l.c;
        return Point(x / t, y / t);
    }
};
struct Segment {
    Point p1, p2;
    bool is_point = false;
    Segment(R x, R y) : p1(x, y), p2(x, y), is_point(true) {}
    Segment(R x1, R y1, R x2, R y2) : p1(x1, y1), p2(x2, y2) {
        if(p1.y > p2.y) swap(p1, p2);
    }
    R at(R y) const {
        if(is_point) {
            assert(sgn(y - p1.y) == 0);
            return p1.x;
        }
        return p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
    }
};

vector<Segment> prepare() {
    int n, m;
    scanf("%d%d", &n, &m);
    VVI es(n);
    repn(i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        es[a].pb(b), es[b].pb(a);
    }
    const int LOG = 20;
    VI my(n, -1), dep(n);
    VVI up(n, VI(LOG, -1));
    const function<int(int, int)> cal_my = [&](int x, int fa) {
        if(fa >= 0) dep[x] = dep[fa] + 1;
        up[x][0] = fa;
        for(int i = 0; up[x][i] >= 0; ++i) up[x][i + 1] = up[up[x][i]][i];
        int size = 1, best = -1;
        for(int y : es[x]) {
            if(y != fa) {
                int tmp = cal_my(y, x);
                size += tmp;
                if(setmax(best, tmp)) my[x] = y;
            }
        }
        return size;
    };
    cal_my(0, -1);
    VI head(n), where(n), arr;
    const function<void(int, int, int)> dfs = [&](int x, int fa, int h) {
        head[x] = h, where[x] = sz(arr), arr.pb(x);
        if(my[x] >= 0) {
            dfs(my[x], x, h);
        }
        for(int y : es[x]) {
            if(y != fa && y != my[x]) {
                arr.pb(x);
                dfs(y, x, x);
            }
        }
    };
    dfs(0, -1, 0);
    const auto lca = [&](int x, int y) {
        if(dep[x] > dep[y]) swap(x, y);
        repn(i, LOG) if((dep[y] - dep[x]) & (1 << i)) y = up[y][i];
        irepn(i, LOG) if(up[x][i] != up[y][i]) x = up[x][i], y = up[y][i];
        if(x != y) x = up[x][0];
        return x;
    };
    const auto extract = [&](int x, int target) {
        VPI r;
        while(x != target) {
            int y = head[x];
            if(dep[y] < dep[target]) y = target;
            int len = dep[x] - dep[y];
            r.pb(mp(where[x], where[x] - len));
            x = y;
        }
        return r;
    };

    // cout << head << endl;
    // cout << where << endl;
    // cout << arr << endl;

    vector<Segment> segments;
    while(m--) {
        int t, c, x, y;
        scanf("%d%d%d%d", &t, &c, &x, &y), --x, --y;
        int z = lca(x, y);
        VPI px = extract(x, z);
        VPI py = extract(y, z);
        bool covered = false;
        if(!px.empty() && px.back().se == where[z]) covered = true;
        if(!py.empty() && py.back().se == where[z]) covered = true;
        int cur = 0;
        for(const auto& p : px) {
            int tmp = cur + abs(p.fi - p.se);
            segments.pb(Segment(p.fi, t + R(cur) / c, p.se, t + R(tmp) / c));
            cur = tmp;
        }
        if(!covered) {
            segments.pb(Segment(where[z], t + R(cur) / c));
        }
        reverse(all(py));
        for(auto& p : py) {
            swap(p.fi, p.se);
            int tmp = cur + abs(p.fi - p.se);
            segments.pb(Segment(p.fi, t + R(cur) / c, p.se, t + R(tmp) / c));
            cur = tmp;
        }
    }
    return segments;
}

bool on_segment(Point p, Segment b) {
    return sgn(dot(p, b.p1, b.p2)) <= 0 && sgn(mult(p, b.p1, b.p2)) == 0;
}

R intersection(Segment a, Segment b) {
    if(sgn(mult(a.p1, a.p2, b.p1)) * sgn(mult(a.p1, a.p2, b.p2)) > 0)
        return 1e50;
    if(sgn(mult(b.p1, b.p2, a.p1)) * sgn(mult(b.p1, b.p2, a.p2)) > 0)
        return 1e50;
    if(sgn(mult(a.p1 - a.p2, b.p1 - b.p2)) == 0) {
        R r = 1e50;
        if(on_segment(a.p1, b)) setmin(r, a.p1.y);
        if(on_segment(a.p2, b)) setmin(r, a.p2.y);
        if(on_segment(b.p1, a)) setmin(r, b.p1.y);
        if(on_segment(b.p2, a)) setmin(r, b.p2.y);
        return r;
    } else {
        return Line(a.p1, a.p2).cross(Line(b.p1, b.p2)).y;
    }
}

R cur = 0;
vector<Segment> segments;

void find_intersection() {
    R found = 1e50;
    vector<pair<R, int>> events;
    repn(i, sz(segments)) {
        events.pb(mp(segments[i].p1.y, -i - 1));
        events.pb(mp(segments[i].p2.y + EPS / 5, i));
    }
    sort(all(events));
    struct Id {
        int i;
        bool operator<(const Id& b) const {
            int s = sgn(segments[i].at(cur) - segments[b.i].at(cur));
            if(s == 0) s = i - b.i;
            return s < 0;
        }
    };
    set<Id> ids;
    for(const auto& e : events) {
        if(e.fi >= found) break;
        cur = e.fi;
        if(e.se < 0) {
            auto it = ids.insert(Id{-e.se - 1}).fi;
            auto p = it;
            ++p;
            if(p != ids.end()) {
                setmin(found, intersection(segments[it->i], segments[p->i]));
            }
            p = it;
            if(p != ids.begin()) {
                --p;
                setmin(found, intersection(segments[it->i], segments[p->i]));
            }
        } else {
            assert(ids.erase(Id{e.se}) == 1);
        }
    }
    if(found > 1e40) {
        printf("-1\n");
    } else {
        assert(found >= 0);
        printf("%.15lf\n", (double)found);
    }
}

int main() {
    segments = prepare();
    find_intersection();
    return 0;
}