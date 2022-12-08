#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //
//
//
PDD go(double x, double y, double r) {
    double p1=(x-r)*(y-r);
    double p2=(x+r)*(y-r);
    double p3=(x-r)*(y+r);
    double p4=(x+r)*(y+r);
    x=min(min(p1,p2), min(p3,p4));
    y=max(max(p1,p2), max(p3,p4));
    return MP(x,y);
}

int main() {
    double a, b, c, d;
    cin>>a>>b>>c>>d;
    double le=0, ri=1e10;
    forn(_, 999) {
        double mid=(le+ri)/2;
        PDD x=go(a, d, mid);
        PDD y=go(b, c, mid);
        if(x.se<y.fi || y.se<x.fi)
            le=mid;
        else
            ri=mid;
    }
    double ans=(le+ri)/2;
    printf("%.16lf\n", ans);
    return 0;
}