#include <unordered_map>
#include <map>
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

int a[N]; pair<PII, int> qs[N];
int n, q;

LL solve(const VPI& m0) {
    //printf("m0:\n"); for(const auto& kv: m0) printf("%d %d\n",kv.fi,kv.se);
    static PII x[N], y[N];
    int xs=1, xt=0, ys=1, yt=0;
    for(const auto& kv: m0) y[++yt]=kv;
    sort(y+1, y+yt+1);

    LL ans=0;
    int cached=0;
    while(xs<=xt || ys<=yt) {
        if(cached>0) {
            int v=0;
            if(xs<=xt && (ys>yt || x[xs].fi<y[ys].fi)) {
                v=x[xs].fi; if(--x[xs].se==0) ++xs;
            } else {
                v=y[ys].fi; if(--y[ys].se==0) ++ys;
            }
            ans+=cached+v;
            if(xs<=xt && x[xt].fi==cached+v) {
                ++x[xt].se;
            } else {
                x[++xt]=mp(cached+v, 1);
            }
            cached=0;
            continue;
        }
        PII p;
        if(xs<=xt && (ys>yt || x[xs].fi<y[ys].fi)) {
            p=x[xs]; ++xs;
        } else {
            p=y[ys]; ++ys;
        }
        if(p.se%2==1) cached=p.fi;
        if(p.se/2>0) {
            ans+=p.fi*(p.se/2)*2;
            if(xs<=xt && x[xt].fi==p.fi*2) {
                x[xt].se+=p.se/2;
            } else {
                x[++xt]=mp(p.fi*2, p.se/2);
            }
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    scanf("%d", &q);
    rep(i, 1, q) {
        scanf("%d%d", &qs[i].fi.fi, &qs[i].fi.se);
        qs[i].se=i;
    }
    sort(qs+1, qs+q+1);
    for(int i=1; i<=q; i+=300) {
        sort(qs+i, qs+min(i+300-1, q)+1, 
                [](const pair<PII,int>& u, const pair<PII,int>& v) {
                    return u.fi.se<v.fi.se;
                });
    }

    VI ca(100010), cc(100010), pre(100010), nxt(100010);
    VL ans(q+1);
    auto add=[&](int i) {
        auto& v=ca[a[i]];
        if(v>0) {
            if(--cc[v]==0) {
                nxt[pre[v]]=nxt[v];
                pre[nxt[v]]=pre[v];
            }
        }
        ++v;
        {
            if(cc[v]++==0) {
                pre[v]=0, nxt[v]=nxt[0];
                pre[nxt[v]]=nxt[pre[v]]=v;
                //printf("v=%d cc=%d nxt=%d\n",v,cc[v],nxt[0]);
            }
        }
    };
    auto remove=[&](int i) {
        auto& v=ca[a[i]];
        {
            if(--cc[v]==0) {
                nxt[pre[v]]=nxt[v];
                pre[nxt[v]]=pre[v];
            }
        }
        --v;
        if(v>0) {
            if(cc[v]++==0) {
                pre[v]=0, nxt[v]=nxt[0];
                pre[nxt[v]]=nxt[pre[v]]=v;
                //printf("v=%d cc=%d nxt=%d\n",v,cc[v],nxt[0]);
            }
        }
    };
    {
        int i=1, j=0;
        rep(k, 1, q) {
            const auto& kv=qs[k];
            while(j<kv.fi.se) add(++j);
            while(j>kv.fi.se) remove(j--);
            while(i<kv.fi.fi) remove(i++);
            while(i>kv.fi.fi) add(--i);
            //printf("go %d\n", kv.se);
            VPI m;
            for(int v=nxt[0]; v!=0; v=nxt[v]) m.pb(mp(v, cc[v]));
            ans[kv.se]=solve(m);
            //printf("go %d done\n", kv.se);
        }
    }
    rep(i, 1, q) printf("%lld\n", ans[i]);

    return 0;
}