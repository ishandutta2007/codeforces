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

struct pt
{
    double x,y;
    pt(double _x = 0,double _y = 0) { x = _x; y = _y;}
    pt operator + (const pt &p) const { return pt(x+p.x,y+p.y);}
    pt operator - (const pt &p) const { return pt(x-p.x,y-p.y);}
    pt operator * (const double p) const { return pt(p*x,p*y);}
    void Rd() { scanf("%lf%lf",&x,&y);}

    pt turn() {
        return pt(-y, x);
    }
} sort_base;

double det(pt a,pt b) { return a.x*b.y - a.y*b.x;}
double dot(pt a,pt b) { return a.x*b.x + a.y*b.y;}
int dblcmp(double x) { return x > eps ? 1 : x < -eps ? -1 : 0;}
double dis(pt a,pt b) { return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));}
double dis2(pt a,pt b) { return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));}

//
double point_line_dis(pt x,pt a,pt b)
{
    return fabs(det(a-x,b-x) / dis(a,b));
}

pt cross_point(pt a,pt b,pt c,pt d)
{
    double p = det(b-a,a-d)/det(b-a,c-d);
    pt ret = d;
    ret.x += (c.x-d.x)*p;
    ret.y += (c.y-d.y)*p;
    return ret;
}

int main() {
    double y1, y2, yw, xb, yb, r;
    cin >> y1 >> y2 >> yw >> xb >> yb >> r;

    yw -= r;

    y1 = 2 * yw - y1;
    y2 = 2 * yw - y2;

    pt a(0, y1 - r), b(xb, yb), c(0, y2);
    if (dblcmp(point_line_dis(c, a, b) - r) >= 0) {
        printf("%.12f\n", cross_point(a, b, pt(0, yw), pt(10, yw)).x);
    } else {
        puts("-1");
    }
	return 0;
}