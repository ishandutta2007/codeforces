#include <algorithm>
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
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

typedef long double Real;

const int MAXN=3030;
template<class T> T sqr(T x) { return x*x; }
const Real PI=acos(-1);

struct Point {
    Real x, y;
    Point(Real _x=0, Real _y=0) : x(_x), y(_y) { }
    Point operator +(const Point &p) const { return Point(x+p.x, y+p.y); }
    Point operator -(const Point &p) const { return Point(x-p.x, y-p.y); }
    Point operator *(Real b) const { return Point(x*b, y*b); }
    Point operator /(Real b) const { return Point(x/b, y/b); }
    Point operator -() const { return Point(-x, -y); }
    void rotate90() { swap(x, y); x=-x; }
    friend Real mult(Point p1, Point p2) { return p1.x*p2.y-p1.y*p2.x; }
    friend Real dot(Point p1, Point p2) { return p1.x*p2.x+p1.y*p2.y; }
    friend Real mult(Point p0, Point p1, Point p2) { return mult(p1-p0, p2-p0); }
    friend Real dot(Point p0, Point p1, Point p2) { return dot(p1-p0, p2-p0); }
    Real lambda(Point s, Point t) const { // return c: p=s+(t-s)*c
        return dot(s, t, *this)/dot(s, t, t);
    }
    void print() const { printf("(%.4lf, %.4lf) ",(double)x,(double)y); }
};
struct Line {
    Real a, b, c;
    void read() {
        int x, y, z;
        scanf("%d%d%d", &x,&y,&z);
        a=x, b=y, c=z;
        if(b>0 || (b==0 && a>0)) a=-a, b=-b, c=-c;
    }
    bool operator <(const Line &l) const {
        Real tmp=a*l.b-b*l.a;
        return tmp>0;
    }
    Point cross_line(Line l) const {
        Real t=a*l.b-b*l.a;
        Real x=b*l.c-c*l.b;
        Real y=c*l.a-a*l.c;
        return Point(x/t, y/t);
    }
};


Line lines[MAXN];
int n;

int main() {
    scanf("%d", &n);
    rep(i, 1, n) lines[i].read();
    sort(lines+1, lines+n+1);

    Real ans=0;
    rep(i, 1, n) {
        Point sum;
        rep(k, 1, n-1) {
            int j=i+k; if(j>n) j-=n;
            Point c=lines[i].cross_line(lines[j]);
            ans+=mult(sum, c)/2;
            sum=sum+c;
        }
    }
    ans=ans*6./n/(n-1)/(n-2);
    printf("%.9lf\n", (double)ans);

    return 0;
}