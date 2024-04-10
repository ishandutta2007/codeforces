// 14:28
// 14:35 - 14:48 - wa 4
#include <cassert>
#include <algorithm>
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

int n, a[100010];

void solve() {
    if(a[n]==1) { printf("NO\n"); return; }
    if(n==1) { printf("YES\n0\n"); return; }
    if(a[n-1]==0 && find(a+1, a+(n-2)+1, 0)==a+(n-2)+1) printf("NO\n");
    else {
        printf("YES\n");
        rep(i, 1, n-2) printf("(%d->", a[i]);
        printf("%d", a[n-1]);
        rep(i, 1, n-2) printf(")");
        printf("->%d\n",a[n]);
        return;
    }
    /*
    if(n==2) {
        if(a[1]==0) { printf("NO\n"); return; }
        printf("YES\n1->0\n"); return;
    }
    if(n==3) {
        if(a[1]==1 && a[2]==0) { printf("NO\n"); return; }
        printf("YES\n(%d->%d)->0\n",a[1],a[2]); return;
    }
    */
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    solve();
    return 0;
}