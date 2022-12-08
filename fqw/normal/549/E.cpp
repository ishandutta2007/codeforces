#include <cassert>
#include <algorithm>
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
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

struct Point;
typedef vector<Point> VP;
struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    void read() { scanf("%d%d", &x,&y); }
    static VP read_vec(int n) { VP r(n); for(auto& p: r) p.read(); return r; }

    bool operator<(const Point& b) const { return x<b.x || (x==b.x && y<b.y); }
    Point operator+(const Point& b) const { return Point(x+b.x, y+b.y); }
    Point operator-(const Point& b) const { return Point(x-b.x, y-b.y); }
    friend int dot(Point a, Point b) { return a.x*b.x+a.y*b.y; }
    friend int dot(Point p, Point a, Point b) { return dot(a-p, b-p); }
    friend int cross(Point a, Point b) { return a.x*b.y-b.x*a.y; }
    friend int cross(Point p, Point a, Point b) { return cross(a-p, b-p); }
};

VP cal_convex(VP a) {
    VP r;
    sort(all(a));
    for(const auto& p: a) {
        while(sz(r)>1 && cross(r[sz(r)-2], r[sz(r)-1], p)<=0) r.pop_back();
        r.pb(p);
    }
    int K=sz(r);
    reverse(all(a));
    for(const auto& p: a) {
        while(sz(r)>K && cross(r[sz(r)-2], r[sz(r)-1], p)<=0) r.pop_back();
        r.pb(p);
    }
    r.pop_back();
    return r;
}

bool check(const VP& a, const VP& b, int i, int j, int* farthest) {
    typedef long double LD;
    auto sgn=[](LD x, LD e=1e-15)->int { return x<-e?-1:x>e; };

    //printf("%d %d\n",i,j);

    LD le=-1e50, ri=1e50;
    *farthest=-1;
    repn(k, sz(a)) { const auto& p=a[k];
        int d=dot(p, a[j], a[i]), c=cross(p, a[j], a[i]);
        if(c==0) {
            if(d>0) return false;
            continue;
        }
        if(c>0) { if(setmin(ri, -LD(d)/LD(c))) *farthest=k; }
            else setmax(le, LD(d)/LD(-c));
    }
    for(const auto& p: b) {
        int d=dot(p, a[j], a[i]), c=cross(p, a[j], a[i]);
        if(c==0) {
            if(d<=0) return false;
            continue;
        }
        if(c>0) setmax(le, -LD(d)/LD(c));
            else setmin(ri, LD(d)/LD(-c));
    }
    return sgn(le-ri)<0;
    //printf("%.9lf %.9lf %.9lf %.9lf\n",(double)al,(double)ar,(double)bl,(double)br);
    //return sgn(al+ar)<=0 && sgn(al-bl)<0 && sgn(ar-br)<0;
}

bool go(const VP& a, const VP& b, int l, int r) {
    int mid=-1;
    if(check(a, b, l, r, &mid)) return true;
    if(mid<0) return false;
    return go(a, b, l, mid) || go(a, b, mid, r);
}

bool solve(VP a, VP b) {
    if(sz(a)<=1) return true;
    a=cal_convex(a);
    return go(a, b, 0, sz(a)-1);
}

int main() {
    int n, m; scanf("%d%d", &n,&m);
    VP a=Point::read_vec(n);
    VP b=Point::read_vec(m);
    bool r=(solve(a, b) || solve(b, a));
    printf("%s\n", r?"YES":"NO");
    return 0;
}