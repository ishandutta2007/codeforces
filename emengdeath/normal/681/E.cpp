#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 200001;
const long double eps = 1e-13;
const long double pi = acos(-1);
struct point
{
    long double x, y;
    point(long double X = 0, long double Y = 0)
    {
        x = X, y = Y;
    }
    point operator + (point b)
    {
        return point(this->x + b.x, this->y + b.y);
    }

    point operator - (point b)
    {
        return point(this->x - b.x, this->y - b.y);
    }

    point operator * (long double b)
    {
        return point(this->x * b, this->y * b);
    }

    point operator / (long double b)
    {
        return point(this->x / b, this->y / b);
    }

    bool operator == (point b)
    {
        return fabs(b.x - this->x) < eps && fabs(b.y - this->y) < eps;
    }
}o;
struct seg
{
    long double l, r;
    seg(long double L = 0, long double R = 0)
    {
        l = L, r = R;
    }
}a_s[N * 2];
long double V, T;
long double R;
int n, tot;
point rotate(point a, long double w)
{
    return point(a.x * cos(w) - a.y * sin(w), a.x * sin(w) + a.y * cos(w));
}
long double sqr(long double x)
{
    return x * x;
}
long double dis(point a, point b)
{
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

long double dis_2(point a, point b)
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}
pair<point, point> point_cut_circle(point a, point b, long double r_b)
{
    long double dis_a_b = dis(a, b);
    long double w = acos(r_b / dis_a_b);
    a = (a - b) / dis_a_b;
    return make_pair(rotate(a, w) * r_b + b, rotate(a, -w) * r_b + b);
}

pair<point, point> circle_intersaction(point a, long double r_a,  point b, long double r_b)
{
    long double dis_a_b = dis(a, b);
    long double w = acos((sqr(dis_a_b) + sqr(r_b) - sqr(r_a))/ (2 * dis_a_b * r_b));
    a = (a - b) / dis_a_b;
    return make_pair(rotate(a, w) * r_b + b, rotate(a, -w) * r_b + b);
}
long double did(long double x)
{
    while (x >= pi * 2) x -= pi * 2;
    while (x < 0) x += pi * 2;
    return x;
}
void work(point a, long double r)
{
    if (dis(a, o)>= r + R - eps) return;
    pair<point, point> u = point_cut_circle(o, a, r);
    if (dis(a, o) <= R - r + eps )
    {
        u.first = u.first - o;
        u.second = u.second - o;
        if (u.first == u.second) return;
        long double w1 = did(atan2(u.first.y, u.first.x));
        long double w2 = did(atan2(u.second.y, u.second.x));
        if (w1 > w2)
        {
            a_s[++tot] = seg(w1, pi * 2);
            a_s[++tot] = seg(0, w2);
        } else
            a_s[++tot] = seg(w1, w2);
        return;
    }
    pair<point, point> v = circle_intersaction(o, R, a, r);
    if (dis(u.first, o) > dis(v.first, o)) u.first = v.first;
    if (dis(u.second, o) > dis(v.second, o)) u.second = v.second;

    u.first = u.first - o;
    u.second = u.second - o;
    if (u.first == u.second) return;
    long double w1 = did(atan2(u.first.y, u.first.x));
    long double w2 = did(atan2(u.second.y, u.second.x));

    if (w1 > w2)
    {
        a_s[++tot] = seg(w1, pi * 2);
        a_s[++tot] = seg(0, w2);
    } else
        a_s[++tot] = seg(w1, w2);
}
bool cmp(const seg &a, const seg &b)
{
    return a.l < b.l;
}
inline bool scan_d(int &num)
{
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
        num*=10,num+=in-'0';
    }
    if(IsN) num=-num;
    return true;
}
int main()
{
    int x;
    scan_d(x);
    o.x = x;
    scan_d(x);
    o.y = x;
    scan_d(x);
    V = x;
    scan_d(x);
    T = x;
    scan_d(x);
    n = x;
    R = V * T;
    long double ans = 0;
    for (int i = 1;i <= n ; i ++)
    {
        point a;
        long double r;
        scan_d(x);
        a.x = x;
        scan_d(x);
        a.y = x;
        scan_d(x);
        r = x;
        if (dis_2(a, o) <= r * r)
            ans = 1;
        else
            if (ans != 1)
                work(a, r);
    }
    if (ans == 1)
    {
        printf("1");
        return 0;
    }
    long double r = -1, l = a_s[1].l;
    sort(a_s + 1, a_s + tot + 1, cmp);
    for (int i = 1; i <= tot;  i ++) {
        if (r < a_s[i].l) {
            if (r - l >= 0)
                ans += r - l ;
            l = a_s[i].l;
        }
        r = max(r, a_s[i].r);
    }
    if (tot > 0)
        ans += r - l;
    printf("%.10f\n", (double)(ans /  pi / 2));
    return 0;
}