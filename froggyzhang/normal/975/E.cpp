#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cctype>
#include <cassert>
#include <bitset>
#include <ctime>

using namespace std;

#define pau system("pause")
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define clr(a, x) memset(a, x, sizeof(a))

const long double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const long double EPS = 1e-9;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
tree<pli, null_type, greater<pli>, rb_tree_tag, tree_order_statistics_node_update> T;
*/

int n, q;
struct point {
    long double x, y;
    point() {}
    point (long double x, long double y) : x(x), y(y) {}
    void input() {
        //scanf("%lf%lf", &x, &y);
        cin >> x >> y;
    }
    void output() {
        double tx = x, ty = y;
        printf("%.12f %.12f\n", tx, ty);
    }
    point operator - (const point &p) const {
        return point(x - p.x, y - p.y);
    }
    point operator + (const point &p) const {
        return point(x + p.x, y + p.y);
    }
    long double operator ^ (const point &p) const {
        return x * p.y - y * p.x;
    }
    point operator / (const long double &k) const {
        return point(x / k, y / k);
    }
    point operator * (const long double &k) const {
        return point(x * k, y * k);
    }
    long double dis(const point &p) const {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
} p[100015];
long double d0[100015], d1[100015], th[100015];
long double cal_th(point p1, point p0, point p2) {
    long double th1 = atan2(p1.y - p0.y, p1.x - p0.x);
    long double th2 = atan2(p2.y - p0.y, p2.x - p0.x);
    long double res = th1 - th2;
    if (res < 0) res += 2 * pi;
    return res;
}
multiset<int> rem;
point get_pos(int index) {
    long double th1 = atan2(p[1].y - p[0].y, p[1].x - p[0].x);
    long double th2 = th1 - th[index];
    if (th2 < 0) th2 += 2 * pi;
    return p[0] + point(d0[index] * cos(th2), d0[index] * sin(th2));
}
void rot_and_update(int index2) {
    point p2 = get_pos(index2);
    long double th01 = atan2(p[0].y - p2.y, p[0].x - p2.x);
    long double th02 = 3 * pi / 2;
    long double th0 = th02 - th01;
    if (th0 < 0) th0 += 2 * pi;
    long double th11 = atan2(p[1].y - p2.y, p[1].x - p2.x);
    //p[0].output(), p[1].output(), p2.output();
    long double th12 = th11 + th0;
    if (2 * pi <= th12) th12 -= 2 * pi;
    //printf("index2 = %d\n", index2);
    p[0] = point(p2.x, p2.y - d0[index2]);
    p[1] = p2 + point(d1[index2] * cos(th12), d1[index2] * sin(th12));
}
void get_wp() {
    long double s = 0;
    p[0] = point(0, 0);
    for (int i = 2; i < n; ++i) {
        long double ts = (p[i] - p[1]) ^ (p[i] - p[i + 1]);
        p[0] = p[0] + (p[1] + p[i] + p[i + 1]) / 3 * ts;
        s += ts;
    }
    p[0] = p[0] / s;
}
int main() {
    scanf("%d%d", &n, &q);
    p[0] = point(0, 0);
    for (int i = 1; i <= n; ++i) {
        p[i].input();
    }
    get_wp();
    for (int i = 1; i <= n; ++i) {
        th[i] = cal_th(p[1], p[0], p[i]);
        d0[i] = p[0].dis(p[i]);
        d1[i] = p[1].dis(p[i]);
    }
    rem.insert(1), rem.insert(2);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (1 == op) {
            int f, t;
            scanf("%d%d", &f, &t);
            multiset<int>::iterator it = rem.lower_bound(f);
            rem.erase(it);
            int v = *rem.begin();
            rot_and_update(v);
            rem.insert(t);
        } else {
            int v;
            scanf("%d", &v);
            get_pos(v).output();
        }
    }
    return 0;
}
/*
10 10
0 -100000000
1 -100000000
1566 -99999999
2088 -99999997
2610 -99999994
3132 -99999990
3654 -99999985
4176 -99999979
4698 -99999972
5220 -99999964
1 2 5
2 1
1 1 7
2 5
1 5 4
1 4 2
2 8
1 7 9
2 1
1 2 10
*/