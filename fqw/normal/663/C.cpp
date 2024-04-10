#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define _ (int)
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

const int N=100010;
const int MAXV=1<<30;

VPI es[N];
int n, m;

int color[N];
VI this_turn[2];

bool dfs(int x, int c) {
    if(color[x]>=0) return color[x]==c;
    color[x]=c; this_turn[c].pb(x);
    for(auto e: es[x]) if(!dfs(e.fi, c^e.se)) return false;
    return true;
}

pair<int, VI> solve() {
    fillchar(color, -1);
    VI r;
    rep(x, 1, n) if(color[x]<0) {
        this_turn[0].clear();
        this_turn[1].clear();
        if(!dfs(x, 0)) return mp(MAXV, VI());
        auto& cur=(this_turn[0].size()<this_turn[1].size()?this_turn[0]:this_turn[1]);
        r.insert(r.end(), all(cur));
    }
    return mp((int)r.size(), r);
}

int main() {
    scanf("%d%d", &n,&m);
    rep(x, 1, n) es[x].clear();
    rep(k, 1, m) {
        int x, y, z; char c[9];
        scanf("%d%d%s", &x,&y,c); z=(c[0]=='B'?1:0);
        es[x].pb(mp(y, z));
        es[y].pb(mp(x, z));
    }
    auto ans=solve();
    rep(x, 1, n) for(auto& e: es[x]) e.se^=1;
    setmin(ans, solve());
    if(ans.fi==MAXV) printf("-1\n");
    else {
        printf("%d\n", ans.fi);
        for(int x: ans.se) printf("%d ", x); printf("\n");
    }
    return 0;
}