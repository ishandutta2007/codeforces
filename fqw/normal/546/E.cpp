// 17:41
// 17:43 - 
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


template<size_t N, size_t E, class T, T INFI> class Dinic { //{{{
    struct Edge {
        int y;  T w;
        Edge *next, *oppo;
    } edges[E*2];
    Edge *g[N], *ce[N];
    int e_cnt, n, src, dst;

    int d[N], q[N];
    bool build() {
        memset(d, 0, sizeof(d)); d[q[1]=src]=1;
        for(int ss=0, tt=1; ss<tt; ) {
            int x=q[++ss];
            for(Edge *e=ce[x]=g[x]; e; e=e->next)
                if(e->w>0 && d[e->y]==0) d[q[++tt]=e->y]=d[x]+1;
        }
        return d[dst]>0;
    }
    T find(int x, T rest) {
        if(x==dst) return rest;
        T ans=0;
        for(Edge *&e=ce[x]; e; e=e->next)
            if(e->w>0 && d[e->y]>d[x]) {
                T cur=find(e->y, min(e->w,rest));
                e->w-=cur; e->oppo->w+=cur;
                ans+=cur; rest-=cur;
                if(rest==0) break;
            }
        return ans;
    }
public:
    Dinic() { init(); }
    int s() { return src; }
    int t() { return dst; }
    void init() {
        memset(g, 0, sizeof(g)); e_cnt=0;
        n=2, src=1, dst=2;
    }
    int new_node() { return ++n; }
    void add_edge(int x, int y, T w1, T w2) {
        Edge *e1=&edges[e_cnt++], *e2=&edges[e_cnt++];
        e1->y=y, e1->w=w1, e1->oppo=e2, e1->next=g[x], g[x]=e1;
        e2->y=x, e2->w=w2, e2->oppo=e1, e2->next=g[y], g[y]=e2;
    }
    T compute() {
        T ans=0; while(build()) ans+=find(src, INFI); return ans;
    }
    T rest(int x, int y) {
        T s=0;
        for(Edge *e=g[x]; e; e=e->next)
            if(e->y==y)
                s+=e->w;
        return s;
    }
    vector<bool> get_left() {
        build();
        vector<bool> ans(n+1);
        for(int i=1; i<=n; ++i) ans[i]=(d[i]>0);
        return ans;
    }
}; //}}}

Dinic<210, 25000, int, 1<<30> net;

int main() {
    int n, m; scanf("%d%d", &n, &m);

    net.init();
    int l[110], r[110], sum=0, sum2=0;
    rep(i, 1, n) l[i]=net.new_node();
    rep(i, 1, n) r[i]=net.new_node();
    rep(i, 1, n) {
        int x; scanf("%d", &x); net.add_edge(net.s(), l[i], x, 0);
        sum+=x;
    }
    rep(i, 1, n) {
        int x; scanf("%d", &x); net.add_edge(r[i], net.t(), x, 0);
        sum2+=x;
    }
    if(sum!=sum2) { printf("NO\n"); return 0; }
    const int V=1000000;
    static int tot[110][110]; fillchar(tot, 0);
    rep(i, 1, m) {
        int a, b; scanf("%d%d", &a,&b);
        net.add_edge(l[a], r[b], V, 0);
        net.add_edge(l[b], r[a], V, 0);
        tot[a][b]+=V, tot[b][a]+=V;
    }
    rep(i, 1, n) net.add_edge(l[i], r[i], V, 0), tot[i][i]+=V;
    
    int val=net.compute();
    if(val==sum) {
        printf("YES\n");
        rep(i, 1, n) {
            rep(j, 1, n) { int x=tot[i][j]-net.rest(l[i], r[j]); printf("%d ", x); }
            printf("\n");
        }
    } else
        printf("NO\n");

    return 0;
}