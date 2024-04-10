#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

#define fst first
#define scnd second
#define EPS 1e-7
#define EPS2 1e-6

using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;

typedef double T;
double x1, x2, y1, y2, vx, vy;

int cmp(double x, double y = 0) {
	return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

struct point {
    T x, y;

    point(T x = 0, T y = 0): x(x), y(y) {}

    point operator + (point b) { return point(x + b.x, y + b.y); }
    point operator - (point b) { return point(x - b.x, y - b.y); }
    bool operator < (const point b) const { return tie(x,y) < tie(b.x, b.y); }
};
typedef pair<point, point> segm;

inline T distPoints(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

inline T escalar(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

inline T vetorial(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

int ccw(point p, point q, point o) {
	return cmp(vetorial(p - o, q - o));
}

struct line {
    T a, b, c;

    line(T a, T b, T c): a(a), b(b), c(c) {}

    line(point p1, point p2):
        a(p1.y - p2.y),
        b(p2.x - p1.x),
        c(p1.x*p2.y - p2.x*p1.y) {}
};

point intersection(line a, line b) {
    point ret;
    ret.x = (b.c * a.b - a.c * b.b) / (b.b * a.a - a.b * b.a);
    ret.y = (b.c * a.a - a.c * b.a) / (a.b * b.a - b.b * a.a);
    return ret;
}

bool parallel(line a, line b) {
    return abs(a.b * b.a - a.a * b.b) < EPS;
}

inline T point_line(point a, line l) {
    return abs(l.a*a.x + l.b*a.y + l.c) / sqrt(l.a*l.a + l.b*l.b);
}

T distLines(line a, line b) {
    if(!parallel(a,b)) return 0;
    if(a.a == 0) return point_line(point(0, -a.c/a.b), b);
    return point_line(point(-a.c/a.a, 0), b);
}

bool equal_lines(line a, line b) {
    if(!parallel(a,b)) return false;
    return abs(distLines(a,b)) < EPS;
}

int n;
vector<segm> trap;
vector<pair<double, int> > event;

bool cmpp(pair<double, int> a, pair<double, int> b) {
    if(a.fst == b.fst) {
        return a.scnd < b.scnd;
    }

    return a.fst < b.fst;
}

void intersec(point a, point b) {
    vector<double> ans;
    if(!parallel(line(trap[0].fst, trap[0].scnd), line(a, b))) {
        point p = intersection(line(trap[0].fst, trap[0].scnd), line(a, b));
        if(x1 < p.x + EPS && p.x < x2 + EPS) {
            double time;
            if(vx != 0) time = (-a.x + p.x) / vx;
            else time = (-a.y + p.y) / vy;

            if(time <= 0) time = 0;
            ans.pb(time);
        }
    }

    if(!parallel(line(trap[1].fst, trap[1].scnd), line(a, b))) {
        point p = intersection(line(trap[1].fst, trap[1].scnd), line(a, b));
        if(y1 < p.y + EPS && p.y < y2 + EPS) {
            double time;
            if(vx != 0) time = (-a.x + p.x) / vx;
            else time = (-a.y + p.y) / vy;

            if(time <= 0) time = 0;
            ans.pb(time);
        }
    }

    if(!parallel(line(trap[2].fst, trap[2].scnd), line(a, b))) {
        point p = intersection(line(trap[2].fst, trap[2].scnd), line(a, b));
        if(x1 < p.x + EPS && p.x < x2 + EPS) {
            double time;
            if(vx != 0) time = (-a.x + p.x) / vx;
            else time = (-a.y + p.y) / vy;

            if(time <= 0) time = 0;
            ans.pb(time);
        }
    }

    if(!parallel(line(trap[3].fst, trap[3].scnd), line(a, b))) {
        point p = intersection(line(trap[3].fst, trap[3].scnd), line(a, b));
        if(y1 < p.y + EPS && p.y < y2 + EPS) {
            double time;
            if(vx != 0) time = (-a.x + p.x) / vx;
            else time = (-a.y + p.y) / vy;

            if(time <= 0) time = 0;
            ans.pb(time);
        }
    }

    sort(ans.begin(), ans.end());
    if(ans.size() > 0) {
        event.pb({ans[0], 1});
        event.pb({ans.back(), -1});
    }
}

bool inside(T x, T y) {
    return (x1 <= x + EPS && x <= x2 + EPS) && (y1 <= y + EPS && y <= y2 + EPS);
}

bool strict_inside(T x, T y) {
    return (x1 < x && x < x2) && (y1 < y && y < y2);
}

int main() {
    scanf("%d",&n);
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    x1 += EPS2, y1 += EPS2, x2 -= EPS2, y2 -= EPS2;

    if(x1 > x2 || y1 > y2) {
        puts("-1");
        return 0;
    }

    //CCW
    point p1(x1, y1), p2(x2, y1), p3(x2, y2), p4(x1, y2);
    trap.pb({p1, p2});
    trap.pb({p2, p3});
    trap.pb({p3, p4});
    trap.pb({p4, p1});

    for(int i=0; i<n; i++) {
        double x, y;
        scanf("%lf %lf %lf %lf", &x, &y, &vx, &vy);

        point p(x, y), pd(x + vx, y + vy);
        pdd times;

        if(vx == 0 && vy == 0) {
            if(strict_inside(x, y))
                event.pb({0, 1});
        }
        else intersec(p, pd);
    }

    sort(event.begin(), event.end(), cmpp);
    int ans = 0;
    for(auto t : event) {
        ans += t.scnd;
        if(ans == n) {
            printf("%.12f\n", t.fst);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}