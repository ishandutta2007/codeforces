#include <algorithm>
#include <cassert>
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
typedef vector<PLL> VPL;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const char *T="%lld";

LL l[200010], r[200010];
int n, m;

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, n) {
        scanf(T, &l[i]);
        scanf(T, &r[i]);
    }
    vector<pair<PLL,int> > need;
    rep(i, 1, n-1) {
        LL x=r[i+1]-l[i];
        LL y=l[i+1]-r[i];
        need.pb(mp(mp(y, x), i));
    }
    vector<pair<LL,int> > have;
    rep(i, 1, m) {
        LL x; scanf(T, &x);
        have.pb(mp(x, i));
    }

    static LL ans[200010];
    sort(all(need));
    sort(all(have));
    multiset<pair<LL,int> > rest;
    size_t i=0;
    bool ok=true;
    for(auto cur: have) {
        while(i<need.size() && need[i].fi.fi<=cur.fi) {
            rest.insert(mp(need[i].fi.se, need[i].se));
            ++i;
        }
        if(!rest.empty()) {
            auto t=*rest.begin();
            rest.erase(rest.begin());
            if(t.fi<cur.fi) {
                ok=false; break;
            }
            ans[t.se]=cur.se;
        }
    }
    if(i<need.size()) ok=false;
    if(!rest.empty()) ok=false;
    if(!ok) printf("No\n");
    else {
        printf("Yes\n");
        rep(k, 1, n-1) { printf(T, ans[k]); printf(" "); }
        printf("\n");
    }

    return 0;
}