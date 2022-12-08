#include <functional>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
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
typedef long double Real;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<Real,Real> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const Real EPS=1e-10;
Real sgn(Real x) { return x<-EPS ? -1 : x>EPS; }
struct Point {
    Real x, y;
    Point() { }
    Point(Real _x, Real _y) : x(_x), y(_y) { }
    Point operator +(const Point &p) const { return Point(x+p.x, y+p.y); }
    Point operator -(const Point &p) const { return Point(x-p.x, y-p.y); }
    Point operator *(Real b) const { return Point(x*b, y*b); }
    Point operator /(Real b) const { return Point(x/b, y/b); }
    void rotate90() { swap(x, y); x=-x; }
    void rotate(Real ang) {
        Real x0=x*cos(ang)-y*sin(ang);
        Real y0=x*sin(ang)+y*cos(ang);
        x=x0, y=y0;
    }
    Real len() const { return sqrt(x*x+y*y); }
    void normalize() { *this=*this/len(); }
    friend Real mult(Point p1, Point p2) { return p1.x*p2.y-p1.y*p2.x; }
    friend Real dot(Point p1, Point p2) { return p1.x*p2.x+p1.y*p2.y; }
    friend Real mult(Point p0, Point p1, Point p2) { return mult(p1-p0, p2-p0); }
    friend Real dot(Point p0, Point p1, Point p2) { return dot(p1-p0, p2-p0); }
    friend Real dist(Point p1, Point p2) { return (p1-p2).len(); }
    Real lambda(Point s, Point t) const { // return c: p=s+(t-s)*c
        return dot(s, t, *this)/dot(s, t, t);
    }
    friend bool on_segment(Point p, Point a, Point b) {
        return sgn(mult(p, a, b))==0 && sgn(dot(p, a, b))<=0;
    }
    void read() { int a, b; scanf("%d%d", &a,&b); x=a, y=b; }
};

struct Line {
    Real a, b, c;
    Line() { }
    Line(Real _a, Real _b, Real _c) : a(_a), b(_b), c(_c) { }
    Line(Point p1, Point p2) { a=p2.y-p1.y, b=p1.x-p2.x; c=-(p1.x*a+p1.y*b); }
};

struct RotatingPoly {
    Point a[1010], c;
    int n;
    void read() {
        c.read();
        scanf("%d", &n);
        rep(i, 1, n) a[i].read();
        a[0]=a[n];
    }
};

bool go(Real x1, Real y1, Real p, Real x0, Real y0, Real q, Point &z1, Real &t1, Point &z2, Real &t2) {
    Real u=x1*x0+y1*y0;
    Real v=x1*y0-y1*x0;
    Real w=p-x1*q;
    // need: u cos + v sin = w
    if(sgn(u*u+v*v-w*w)<0) return false;
    rep(k, 1, 2) {
        Real s=(k==1?-1.:1.);
        Real tmp=u*u+v*v-w*w; if(sgn(tmp)<=0) tmp=0; else tmp=sqrt(tmp)*s;
        Real ang1=atan2(w, tmp);
        Real ang2=atan2(u, v);
        Real theta=ang1-ang2;
        Point z(x0+q*cos(theta), y0+q*sin(theta));
        if(k==1) z1=z, t1=theta; else z2=z, t2=theta;
    }
    return true;
}

int main() {
    auto solve1=[](Point ac, Point a1, Point a2, Point bc, Point b) -> bool {
        // move so that ac=(0,0)
        a1=a1-ac, a2=a2-ac;
        bc=bc-ac, b=b-ac;
        ac=Point(0,0);

        // rotate so that atan2(b-bc)=0
        Real ang=atan2(b.y-bc.y, b.x-bc.x);
        b=b-bc; b.rotate(-ang); b=b+bc;
        a1=a1-ac; a1.rotate(-ang); a1=a1+ac;
        a2=a2-ac; a2.rotate(-ang); a2=a2+ac;

        Line line(a1, a2); if(line.c<0) line.a*=-1, line.b*=-1, line.c*=-1;
        Point z1, z2; Real t1, t2;
        if(!go(-line.a, -line.b, line.c, bc.x, bc.y, dist(b,bc), z1, t1, z2, t2))
            return false;

        rep(k, 1, 2) {
            Real theta=(k==1?t1:t2);
            Point z=(k==1?z1:z2);
            Point a1r=a1, a2r=a2;
            a1r.rotate(theta);
            a2r.rotate(theta);
            if(on_segment(z, a1r, a2r)) return true;
        }

        return false;
    };

    auto solve=[&solve1](const RotatingPoly &a, const RotatingPoly &b) -> bool {
        rep(i, 1, a.n) rep(j, 1, b.n)
            if(solve1(a.c, a.a[i-1], a.a[i], b.c, b.a[j]))
                return true;
        return false;
    };

    static RotatingPoly a, b;
    a.read();
    b.read();
    bool ok=false;
    if(solve(a, b)) ok=true;
    if(solve(b, a)) ok=true;
    printf("%s\n", ok?"YES":"NO");

    return 0;
}