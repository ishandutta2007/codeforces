#include <cassert>
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

int a[500010]; LL sum[500010][2];
char s[500010];
int n;

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    scanf("%s", s+1);
    sum[0][0]=sum[0][1]=0;
    rep(i, 1, n) {
        sum[i][0]=sum[i-1][0];
        sum[i][1]=sum[i-1][1];
        sum[i][s[i]=='A'?0:1]+=a[i];
    }
    LL ans=0;
    rep(i, 0, n) {
        LL a1=sum[i][0], a2=sum[n][0]-a1;
        LL b1=sum[i][1], b2=sum[n][1]-b1;
        setmax(ans, a1+b2);
        setmax(ans, b1+a2);
    }
    cout<<ans<<endl;
    return 0;
}