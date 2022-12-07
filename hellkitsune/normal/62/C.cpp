#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

struct Ev {
    double pos;
    bool st;
    Ev(double pos, bool st) : pos(pos), st(st) {}
};

int n;
double x[100][3], y[100][3];
const double EPS = 1e-9;


bool segSeg(double x1, double y1, double xx1, double yy1, double x2, double y2, double xx2, double yy2, double &ix, double &iy) {
    double a1 = y1 - yy1;
    double b1 = xx1 - x1;
    double c1 = a1 * x1 + b1 * y1; //minus c
    double a2 = y2 - yy2;
    double b2 = xx2 - x2;
    double c2 = a2 * x2 + b2 * y2; //minus c;
    double det = a1 * b2 - a2 * b1;
    if (abs(det) < EPS) return false;
    ix = (c1 * b2 - c2 * b1) / det;
    iy = (a1 * c2 - a2 * c1) / det;
    if (x1 > xx1) swap(x1, xx1);
    if (x2 > xx2) swap(x2, xx2);
    if (y1 > yy1) swap(y1, yy1);
    if (y2 > yy2) swap(y2, yy2);
    if (ix < x1 - EPS || ix < x2 - EPS || ix > xx1 + EPS || ix > xx2 + EPS) return false;
    if (iy < y1 - EPS || iy < y2 - EPS || iy > yy1 + EPS || iy > yy2 + EPS) return false;
    return true;
}

double prod(double x, double y, double xx, double yy) {
    return x * yy - xx * y;
}

bool inside(double x, double y, double x1, double y1, double x2, double y2, double x3, double y3) {
    double s = fabs(prod(x2 - x1, y2 - y1, x3 - x1, y3 - y1));
    double t = fabs(prod(x1 - x, y1 - y, x2 - x, y2 - y));
    t += fabs(prod(x2 - x, y2 - y, x3 - x, y3 - y));
    t += fabs(prod(x3 - x, y3 - y, x1 - x, y1 - y));
    return fabs(t - s) < EPS;
}

double getDist(double dx, double dy) {
    return sqrt(dx * dx + dy * dy);
}

bool cmp(const Ev &lhs, const Ev &rhs) {
    return lhs.pos < rhs.pos;
}

vector<Ev> ev;
vector<PDD> v;

int main() {
    scanf("%d", &n);
    REP(i, n) REP(j, 3) {
        scanf("%lf%lf", x[i] + j, y[i] + j);
    }
    double ans = 0;
    REP(i, n) REP(j, 3) {
        double sx = x[i][j], sy = y[i][j];
        double tx = x[i][(j + 1) % 3], ty = y[i][(j + 1) % 3];
        ev.clear();
        bool ok = true;
        REP(j, n) if (j != i) {
            bool sIns = inside(sx, sy, x[j][0], y[j][0], x[j][1], y[j][1], x[j][2], y[j][2]);
            bool tIns = inside(tx, ty, x[j][0], y[j][0], x[j][1], y[j][1], x[j][2], y[j][2]);
            if (sIns && tIns) {
                ok = false;
                break;
            }
            double ix, iy;
            v.clear();
            if (segSeg(x[j][0], y[j][0], x[j][1], y[j][1], sx, sy, tx, ty, ix, iy)) {
                v.pb(mp(ix, iy));
            }
            if (segSeg(x[j][1], y[j][1], x[j][2], y[j][2], sx, sy, tx, ty, ix, iy)) {
                v.pb(mp(ix, iy));
            }
            if (segSeg(x[j][2], y[j][2], x[j][0], y[j][0], sx, sy, tx, ty, ix, iy)) {
                v.pb(mp(ix, iy));
            }
            vector<double> pos;
            for (PDD p : v) {
                if (abs(sx - tx) > abs(sy - ty)) {
                    pos.pb((p.first - sx) / (tx - sx));
                } else {
                    pos.pb((p.second - sy) / (ty - sy));
                }
            }
            if (sIns) pos.pb(0);
            if (tIns) pos.pb(1);
            if ((int)pos.size() > 1) {
                sort(pos.begin(), pos.end());
                ev.pb(Ev(pos[0], true));
                ev.pb(Ev(pos.back(), false));
            }
        }
        if (!ok) continue;
        sort(ev.begin(), ev.end(), cmp);
        double dist = 1;
        double pre = 0;
        int bal = 0;
        for (Ev e : ev) {
            if (bal > 0) {
                dist -= e.pos - pre;
            }
            pre = e.pos;
            if (e.st) ++bal;
            else --bal;
        }
        dist *= getDist(tx - sx, ty - sy);
        ans += dist;
    }
    printf("%.12f\n", ans);
    return 0;
}