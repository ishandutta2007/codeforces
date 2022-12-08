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
const int MAXE=300010;

VPI es[MAXN];
bool vis[MAXE];
int n;

VPI ans;

void go(int start) {
    while(!es[start].empty() && vis[es[start].back().se])
        es[start].pop_back();
    if(es[start].empty()) return;

    VI path;
    for(int x=start; ;) {
        path.pb(x);
        while(vis[es[x].back().se])
            es[x].pop_back();
        vis[es[x].back().se]=true;
        int y=es[x].back().fi;
        if(y==start) break;
        x=y;
    }
    repn(i, path.size()) {
        go(path[i]);
        ans.pb(mp(path[i], path[(i+1)%path.size()]));
    }
}

VPI get_cycle() {
    fillchar(vis, false);
    ans.clear();
    go(1);
    return ans;
}

int main() {
    int m; scanf("%d%d", &n,&m);
    repn(i, m) { 
        int a, b; scanf("%d%d", &a,&b); 
        es[a].pb(mp(b, i));
        es[b].pb(mp(a, i)); 
    }
    int la=-1;
    rep(i, 1, n) if(es[i].size()%2==1) {
        if(la>0) {
            ++m;
            es[i].pb(mp(la, m));
            es[la].pb(mp(i, m));
            la=-1;
        } else
            la=i;
    }
    assert(la<0);

    if(m%2==1) {
        ++m; 
        es[1].pb(mp(1, m));
        es[1].pb(mp(1, m));
    }

    VPI cycle=get_cycle();
    assert((int)cycle.size()==m);

    printf("%d\n", m);
    bool b=true;
    for(PII p: cycle) {
        b=!b;
        if(b) swap(p.fi, p.se);
        printf("%d %d\n", p.fi,p.se);
    }

    return 0;
}