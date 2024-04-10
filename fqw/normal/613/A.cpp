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

const int MAXN=100010;

struct Point {
    double x, y;
    void read() { scanf("%lf%lf", &x,&y); }
    friend double sqdis(Point p, Point q) {
        double dx=q.x-p.x, dy=q.y-p.y;
        return dx*dx+dy*dy;
    }
    friend double dis(Point p, Point q) {
        return sqrt(sqdis(p, q));
    }
    friend double mult(Point a, Point b, Point c) {
        return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
    }
    friend double dis(Point c, Point p, Point q) {
        double p2=sqdis(c, q), q2=sqdis(c, p), c2=sqdis(p, q);
        if(p2>q2+c2) return dis(c, p);
        if(q2>p2+c2) return dis(c, q);
        return abs(mult(c, p, q))/sqrt(c2);
    }
};

Point a[MAXN];
int n; Point p;

int main() {
    scanf("%d", &n); p.read();
    rep(i, 1, n) a[i].read();
    double d1=1e50, d2=-1;
    rep(i, 1, n) setmin(d1, dis(p, a[i], a[i%n+1]));
    rep(i, 1, n) setmax(d2, dis(p, a[i]));
    double r1=(double)d1, r2=(double)d2;
    double PI=acos(-1);
    double a1=r1*r1*PI, a2=r2*r2*PI;
    double ans=a2-a1;
    printf("%.16lf\n", ans);
    return 0;
}