// 8:12
// 8:44 - 
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const double EPS=1e-10;
double sgn(double x) { return x<-EPS ? -1 : x>EPS; }
struct Point {
    double x, y;
    Point() { }
    Point(double _x, double _y) : x(_x), y(_y) { }
    Point operator +(const Point &p) const { return Point(x+p.x, y+p.y); }
    Point operator -(const Point &p) const { return Point(x-p.x, y-p.y); }
    Point operator *(double b) const { return Point(x*b, y*b); }
    Point operator /(double b) const { return Point(x/b, y/b); }
    void rotate90() { swap(x, y); x=-x; }
    double len() const { return sqrt(x*x+y*y); }
    void normalize() { *this=*this/len(); }
    friend double mult(Point p1, Point p2) { return p1.x*p2.y-p1.y*p2.x; }
    friend double dot(Point p1, Point p2) { return p1.x*p2.x+p1.y*p2.y; }
    friend double mult(Point p0, Point p1, Point p2) { return mult(p1-p0, p2-p0); }
    friend double dot(Point p0, Point p1, Point p2) { return dot(p1-p0, p2-p0); }
    friend double dist(Point p1, Point p2) { return (p1-p2).len(); }
    double lambda(Point s, Point t) const { // return c: p=s+(t-s)*c
        return dot(s, t, *this)/dot(s, t, t);
    }
    void read() { scanf("%lf%lf", &x,&y); }
};
struct Line {
    double a, b, c;
    Line() { }
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) { }
    Line(Point p1, Point p2) { a=p2.y-p1.y, b=p1.x-p2.x; c=-(p1.x*a+p1.y*b); }
    Point cross(const Line &l) const {
        double t=a*l.b-b*l.a;
        double x=b*l.c-c*l.b;
        double y=c*l.a-a*l.c;
        return Point(x/t, y/t);
    }
};

double cal(Point p, double r, Point q, Point vwind, double vmax, double tl) {
    double le=0, ri=tl+10;
    repn(tt, 999) {
        double mid=(le+ri)/2;
        Point q2=q-vwind*mid;
        double d=dist(q2, p)-r;
        double dmax=vmax*mid;
        if(d<=dmax) ri=mid;
            else le=mid;
    }
    return ri;
}

int main() {
    Point p, q; p.read(), q.read();
    double vmax, t; scanf("%lf%lf", &vmax,&t);
    Point v1, v2; v1.read(), v2.read();

    double x=cal(p, 0, q, v1, vmax, t);
    if(x<=t) {
        printf("%.19lf\n", x);
    } else {
        double y;
        for(double tl=1; ; tl*=10) {
            y=cal(p+v1*t, vmax*t, q, v2, vmax, tl);
            if(y<=tl) break;
        }
        printf("%.19lf\n", y+t);
    }
    return 0;
}