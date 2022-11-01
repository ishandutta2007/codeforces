#include <bits/stdc++.h>

using namespace std;
typedef long long T;

T EPS = 0;

int cmp(T x, T y = 0) {
	return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}
struct point {
    T x, y;
    int id;

    point(T x = 0, T y = 0, int id = -1): x(x), y(y), id(id) {}

    point operator + (point b) { return point(x + b.x, y + b.y); }
    point operator - (point b) { return point(x - b.x, y - b.y); }
    point operator * (T c) { return point(x*c, y*c); }
    point operator / (T c) { return point(x/c, y/c); }
    bool operator < (const point b) const {
        return pair<T, T>(x, y) < pair<T, T>(b.x, b.y);
    }
};

inline T distPoints(point a) {
    return (a.x * a.x + a.y * a.y);
}


struct line {
    T a, b, c;

    line(T a, T b, T c): a(a), b(b), c(c) {}

    line(point p1, point p2):
        a(p1.y - p2.y),
        b(p2.x - p1.x),
        c(p1.x*p2.y - p2.x*p1.y) {}
};

bool parallel(line a, line b) {
    return (a.b * b.a - a.a * b.b) == 0;
}

int n;
vector<point> p;
point pl, pr;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        p.emplace_back(x, y, i);

        if(!i) pl = pr = p.back();
        else {
            if(pl.x < x || (pl.x == x && pl.y < y)) pl = p.back();
            if(pr.x > x || (pr.x == x && pr.y > y)) pr = p.back();
        }
    }

    for(int i = 0; i < n; i++) {
        point nl = p[(pl.id + 1) % n];
        point nr = p[(pr.id + 1) % n];

        line l1(pl, nl);
        line l2(nr, pr);

        if(!parallel(l1, l2) || distPoints(pl - nl) != distPoints(nr - pr)) {
            puts("NO");
            return 0;
        }

        pl = nl;
        pr = nr;
    }

    puts("YES");
    return 0;
}