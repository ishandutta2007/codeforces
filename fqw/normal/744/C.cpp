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

int main() {
    int n; cin>>n;
    VI r(n), b(n); VS c(n);
    repn(i, n) cin>>c[i]>>r[i]>>b[i];

    static int f[1<<16][300];
    fillchar(f, -1);
    f[0][0]=0;
    repn(st, (1<<n)-1) repn(x, 300) {
        if(f[st][x]<0) continue;
        int y=f[st][x];
        int rn=0, bn=0;
        repn(i, n) if(st&(1<<i)) {
            if(c[i]=="R") ++rn; else ++bn;
        }
        repn(i, n) if((st&(1<<i))==0) {
            int rdeduce=min(rn, r[i]);
            int bdeduce=min(bn, b[i]);
            setmax(f[st|(1<<i)][x+rdeduce], y+bdeduce);
        }
    }

    LL ans=1ll<<55;
    LL sx=0, sy=0;
    repn(i, n) sx+=r[i], sy+=b[i];
    repn(x, 300) {
        int y=f[(1<<n)-1][x];
        if(y<0) continue;
        setmin(ans, max(sx-x, sy-y));
    }
    cout<<(ans+n)<<endl;

    return 0;
}