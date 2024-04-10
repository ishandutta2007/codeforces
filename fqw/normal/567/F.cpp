// 21:49
// 22:08 - 
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

int eq[77]; VI le[77], ge[77], lt[77], gt[77];
int n;

bool check(int l, int r, int i, int j) {
    //printf("check %d %d %d %d\n",l,r,i,j);
    if(eq[i]>0) {
        if(eq[i]!=j) return false;
    }
    for(int k: ge[i]) {
        if(k>=l && k<=r && k!=j) return false;
    }
    for(int k: gt[i]) {
        if(k>=l && k<=r) return false;
    }
    //printf("   --- ok\n");
    return true;
}

LL memo[77][77];

LL cal(int l, int r) {
    LL &ans=memo[l][r];
    if(ans>=0) return ans;
    if(r-l+1==2) {
        if(check(l,r,l,r) && check(l,r,r,l))
            return ans=1;
        return ans=0;
    }
    ans=0;
    //printf("%d %d (%d)\n",l,r,r-l+1);
    if(check(l, r, l, l+1) && check(l, r, l+1, l)) {
        //printf("  += %d %d\n",l+2,r);
        ans+=cal(l+2, r);
    }
    if(check(l, r, l, r) && check(l, r, r, l)) {
        //printf("  += %d %d\n",l+1,r-1);
        ans+=cal(l+1, r-1);
    }
    if(check(l, r, r-1, r) && check(l, r, r, r-1)) {
        //printf("  += %d %d\n",l,r-2);
        ans+=cal(l, r-2);
    }
    //printf("%d %d (%d)-> %lld\n",l,r,r-l+1,ans);
    return ans;
}

LL solve() {
    int k; scanf("%d%d", &n,&k);
    rep(i, 1, n*2) le[i].clear(), ge[i].clear(), lt[i].clear(), gt[i].clear();
    fillchar(eq, 0);

    repn(ki, k) {
        int i, j; char b[99]; scanf("%d%s%d", &i,b,&j);
        if(strcmp(b, "=")==0) {
            if(i==j) continue;
            if(eq[i]>0 && eq[i]!=j) return 0;
            if(eq[j]>0 && eq[j]!=i) return 0;
            eq[i]=j, eq[j]=i;
        }
        if(strcmp(b, ">")==0) {
            if(i==j) return false;
            gt[i].pb(j), lt[j].pb(i);
        }
        if(strcmp(b, "<")==0) {
            if(i==j) return false;
            lt[i].pb(j), gt[j].pb(i);
        }
        if(strcmp(b, ">=")==0) {
            if(i==j) continue;
            ge[i].pb(j), le[j].pb(i);
        }
        if(strcmp(b, "<=")==0) {
            if(i==j) continue;
            le[i].pb(j), ge[j].pb(i);
        }
    }

    fillchar(memo, 0xff);
    LL ans=cal(1, n*2);
    return ans;
}

int main() {
    LL ans=solve();
    printf("%lld\n", ans);
    return 0;
}