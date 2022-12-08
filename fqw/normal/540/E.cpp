// 15:13
// 15:15 - 
#include <cassert>
#include <algorithm>
#include <cstring>
#include <map>
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

template<class T> class FenwickTree {
    std::vector<T> a;
    int n; T v0;
public:
    FenwickTree() { }
    FenwickTree(int n, T v) : a(size_t(n+1), v), n(n), v0(v) { }
    void add(int x, T v) { for(; x<=n; x+=(x&-x)) a[(size_t)x]+=v; }
    T get(int x) const { T r=v0; for(; x>=1; x-=(x&-x)) r+=a[(size_t)x]; return r; }
};

int main() {
    int num; scanf("%d", &num);
    map<int,int> h;
    rep(i, 1, num) {
        int a, b; scanf("%d%d", &a,&b);
        if(h.count(a)==0) h[a]=a;
        if(h.count(b)==0) h[b]=b;
        swap(h[a], h[b]);
    }
    VPI lst;
    int cur=1;
    for(PII p: h) {
        if(cur<p.fi) {
            lst.pb(mp(cur, p.fi-cur));
        }
        lst.pb(mp(p.se, 1));
        cur=p.fi+1;
    }

    VI vs;
    for(PII &p: lst) vs.pb(p.fi);
    sort(all(vs));
    vs.erase(unique(all(vs)), vs.end());
    for(PII &p: lst) p.fi=int(lower_bound(all(vs), p.fi)-vs.begin()+1);
    int n=(int)vs.size();

    FenwickTree<LL> tr(n, 0);
    reverse(all(lst));
    LL ans=0;
    for(PII p: lst) {
        ans+=tr.get(p.fi)*LL(p.se);
        tr.add(p.fi, p.se);
    }
    printf("%lld\n", ans);
    return 0;
}