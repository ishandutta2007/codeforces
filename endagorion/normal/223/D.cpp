#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct Point {
    i64 x, y;
    int id;

    Point operator+(Point p) const {
        return {x + p.x, y + p.y, -1};
    }

    Point operator-(Point p) const {
        return {x - p.x, y - p.y, -1};
    }

    i64 operator*(Point p) const {
        return x * p.x + y * p.y;
    }

    i64 operator%(Point p) const {
        return x * p.y - y * p.x;
    }

    bool operator==(Point p) const {
        return x == p.x && y == p.y;
    }

    ld operator~() const {
        return sqrt(*this * *this);
    }

    bool collin(Point p) const {
        return *this % p == 0 && *this * p > 0;
    }
};

struct SideOrVertex {
    Point a, b;

    SideOrVertex(Point a_, Point b_)
        : a(a_)
        , b(b_)
    {
        if (mp(a.x, a.y) > mp(b.x, b.y)) swap(a, b);
    }

    SideOrVertex to_vertex(int z) const {
        if (!z) return {a, a};
        return {b, b};
    }

    bool is_vertex() const {
        return a == b;
    }

    int compare(SideOrVertex r) const {
        if (is_vertex() && r.is_vertex()) {
            return a.x == r.a.x ? (a.y < r.a.y ? -1 : 1) : 0;
        }
        if (!is_vertex() && !r.is_vertex()) {
            #define return_or(x) {int tmp = (x); if (tmp) return tmp;}
            return_or(to_vertex(0).compare(r));
            return_or(to_vertex(1).compare(r));
            return_or(-r.to_vertex(0).compare(*this));
            return_or(-r.to_vertex(1).compare(*this));
            return 0;
        }
        if (!is_vertex()) return -r.compare(*this);
        if (a.x < r.a.x || a.x > r.b.x) return 0;
        i64 v = (r.b - r.a) % (a - r.a);
        if (v == 0) return 0;
        if (v > 0) return 1;
        return -1;
    }

    bool operator<(const SideOrVertex &r) const {
        return compare(r) == -1;
    }
};

const int maxn = 110000;
Point p[maxn];

struct TEvent {
    i64 x;
    int type;
    SideOrVertex sv;

    bool operator<(const TEvent &ev) const {
        if (x != ev.x) return x < ev.x;
        if (type != ev.type) return type < ev.type;
        return false;
    }
};

vector<pair<int, ld> > e[maxn];

const ld PI = atan2(0, -1);

ld atan3(ld y, ld x) {
    ld res = atan2(y, x);
    if (res < 0) res += 2 * PI;
    return res;
}

bool ccw(Point a, Point b, Point c) {
    if (a.collin(b)) return false;
    if (a.collin(c)) return false;
    if (b.collin(c)) return false;
    ld sang = atan3(a % b, a * b) + atan3(b % c, b * c) + atan3(c % a, c * a);
//    cerr << a.id << ' ' << b.id << ' ' << c.id << ' ' << sang << '\n';
    return sang > 3 * PI;
}

class Entry: public pair<ld, int> {
public:
    using pair<ld, int>::pair;

    bool operator<(const Entry &r) const {
        if (fabs(fi - r.fi) > 1e-9) return fi < r.fi;
        return se < r.se;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    forn(i, n) cin >> p[i].x >> p[i].y, p[i].id = i;
    p[n] = p[0];

    forn(i, n) {
        int j = (i + 1) % n;
        e[i].pb({j, ~(p[i] - p[j])});
        e[j].pb({i, ~(p[i] - p[j])});
    }

    vector<TEvent> evs;

    forn(i, n) {
        SideOrVertex s(p[i], p[i]);
        evs.pb({p[i].x, 1, s});
    }

    forn(i, n) {
        Point a = p[i], b = p[i + 1];
        if (a.x == b.x) continue;
        SideOrVertex s(a, b);
        evs.pb({s.a.x, 2, s});
        evs.pb({s.b.x, 0, s});
    }
    sort(all(evs));
    set<SideOrVertex> svs;

    int ptr = 0;
    while (ptr < evs.size()) {
        int x = evs[ptr].x;
//        cerr << x << '\n';
        while (ptr < evs.size() && evs[ptr].x == x && evs[ptr].type == 0) {
            svs.erase(evs[ptr++].sv);
        }
        vector<SideOrVertex> xp;
        while (ptr < evs.size() && evs[ptr].x == x && evs[ptr].type == 1) {
            svs.insert(evs[ptr].sv);
            xp.pb(evs[ptr].sv);
            ++ptr;
        }                 

        for (auto sv: xp) {
            int j = sv.a.id;
            int i = (j + n - 1) % n, k = (j + 1) % n;
            if (ccw(p[i] - p[j], Point({0, 1}), p[k] - p[j])) {
                auto it = svs.upper_bound(sv);
                if (it != svs.end()) {
                    SideOrVertex rsv = *it;
                    if (rsv.is_vertex()) {
//                        cerr << rsv.a.id << " > " << sv.a.id << '\n';
                        int rp = rsv.a.id;
                        e[rp].pb({j, ~(p[rp] - p[j])});
                    } else {
//                        cerr << rsv.a.id << '-' << rsv.b.id << " > " << sv.a.id << '\n';
                        Point v = rsv.b - rsv.a;
                        ld y = rsv.a.y + 1.0 * v.y * (x - rsv.a.x) / v.x;
                        e[rsv.a.id].pb({j, y - sv.a.y + hypot(rsv.a.x - x, rsv.a.y - y)});
                        e[rsv.b.id].pb({j, y - sv.a.y + hypot(rsv.b.x - x, rsv.b.y - y)});
                    }
                };// else cerr << "Nothing above" << sv.a.id << '\n';
            }
            if (ccw(p[i] - p[j], Point({0, -1}), p[k] - p[j])) {
                auto it = svs.lower_bound(sv);
                if (it != svs.begin()) {
                    --it;
                    SideOrVertex rsv = *it;
                    if (rsv.is_vertex()) {
//                        cerr << sv.a.id << " > " << rsv.a.id << '\n';
                        int rp = rsv.a.id;
                        e[j].pb({rp, ~(p[rp] - p[j])});
                    } else {
//                        cerr << sv.a.id << " > " << rsv.a.id << '-' << rsv.b.id << '\n';
                        Point v = rsv.b - rsv.a;
                        ld y = rsv.a.y + 1.0 * v.y * (x - rsv.a.x) / v.x;
                        e[j].pb({rsv.a.id, sv.a.y - y + hypot(rsv.a.x - x, rsv.a.y - y)});
                        e[j].pb({rsv.b.id, sv.a.y - y + hypot(rsv.b.x - x, rsv.b.y - y)});
                    }
                };// else cerr << "Nothing below " << sv.a.id << '\n';
            }
        }

        for (auto sv: xp) svs.erase(sv);

        while (ptr < evs.size() && evs[ptr].x == x && evs[ptr].type == 2) {
            svs.insert(evs[ptr++].sv);
        }
//        for (auto sv: svs) cerr << sv.a.id << ' ' << sv.b.id << '\n';

    }

    int s, t;
    cin >> s >> t;
    --s; --t;
    vector<ld> dist(n, 1e9);
    dist[s] = 0.0;
    set<Entry> q = {{0.0, s}};
    while (!q.empty()) {
        auto it = q.begin();
        int v = it->se;
        q.erase(it);
        for (auto [u, len]: e[v]) {
            ld ndist = dist[v] + len;
            if (ndist + 1e-9 < dist[u]) {
                q.erase({dist[u], u});
                dist[u] = ndist;
                q.insert({dist[u], u});
            }
        }
    }
    cout << dist[t] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}