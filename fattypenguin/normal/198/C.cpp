#include <functional>
#include <algorithm>
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

const double eps = 1e-8;

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

const double pi  = acos(-1);

struct pt
{
    double x,y;
    pt(double _x = 0,double _y = 0) { x = _x; y = _y;}
    pt operator + (const pt &p) const { return pt(x+p.x,y+p.y);}
    pt operator - (const pt &p) const { return pt(x-p.x,y-p.y);}
    pt operator * (const double p) const { return pt(p*x,p*y);}
    void Rd() { scanf("%lf%lf",&x,&y);}
} sort_base;

double det(pt a,pt b) { return a.x*b.y - a.y*b.x;}
double dot(pt a,pt b) { return a.x*b.x + a.y*b.y;}
int dblcmp(double x) { return x > eps ? 1 : x < -eps ? -1 : 0;}
double dis(pt a,pt b) { return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));}
double vlen(pt x) { return dis(pt(0, 0), x); }
double dis2(pt a,pt b) { return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));}
double vlen2(pt x) { return dis2(pt(0, 0), x); }
void swap(pt &a,pt &b) { pt t = a; a = b; b = t;}

pt cross_point(pt a,pt b,pt c,pt d)
{
    double p = det(b-a,a-d)/det(b-a,c-d);
    pt ret = d;
    ret.x += (c.x-d.x)*p;
    ret.y += (c.y-d.y)*p;
    return ret;
}

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
double point_line_dis(pt x,pt a,pt b)
{
    return fabs(det(a-x,b-x) / dis(a,b));
}

double fix(double x)
{
    if (x < -eps) return x + pi;
    if (x > pi-eps) return x - pi;
    return x;
}

int main()
{

    double xp, yp, vp;
    double x, y, v, R;
    cin >> xp >> yp >> vp;
    cin >> x >> y >> v >> R;

    double r = sqrt(xp*xp + yp*yp);
    double av = vp / r,
           a0 = atan2(yp, xp);

    double mi = 0, ma = 1e10;
    double tt;
    for (int cnt = 0; cnt < 100; ++cnt)
    {
        double mid = (mi+ma)/2;

        bool ok = false;
        double nx = r*cos(a0 + mid*av),
               ny = r*sin(a0 + mid*av);

        pt p1(nx, ny), p2(x, y);

        if (!dblcmp(nx-x)&&!dblcmp(ny-y))
        {
            ok = true;
        }
        else
        {
            if ( dblcmp(dot(pt(0, 0) - p1, p2 - p1)) <= 0 || dblcmp(dot(pt(0, 0) - p2, p1 - p2)) <= 0
                || dblcmp(point_line_dis(pt(0,0), pt(nx,ny), pt(x, y)) - R) >= 0)
            {
                if (dblcmp(dis(p1, p2)  - mid * v) <= 0)
                    ok = true;
            }
            else
            {
                double d1 = sqrt(vlen2(p1)-R*R),
                       d2 = sqrt(vlen2(p2)-R*R);
                double d = d1 + d2;

                pt p, q, r, s;
                intersection_circle_circle(p1, d1, pt(0, 0), R, p, q);
                intersection_circle_circle(p2, d2, pt(0, 0), R, r, s);

                p = p * (1.0 / R);
                q = q * (1.0 / R);
                r = r * (1.0 / R);
                s = s * (1.0 / R);

                double angle = 1e50;
                angle = min(angle, acos(dot(p, r)));
                angle = min(angle, acos(dot(p, s)));
                angle = min(angle, acos(dot(q, r)));
                angle = min(angle, acos(dot(q, s)));

                d += angle * R;

                if (dblcmp(d - mid * v) <= 0)
                    ok = true;
            }
        }

        if (ok)
        {
            ma = mid;
            tt = mid;
        } else mi = mid;
    }

    printf("%.10f\n", tt);
    return 0;
}