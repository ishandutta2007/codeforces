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
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=5050;

struct Point {
    LL x, y;
    void read() { scanf("%lld%lld", &x,&y); }
    bool operator<(const Point& p) const {
        return x<p.x || (x==p.x && y<p.y);
    }
};

LL mult(Point p0, Point p1, Point p2) {
    return (p1.x-p0.x)*(p2.y-p0.y) - (p2.x-p0.x)*(p1.y-p0.y);
}

vector<Point> convex(vector<Point> a) {
    vector<Point> b;
    sort(all(a));
    for(const auto& p: a) {
        while(sz(b)>1 && mult(b[sz(b)-2], b.back(), p)<=0)
            b.pop_back();
        b.pb(p);
    }
    reverse(all(a));
    const int L=sz(b);
    for(const auto& p: a) {
        while(sz(b)>L && mult(b[sz(b)-2], b.back(), p)<=0)
            b.pop_back();
        b.pb(p);
    }
    b.pop_back();
    return b;
}

int main() {
    int n; LL tmp; scanf("%d%lld", &n,&tmp);
    vector<Point> a(n);
    for(auto& p: a) p.read();
    a=convex(a);
    int z[3]={0, 1, 2};
    while(1) {
        bool updated=false;
        repn(i, 3) {
            int zi=z[i], zj=z[(i+1)%3], zk=z[(i+2)%3];
            int zi1=(zi+1)%sz(a);
            int zi2=(zi-1+sz(a))%sz(a);
            if(mult(a[zj], a[zk], a[zi1])>mult(a[zj], a[zk], a[zi])) {
                zi=zi1; updated=true;
            }
            if(mult(a[zj], a[zk], a[zi2])>mult(a[zj], a[zk], a[zi])) {
                zi=zi2; updated=true;
            }
            z[i]=zi;
        }
        if(!updated) break;
    }
    repn(i, 3) {
        int zi=z[i], zj=z[(i+1)%3], zk=z[(i+2)%3];
        LL x=a[zi].x+a[zj].x-a[zk].x;
        LL y=a[zi].y+a[zj].y-a[zk].y;
        printf("%lld %lld\n", x,y);
    }
    return 0;
}