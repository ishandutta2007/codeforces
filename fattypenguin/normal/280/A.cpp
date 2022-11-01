#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const double eps = 1e-8,
             pi  = 3.141592653;

#define REP(i,n) for(int i=0;i<n;i++)
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
    return ret;
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
pt rotate(pt p, double angle) {
	pt ret = pt(p.x*cos(angle)-p.y*sin(angle), p.x*sin(angle)+p.y*cos(angle));
	return ret;
}

pt t1[50000], t2[5000], t3[5000];

int main() {
	double w, h, a;
	cin >> w >> h >> a;
	int n = 4;
	t1[0] = pt(w/2, h/2);
	t1[1] = pt(-w/2, h/2);
	t1[2] = pt(-w/2, -h/2);
	t1[3] = pt(w/2, -h/2);

	REP(i, 4) t2[i] = rotate(t1[i], a / 180.0 * pi);
	REP(i, 4) half_plane_its(t1, n, t2[i], t2[(i+1)%4], t3);

	double area = poly_area(t1, n);
	area = fabs(area) / 2.0;
	printf("%.10f\n", area);
	return 0;
}