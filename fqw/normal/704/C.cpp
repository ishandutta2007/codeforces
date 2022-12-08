#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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
const int M=100010;
const LL MOD=LL(1e9)+7;

struct Edge {
    int x, y;
    int nx, ny;
};

Edge edges[M]; bool pos[N], neg[N];

VPI es[N];
int n, m;

int eval(int ei, int x, int vx, int y, int vy) {
    if(x!=edges[ei].x) swap(x, y), swap(vx, vy);
    assert(x==edges[ei].x && y==edges[ei].y);
    vx^=edges[ei].nx, vy^=edges[ei].ny;
    return vx|vy;
}

PLL cal(VI xs, VI eis) {
    //printf("cal:\n");
    //for(int x: xs) printf(" %d", x); printf("\n");
    //for(int x: eis) printf(" %d", x); printf("\n");
    assert(sz(xs)>=2 && (sz(eis)+1==sz(xs) || sz(eis)==sz(xs)));
    VL ans(2);
    repn(start, 2) {
        static LL f[N][2][2];
        int num=sz(xs);
        rep(i, 0, num) repn(j, 2) repn(k, 2) f[i][j][k]=0;
        f[0][0][0]=1;
        repn(i, num) repn(j, 2) repn(k, 2) {
            repn(cur, 2) {
                if(i==0 && cur!=start) continue;
                int k2=k; if(i>0) k2^=eval(eis[i-1], xs[i-1], j, xs[i], cur);
                if(pos[xs[i]] && cur==1) k2^=1;
                if(neg[xs[i]] && cur==0) k2^=1;
                (f[i+1][cur][k2]+=f[i][j][k])%=MOD;
            }
        }
        repn(j, 2) repn(k, 2) {
            int k2=k;
            if(num-1<sz(eis)) k2^=eval(eis[num-1], xs[num-1], j, xs[0], start);
            (ans[k2]+=f[num][j][k])%=MOD;
        }
    }
    //printf("%d %d\n", int(ans0), int(ans1));
    return mp(ans[0], ans[1]);
}

LL solve(int want) {
    LL ans0=1, ans1=0;
    auto merge=[&](LL tmp0, LL tmp1) {
        LL a0=(ans0*tmp0+ans1*tmp1)%MOD;
        LL a1=(ans0*tmp1+ans1*tmp0)%MOD;
        //printf("merge (%d,%d) (%d,%d) -> (%d,%d)\n",int(ans0),int(ans1),int(tmp0),int(tmp1),int(a0),int(a1));
        ans0=a0, ans1=a1;
    };
    rep(i, 1, n) if(es[i].empty()) {
        if(!pos[i] && !neg[i]) merge(2, 0);
        else if(pos[i] && neg[i]) merge(0, 2);
        else merge(1, 1);
    }
    rep(i, 1, n) if(sz(es[i])==1) {
        VI xs, eis;
        int x=i; xs.pb(x);
        while(sz(es[x])>0) {
            int y=es[x][0].fi, ei=es[x][0].se;
            xs.pb(y), eis.pb(ei);
            es[x].erase(es[x].begin());
            repn(j, sz(es[y])) if(es[y][j].se==ei) {
                es[y].erase(es[y].begin()+j);
                break;
            }
            x=y;
        }
        PLL tmp=cal(xs, eis);
        merge(tmp.fi, tmp.se);
    }
    rep(i, 1, n) if(sz(es[i])==2) {
        VI xs, eis;
        int x=i; xs.pb(x);
        while(sz(es[x])>0) {
            int y=es[x][0].fi, ei=es[x][0].se;
            xs.pb(y), eis.pb(ei);
            es[x].erase(es[x].begin());
            repn(j, sz(es[y])) if(es[y][j].se==ei) {
                es[y].erase(es[y].begin()+j);
                break;
            }
            x=y;
        }
        assert(xs.back()==i && x==i);
        xs.pop_back();

        PLL tmp=cal(xs, eis);
        merge(tmp.fi, tmp.se);
    }
    return want?ans1:ans0;
}

int main() {
    scanf("%d%d", &m,&n);
    fillchar(pos, false);
    fillchar(neg, false);
    int want=1;
    rep(i, 1, m) {
        int k; scanf("%d", &k);
        if(k==1) {
            int x; scanf("%d", &x);
            if(x>0) pos[x]^=true; else neg[-x]^=true;
        } else {
            int x, y; scanf("%d%d", &x,&y);
            if(abs(x)==abs(y)) {
                if(x==y) { if(x>0) pos[x]^=true; else neg[-x]^=true; }
                else want^=1;
            } else {
                edges[i].x=abs(x), edges[i].y=abs(y);
                edges[i].nx=(x<0), edges[i].ny=(y<0);
                x=abs(x), y=abs(y);
                es[x].pb(mp(y, i));
                es[y].pb(mp(x, i));
            }
        }
    }
    LL ans=solve(want);
    printf("%d\n", int(ans));
    return 0;
}