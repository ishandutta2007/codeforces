#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
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
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

int main() {
    int n; scanf("%d", &n);
    vector<VPI> a;
    vector<pair<bool, bool>> w;
    repn(i, n) {
        int a1, b1, a2, b2;
        scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
        bool wa=(a1>b2), wb=(b1>a2);
        if(!wa && !wb) continue;
        if(!wa || !wb) {
            if(a1+b1>=a2+b2) wa=wb=true;
        }
        a.pb({mp(a2, b2), mp(a1, b1)});
        w.pb(mp(wa, wb));
    }
    n=sz(a);

    //cout<<a<<endl;

    set<PII> h[2];
    const auto add=[&](int i) {
        if(a[i].empty()) return;
        int s=a[i].back().fi+a[i].back().se;
        if(w[i].fi || sz(a[i])==1) h[0].insert(mp(s, i));
        if(w[i].se || sz(a[i])==1) h[1].insert(mp(s, i));
    };
    const auto remove=[&](int i) {
        int s=a[i].back().fi+a[i].back().se;
        h[0].erase(mp(s, i));
        h[1].erase(mp(s, i));
        a[i].pop_back();
    };
    repn(i, n) add(i);
    LL ans=0;
    while(!h[0].empty() || !h[1].empty()) {
        repn(k, 2) {
            if(h[k].empty()) continue;
            int i=h[k].rbegin()->se;
            if(k==0) {
                ans+=a[i].back().fi;
            } else {
                ans-=a[i].back().se;
            }
            remove(i); add(i);
        }
    }
    printf("%lld\n", ans);
    return 0;
}