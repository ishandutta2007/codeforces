// 20:35
// 20:42 - 
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

const int MAXN=500010;

int lc[MAXN], rc[MAXN], fa[MAXN], dep[MAXN];
int st[MAXN], en[MAXN], tt;
VPI hs[MAXN];
char str[MAXN];
int n, m;

void dfs(int x, int d) {
    st[x]=++tt; dep[x]=d;
    hs[d].pb(mp(tt, x));
    for(int y=lc[x]; y; y=rc[y])
        dfs(y, d+1);
    en[x]=tt;
}

struct A {
    int cnt[26];
};

vector<A> cs[MAXN];

int main() {
    scanf("%d%d",&n,&m);
    fillchar(lc, 0);
    rep(i, 2, n) { scanf("%d", &fa[i]); rc[i]=lc[fa[i]]; lc[fa[i]]=i; }
    scanf("%s", str+1);

    rep(i, 1, n) hs[i].clear();
    tt=0; dfs(1, 1);
    rep(i, 1, n) if(hs[i].size()>0) {
        cs[i].resize(hs[i].size()+1);
        fillchar(cs[i][0].cnt, 0);
        repn(j, hs[i].size()) {
            cs[i][j+1]=cs[i][j];
            cs[i][j+1].cnt[int(str[hs[i][j].se]-'a')]++;
        }
    }

    repn(k, m) {
        int v, h; scanf("%d%d", &v,&h);
        int l=int(lower_bound(all(hs[h]), mp(st[v],0))-hs[h].begin());
        int r=int(lower_bound(all(hs[h]), mp(en[v]+1,0))-hs[h].begin());
        bool ans=false;
        //printf("l=%d r=%d sz=%d\n",l,r,(int)hs[h].size());
        if(l<r) {
            A sl=cs[h][l];
            A sr=cs[h][r];
            int cnt=0;
            repn(i, 26) if((sr.cnt[i]-sl.cnt[i])%2!=0) ++cnt;
            if(cnt<=1) ans=true;
        } else {
            ans=true;
        }
        puts(ans?"Yes":"No");
    }
    return 0;
}