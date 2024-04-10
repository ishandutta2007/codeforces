#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
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
    static char s[100010];
    scanf("%s", s);
    int len=(int)strlen(s);
    int la=-1, cl=0, cr=0;
    repn(i, len) {
        if(s[i]=='(') ++cl; else ++cr;
        if(s[i]=='#') la=i;
    }
    if(cl<cr) { printf("-1\n"); return 0; }

    VI ans;
    int cur=0; bool ok=true;
    repn(i, len) {
        if(s[i]=='(') ++cur;
        else {
            --cur;
            if(s[i]=='#') {
                if(i==la) cur-=cl-cr, ans.pb(cl-cr+1);
                else ans.pb(1);
            }
            if(cur<0) {
                ok=false; break;
            }
        }
    }
    if(ok) {
        assert(cur==0);
        for(int x: ans) printf("%d\n", x);
    } else printf("-1\n");

    return 0;
}