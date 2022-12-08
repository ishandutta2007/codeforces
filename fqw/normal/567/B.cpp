// 20:23
// 20:26 - 20:29 - re 15
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

int data[111]; bool in[111];
bool vis[1000010], init[1000010];
int n;

int main() {
    scanf("%d", &n); rep(i, 1, n) {
        char b[99]; scanf("%s%d", b,&data[i]);
        in[i]=(b[0]=='+');
    }
    fillchar(vis, false);
    fillchar(init, false);
    rep(i, 1, n) if(!vis[data[i]]) {
        init[data[i]]=(!in[i]);
        vis[data[i]]=true;
    }

    int cur=0, ans=0;
    rep(i, 1, 1000000) if(init[i]) ++cur;
    ans=cur;
    rep(i, 1, n) {
        if(in[i]) ++cur; else --cur;
        setmax(ans, cur);
    }
    printf("%d\n", ans);


    return 0;
}