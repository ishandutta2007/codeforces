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
typedef vector<PLL> VPL;
typedef vector<string> VS;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

struct NumSet {
    int c[44], r[44];
    NumSet() {
        fillchar(c, 0), fillchar(r, 0);
    }

    bool insert(LL x, LL p) {
        const LL copy=x;
        for(int y=2; y<=x; ++y) {
            int z=1;
            while(x%y==0) {
                z*=y, x/=y;
                if(c[z]>0 && r[z]!=p%z) return false;
            }
        }
        x=copy;
        for(int y=2; y<=x; ++y) {
            int z=1;
            while(x%y==0) {
                z*=y, x/=y;
                ++c[z], r[z]=p%z;
            }
        }
        return true;
    }
    void erase(LL x) {
        for(int y=2; y<=x; ++y) {
            int z=1;
            while(x%y==0) {
                z*=y, x/=y;
                --c[z];
            }
        }
    }
};

int solve(const VPL& a) {
    if(a.empty()) return 0;
    int i=0, ans=0;
    NumSet s;
    repn(j, sz(a)) {
        while(!s.insert(a[j].fi, a[j].se)) {
            s.erase(a[i++].fi);
        }
        setmax(ans, j-i+1);
    }
    return ans;
}

int main() {
    int n, m; scanf("%d%d", &n,&m);
    vector<vector<pair<int, PLL>>> a(m);
    repn(i, n) {
        int k; scanf("%d", &k);
        repn(j, k) {
            int x; scanf("%d", &x);
            --x;
            a[x].pb(mp(i, mp(k,j)));
        }
    }
    repn(i, m) {
        int ans=0, last=-1;
        VPL cur;
        for(const auto& kv: a[i]) {
            if(kv.fi>last+1) {
                setmax(ans, solve(cur));
                cur.clear();
            }
            last=kv.fi, cur.pb(kv.se);
        }
        setmax(ans, solve(cur));
        printf("%d\n", ans);
    }
    return 0;
}