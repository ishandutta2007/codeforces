// 10:40
// 10:49 - 11:06 - wa
#include <cassert>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
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

const int MAXN=200010;
const int MAXV=int(1e9);

PII a[MAXN], b[MAXN];
int c[MAXN], ans[MAXN], ansv[MAXN];
int n, m;

void update(int i, int j) {
    if(i==0) return;
    int l=max(a[i].fi, b[j].fi);
    int r=min(a[i].se, b[j].se);
    if(r-l>ansv[j]) {
        ans[j]=i, ansv[j]=r-l;
    }
}

void go1() {
    int cur=0;
    VPI lst;
    rep(i, 1, n) lst.pb(mp(a[i].fi, -i));
    rep(j, 1, m) lst.pb(mp(b[j].fi, j));
    sort(all(lst));
    for(PII p: lst)
        if(p.se>0) {
            int j=p.se;
            update(cur, j);
        } else {
            int i=-p.se;
            if(cur==0 || a[i].se>a[cur].se)
                cur=i;
        }
}

int a2[MAXN], b2[MAXN], num;

void discretize() {
    VI lst;
    rep(i, 1, n) lst.pb(a[i].se);
    rep(i, 1, m) lst.pb(b[i].se);
    sort(all(lst));
    lst.erase(unique(all(lst)), lst.end());
    num=(int)lst.size();
    rep(i, 1, n) a2[i]=int(lower_bound(all(lst), a[i].se)-lst.begin()+1);
    rep(i, 1, m) b2[i]=int(lower_bound(all(lst), b[i].se)-lst.begin()+1);
}

template<class T> class FenwickTree {
    std::vector<T> a;
    int n; T v0;
public:
    FenwickTree() { }
    FenwickTree(int _n, T _v) : a(size_t(_n+1), _v), n(_n), v0(_v) { }
    void add(int x, T v) { for(; x<=n; x+=(x&-x)) a[(size_t)x]=max(a[(size_t)x], v); }
    T get(int x) const { T r=v0; for(; x>=1; x-=(x&-x)) r=max(r, a[(size_t)x]); return r; }
};

void go2() {
    discretize();

    VPI lst;
    rep(i, 1, n) lst.pb(mp(-a[i].fi, -i));
    rep(j, 1, m) lst.pb(mp(-b[j].fi, j));
    sort(all(lst));

    FenwickTree<PII> tr(num, mp(0,0));
    for(PII p: lst)
        if(p.se>0) {
            int j=p.se;
            PII va=tr.get(b2[j]);
            update(va.se, j);
        } else {
            int i=-p.se;
            tr.add(a2[i], mp(a[i].se-a[i].fi, i));
        }
}

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, n) scanf("%d%d", &a[i].fi,&a[i].se);
    rep(i, 1, m) scanf("%d%d%d", &b[i].fi,&b[i].se,&c[i]);

    fillchar(ans, 0);
    fillchar(ansv, 0);
    go1();
    rep(i, 1, n) a[i].fi=MAXV-a[i].fi, a[i].se=MAXV-a[i].se, swap(a[i].fi,a[i].se);
    rep(i, 1, m) b[i].fi=MAXV-b[i].fi, b[i].se=MAXV-b[i].se, swap(b[i].fi,b[i].se);
    go1();
    rep(i, 1, n) a[i].fi=MAXV-a[i].fi, a[i].se=MAXV-a[i].se, swap(a[i].fi,a[i].se);
    rep(i, 1, m) b[i].fi=MAXV-b[i].fi, b[i].se=MAXV-b[i].se, swap(b[i].fi,b[i].se);
    go2();

    LL best=0;
    int besti=0, bestj=0;
    rep(j, 1, m) {
        int i=ans[j]; if(i==0) continue;
        if(setmax(best, LL(ansv[j])*LL(c[j])))
            besti=i, bestj=j;
    }
    cout<<best<<endl;
    if(best>0) cout<<besti<<" "<<bestj<<endl;

    return 0;
}