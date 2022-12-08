// 11:38 - 11:54 - wa sample
//       - 12:06 - pass sample
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

const int N=5010;
const int K=1010;
const int Q=30010;

int v[N+Q], w[N+Q], start[N+Q], available[N+Q];
int n, k, q, num, ans[Q];

struct Exhibit {
    int l, r, v, w, id;
    Exhibit(int l, int r, int v, int w, int id)
        : l(l), r(r), v(v), w(w), id(id) { }
};

struct Res {
    int f[K];
    Res() {
        fillchar(f, 0);
    }
    void add(int v, int w) {
        irep(i, k-w, 0) setmax(f[i+w], f[i]+v);
    }
    int hash() const {
        const int p=int(1e7)+19;
        const int q=int(1e9)+7;
        LL ans=0;
        irep(i, k, 1) {
            ans=(ans*p+f[i])%q;
        }
        return int(ans);
    }
};

void solve(Res res, const vector<Exhibit> &exs, int l, int r) {
    vector<Exhibit> el, er;
    int mid=(l+r)/2;
    //printf("\n");
    for(const auto &e: exs) {
        if(e.l<=l && r<=e.r) {
        //printf("l=%d r=%d: l=%d r=%d v=%d w=%d [id=%d]\n",l,r,e.l,e.r,e.v,e.w,e.id);
            res.add(e.v, e.w);
        } else {
            if(e.l<=mid) el.pb(e);
            if(e.r>mid) er.pb(e);
        }
    }
    if(l==r) {
        //printf("l=r=%d: ", l); rep(i, 1, k) printf("%d ", res.f[i]); printf("\n");
        ans[l]=res.hash();
        return;
    }
    solve(res, el, l, mid);
    solve(res, er, mid+1, r);
}

int main() {
    fillchar(available, false);
    scanf("%d%d", &n,&k);
    rep(i, 1, n) scanf("%d%d", &v[i],&w[i]), available[i]=true, start[i]=1;

    scanf("%d", &q);
    vector<Exhibit> exs;
    num=0;
    int i=0;
    rep(__, 1, q) {
        int t; scanf("%d", &t);
        if(t==1) {
            ++i;
            scanf("%d%d", &v[n+i],&w[n+i]);
            available[n+i]=true;
            start[n+i]=num+1;
        } else if(t==2) {
            int p; scanf("%d", &p);
            available[p]=false;
            exs.pb(Exhibit(start[p], num, v[p], w[p], p));
        } else if(t==3) {
            ++num;
        }
    }
    rep(i, 1, n+q) if(available[i])
        exs.pb(Exhibit(start[i], num, v[i], w[i], i));

    Res res;
    solve(res, exs, 1, num);

    rep(i, 1, num) printf("%d\n", ans[i]);

    return 0;
}