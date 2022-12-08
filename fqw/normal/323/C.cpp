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

const int MAXLog=21;
const int N=1001000;
const int MAXNodes=N*(MAXLog+1);

struct Node {
    int cnt;
    int child[2];
} tr[MAXNodes];
int num, root[N], n;

int ins(int x, int v, int d) {
    tr[++num]=tr[x], x=num; ++tr[x].cnt;
    if(d<0) return x;
    int c=(v&(1<<d))?1:0;
    tr[x].child[c]=ins(tr[x].child[c], v, d-1);
    return x;
}

void init() {
    scanf("%d", &n);
    static int p[N], q[N], rq[N], a[N];
    rep(i, 1, n) scanf("%d", &p[i]);
    rep(i, 1, n) scanf("%d", &q[i]);
    rep(i, 1, n) rq[q[i]]=i;
    rep(i, 1, n) a[i]=rq[p[i]];
    //rep(i, 1, n) printf("a[%d]=%d\n", i,a[i]);

    memset(&tr[0], 0, sizeof(tr[0]));
    root[0]=0;
    rep(i, 1, n) root[i]=ins(root[i-1], a[i], MAXLog-1);
}

int get(int x, int v, int d) {
    if(d<0) return tr[x].cnt;
    if(x==0) return 0;
    int ans=0;
    int c=(v&(1<<d))?1:0; if(c==1) ans+=tr[tr[x].child[0]].cnt;
    ans+=get(tr[x].child[c], v, d-1);
    return ans;
}

int G(int t, int z) {
    int r=get(root[t], z, MAXLog-1);
    //printf("G(%d,%d)=%d\n",t,z,r);
    return r;
}

int F(int t, int l, int r) {
    return G(t, r)-G(t, l-1);
}

void solve() {
    int m; scanf("%d", &m);
    int ans=-1;
    while(m--) {
        ++ans;
        int a, b, c, d; scanf("%d%d%d%d", &a,&b,&c,&d);
        int _n=n; auto f=[&ans, _n](int z) { return ((z-1+ans)%_n)+1; };
        a=f(a), b=f(b), c=f(c), d=f(d);
        int l1=min(a, b), r1=max(a, b);
        int l2=min(c, d), r2=max(c, d);
        //printf("%d %d %d %d\n",l1,r1,l2,r2);
        ans=F(r1, l2, r2)-F(l1-1, l2, r2);
        printf("%d\n", ans);
    }
}

int main() {
    init();
    solve();
    return 0;
}