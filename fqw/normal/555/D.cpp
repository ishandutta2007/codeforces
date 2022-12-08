#include <cassert>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
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

const int MAXN=200010;

PII xs[MAXN];
int where[MAXN];
int n, m;

int go(int i, int len) {
    while(1) {
        int j=int(lower_bound(xs+1,xs+n+1, mp(xs[i].fi+len+1,0))-xs)-1;
        int lj=xs[j].fi-xs[i].fi;
        int k=int(lower_bound(xs+1,xs+n+1, mp(xs[j].fi-(len-lj),0))-xs);
        int lk=xs[j].fi-xs[k].fi;
        if(j==i && k==i) return i;
        if(j>i && k==i) {
            len%=lj+lk; 
            continue;
        }
        len-=lj+lk, i=k;
    }
}

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, n) scanf("%d", &xs[i].fi), xs[i].se=i;
    sort(xs+1, xs+n+1);
    rep(i, 1, n) where[xs[i].se]=i;

    while(m--) {
        int a, l;
        scanf("%d%d", &a,&l);
        int p=go(where[a], l);
        printf("%d\n", xs[p].se);
    }
    return 0;
}