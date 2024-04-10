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

const int MAXN=1000010;

LL f[MAXN][2];
int a[MAXN], n;

int main() {
    scanf("%d", &n); rep(i, 1, n) scanf("%d", &a[i]);
    fillchar(f, 0xff);
    f[1][0]=f[1][1]=0;
    rep(i, 2, n) {
        if(a[i]<=a[i-1]) setmax(f[i][0], f[i-1][0]+a[i-1]-a[i]);
        if(a[i]>=a[i-1]) setmax(f[i][1], f[i-1][1]+a[i]-a[i-1]);
        setmax(f[i][0], f[i-1][1]);
        setmax(f[i][0], f[i-1][0]);
        setmax(f[i][1], f[i-1][1]);
        setmax(f[i][1], f[i-1][0]);
    }
    LL ans=max(f[n][0], f[n][1]);
    cout<<ans<<endl;
    return 0;
}