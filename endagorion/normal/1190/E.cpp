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

const ld PI = atan2(0, -1);

ld norm(ld angle) {
    while (angle < 0) angle += 2 * PI;
    while (angle > 2 * PI - 1e-9) angle -= 2 * PI;
    return angle;
}

struct TPoint {
    ld x, y;

    TPoint operator-(const TPoint &p) const {
        return {x - p.x, y - p.y};
    }

    ld angle() const {
        return norm(atan2(y, x));
    }

    ld operator~() const {
        return hypot(x, y);
    }
};

int n, m;

ld tangent(TPoint p, ld R, int dir) {
    ld angle = p.angle();
    angle -= dir * asin(R / ~p);
    if (dir == -1) angle += PI;
    return norm(angle);
}

struct TEvent {
    ld angle;
    int i;
    bool add;

    bool operator<(const TEvent &ev) const {
        return angle < ev.angle;
    }
};

bool test(vector<TPoint> p, ld R) {
    vector<pair<ld, int> > ord;
    forn(i, n) ord.pb(mp(tangent(p[i], R, 1), i));
    sort(all(ord));
    vector<TPoint> q(n);
    forn(i, n) q[i] = p[ord[i].se];

    vector<TEvent> evs;
    forn(i, n) {
        evs.pb({tangent(q[i], R, 1), i, false});
        evs.pb({tangent(q[i], R, -1), i, true});
    }
    sort(all(evs));
    set<int> outs;
    forn(i, n) {
        if (tangent(q[i], R, -1) < tangent(q[i], R, 1)) outs.insert(i);
    }

    vi64 tr(n);
    for (auto ev: evs) {
        if (ev.add) {
            outs.erase(ev.i);
            outs.erase(ev.i + n);
        } else {
            tr[ev.i] = (outs.empty() ? ev.i + n : *outs.begin()) - ev.i;
            assert(tr[ev.i] > 0);
            outs.insert(ev.i + n);
        }
    }

/*    forn(i, n) {
        cerr << q[i].x << ' ' << q[i].y << ' ' << tangent(q[i], R, 1) << ' ' << tangent(q[i], R, -1) << ' ' << tr[i] << '\n';
    }*/

    vi64 mtr(n);
    int rm = m;
    while (rm) {
        if (rm & 1) {
            forn(i, n) mtr[i] += tr[(i + mtr[i]) % n];
        }
        vi64 ntr(n);
        forn(i, n) ntr[i] = tr[i] + tr[(i + tr[i]) % n];
        tr = ntr;
        rm /= 2;
    }
    return *max_element(all(mtr)) >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m;
    vector<TPoint> p(n);
    forn(i, n) cin >> p[i].x >> p[i].y;

    ld L = 1e-7, R = 1e9;
    forn(i, n) uin(R, ~p[i]);
    R -= 1e-7;
    forn(its, 100) {
        if (fabs(R - L) < 1e-7 || (R - L) < 1e-7 * L) break;
        ld M = 0.5 * (L + R);
//        cerr << L << ' ' << R << ' ' << M << '\n';
        (test(p, M) ? L : R) = M;
//        cerr << fabs(R - L) << ' ' << (R - L) / L << '\n';
    }

    cout << 0.5 * (L + R) << '\n';
//    test(p, 2);

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}