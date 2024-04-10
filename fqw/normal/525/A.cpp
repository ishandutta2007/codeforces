// 10:11
// 10:13 - 10:15 - 
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
    static char s[200010];
    scanf("%*d%s", s+1);
    int len=(int)strlen(s+1);
    int d[33], ans[33];
    fillchar(d, 0); fillchar(ans, 0);
    rep(i, 1, len) {
        int cur=0;
        if(s[i]>='a' && s[i]<='z') d[cur=int(s[i]-'a')]++;
        else d[cur=(s[i]-'A')]--;
        setmax(ans[cur], -d[cur]);
    }
    int tot=0;
    rep(i, 0, 30) tot+=ans[i];
    printf("%d\n", tot);

    return 0;
}