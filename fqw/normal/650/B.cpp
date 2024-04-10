#include <algorithm>
#include <iostream>
#include <cassert>
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

char o[1000010];
int n; LL a, b, T;

LL c[1000010];

LL look(int i) { return 1+(o[i]=='w'?b:0); }

LL cst(int i, int j) { return c[j]-c[i-1]-a; }

LL cst(int i, int m, int j) {
    return cst(i, m)+(m-i+1)*a+cst(m+1,j);
}

LL solve() {
    rep(i, 1, n) o[n+i]=o[i];
    c[0]=0; rep(i, 1, n*2) c[i]=c[i-1]+a+look(i);

    LL ans=0;
    irep(i, n+1, 2) if(cst(i, n+1)<=T) setmax(ans, LL(n+1)-i+1);
    int j=n*2;
    irep(i, n+1, 2) {
        if(j-i+1>n) --j;
        while(j>n+1 && cst(i, n+1, j)>T) --j;
        if(cst(i, n+1, j)<=T) setmax(ans, LL(j-i+1));
    }
    return ans;
}

int main() {
    cin>>n>>a>>b>>T;
    scanf("%s", o+1);
    LL ans=solve();
    reverse(o+2, o+n+1);
    setmax(ans, solve());
    cout<<ans<<endl;

    return 0;
}