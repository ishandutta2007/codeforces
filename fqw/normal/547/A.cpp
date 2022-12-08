#include <algorithm>
#include <functional>
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

LL solve() {
    LL m; cin>>m;
    LL h1, a1, x1, y1; cin>>h1>>a1>>x1>>y1;
    LL h2, a2, x2, y2; cin>>h2>>a2>>x2>>y2;

    LL t=0;
    while(h1!=a1) {
        if(t>m) return -1;
        ++t; h1=(h1*x1+y1)%m;
    }
    LL p=0;
    for(LL h=h1, cnt=0; ; ) {
        if(cnt++>m) { p=-1; break; }
        ++p; h=(h*x1+y1)%m;
        if(h==h1) break;
    }

    forn(i, t) h2=(h2*x2+y2)%m;
    if(h2==a2) return t;
    if(p<0) return -1;

    LL x=1, y=0;
    forn(i, p) {
        x=(x*x2)%m;
        y=(y*x2+y2)%m;
    }
    for(LL cnt=0; h2!=a2; ) {
        if(cnt++>m) return -1;
        t+=p; h2=(h2*x+y)%m;
    }
    return t;
}

int main() {
    LL ans=solve();
    cout<<ans<<endl;
    return 0;
}