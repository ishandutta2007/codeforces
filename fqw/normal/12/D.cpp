#include <algorithm>
#include <unordered_map>
#include <map>
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

const int INF=int(1e9)+1;

void discretize(VI* a) {
    VI xs;
    for(int x: *a) xs.pb(x);
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    for(int& x: *a) {
        x=int(lower_bound(all(xs), x)-xs.begin());
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    map<int, VPI> a;
    int n; cin>>n;
    {
        VI x(n), y(n), z(n);
        repn(i, n) cin>>x[i];
        repn(i, n) cin>>y[i]; discretize(&y);
        repn(i, n) cin>>z[i];
        repn(i, n) {
            a[INF-x[i]].pb(mp(n-y[i], INF-z[i]));
        }
    }

    VI tr(n+1, 1<<30);
    const auto add=[&tr,n](int x, int v) {
        for(; x<=n; x+=x&-x) {
            setmin(tr[x], v);
        }
    };
    const auto get=[&tr](int x) {
        int r=1<<30;
        for(; x>=1; x-=(x&-x)) {
            setmin(r, tr[x]);
        }
        return r;
    };

    int ans=0;
    for(const auto& kv: a) {
        for(const auto& p: kv.se) {
            if(get(p.fi-1)<p.se) {
                ++ans;
            }
        }
        for(const auto& p: kv.se) {
            add(p.fi, p.se);
        }
    }
    cout<<ans<<endl;


    return 0;
}