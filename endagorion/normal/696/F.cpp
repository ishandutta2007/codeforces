#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TPoint {
    ld x, y;

    explicit TPoint(ld x = 0.0, ld y = 0.0)
        : x(x)
        , y(y)
    {
    }

    TPoint operator+(const TPoint &p) const {
        return TPoint(x + p.x, y + p.y);
    }

    TPoint operator-(const TPoint &p) const {
        return TPoint(x - p.x, y - p.y);
    }

    TPoint operator-() const {
        return TPoint(-x, -y);
    }

    TPoint operator*(ld p) const {
        return TPoint(p * x, p * y);
    }

    ld operator*(const TPoint &p) const {
        return x * p.x + y * p.y;
    }

    ld operator%(const TPoint &p) const {
        return x * p.y - y * p.x;
    }

    TPoint rotate() const {
        return TPoint(y, -x);
    }

    ld operator~() const {
        return sqrt(*this * *this);
    }

    TPoint norm() const {
        return *this * (1.0 / ~*this);
    }
};

const int maxn = 500;
const ld eps = 1e-12;
TPoint p[maxn];

TPoint intersect(TPoint n1, ld v1, TPoint n2, ld v2) {
    assert(fabs(n1 % n2) > eps);
    ld D = n1 % n2;
    return TPoint((TPoint(v1, n1.y) % TPoint(v2, n2.y)) / D, (TPoint(n1.x, v1) % TPoint(n2.x, v2)) / D);
}

bool halfplanes(vector< pair<TPoint, ld> > h, TPoint &res) {
    random_shuffle(all(h));
    TPoint up = -h[0].fi;
    TPoint best;
    forn(i, h.size()) {
        if (fabs(h[0].fi % h[i].fi) < eps) continue;
        best = intersect(h[0].fi, h[0].se, h[i].fi, h[i].se);
        break;
    }
    for1(i, h.size() - 1) {
        if (h[i].fi * best > h[i].se - eps) continue;
        TPoint any;
        forn(j, i) {
            if (fabs(h[i].fi % h[j].fi) < eps) continue;
            any = intersect(h[i].fi, h[i].se, h[j].fi, h[j].se);
            break;
        }
        TPoint v = h[i].fi.rotate();
        TPoint L = any + v * 1e9, R = any - v * 1e9;
        bool g = true;
        forn(j, i) {
            g &= h[j].fi * L - h[j].se > -eps || h[j].fi * R - h[j].se > -eps;
            if (!g) break;
            if (fabs(h[i].fi % h[j].fi) < eps) continue;
            if (h[j].fi * L < h[j].se) L = intersect(h[i].fi, h[i].se, h[j].fi, h[j].se);
            if (h[j].fi * R < h[j].se) R = intersect(h[i].fi, h[i].se, h[j].fi, h[j].se);
        }

        if (!g) return false;

        bool ok = false;
        if (h[i].fi * L - h[i].se > -eps) {
            if (!ok || up * L > up * best) best = L;
            ok = true;
        }
        if (h[i].fi * R - h[i].se > -eps) {
            if (!ok || up * R > up * best) best = R;
            ok = true;
        }
        if (!ok) return false;
    }
    res = best;
    return true;
}

pair<TPoint, ld> toTheLeft(TPoint a, TPoint b) {
    TPoint n = TPoint(b.y - a.y, a.x - b.x).norm();
    return mp(n, n * a);
}

bool inside(TPoint a, const vector<pair<TPoint, ld> > &h) {
    for (auto w: h) {
        if (w.fi * a - w.se < -eps) return false;
    }
    return true;
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
    forn(i, n) cin >> p[i].x >> p[i].y;
    p[n] = p[0];
    ld L = 0.0, R = 1e5;
    vector< pair<TPoint, ld> > P(n);
    forn(i, n) {
        P[i] = toTheLeft(p[i + 1], p[i]);
    }
    TPoint A, B;
    cerr.precision(10);
    forn(its, 50) {
        ld M = 0.5 * (L + R);
//        cerr << M << '\n';
        bool ok = false;
        vector< pair<TPoint, ld> > h;
        forn(i, n) {
            h.pb(P[i]);
//            h.pb(mp(P[i].fi, P[i].se - M));
            h.pb(mp(-P[i].fi, -P[i].se - M));
        }
        vector<TPoint> cands;
        forn(i, n) cands.pb(p[i]);
        forn(i, n) {
            TPoint n1 = -P[i].fi;
            ld v1 = -P[i].se - M;
            forn(j, n) {
                if (fabs(n1 % P[j].fi) < eps) continue;
                if ((n1 * p[j] > v1) != (n1 * p[j + 1] > v1)) cands.pb(intersect(n1, v1, P[j].fi, P[j].se));
            }
        }
        for (TPoint a: cands) {
            if (ok) break;
//            if (fabs(h[i].fi % h[j].fi) < eps) continue;
//            TPoint a = intersect(h[i].fi, h[i].se, h[j].fi, h[j].se);
            if (!inside(a, P)) continue;
            vector< pair<TPoint, ld> > H = P;
            for (auto w: h) {
                if (w.fi * a - w.se < -eps) H.pb(w);
            }
            TPoint b;
            if (halfplanes(H, b)) {
                A = a;
                B = b;
                ok = true;
            }
        }
        (ok ? R : L) = M;
    }
    cout << R << '\n';
    cout << A.x << ' ' << A.y << '\n';
    cout << B.x << ' ' << B.y << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}