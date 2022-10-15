#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct Point {
    ld x, y;

    inline ld ygol() const { return atan2l(y, x); }

    inline ld sqd() const { return x*x + y*y; }
};

struct Line {
    ld a, b, c;

    Line() {}

    Line(Point p1, Point p2)
        : a(p1.y - p2.y), b(p2.x - p1.x), c(-(a*p1.x + b*p1.y)) {}
};

inline Line byYgol(ld yy) {
    return Line(Point {0, 0}, Point {cosl(yy), sinl(yy)});
}

inline ld det(ld a, ld b, ld c, ld d) { return a*d - b*c; }

const ld eps = 1e-9;

inline bool eq(ld a, ld b) { return abs(a-b) < eps; }
inline bool leq(ld a, ld b) { return a < b || eq(a, b); }
inline bool lt(ld a, ld b) { return a < b && !eq(a, b); }

inline Point intr(Line l1, Line l2, bool &ok) {
    ld d0 = det(l1.a, l2.a, l1.b, l2.b);
    ld d1 = det(-l1.c, -l2.c, l1.b, l2.b);
    ld d2 = det(l1.a, l2.a, -l1.c, -l2.c);
    if (eq(d0, 0)) {
        ok = false;
        return {2112, 2112};
    }
    ok = true;
    return {d1/d0, d2/d0};
}

struct Segment {
    Point l, r;
    int who;
};

ld curYgol = -2112;

bool operator<(const Segment &a, const Segment &b) {
    Line ln = byYgol(curYgol);
    bool ok1, ok2;
    Point p1 = intr(ln, Line(a.l, a.r), ok1);
    Point p2 = intr(ln, Line(b.l, b.r), ok2);
    assert(ok1 && ok2);
    ld d1 = p1.sqd(), d2 = p2.sqd();
    return d1 < d2;
}

inline Point &operator-=(Point &p, Point q) {
    p.x -= q.x;
    p.y -= q.y;
    return p;
}

inline ld square(Point a, Point b, Point c) {
    b -= a;
    c -= a;
    return 0.5 * det(b.x, b.y, c.x, c.y);
}

inline ld square4(Point a, Point b, Point c, Point d) {
    return abs(square(a, b, c)) + abs(square(a, c, d));
}

int main() {
    ios_base::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif // DEBUG

    const ld pi = acosl(-1);

    int n; cin >> n;
    vector<Segment> segs;
    vector<ld> ygly {-pi, pi};
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        vector<int> x(k), y(k);
        for (int j = 0; j < k; ++j) {
            cin >> x[j] >> y[j];
        }
        for (int j = 0; j < k; ++j) {
            int nj = (j+1) % k;
            ygly.push_back(atan2l(y[j], x[j]));
            segs.push_back({{(ld)x[j], (ld)y[j]}, {(ld)x[nj], (ld)y[nj]}, i});
        }
    }

    sort(begin(ygly), end(ygly), lt);
    ygly.erase(unique(begin(ygly), end(ygly), eq), end(ygly));

    int ys = ygly.size();
    int ss = segs.size();
    vector< vector<int> > add(ys), del(ys);
    for (int sid = 0; sid < ss; ++sid) {
        Segment s = segs[sid];
        ld ly = s.l.ygol(), ry = s.r.ygol();
        if (eq(ly, ry)) continue;
        if (ly > ry) {
            swap(ly, ry);
            swap(s.l, s.r);
        }
        if (lt(pi, ry - ly)) {
            swap(ly, ry);
            swap(s.l, s.r);
        }
        int lp = lower_bound(begin(ygly), end(ygly), ly, lt) - begin(ygly);
        int rp = lower_bound(begin(ygly), end(ygly), ry, lt) - begin(ygly);
        assert(lp != rp);
        if (lp < rp) {
            add[lp].push_back(sid);
            del[rp].push_back(sid);
        } else {
            add[lp].push_back(sid);
            del[ys-1].push_back(sid);
            if (rp != 0) {
                add[0].push_back(sid);
                del[rp].push_back(sid);
            }
        }
    }

    set< pair<Segment, int> > st;
    ld answr = 0.0;
    for (int yid = 0; yid+1 < ys; ++yid) {
        for (int sid : del[yid]) {
            st.erase({segs[sid], sid});
        }
        curYgol = (ygly[yid] + ygly[yid+1]) * 0.5;
        for (int sid : add[yid]) {
            st.emplace(segs[sid], sid);
        }
        if (!st.empty()) {
            assert((int)st.size() >= 2);
            Segment s1 = begin(st)->first;
            Segment s2 = next(begin(st))->first;
            assert(s1.who == s2.who);
            Line l1 = byYgol(ygly[yid]), l2 = byYgol(ygly[yid+1]);
            bool ok1, ok2, ok3, ok4;
            Point p1 = intr(l1, Line(s1.l, s1.r), ok1);
            Point p2 = intr(l2, Line(s1.l, s1.r), ok2);
            Point p3 = intr(l2, Line(s2.l, s2.r), ok3);
            Point p4 = intr(l1, Line(s2.l, s2.r), ok4);
            assert(ok1 && ok2 && ok3 && ok4);
            answr += square4(p1, p2, p3, p4);
        }
    }

    cout << fixed << setprecision(10) << answr << endl;
    return 42 ^ 42;
}