// 13:50
// 13:53 - 13:36
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

int main() {
    char s[110]; scanf("%s", s+1);
    int n=(int)strlen(s+1);
    int a[110]; rep(i, 1, n) a[i]=int(s[i]-'0');
    rep(i, 1, n) if(a[i]%8==0) { printf("YES\n%d\n",a[i]); return 0; }
    rep(i, 1, n) rep(j, i+1, n) if(a[i]!=0 && (a[i]*10+a[j])%8==0) {
        printf("YES\n%d%d\n", a[i],a[j]); return 0;
    }
    rep(i, 1, n) rep(j, i+1, n) rep(k, j+1, n)
        if(a[i]!=0 && (a[i]*100+a[j]*10+a[k])%8==0) {
            printf("YES\n%d%d%d\n", a[i],a[j],a[k]); return 0;
        }
    printf("NO\n");
    return 0;
}