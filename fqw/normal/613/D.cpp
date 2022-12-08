// 4:14 - 4:26 - wa sample
#include <cassert>
#include <set>
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

const int MAXN=100010;
const int MAXQ=100010;

VI es[MAXN], queries[MAXQ];
int ans[MAXQ];
int father[MAXN];
int n, q;

void add(int i, int v) { if(ans[i]>=0) ans[i]+=v; }

typedef map<int, int> Map;

Map* merge(Map* a, Map* b, map<int, set<int>>& groups) {
    if(a->size()<b->size()) return merge(b, a, groups);
    for(auto& kv: *b) {
        if(a->count(kv.fi)) {
            groups[kv.fi].insert(kv.se);
        } else {
            a->insert(kv);
        }
    }
    delete b;
    return a;
}

Map* dfs(int x, int fa) {
    father[x]=fa;
    Map* r=new Map();
    map<int, set<int>> groups;

    for(int y: es[x]) if(y!=fa) {
        Map* t=dfs(y, x);
        r=merge(r, t, groups);
    }
    for(auto& ks: groups)
        if(r->count(ks.fi)) {
            ks.se.insert(r->find(ks.fi)->se);
            r->erase(ks.fi);
        }

    for(int i: queries[x]) {
        if(r->count(i)) {
            groups[i].insert(r->find(i)->se);
            r->erase(i);
        }
        if(groups.count(i)) {
            for(int y: groups[i]) if(father[y]==x) ans[i]=-1;
            add(i, (int)groups[i].size());
            groups.erase(i);
        }
        r->insert(mp(i, x));
    }

    for(auto& ks: groups) add(ks.fi, 1);

    return r;
}

int main() {
    scanf("%d", &n); rep(i, 1, n) es[i].clear();
    rep(i, 1, n-1) { int x, y; scanf("%d%d", &x,&y); es[x].pb(y), es[y].pb(x); }
    scanf("%d", &q); rep(i, 1, q) queries[i].clear();
    rep(i, 1, q) {
        int k; scanf("%d", &k);
        while(k--) { int x; scanf("%d", &x); queries[x].pb(i); }
    }

    fillchar(ans, 0);
    dfs(1, 0);
    rep(i, 1, q) printf("%d\n", ans[i]);

    return 0;
}