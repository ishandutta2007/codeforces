#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
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

typedef long double LD;
typedef pair<LD,LD> PDD;
const LD PI=acos(-1);

struct Point {
    LL x=0, y=0;
    Point() {}
    Point(LL _x, LL _y) : x(_x), y(_y) {}
    void read() { scanf("%lld%lld", &x,&y); }
    Point operator+(const Point& p) const { return Point(x+p.x, y+p.y); }
    Point operator-(const Point& p) const { return Point(x-p.x, y-p.y); }
    LL sq_len() const { return x*x+y*y; }
    LD ang() const { return atan2(y, x); }
};

LD angle(LL a2, LL b2, LL c2) {
    LD x=(LD(b2)+LD(c2)-a2)/(sqrt(LD(b2))*sqrt(LD(c2))*2);
    if(x>1) x=1;
    if(x<-1) x=-1;
    return acos(x);
}

double solve() {
    Point p0; p0.read();
    LL v, t; scanf("%lld%lld", &v,&t);
    const LL s=v*t;

    vector<PDD> intervals;
    auto add=[&](LD x, LD y) {
        setmax(x, -PI); setmin(y, PI);
        if(x<y) intervals.emplace_back(x, y);
    };
    int n; scanf("%d", &n);
    repn(i, n) {
        Point p; p.read();
        LL r; scanf("%lld", &r);

        const LL r2=r*r; 
        const LL d2=(p-p0).sq_len();
        if(d2<=r2) return 1.0;
        if(r+s==0) {
            if(d2>0) continue;
        } else {
            if((r+s)<=d2/(r+s)) continue;
        }
        LL x2=d2-r2;
        if(s==0 || s<=x2/s) x2=s*s;
        const LD width=angle(r2, d2, x2);

        const LD ang=(p-p0).ang();
        const LD ang1=ang-width, ang2=ang+width;
        add(ang1, ang2);
        add(ang1-PI*2, ang2-PI*2);
        add(ang1+PI*2, ang2+PI*2);
    }
    sort(all(intervals));
    LD la=-PI, ans=0;
    for(const auto& p: intervals) {
        if(p.se>la) {
            ans+=p.se-max(la, p.fi);
            la=p.se;
        }
    }
    return double(ans/PI/2);
}

int main() {
    double ans=solve();
    printf("%.9lf\n", ans);
    return 0;
}