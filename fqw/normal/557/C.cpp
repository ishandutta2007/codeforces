#include <algorithm>
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
    int n; scanf("%d", &n);
    static PII a[100010];
    rep(i, 1, n) scanf("%d", &a[i].fi);
    rep(i, 1, n) scanf("%d", &a[i].se);
    sort(a+1, a+n+1);

    int ans=0, cnt[222];
    fillchar(cnt, 0);
    for(int le=1, ri; le<=n; le=ri+1) {
        for(ri=le; ri<n && a[ri+1].fi==a[ri].fi; ++ri);

        int tmp=0;
        rep(i, le, ri) tmp+=a[i].se;
        int r=ri-le;
        irepn(k, 201) {
            int take=min(r, cnt[k]);
            tmp+=take*k;
            r-=take;
        }
        setmax(ans, tmp);

        rep(i, le, ri) cnt[a[i].se]++;
    }
    int sum=0; rep(i, 1, n) sum+=a[i].se;
    ans=sum-ans;
    printf("%d\n", ans);

    return 0;
}