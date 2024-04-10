#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;
typedef pair<DB, DB> DPI;
const DB eps = 1e-8;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

struct Point{
    DB x, y;
    Point(){}
    Point(DB _x, DB _y){x = _x, y = _y;}
} p[4], o[4];
struct LINESEG{
    Point s, e;
    LINESEG(){}
    LINESEG(Point _s, Point _e){s = _s, e = _e;}
};

Point Rotate(Point p,double alpha,Point o) {
 Point tp;
 p.x-=o.x;
 p.y-=o.y;
 tp.x=p.x*cos(alpha)-p.y*sin(alpha)+o.x;
 tp.y=p.y*cos(alpha)+p.x*sin(alpha)+o.y;
 return tp;
}

bool c(Point a, Point b, Point c, Point d){
    return fabs((a.x - b.x) * (c.y - d.y) - (c.x - d.x) * (a.y - b.y)) < eps;
}

DB dis(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
vector <DB> v;
bool check(Point a, Point b, Point c, Point d){
    v.clear();
    v.PB(dis(a, b)); v.PB(dis(a, c)); v.PB(dis(a, d));
    v.PB(dis(b, c)); v.PB(dis(b, d));
    v.PB(dis(c, d));
    sort(v.begin(), v.end());
    if (fabs(v[0] - v[1]) < eps && fabs(v[1] - v[2]) < eps && fabs(v[2] - v[3]) < eps
        && fabs(v[4] - v[5]) < eps && fabs(v[5] - v[0] * sqrt(2)) < eps) return 1;
    return 0;
}

bool EQ(Point a, Point b){
    return fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps;
}
const DB pi = acos(-1.0);
int main(){
    int cas;
    scanf("%d", &cas);
    while (cas--){
        for (int i = 0; i < 4; i++) scanf("%lf%lf%lf%lf", &p[i].x, &p[i].y, &o[i].x, &o[i].y);
        int ans = INF;
        for (int i1 = 0; i1 < 4; i1++)
        for (int i2 = 0; i2 < 4; i2++)
        for (int i3 = 0; i3 < 4; i3++)
        for (int i4 = 0; i4 < 4; i4++){
            Point p0 = Rotate(p[0], i1 * pi / 2, o[0]);
            Point p1 = Rotate(p[1], i2 * pi / 2, o[1]);
            Point p2 = Rotate(p[2], i3 * pi / 2, o[2]);
            Point p3 = Rotate(p[3], i4 * pi / 2, o[3]);
            if (!EQ(p0, p1) && !EQ(p0, p2) && !EQ(p0, p3) && !EQ(p1, p2) && !EQ(p1, p3) && !EQ(p2, p3))
                if (check(p0, p1, p2, p3)) ans = min(ans, i1 + i2 + i3 + i4);

        }
        if (ans == INF) puts("-1"); else printf("%d\n", ans);
    }
}