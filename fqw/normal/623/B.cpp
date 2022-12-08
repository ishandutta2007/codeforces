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

const int N=1000010;
const LL INF=1LL<<60;

int n; LL ca, cb;
int a[N];

LL solve(int p) {
    static LL l[N], r[N];
    l[0]=0;
    rep(i, 1, n) {
        l[i]=INF;
        if((a[i]-1)%p==0) setmin(l[i], l[i-1]+cb);
        if((a[i]+1)%p==0) setmin(l[i], l[i-1]+cb);
        if(a[i]%p==0) setmin(l[i], l[i-1]);
    }
    r[n+1]=0;
    irep(i, n, 1) {
        r[i]=INF;
        if((a[i]-1)%p==0) setmin(r[i], r[i+1]+cb);
        if((a[i]+1)%p==0) setmin(r[i], r[i+1]+cb);
        if(a[i]%p==0) setmin(r[i], r[i+1]);
    }

    static LL s[N];
    s[0]=0;
    rep(i, 1, n) {
        s[i]=min(s[i-1], l[i]-i*ca);
    }
    LL ans=INF;
    rep(j, 0, n) {
        setmin(ans, s[j]+r[j+1]+j*ca);
    }
    return ans;
}

int main() {
    cin>>n>>ca>>cb;
    rep(i, 1, n) cin>>a[i];

    VI ps;
    auto add_factors=[](VI* r, int x) {
        for(int y=2; y*y<=x; ++y)
            if(x%y==0) {
                r->pb(y);
                while(x%y==0) x/=y;
            }
        if(x>1) r->pb(x);
    };
    add_factors(&ps, a[1]);
    add_factors(&ps, a[1]-1);
    add_factors(&ps, a[1]+1);
    add_factors(&ps, a[n]);
    add_factors(&ps, a[n]-1);
    add_factors(&ps, a[n]+1);
    sort(all(ps));
    ps.erase(unique(all(ps)), ps.end());

    LL ans=INF;
    for(int p: ps) setmin(ans, solve(p));
    cout<<ans<<endl;
    return 0;
}