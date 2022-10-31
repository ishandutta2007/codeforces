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

typedef pair<point, point> segm;
typedef vector<point> polygon;

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

point pivot;
bool polar_cmp(point a , point b) {
    T cross = vetorial(a - pivot, b - pivot);
    return cmp(cross) == 1 || (cmp(cross) == 0 && cmp(distPoints(pivot - a), distPoints(pivot - b)) == -1);
}

vector<point> convex_hull(vector<point> p, bool strict, bool repeat_last = false) {
    if(p.size() <= 2) return p;

    int pi = 0;
    for(int i = 1; i < p.size(); i++)
        if(p[i] < p[pi]) pi = i;

    swap(p[0], p[pi]); pivot = p[0];
    sort(p.begin()+1, p.end(), polar_cmp);

    vector<point> s;
    s.push_back(p.back()); s.push_back(p[0]); s.push_back(p[1]);

    for(int i = 2; i < p.size();) {
        int j = s.size()-1;
        if(s.size() == 2 || ccw(s[j], p[i], s[j-1]) >= (strict ? 1 : 0)) s.push_back(p[i++]);
        else s.pop_back();
    }
    if(!repeat_last) s.pop_back();
    return s;
}

polygon p, hull, jonson, nohull;

bool fk(polygon& p) {
    for(point wilson : p)
        if(wilson.x % 2 || wilson.y % 2)
            return true;
    return false;
}

void ani() {
    puts("Ani");
    exit(0);
}

int mark[200020], n;

int main() {
    scanf("%d", &n);

    p.emplace_back(0, 0, 0);
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        p.emplace_back(x, y, i);
    }

    hull = convex_hull(p, true);
    if(fk(hull)) ani();

    for(point po : hull) {
        mark[po.id] = 1;
    }
    for(int i = 0; i <= n; i++) {
        if(!mark[i]) nohull.push_back(p[i]);
    }

    jonson = nohull;
    jonson.push_back(p[0]);
    for(int i = 0; i < hull.size(); i += 2) jonson.push_back(hull[i]);
    jonson = convex_hull(jonson, true);
    if(fk(jonson)) ani();

    if(hull.size() % 2 == 0) {
        jonson = nohull;
        jonson.push_back(p[0]);
        for(int i = 1; i < hull.size(); i += 2) jonson.push_back(hull[i]);
        jonson = convex_hull(jonson, true);
        if(fk(jonson)) ani();
    } else {
        jonson = nohull;
        jonson.push_back(hull[0]);
        jonson.push_back(p[0]);
        for(int i = 1; i < hull.size(); i += 2) jonson.push_back(hull[i]);
        jonson = convex_hull(jonson, true);
        if(fk(jonson)) ani();

        jonson = nohull;
        jonson.push_back(hull.back());
        jonson.push_back(p[0]);
        for(int i = 1; i < hull.size(); i += 2) jonson.push_back(hull[i]);
        jonson = convex_hull(jonson, true);
        if(fk(jonson)) ani();
    }

    puts("Borna");
    return 0;
}