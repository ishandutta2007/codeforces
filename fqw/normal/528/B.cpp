#include <algorithm>
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

const int MAXN=200010;

template<class T> class FenwickTree {
    std::vector<T> a;
    int n; T v0;
public:
    FenwickTree() { }
    FenwickTree(int _n, T v) : a(size_t(_n+1), v), n(_n), v0(v) { }
    void add(int x, T v) { for(; x<=n; x+=(x&-x)) a[(size_t)x]=max(a[(size_t)x], v); }
    T get(int x) const { T r=v0; for(; x>=1; x-=(x&-x)) r=max(r, a[(size_t)x]); return r; }
};

int main() {
    static PII a[MAXN];
    int n;
    scanf("%d", &n);
    rep(i, 1, n) {
        int x, w; scanf("%d%d", &x,&w);
        a[i]=mp(x-w, x+w);
    }
    sort(a+1, a+n+1);

    VI xs;
    rep(i, 1, n) xs.pb(a[i].fi), xs.pb(a[i].se);
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    rep(i, 1, n) {
        a[i].fi=int(lower_bound(all(xs), a[i].fi)-xs.begin()+1);
        a[i].se=int(lower_bound(all(xs), a[i].se)-xs.begin()+1);
    }

    FenwickTree<int> tr((int)xs.size(), 0);
    int ans=0;
    rep(i, 1, n) {
        int val=tr.get(a[i].fi)+1;
        tr.add(a[i].se, val);
        setmax(ans, val);
    }
    printf("%d\n", ans);


    return 0;
}