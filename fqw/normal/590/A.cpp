// 8:00
// 8:05 - 8:11 - wa 6
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

int a[500010];
bool sure[500010];

int main() {
    int n; scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    fillchar(sure, false);
    sure[1]=sure[n]=true;
    rep(i, 2, n) if(a[i]==a[i-1]) sure[i-1]=sure[i]=true;
    int ans=0;
    for(int i=1, j; i<n; i=j) {
        j=i+1; while(!sure[j]) ++j;
        setmax(ans, (j-i)/2);
        if(a[i]==a[j]) {
            rep(k, i+1, j-1) a[k]=a[i];
        } else {
            for(int p=i+1, q=j-1; p<q; ++p,--q)
                a[p]=a[i], a[q]=a[j];
        }
    }
    printf("%d\n", ans);
    rep(i, 1, n) printf("%d ", a[i]); printf("\n");

    return 0;
}