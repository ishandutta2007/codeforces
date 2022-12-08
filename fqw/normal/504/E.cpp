#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <functional>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
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
typedef unsigned long long ULL;
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

const int N=300010;
const int LOG=20;
constexpr LL MOD=LL(1e9)+7;
static LL P=911;
static LL inv_P=[&]{
    LL a=P, b=MOD-2, c=1;
    for(; b; b>>=1, a=a*a%MOD)
        if(b&1) c=c*a%MOD;
    return c;
}();

char chars[N];
VI es[N];
int n;

int seq[N], ind[N], head[N], dep[N], fa[N];
LL hu[N], hd[N], power[N], inv_power[N];

void prepare() {
    static int size[N], maxp[N];
    function<void(int, int, int)> dfs1=[&](int x, int f, int d) {
        dep[x]=d, fa[x]=f;
        size[x]=1, maxp[x]=0;
        for(int y: es[x]) if(y!=f) {
            dfs1(y, x, d+1);
            size[x]+=size[y];
            if(maxp[x]==0 || size[y]>size[maxp[x]])
                maxp[x]=y;
        }
    };
    dfs1(1, 0, 1);

    int cur=0;
    function<void(int, int, int)> dfs2=[&](int x, int f, int h) {
        int ny=maxp[x];
        for(int y: es[x]) if(y!=f && y!=ny) {
            dfs2(y, x, y);
        }
        if(ny>0) dfs2(ny, x, h);
        head[x]=h, seq[ind[x]=++cur]=x;
    };
    dfs2(1, 0, 1);

    power[0]=1; rep(i, 1, n) power[i]=power[i-1]*P%MOD;
    inv_power[0]=1; rep(i, 1, n) inv_power[i]=inv_power[i-1]*inv_P%MOD;
    hu[0]=hd[0]=0;
    function<void(int, int)> dfs3=[&](int x, int f) {
        hu[x]=(hu[f]*P+LL(chars[x]))%MOD;
        hd[x]=(hd[f]+LL(chars[x])*power[dep[x]-1])%MOD;
        for(int y: es[x]) if(y!=f) {
            dfs3(y, x);
        }
    };
    dfs3(1, 0);
}

struct Seg { int x, d; bool up; };

Seg* extract(int x, int y, Seg* begin, Seg* end) {
    auto i=begin, j=end;
    int nx=head[x], ny=head[y], num=0;
    while(1) {
        if(nx==ny) {
            *(i++)=Seg{x, abs(dep[x]-dep[y])+1, dep[x]>dep[y]};
            break;
        }
        if(dep[nx]>dep[ny]) {
            *(i++)=Seg{x, dep[x]-dep[nx]+1, true};
            x=fa[nx], nx=head[x];
        } else {
            *(--j)=Seg{ny, dep[y]-dep[ny]+1, false};
            ++num;
            y=fa[ny], ny=head[y];
        }
    }
    memmove(i, j, sizeof(Seg)*num);
    return i+num;
}


int solve(int x1, int y1, int x2, int y2) {
    auto hash=[&](const Seg& s, int len) {
        if(s.up) {
            int y=fa[seq[ind[s.x]+len-1]];
            return hu[s.x]-hu[y]*power[len];
        } else {
            int y=seq[ind[s.x]-len+1], x=fa[s.x];
            return (hd[y]-hd[x])*inv_power[dep[x]];
        }
    };
    auto go=[&](int x, int d, bool up) {
        if(up) {
            return seq[ind[x]+d];
        } else {
            return seq[ind[x]-d];
        }
    };

    static constexpr int L=40;
    static Seg p1[L]; auto end1=extract(x1, y1, p1, p1+L);
    static Seg p2[L]; auto end2=extract(x2, y2, p2, p2+L);
    int ans=0;
    auto i=p1, j=p2;
    while(i!=end1 && j!=end2) {
        int len=min(i->d, j->d);
        if((hash(*i, len)-hash(*j, len))%MOD!=0) {
            break;
        }
        ans+=len;
        if(i->d==len) ++i; else i->d-=len, i->x=go(i->x, len, i->up);
        if(j->d==len) ++j; else j->d-=len, j->x=go(j->x, len, j->up);
    }
    if(i<end1 && j<end2) {
        int le=0, ri=min(i->d, j->d);
        while(le<ri) {
            int len=(le+ri+1)/2;
            if((hash(*i, len)-hash(*j, len))%MOD==0) {
                le=len;
            } else {
                ri=len-1;
            }
        }
        ans+=le;
    }
    return ans;
}

int main() {
    scanf("%d%s", &n,chars+1);
    repn(i, n-1) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b), es[b].pb(a);
    }
    prepare();
    int q; scanf("%d", &q);
    while(q--) {
        int x1, y1, x2, y2; scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
        int r=solve(x1, y1, x2, y2);
        printf("%d\n", r);
    }
    return 0;
}