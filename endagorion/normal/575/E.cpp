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

    Point operator+(const Point &p) const {
        return {x + p.x, y + p.y};
    }

    Point operator-(const Point &p) const {
        return {x - p.x, y - p.y};
    }

    bool operator==(const Point &p) const {
        return mp(x, y) == mp(p.x, p.y);
    }

    bool operator<(const Point &p) const {
        return mp(x, y) < mp(p.x, p.y);
    }

    i64 operator%(const Point &p) const {
        return x * p.y - y * p.x;
    }

    i64 operator*(const Point &p) const {
        return x * p.x + y * p.y;
    }

    i64 operator~() const {
        return *this * *this;
    }

    ld norm() const {
        return hypot(x, y);
    }
};

const int A = 100000;
int clamp(int x) {
    uax(x, 0);
    uin(x, A);
    return x;
}

vector<Point> ps;

void push(int x, int y) {
    if (x < 0) {
        int d = -x;
        ps.pb({0, clamp(y - d)});
        ps.pb({0, clamp(y + d)});
    } else if (y < 0) {
        int d = -y;
        ps.pb({clamp(x - d), 0});
        ps.pb({clamp(x + d), 0});
    } else if (x > A) {
        int d = x - A;
        ps.pb({A, clamp(y - d)});
        ps.pb({A, clamp(y + d)});
    } else if (y > A) {
        int d = y - A;
        ps.pb({clamp(x - d), A});
        ps.pb({clamp(x + d), A});
    } else ps.pb({x, y});
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

ld r3(Point a, Point b, Point c) {
    Point v = b - a, u = c - a;
    return v.norm() * u.norm() * (v - u).norm() / 2 / abs(v % u);
}

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
    forn(i, n) {
        int x, y, v;
        cin >> x >> y >> v;

        forn(d, 4) {
            push(x + dx[d] * v, y + dy[d] * v);
        }
    }

    sort(all(ps));
    ps.erase(unique(all(ps)), ps.end());

    Point O = ps[0];
    sort(1 + all(ps), [&](Point a, Point b){
        i64 v = (a - O) % (b - O);
        if (v) return v > 0;
        return ~a < ~b;
    });

    {
        vector<Point> nps = {O};
        for1(i, ps.size() - 1) {
            if (i + 1 == ps.size() || (ps[i] - O) % (ps[i + 1] - O)) nps.pb(ps[i]);
        }
        ps = nps;
    }

/*    for (auto p: ps) {
        cerr << p.x << ' ' << p.y << '\n';
    }*/

    vector<Point> st = {O};
    for1(i, ps.size() - 1) {
        auto p = ps[i];
        while (st.size() > 1) {
            auto prv = st.end()[-1], pprv = st.end()[-2];
            if ((p - pprv) % (prv - pprv) >= 0) st.pop_back();
            else break;
        }
        st.pb(p);
    }


    ld br = -1;
    vector<Point> bv;
    assert(st.size() >= 3);
    forn(i, st.size()) {
        Point a = st[i], b = st[(i + 1) % st.size()], c = st[(i + 2) % st.size()];
        auto r = r3(a, b, c);
//        for (auto p: {a, b, c}) cerr << p.x << ' ' << p.y << ' ';
//        cerr << r << '\n';
        if (uax(br, r)) bv = {a, b, c};
    }

    for (auto p: bv) cout << p.x << ' ' << p.y << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}