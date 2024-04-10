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

const int MAXN=100010;
const int MAXV=10050;
const int MAXR=5050;

struct Recom {
    int l, r; double p;
    bool operator <(const Recom &t) const {
        return l<t.l || (l==t.l && r>t.r);
    }
};
Recom recom[MAXR];
int a[MAXN];
int n, q;

double distr[MAXR][MAXV];

void merge(double a[], double b[]) {
    double sa=0, sb=0;
    repn(i, MAXV) {
        sa+=a[i], sb+=b[i];
        a[i]=sa*sb;
    }
    irepn(i, MAXV-1) a[i+1]-=a[i];
}

void update_max(double a[], int v) {
    rep(i, 0, v-1) a[v]+=a[i], a[i]=0;
}

void add(double a[], double prob) {
    irepn(i, MAXV-1) a[i+1]=prob*a[i]+(1-prob)*a[i+1];
    a[0]=(1-prob)*a[0];
}

void dfs(int cur, int x, int y) {
    int i=recom[cur].l, maxv=0;
    fillchar(distr[cur], 0);
    distr[cur][0]=1;
    while(x<=y) {
        int son=x++;
        while(i<recom[son].l) setmax(maxv, a[i++]);
        i=recom[son].r+1;

        int sx=x, sy=x-1;
        while(x<=y && recom[x].r<=recom[son].r)
            sy=x, ++x;
        dfs(son, sx, sy);
        merge(distr[cur], distr[son]);
    }
    while(i<=recom[cur].r) setmax(maxv, a[i++]);
    update_max(distr[cur], maxv);
    add(distr[cur], recom[cur].p);
}

int main() {
    scanf("%d%d", &n,&q);
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 1, q) {
        int l, r; double p; scanf("%d%d%lf", &l, &r, &p);
        Recom t; t.l=l, t.r=r, t.p=p;
        recom[i]=t;
    }
    sort(recom+1, recom+q+1);

    int maxv=0;
    rep(i, 1, n) setmax(maxv, a[i]);
    int offset=5010-maxv;
    rep(i, 1, n) a[i]=max(0, a[i]+offset);

    recom[0].l=1, recom[0].r=n, recom[0].p=0;
    dfs(0, 1, q);

    double ans=0;
    repn(i, MAXV) ans+=distr[0][i]*i;
    ans-=offset;

    printf("%.9lf\n", ans);

    return 0;
}