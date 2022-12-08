#include <algorithm>
#include <set>
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
typedef vector<PLL> VPL;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

vector<VI> cal_obstacles(PLL p0, const VPL& ps) {
    vector<pair<PLL, pair<LL,int>>> a;
    repn(i, sz(ps)) {
        const LL x=ps[i].fi-p0.fi, y=ps[i].se-p0.se;
        const LL g=abs(gcd(x, y));
        const LL nx=x/g, ny=y/g;
        const LL dis=abs(x)+abs(y);
        a.pb(mp(mp(nx, ny), mp(dis, i)));
    }
    sort(all(a));
    vector<VI> r(sz(a));
    for(int i=0, j; i<sz(a); i=j) {
        for(j=i; j<sz(a) && a[j].fi==a[i].fi; ++j);
        VI cur;
        rep(k, i, j-1) {
            r[a[k].se.se]=cur;
            if(sz(cur)<=6) cur.pb(a[k].se.se);
        }
    }
    return r;
}

vector<vector<VI>> obstacles;

bool solve(const VI& as, const set<int>& bs, const set<int>& fbs) {
    if(sz(as)<sz(bs)) return false;
    if(sz(bs)==0) return true;
    const int b=*bs.begin();
    repn(i, sz(as)) if(sz(obstacles[as[i]][b])<=6){
        VI as0=as; as0.erase(as0.begin()+i);
        set<int> bs0=bs; bs0.erase(b);
        set<int> fbs0=fbs; fbs0.insert(b);
        for(int z: obstacles[as[i]][b]) if(fbs0.count(z)==0) bs0.insert(z);
        if(solve(as0, bs0, fbs0)) return true;
    }
    return false;
}

int main() {
    auto read=[] {
        int a, b; scanf("%d%d", &a,&b);
        return mp(LL(a), LL(b));
    };
    int k, n; scanf("%d%d", &k,&n);
    VPL a(k), m(n);
    for(auto& p: a) p=read();
    for(auto& p: m) p=read();
    obstacles.clear();
    for(const auto& p: a) {
        obstacles.pb(cal_obstacles(p, m));
    }

    int ans=0;
    repn(i, n) {
        bool ok=false;
        repn(j, k) {
            VI as; repn(z, k) if(z!=j) as.pb(z);
            set<int> bs(obstacles[j][i].begin(), obstacles[j][i].end());
            //printf("%d->%d  %d\n",j,i,bs.size());
            if(solve(as, bs, set<int>())) {
                ok=true; break;
            }
        }
        if(ok) ++ans;
    }
    printf("%d\n", ans);

    return 0;
}