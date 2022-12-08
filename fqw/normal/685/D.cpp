#include <map>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

const int N=100010;

int main() {
    int n, k; scanf("%d%d", &n,&k);
    map<LL, vector<pair<int, LL>>> a;
    rep(i, 1, n) {
        LL x, y; scanf("%lld%lld", &x,&y);
        a[x].pb(mp(+1, y));
        a[x+k].pb(mp(-1, y));
    }
    map<LL, int> b;
    vector<LL> ans(n+1);
    for(auto it=a.begin(), nit=next(it); nit!=a.end(); ++it, ++nit) {
        LL width=nit->fi-it->fi;
        for(const auto& p: it->se) {
            if((b[p.se]+=p.fi)==0) b.erase(p.se);
            if((b[p.se+k]-=p.fi)==0) b.erase(p.se+k);
        }
        if(!b.empty()) {
            int cnt=0;
            for(auto u=b.begin(), v=next(u); v!=b.end(); ++u, ++v) {
                LL height=v->fi-u->fi;
                cnt+=u->se;
                ans[cnt]+=height*width;
            }
        }
    }
    rep(i, 1, n) printf("%lld ", ans[i]); printf("\n");
    return 0;
}