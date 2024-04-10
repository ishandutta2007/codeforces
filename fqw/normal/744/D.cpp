#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
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
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

typedef long double LD;

const LD PI=acosl(-1);

int sgn(LD x, LD e=1e-15) { return x<-e ? -1 : x>e; }

struct Point {
    LD x, y;
    int label=0;
    Point() : x(0), y(0) {}
    Point(LD _x, LD _y) : x(_x), y(_y) {}
    Point operator +(const Point& p) const { return Point(x+p.x, y+p.y); }
    Point operator -(const Point& p) const { return Point(x-p.x, y-p.y); }
    Point operator *(LD b) const { return Point(x*b, y*b); }
    Point operator /(LD b) const { return Point(x/b, y/b); }
    bool operator ==(Point p) const { return sgn(x-p.x)==0 && sgn(y-p.y)==0; }
    LD sqr_abs() const { return x*x+y*y; }
    LD abs() const { return sqrt(sqr_abs()); }
    LD ang() const { return atan2l(y, x); }
    friend LD mult(Point p1, Point p2) { return p1.x*p2.y-p1.y*p2.x; }
    friend LD mult(Point p0, Point p1, Point p2) { return mult(p1-p0, p2-p0); }
    friend LD dot(Point p1, Point p2) { return p1.x*p2.x+p1.y*p2.y; }
    friend LD dot(Point p0, Point p1, Point p2) { return dot(p1-p0, p2-p0); }
    void print() const { printf("%.2lf %.2lf", (double)x,(double)y); }
};

Point read_point() { double u, v; scanf("%lf%lf", &u, &v); return Point(u, v); }

vector<Point> ps;

LD normalize(LD ang) {
    if(ang<-PI) ang+=PI*2;
    if(ang>+PI) ang-=PI*2;
    return ang;
}

bool check(Point center, LD r) {
    //center.print(); printf(", %.3lf\n", (double)r);

    struct Event {
        LD t;
        int label;
        int stub;
        bool operator<(const Event& e) const {
            int s=sgn(t-e.t);
            if(s!=0) return s<0;
            if(stub!=e.stub) return stub<0;
            if(stub>0) {
                return label>e.label;
            } else {
                return label<e.label;
            }
        }
    };
    vector<Event> es;
    for(const auto& p: ps) {
        if(p==center) continue;
        if(center.label && p.label) continue;
        LD d=(p-center).abs();
        if(sgn(d-r*2)>0) continue;
        LD dir=(p-center).ang();
        LD phi=acosl(d/2/r);
        LD st=normalize(dir-phi), en=normalize(dir+phi);
        //p.print(); printf("  --> %.3lf %.3lf\n", double(st/PI),double(en/PI));
        if(sgn(st-en)<=0) {
            es.pb({st, p.label, 1});
            es.pb({en, p.label, -1});
        } else {
            es.pb({st, p.label, 1});
            es.pb({PI+1, p.label, -1});
            es.pb({-PI-1, p.label, 1});
            es.pb({en, p.label, -1});
        }
    }
    if(center.label) {
        es.pb({-PI-1, 1, 1});
        es.pb({0, 1, -1});
        es.pb({0, 1, 1});
        es.pb({PI+1, 1, -1});
    }
    sort(all(es));
    int cnt[2]={0, 0};
    for(const auto& e: es) {
        cnt[e.label]+=e.stub;
        //printf("e @ %.3lf %d %d\n",double(e.t/PI),cnt[0],cnt[1]);
        if(sgn(e.t+PI)>=0 && sgn(e.t-PI)<=0) {
            if(cnt[1]>0 && cnt[0]==0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m; scanf("%d%d", &n,&m);
    repn(i, n) {
        ps.pb(read_point());
        ps.back().label=1;
    }
    repn(i, m) {
        ps.pb(read_point());
    }

    //random_shuffle(all(ps));

    //cout<<check(ps[4], 4.999); return 0;

    for(const auto& p: ps) {
        if(p.label && check(p, 1e15)) {
            printf("-1\n");
            return 0;
        }
    }
    LD ans=0.1;
    irep(label, 1, 0) {
        for(const auto& p: ps) {
            if(p.label==label) {
                if(!check(p, ans)) continue;
                LD l=ans, r=ans*2;
                while(check(p, r)) r*=2;
                repn(i, 70) {
                    LD mid=(l+r)/2;
                    if(check(p, mid)) l=mid; else r=mid;
                }
                ans=l;
    //p.print(); printf(">>%.9lf\n", (double)ans);
            }
        }
    }
    printf("%.9lf\n", (double)ans);

    return 0;
}