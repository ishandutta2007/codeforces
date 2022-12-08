// 8:56
// 9:01 - 
#include <cassert>
#include <iostream>
#include <algorithm>
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

const int N=100010;

int a[N], diff[N], n;
int ind[N];
VI lst[N];

int rt[N], sz[N]; int get(int x) {
    return rt[x]==0 ? x : (rt[x]=get(rt[x]));
}

void solve(int l, int r) {
    fillchar(rt, 0);
    fillchar(sz, 0);
    rep(i, l+1, r)
        lst[ind[i]].pb(i);
    LL ans=0;
    repn(k, n) {
        for(int i: lst[k]) {
            //printf("i=%d diff=%d cnt=%d\n",i,diff[i],(x+1)*(y+1);
            int x=get(i-1), y=get(i);
            LL cnt=(sz[x]+1)*LL(sz[y]+1);
            ans+=cnt*diff[i];
            rt[y]=x, sz[x]+=sz[y]+1;
        }
        lst[k].clear();
    }
    cout<<ans<<endl;
}

int main() {
    int q; scanf("%d%d", &n,&q);
    rep(i, 1, n) scanf("%d", &a[i]);

    auto absv=[](int x) { return x>0?x:-x; };
    VI vec; rep(i, 2, n) vec.pb(diff[i]=absv(a[i]-a[i-1]));
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    rep(i, 2, n) {
        ind[i]=int(lower_bound(all(vec), diff[i]) - vec.begin());
    }

    while(q--) {
        int l, r; scanf("%d%d", &l,&r);
        solve(l, r);
    }
    return 0;
}