#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

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
    void Rd() { cin >> x >> y;}
};

double det(pt a,pt b) { return a.x*b.y - a.y*b.x;}
double dot(pt a,pt b) { return a.x*b.x + a.y*b.y;}
int dblcmp(double x) { return x > eps ? 1 : x < -eps ? -1 : 0;}
double dis(pt a,pt b) { return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));}
double dis2(pt a,pt b) { return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));}
void swap(pt &a,pt &b) { pt t = a; a = b; b = t;}

int n;
double sum[99999 * 3];
pt pts[99999];

//
double poly_area(pt p[],int n)
{
    double ret = 0;
    for (int i = 1;i < n-1;++i)
        ret += det(p[i]-p[0],p[i+1]-p[0]);
    return ret;
}

//
double point_line_dis(pt x,pt a,pt b)
{
    return fabs(det(a-x,b-x) / dis(a,b));
}

/////////////
double area(int l,int r)
{
    if (r > l) return fabs(sum[r] - sum[l] + det(pts[r],pts[l]));
    return fabs(sum[r+n] - sum[l] + det(pts[r],pts[l]));
}

double triangle(pt x,pt a,pt b)
{
    return fabs(dot(b-a,x-a)/dis(b,a) * point_line_dis(x,a,b));
}

double get_corner_area(pt p[],int n)
{
    int bot = 0,rig = 0,lft = 0;
    for (int i = 0;i < n;++i)
    {
        if (p[i].y < p[bot].y)
            bot = i;
        if (p[i].x > p[rig].x)
            rig = i;
        if (p[i].x < p[lft].x)
            lft = i;
    }

    double ret = 1e20;
    for (int i = 0;i < n;++i,++bot)
    {
        while (dot(p[(bot+1)%n]-p[bot%n],p[(rig+1)%n]-p[bot%n]) > dot(p[(bot+1)%n]-p[bot%n],p[rig%n]-p[bot%n]))
            ++rig;
        while (dot(p[(bot+1)%n]-p[bot%n],p[(lft+1)%n]-p[bot%n]) < dot(p[(bot+1)%n]-p[bot%n],p[lft%n]-p[bot%n]))
            ++lft;
        ret = min(ret,triangle(p[rig%n],p[bot%n],p[(bot+1)%n]) - area(bot%n,rig%n));
        ret = min(ret,triangle(p[lft%n],p[(bot+1)%n],p[bot%n]) - area(lft%n,(bot+1)%n));
    }
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0;i < n;++i)
        pts[i].Rd();
    sum[0] = 0;
    if (poly_area(pts,n) < 0)
        reverse(pts,pts+n);
    for (int i = 0;i < 3 * n;++i)
        sum[i+1] = sum[i] + det(pts[i%n],pts[(i+1)%n]);
    printf("%.10f\n",get_corner_area(pts,n)/2.0);
    return 0;
}