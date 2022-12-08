#include <cassert>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <set>
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
typedef vector<PLL> VPL;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=100010;

int n; LL x[N], y[N];

LL sqr(LL a) { return a*a; }

PLL a[N]; 
LL l1[N], l2[N], r1[N], r2[N];

bool check(LL limit) {
    int j=1;
    //rep(i, 1, n) printf("a[%d]=%lld %lld\n",i,a[i].fi,a[i].se);
    rep(i, 1, n) {
        j=max(i, j);
        while(j<n && sqr(a[j+1].fi-a[i].fi)<=limit && abs(a[j+1].fi)<=abs(a[i].fi)) ++j;
        while(j>i && abs(a[j].fi)>abs(a[i].fi)) --j;
        //printf("i=%d j=%d\n",i,j);
        LL y1=min(l1[i-1], r1[j+1]);
        LL y2=max(l2[i-1], r2[j+1]);
        if(sqr(y1-y2)<=limit && max(sqr(y1),sqr(y2))+sqr(a[i].fi)<=limit) {
            //printf("true\n");
            return true;
        }
    }
    return false;
}

LL solve() {
    rep(i, 1, n) a[i]=mp(x[i], y[i]);
    sort(a+1, a+n+1);

    l1[0]=1LL<<30, l2[0]=-l1[0];
    rep(i, 1, n) {
        l1[i]=min(l1[i-1], a[i].se);
        l2[i]=max(l2[i-1], a[i].se);
    }
    r1[n+1]=1LL<<30, r2[n+1]=-r1[n+1];
    irep(i, n, 1) {
        r1[i]=min(r1[i+1], a[i].se);
        r2[i]=max(r2[i+1], a[i].se);
    }

    LL le=0, ri=1LL<<60;
    while(le<ri) {
        LL mi=(le+ri)/2;
        if(check(mi)) ri=mi;
            else le=mi+1;
    }
    return le;
}

int main() {
    cin>>n; rep(i, 1, n) cin>>x[i]>>y[i];

    //check(1); return 0;

    LL ans=1LL<<60;
    setmin(ans, sqr(*max_element(x+1, x+n+1)-*min_element(x+1, x+n+1)));
    setmin(ans, sqr(*max_element(y+1, y+n+1)-*min_element(y+1, y+n+1)));

    setmin(ans, solve());
    rep(i, 1, n) x[i]=-x[i];
    setmin(ans, solve());

    cout<<ans<<endl;

    return 0;
}