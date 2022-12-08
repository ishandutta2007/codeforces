#include <set>
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

void cut(set<PII> &s, multiset<int> &v, int p) {
    PII cur=*--s.upper_bound(mp(p, p));
    s.erase(cur);
    s.insert(mp(cur.fi, p));
    s.insert(mp(p, cur.se));
    v.erase(v.find(cur.se-cur.fi));
    v.insert(p-cur.fi);
    v.insert(cur.se-p);
}

int main() {
    int w, h, n; scanf("%d%d%d", &w,&h,&n);

    set<PII> xs, ys;
    multiset<int> xv, yv;
    xs.insert(mp(0, w)); xv.insert(w);
    ys.insert(mp(0, h)); yv.insert(h);
    rep(i, 1, n) {
        char op[9]; int p;
        scanf("%s%d", op,&p);
        if(op[0]=='V')
            cut(xs, xv, p);
        else
            cut(ys, yv, p);
        int xmax=*xv.rbegin();
        int ymax=*yv.rbegin();
        LL ans=LL(xmax)*LL(ymax);
        printf("%lld\n", ans);
    }
    return 0;
}