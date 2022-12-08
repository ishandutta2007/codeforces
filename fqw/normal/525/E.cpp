// 10:30
// 10:32 - 10:52 - wa
//       - 10:54 - wa
#include <cassert>
#include <algorithm>
#include <map>
#include <iostream>
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

const LL MAXV=LL(1e16)+100;
typedef pair<LL,int> PLI;
typedef vector<PLI> VPLI;

VPLI get(LL a[], LL b[], int le, int ri) {
    int n=ri-le;
    int tot=1; repn(i, n) tot*=3;
    VPLI ret;
    repn(s, tot) {
        int tmp=s;
        LL cur=0; int ce=0;
        rep(i, le, ri-1) {
            if(tmp%3==0) cur+=a[i];
            if(tmp%3==1) cur+=b[i], ++ce;
            tmp/=3;
        }
        ret.pb(mp(cur, ce));
    }
    return ret;
}

int main() {
    int n, k; LL sum;
    cin>>n>>k>>sum;
    LL a[33], b[33];
    repn(i, n) {
        cin>>a[i];
        b[i]=1;
        rep(t, 1, a[i]) {
            if(b[i]>MAXV/t) {
                b[i]=MAXV; break;
            } else
                b[i]*=t;
        }
    }

    VPLI v1=get(a, b, 0, n/2);
    VPLI v2=get(a, b, n/2, n);

    map<LL, VI> cnt;
    for(PLI x: v1) cnt[sum-x.fi].pb(x.se);
    for(auto &it: cnt) sort(all(it.se));

    LL ans=0;
    for(PLI x: v2) {
        if(cnt.find(x.fi)==cnt.end()) continue;
        const VI &vi=cnt[x.fi];
        int num=(int)(upper_bound(all(vi), k-x.se)-vi.begin());
        ans+=num;
    }
    cout<<ans<<endl;

    return 0;
}