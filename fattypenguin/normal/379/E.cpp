#include <functional>
#include <algorithm>
#include <tr1/unordered_map>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

using namespace std;

const double eps = 1e-8,
             pi  = 3.141592653;

struct pt
{
    double x,y;
    pt(double _x = 0,double _y = 0) { x = _x; y = _y;}
    pt operator + (const pt &p) const { return pt(x+p.x,y+p.y);}
    pt operator - (const pt &p) const { return pt(x-p.x,y-p.y);}
    pt operator * (const double p) const { return pt(p*x,p*y);}
    /*  */
    bool operator < (const pt &p) const
    {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    void Rd() { scanf("%lf%lf",&x,&y);}
} sort_base;

double det(pt a,pt b) { return a.x*b.y - a.y*b.x;}
double dot(pt a,pt b) { return a.x*b.x + a.y*b.y;}
int dblcmp(double x) { return x > eps ? 1 : x < -eps ? -1 : 0;}
double dis(pt a,pt b) { return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));}
double dis2(pt a,pt b) { return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));}
void swap(pt &a,pt &b) { pt t = a; a = b; b = t;}

//compare

bool cmp_angle(const pt &a,const pt &b)
{
    if (dblcmp(a.y*b.y) < 0) return a.y > b.y;
    if (dblcmp(det(a-sort_base,b-sort_base)) != 0) return dblcmp(det(a-sort_base,b-sort_base)) > 0;
    return dblcmp(dis(a,sort_base) - dis(b,sort_base)) < 0;
}

bool cmp_cord(const pt &a,const pt &b)
{
    if (dblcmp(a.y-b.y) != 0) return dblcmp(a.y-b.y) < 0;
    return dblcmp(a.x-b.x) < 0;
}

//line operations

bool line_seg_cross(pt a,pt b,pt c,pt d) // a,b : Line    c,d : Segment
{
    int d1 = dblcmp(det(c-a,b-a)),
        d2 = dblcmp(det(d-a,b-a));
    if (d1 * d2 <= 0) return true;
    return false;
}

bool res_line_seg_cross(pt a,pt b,pt c,pt d) // a,b : Line    c,d : Segment
{
    int d1 = dblcmp(det(c-a,b-a)),
        d2 = dblcmp(det(d-a,b-a));
    if (d1 * d2 < 0) return true;
    return false;
}

// without whole line
bool line_line_cross(pt a,pt b,pt c,pt d)
{
    return dblcmp(det(b-a,d-c)) ? true : false;
}

bool res_cross(pt a,pt b,pt c,pt d)
{
    int d1 = dblcmp(det(a-c,d-c)),
        d2 = dblcmp(det(b-c,d-c)),
        d3 = dblcmp(det(c-a,b-a)),
        d4 = dblcmp(det(d-a,b-a));

    if (d1*d2 == -1 && d3*d4 == -1)
        return true;

    return false;
}

bool cross(pt a,pt b,pt c,pt d)
{
    int d1 = dblcmp(det(a-c,d-c)),
        d2 = dblcmp(det(b-c,d-c)),
        d3 = dblcmp(det(c-a,b-a)),
        d4 = dblcmp(det(d-a,b-a));

    if (d1*d2 == -1 && d3*d4 == -1)
        return true;

    if (!d1 && dblcmp(dot(a-c,a-d)) <= 0) return true;
    if (!d2 && dblcmp(dot(b-c,b-d)) <= 0) return true;
    if (!d3 && dblcmp(dot(c-a,c-b)) <= 0) return true;
    if (!d4 && dblcmp(dot(d-a,d-b)) <= 0) return true;

    return false;
}

pt cross_point(pt a,pt b,pt c,pt d)
{
    double p = det(b-a,a-d)/det(b-a,c-d);
    pt ret = d;
    ret.x += (c.x-d.x)*p;
    ret.y += (c.y-d.y)*p;
    return ret;
}

//
bool is_convex(pt p[],int n)
{
  int s[3] = {1,1,1};  // from ISun orz..
  for (int i = 0;i < n;++i)
        s[dblcmp(det(p[(i+1)%n]-p[i],p[(i+2)%n]-p[i]))] = 0;
    return s[1] | s[2];
}

//
bool is_in_convex(pt p[],pt x,int n)
{
  int s[3] = {1,1,1};  // from ISun orz..
  for (int i = 0;i < n;++i)
        s[dblcmp(det(p[i]-x,p[(i+1)%n]-x))] = 0;
    return s[1] | s[2];
}

//
double point_line_dis(pt x,pt a,pt b)
{
    return fabs(det(a-x,b-x) / dis(a,b));
}

//
double point_seg_dis(pt x,pt a,pt b)
{
    pt dir = b - a;
    pt t(x.x - dir.y,x.y + dir.x);
    if (dblcmp(det(x-t,a-t) * det(x-t,b-t)) > 0)
        return min(dis(a,x),dis(b,x));
    return point_line_dis(x,a,b);
}

//
double seg_seg_dis(pt a,pt b,pt c,pt d)
{
    return min(min(point_seg_dis(a,c,d),point_seg_dis(b,c,d)),min(point_seg_dis(c,a,b),point_seg_dis(d,a,b)));
}

//
void make_convex_hull(pt p[],int n,int *s,int &top)
{
    top = 0;
    sort(p,p+n,cmp_cord);
    for (int i = 0;i < n;++i)
    {
        while (top > 1 && dblcmp(det(p[s[top-1]] - p[s[top-2]],p[i] - p[s[top-2]])) < 0) --top;
        s[top++] = i;
    }
    int mid = top;
    for (int i = n-2;i >= 0;--i)
    {
        while (top > mid && dblcmp(det(p[s[top-1]] - p[s[top-2]],p[i] - p[s[top-2]])) < 0) --top;
        s[top++] = i;
    }
    --top;
}

//
void make_convex_hull_pt(pt p[],int n,pt s[],int &top)
{
    top = 0;
    sort(p,p+n,cmp_cord);
    for (int i = 0;i < n;++i)
    {
        while (top > 1 && dblcmp(det(s[top-1] - s[top-2],p[i] - s[top-2])) < 0) --top;
        s[top++] = p[i];
    }
    int mid = top;
    for (int i = n-2;i >= 0;--i)
    {
        while (top > mid && dblcmp(det(s[top-1] - s[top-2],p[i] - s[top-2])) < 0) --top;
        s[top++] = p[i];
    }
    --top;
}

//
void make_convex_hull_strict(pt p[],int n,int *s,int &top)
{
    top = 0;
    sort(p,p+n,cmp_cord);
    for (int i = 0;i < n;++i)
    {
        while (top > 1 && dblcmp(det(p[s[top-1]] - p[s[top-2]],p[i] - p[s[top-2]])) < 0) --top;
        s[top++] = i;
    }
    int mid = top;
    for (int i = n-2;i >= 0;--i)
    {
        while (top > mid && dblcmp(det(p[s[top-1]] - p[s[top-2]],p[i] - p[s[top-2]])) <= 0) --top;
        s[top++] = i;
    }
    --top;
}

//
void make_convex_hull_pt_strict(pt p[],int n,pt s[],int &top)
{
    top = 0;
    sort(p,p+n,cmp_cord);
    for (int i = 0;i < n;++i)
    {
        while (top > 1 && dblcmp(det(s[top-1] - s[top-2],p[i] - s[top-2])) <= 0) --top;
        s[top++] = p[i];
    }
    int mid = top;
    for (int i = n-2;i >= 0;--i)
    {
        while (top > mid && dblcmp(det(s[top-1] - s[top-2],p[i] - s[top-2])) <= 0) --top;
        s[top++] = p[i];
    }
    --top;
}

//
double poly_circumference(pt p[],int n)
{
    double ret = 0;
    for (int i = 0;i < n;++i)
        ret += dis(p[i],p[(i+1)%n]);
    return ret;
}

//
double poly_area(pt p[],int n)
{
    double ret = 0;
    for (int i = 1;i < n-1;++i)
        ret += det(p[i]-p[0],p[i+1]-p[0]);
    return ret * 0.5;
}

//
//vector < a -> b > left side O(N^2)
void half_plane_its(pt p[],int &n,pt a,pt b,pt tmp[])
{
    int tot = 0;
    for (int i = 0;i < n;++i)
    {
        int now = dblcmp(det(b-a,p[i]-a)),
            next = dblcmp(det(b-a,p[(i+1)%n]-a));
        if (now >= 0)
            tmp[tot++] = p[i];
        if (now * next < 0)
            tmp[tot++] = cross_point(a,b,p[i],p[(i+1)%n]);
    }
    n = tot;
    for (int i = 0;i < n;++i)
        p[i] = tmp[i];
}

//following code is written By iSun
//
pt circumcenter(pt a, pt b, pt c)
{
  pt u1, u2, v1, v2;
  u1.x = (a.x+b.x)/2;
  u1.y = (a.y+b.y)/2;
  u2.x = u1.x-a.y+b.y;
  u2.y = u1.y+a.x-b.x;
  v1.x = (a.x+c.x)/2;
  v1.y = (a.y+c.y)/2;
  v2.x = v1.x-a.y+c.y;
  v2.y = v1.y+a.x-c.x;
  return cross_point(u1, u2, v1, v2);
}

//
pt incenter(pt a, pt b, pt c)
{
  pt u1, u2, v1, v2;
  double m, n;
  u1 = a;
  m = atan2(b.y-a.y, b.x-a.x);
  n = atan2(c.y-a.y, c.x-a.x);
  u2.x = u1.x + cos((m+n)/2);
  u2.y = u1.y + sin((m+n)/2);
  v1 = b;
  m = atan2(a.y-b.y, a.x-b.x);
  n = atan2(c.y-b.y, c.x-b.x);
  v2.x = v1.x + cos((m+n)/2);
  v2.y = v1.y + sin((m+n)/2);
  return cross_point(u1, u2, v1, v2);
}


//
pt perpencenter(pt a, pt b, pt c)
{
  pt u1, u2, v1, v2;
  u1 = c;
  u2.x = u1.x-a.y+b.y;
  u2.y = u1.y+a.x-b.x;
  v1 = b;
  v2.x = v1.x-a.y+c.y;
  v2.y = v1.y+a.x-c.x;
  return cross_point(u1, u2, v1, v2);
}

//
//
//
pt barycenter(pt a, pt b, pt c)
{
  pt ret;
  ret.x = (a.x + b.x + c.x) / 3;
  ret.y = (a.y + b.y + c.y) / 3;
  return ret;
}

//
//
pt fermentpoint(pt a, pt b, pt c)
{
  pt u, v;
  double step = fabs(a.x)+fabs(a.y)+fabs(b.x)+fabs(b.y)+fabs(c.x)+fabs(c.y);
  int i, j, k;
  u.x = (a.x+b.x+c.x)/3;
  u.y = (a.y+b.y+c.y)/3;
  while (step > 1e-10)
  {
    for (k = 0; k < 10; step/=2, k++)
    for (i = -1; i <= 1; i++)
    for (j = -1; j <= 1; j++)
    {
      v.x = u.x + step*i;
      v.y = u.y + step*j;
      if (dis(u,a) + dis(u,b) + dis(u,c) > dis(v,a) + dis(v,b) + dis(v,c))
        u = v;
    }
  }
  return u;
}


//,
//
void intersection_line_circle(pt c, double r, pt l1, pt l2, pt &p1, pt &p2)
{
  pt p = c;
  p.x += l1.y - l2.y;
  p.y += l2.x - l1.x;
  p = cross_point(p, c, l1, l2);
  double d = dis(p,c), t = sqrt(r*r - d*d) / dis(l1,l2);
  p2.x = p.x + (l2.x-l1.x)*t;
  p2.y = p.y + (l2.y-l1.y)*t;
  p1.x = p.x - (l2.x-l1.x)*t;
  p1.y = p.y - (l2.y-l1.y)*t;
}


//,,
void intersection_circle_circle(pt c1, double r1, pt c2, double r2, pt &p1, pt &p2)
{
  pt u, v;
  double t = (1+(r1*r1-r2*r2)/dis(c1,c2)/dis(c1,c2))/2;
  u.x = c1.x + (c2.x-c1.x)*t;
  u.y = c1.y + (c2.y-c1.y)*t;
  v.x = u.x + c1.y - c2.y;
  v.y = u.y - c1.x + c2.x;
  intersection_line_circle(c1, r1, u, v, p1, p2);
}


//

//
void find_tp(double a, double b, double c, double &ang1, double &ang2)
{
  double v1, v2;
  v1 = fabs(c) > eps ? atan2(b*c, a*c) : atan2(b, a);
  v2 = acos(fabs(c)/sqrt(a*a+b*b));
  ang1 = v1 - v2;
  ang2 = v1 + v2;
}

//(t1 t2)
void tangent1(pt c1, double r1, pt c2, double r2, double &t1, double &t2)
{
  find_tp(c2.x-c1.x, c2.y-c1.y, r1-r2, t1, t2);
}

//(t1 t2c1,c2()PI)
void tangent2(pt c1, double r1, pt c2, double r2, double &t1, double &t2)
{
  find_tp(c2.x-c1.x, c2.y-c1.y, r1+r2, t1, t2);
}

//by sheep
//

//convex diameter
double convex_diameter_rc(pt p[],int n)
{
    int now = 1;
    double ret = 0.00;
    for (int i = 0;i < n;++i)
    {
        while (det(p[(i+1)%n]-p[i],p[now%n]-p[i]) < det(p[(i+1)%n]-p[i],p[(now+1)%n]-p[i])) ++now;
        ret = max(ret,max(dis2(p[now%n],p[i]),dis2(p[now%n],p[(i+1)%n])));
        if (dblcmp(det(p[(i+1)%n]-p[i],p[now%n]-p[i]) - det(p[(i+1)%n]-p[i],p[(now+1)%n]-p[i])) == 0)
            ret = max(ret,max(dis2(p[(now+1)%n],p[i]),dis2(p[(now+1)%n],p[(i+1)%n])));
    }
    return ret;
}

//convex width
double convex_width_rc(pt p[],int n)
{
    int now = 1;
    double ret = 1e10;
    for (int i = 0;i < n;++i)
    {
        while (det(p[(i+1)%n] - p[i],p[now%n] - p[i]) < det(p[(i+1)%n] - p[i],p[(now+1)%n] - p[i])) ++now;
        ret = min(ret,point_line_dis(p[now%n],p[i],p[(i+1)%n]));
    }
    return ret;
}

//the minimum distance of two convex
//pq

//
double min_dist_two_convex_process_rc(pt p[],int n,pt q[],int m)
{
    double ret = 1e10;
    int pp = 0,qq = 0;
    for (int i = 0;i < n;++i)
        if (p[i].y < p[pp].y)
            pp = i;
    for (int i = 0;i < m;++i)
        if (q[i].y > q[qq].y)
            qq = i;
    for (int i = 0;i < n;++i,++pp)
    {
        while (det(p[(pp+1)%n] - p[pp%n],q[(qq+1)%m] - p[pp%n]) > det(p[(pp+1)%n] - p[pp%n],q[qq%m] - p[pp%n]))
            ++ qq;
        if (dblcmp(det(p[(pp+1)%n] - p[pp%n],q[(qq+1)%m] - p[pp%n]) - det(p[(pp+1)%n] - p[pp%n],q[qq%m] - p[pp%n])) != 0)
            ret = min(ret,point_seg_dis(q[qq%m],p[pp%n],p[(pp+1)%n]));
        else
            ret = min(ret,seg_seg_dis(p[pp%n],p[(pp+1)%n],q[qq%m],q[(qq+1)%m]));
    }
    return ret;
}

double min_dist_two_convex(pt p[],int n,pt q[],int m)
{
    return min(min_dist_two_convex_process_rc(p,n,q,m),min_dist_two_convex_process_rc(q,m,p,n));
}

int n, k;
double ys[555][555];
double result[555];

pt l[555], r[555];
pt hull[1000000], temp[1000000];

int main()
{
  cin >> n >> k;
  REP(i, n) {
    REP(j, k + 1) scanf("%lf", &ys[i][j]);
  }
  REP(i, k) {
    REP(j, n) {
      l[j] = pt(i, ys[j][i]);
      r[j] = pt(i + 1, ys[j][i + 1]);
    }
    int count = 4;
    hull[0] = pt(i, 0);
    hull[1] = pt(i + 1, 0);
    hull[2] = pt(i + 1, 1500);
    hull[3] = pt(i, 1500);

    double lastArea = fabs(poly_area(hull, count));
    REP(j, n) {
      half_plane_its(hull, count, l[j], r[j], temp);
      // REP(x, count) cout << hull[x].x << " " << hull[x].y << endl;
      double currentArea = fabs(poly_area(hull, count));
      result[j] += lastArea - currentArea;
      // cout << "delta = " << lastArea - currentArea << endl;
      lastArea = currentArea;
    }
  }
  REP(i, n) {
    printf("%.10f\n", result[i]);
  }
  return 0;
}