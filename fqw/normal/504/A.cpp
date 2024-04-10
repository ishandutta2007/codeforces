#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
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

int deg[1<<16], s[1<<16];
int n;

int main() {
    scanf("%d", &n);
    repn(i, n) scanf("%d%d", &deg[i],&s[i]);

    set<PII> b;
    VPI ans;
    repn(i, n) b.insert(mp(deg[i], i));
    while(!b.empty()) {
        int x=b.begin()->se, dx=b.begin()->fi;
        b.erase(mp(dx, x));
        assert(dx==deg[x]);
        if(dx==0) {
            assert(s[x]==0);
            deg[x]=-1;
            continue;
        }
        assert(dx==1);
        int y=s[x];
        assert(deg[y]>0);
        ans.pb(mp(x, y));
        b.erase(mp(deg[y], y));
        --deg[y]; s[y]^=x;
        b.insert(mp(deg[y], y));
    }

    printf("%d\n", (int)ans.size());
    for(PII p: ans) printf("%d %d\n", p.fi,p.se);
    
    return 0;
}