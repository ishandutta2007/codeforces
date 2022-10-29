#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int N = 100001;
const double eps = 1e-8;
struct point
{
    double x, y;
    point(double X = 0, double Y = 0)
    {
        x = X , y = Y;
    }
    point operator+(point a)
    {
        return point(this->x + a.x, this->y + a.y);
    }
    point operator-(point a)
    {
        return point(this->x - a.x, this->y - a.y);
    }
    point operator*(double a)
    {
        return point(this->x * a, this->y * a);
    }
    double operator*(point a)
    {
        return this->x * a.y - this->y * a.x;
    }
    bool operator==(point a)
    {
        return fabs(a.x - this->x) <= eps && fabs(a.y - this->y)<=eps;
    }
    bool operator!=(point a)
    {
        return fabs(a.x - this->x) > eps || fabs(a.y - this->y)>eps;
    }
    bool operator>=(point a)
    {
        return this->x >= a.x - eps && this->y >= a.y - eps;
    }
}a[N], d[N], b;
int n;
bool cmp(const point&a,const point&b){
    if (a.y==b.y)return a.x<b.x;
    return a.y<b.y;
}
double cross(point a, point b, point c)
{
    return (b - a) * (c - a);
}

int tot;
void granham() {
    sort(a + 1, a + n + 1, cmp);
    int nn = n;
    n = 1;
    for (int i = 2; i <= nn ; i ++)
        if (a[i] != a[n])
            a[++n] = a[i];
    tot = 1;
    d[1] = a[1];
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i - 1]) {
            while (tot >= 2 && cross(d[tot - 1], d[tot], a[i]) <= eps)tot--;
            d[++tot] = a[i];
        }
    if (n > 1) {
        int len = tot;
        d[++tot] = a[n - 1];
        for (int i = n - 2; i; i--)
            if (a[i] != a[i + 1]) {
                while (len != tot && cross(d[tot - 1], d[tot], a[i]) <= eps)tot--;
                d[++tot] = a[i];
            }
    }
    if (tot != 1)tot --;
}
bool check(double mid)
{
    if (mid < 5){
        int xx;
        xx = 0;
    }
    for (int i = 1;  i<= tot;  i++)
        a[i] = d[i] * mid;
    for (int i = 1; i <= tot; i ++) {
        if (a[i] >= b) return 1;
        if (tot != 1)
        {
            if (cross(a[i], a[i % tot + 1], b) > -eps && cross(a[i % tot + 1], point(0, 0), b) > -eps && cross(point(0, 0), a[i], b) > -eps)
                return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d %lf %lf", &n, &b.x, &b.y);
    for (int i = 1; i <= n ; i ++)
        scanf("%lf %lf", &a[i].x, &a[i].y);

    granham();
    double l = 0, r = 1e9, mid;
    while (l + eps < r)
    {
        if (check(mid = (l + r) / 2)) r = mid;
        else
            l = mid;
    }
    printf("%.7f", l);
    return 0;
}