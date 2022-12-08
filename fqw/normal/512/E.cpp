// 21:03
#include <algorithm>
#include <set>
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

const int MAXN=1010;

struct Node {
    int a, b, c;
    int l, r, size;
} tr[MAXN*2];
int node_cnt;
int root1, root2;

set<int> es[MAXN]; int n;

int make_node(int a, int b) {
    if(b%n+1==a) return 0;
    int c=b%n+1;
    while(c!=a) {
        if(es[a].find(c)!=es[a].end()) break;
        c=c%n+1;
    }
    assert(c!=a);
    assert(es[a].find(c)!=es[a].end());
    assert(es[b].find(c)!=es[b].end());
    int x=++node_cnt;
    tr[x].a=a, tr[x].b=b, tr[x].c=c;
    tr[x].l=make_node(a, c);
    tr[x].r=make_node(c, b);
    tr[x].size=1+tr[tr[x].l].size+tr[tr[x].r].size;
    return x;
}

int make(VPI x) {
    assert(int(x.size())==n-3);
    rep(i, 1, n) es[i].clear();
    rep(i, 1, n) es[i].insert(i%n+1), es[i%n+1].insert(i);
    for(PII p: x) es[p.fi].insert(p.se), es[p.se].insert(p.fi);
    return make_node(1, 2);
}

vector<pair<PII,PII>> operations;

int lrotate(int x) {
    int y=tr[x].l; tr[x].l=tr[y].r; tr[y].r=x;
    int a=tr[x].a, b=tr[x].b, c=tr[x].c, d=tr[y].c;
    assert(a==tr[y].a && c==tr[y].b);
    tr[y].a=a, tr[y].b=b, tr[y].c=d;
    tr[x].a=d, tr[x].b=b, tr[x].c=c;
    tr[x].size=tr[tr[x].l].size+tr[tr[x].r].size+1;
    tr[y].size=tr[tr[y].l].size+tr[tr[y].r].size+1;
    operations.pb(mp(mp(a,c), mp(b,d)));
    return y;
}

int rrotate(int x) {
    int y=tr[x].r; tr[x].r=tr[y].l; tr[y].l=x;
    int a=tr[x].a, b=tr[x].b, c=tr[x].c, d=tr[y].c;
    assert(c==tr[y].a && b==tr[y].b);
    tr[y].a=a, tr[y].b=b, tr[y].c=d;
    tr[x].a=a, tr[x].b=d, tr[x].c=c;
    tr[x].size=tr[tr[x].l].size+tr[tr[x].r].size+1;
    tr[y].size=tr[tr[y].l].size+tr[tr[y].r].size+1;
    operations.pb(mp(mp(b,c), mp(a,d)));
    return y;
}

int extract_kth(int x, int k) {
    int lsize=tr[tr[x].l].size;
    if(k==lsize+1)
        return x;
    if(k<=lsize) {
        tr[x].l=extract_kth(tr[x].l, k);
        x=lrotate(x);
    } else {
        tr[x].r=extract_kth(tr[x].r, k-lsize-1);
        x=rrotate(x);
    }
    return x;
}

int build_bst(int x) {
    if(x==0) return 0;
    int k=(tr[x].size+1)/2;
    x=extract_kth(x, k);
    tr[x].l=build_bst(tr[x].l);
    tr[x].r=build_bst(tr[x].r);
    return x;
}

int main() {
    scanf("%d", &n);
    VPI x(n-3); for(PII &p: x) scanf("%d%d", &p.fi,&p.se);
    VPI y(n-3); for(PII &p: y) scanf("%d%d", &p.fi,&p.se);
    node_cnt=0; fillchar(tr, 0);
    root1=make(x);
    root2=make(y);

    operations.clear(); root1=build_bst(root1); auto tmp1=operations;
    operations.clear(); root2=build_bst(root2); auto tmp2=operations;
    VPI ans;
    for(auto o: tmp1) ans.pb(o.fi);
    reverse(all(tmp2));
    for(auto o: tmp2) ans.pb(o.se);

    printf("%d\n", (int)ans.size());
    for(auto p: ans) printf("%d %d\n", p.fi,p.se);

    return 0;
}