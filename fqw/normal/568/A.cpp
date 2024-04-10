// 19:25 - 19:27 - ?
// 19:37
// 19:39 - 19:46 - wa
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

const int N=8000000;

bool prime[N], rev[N];

int main() {
    fillchar(prime, true);
    prime[1]=false;
    rep(i, 2, N-1) if(prime[i]) {
        for(int j=i*2; j<N; j+=i) prime[j]=false;
    }
    rep(i, 1, N-1) {
        int j=0; for(int t=i; t>0; t/=10) j=j*10+t%10;
        rev[i]=(i==j);
    }

    int p, q; scanf("%d%d", &p,&q);
    //rep(p, 1, 10000) rep(q, 1, 10000) {  if(p>q*42 || q>p*42) continue; printf("%d %d: ",p,q);
    int pi=0, rub=0, ans=-1;
    rep(i, 1, N-1) {
        if(prime[i]) ++pi;
        if(rev[i]) ++rub;
        if(pi*LL(q)<=LL(p)*rub) ans=i;
    }
    if(ans<0) {
        printf("Palindromic tree is better than splay tree\n");
        //exit(0);
    }
    else printf("%d\n", ans);
    //}
    return 0;
}