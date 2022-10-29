#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
using namespace std;
const int N = 1e5 + 1;
const double pi = acos(-1);
struct point{
    double x, y;
    point(double X = 0, double Y = 0) {
        x = X , y = Y;
    }
}a[N];
int n, m;
int f[N * 2][18];
struct node{
    double l, r;
    bool type;
}d[N * 2];
bool bz[N * 2];
point operator+(point a, point b){
    return point(a.x + b.x, a.y + b.y);
}
double sqr(double x) {
    return x * x;
}
bool check(double r) {
    int tot = 0;
    for (int i = 1;  i <= n ; i++) {
        double w = atan2(a[i].y, a[i].x);
        double v = acos(r / sqrt(sqr(a[i].x) + sqr(a[i].y)));
        d[++ tot].l = w - v;
        d[tot].r = w + v;
        d[tot].type = 0;
        d[++ tot].l = w - v + pi * 2;
        d[tot].r = w + v + pi * 2;
        d[tot].type = 1;
        bz[i] = 0;
    }
    sort(d + 1, d + tot  +1, [](node a , node b) {return a.type != b.type?a.type < b.type:a.l < b.l;});
    double mnr = 1e9;
    for (int i = tot; i ; i --)
        if (mnr > d[i].r) mnr = d[i].r;
        else
            bz[i] = 1;
    tot = 0;
    for (int i = 1; i <= n ; i ++) if (!bz[i]) d[++ tot] = d[i];
    for (int i = 1; i <= tot ; i ++) d[tot + i].l = d[i].l + 2 * pi, d[tot + i].r = d[i].r + 2 * pi;
    tot += tot;
    int j = 1;
    for (int i = 1; i <= tot; i ++) {
        while (j <= tot && d[j].l <= d[i].r) j ++;
        f[i][0] = j;
    }
    for (int i = 1; i <= 17; i ++)
        for (int j = 1; j <= tot; j ++)
            f[j][i] = f[f[j][i - 1]][i - 1];
    for (int i = 1; i <= tot / 2; i ++) {
        int x = i, y = m;
        for (int j = 17; y; j --)
            if (y >= (1 << j)) {
                y -= (1<<j);
                x = f[x][j];
            }
        if (!x || x >= i + tot / 2) return 1;
    }
    return 0;
}
int main()
{
    scanf("%d %d", &n, &m);
    double l = 0, r = 1e6, mid;
    for (int i = 1;  i<= n ;  i++)
        scanf("%lf %lf", &a[i].x, &a[i].y), r = min(r, sqrt(sqr(a[i].x) + sqr(a[i].y)));
    for (int i = 1; i <= 50; i ++)
        if (check(mid = (l + r) /2 )) l = mid;
        else
            r = mid;
    printf("%.10f\n", l);
    return 0;
}