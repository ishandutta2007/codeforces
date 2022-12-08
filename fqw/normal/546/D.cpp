// 17:35
// 17:38 - 
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

int cnt[5000010], pre[5000010];
int sum[5000010];

int main() {
    fillchar(pre, 0);
    pre[1]=0, cnt[1]=0;
    rep(i, 2, 5000000) {
        if(pre[i]==0) {
            cnt[i]=1;
            for(int j=i*2; j<=5000000; j+=i) pre[j]=i;
        } else {
            cnt[i]=cnt[i/pre[i]]+1;
        }
    }
    sum[0]=0;
    rep(i, 1, 5000000) sum[i]=sum[i-1]+cnt[i];

    int t; scanf("%d", &t);
    while(t--) {
        int a, b; scanf("%d%d", &a,&b);
        int ans=sum[a]-sum[b];
        printf("%d\n", ans);
    }
    return 0;
}