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
typedef vector<string> VS;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

struct SegmentTree {
    const int n;
    VI tr;
    SegmentTree(int _n) : n(_n), tr(n*4) {
        build(0, 0, n);
    }

    void build(int x, int l, int r) {
        if(l+1==r) {
            tr[x]=0; return;
        }
        const int m=(l+r)/2;
        tr[x]=-1;
        build(x*2+1, l, m);
        build(x*2+2, m, r);
    }

    void release(int x) {
        if(tr[x]>=0) {
            setmax(tr[x*2+1], tr[x]);
            setmax(tr[x*2+2], tr[x]);
            tr[x]=-1;
        }
    }

    void update(int x, int l, int r, int s, int t, int val) {
        if(s<=l && r<=t) {
            setmax(tr[x], val);
            return;
        }
        const int m=(l+r)/2;
        release(x);
        if(s<m) update(x*2+1, l, m, s, t, val);
        if(m<t) update(x*2+2, m, r, s, t, val);
    }

    int get(int x, int l, int r, int i) {
        if(l+1==r) {
            return tr[x];
        }
        const int m=(l+r)/2;
        release(x);
        if(i<m) return get(x*2+1, l, m, i);
            else return get(x*2+2, m, r, i);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; scanf("%d", &n);
    vector<pair<int, PII>> a(n);
    for(auto& b: a) scanf("%d%d%d", &b.fi,&b.se.fi,&b.se.se);

    VI xs;
    for(const auto& b: a) xs.pb(b.se.fi), xs.pb(b.se.se);
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    const int m=sz(xs);
    for(auto& b: a) {
        b.se.fi=int(lower_bound(all(xs), b.se.fi)-xs.begin());
        b.se.se=int(lower_bound(all(xs), b.se.se)-xs.begin());
    }

    SegmentTree tr(m);
    for(const auto& b: a) {
        tr.update(0, 0, m, b.se.fi, b.se.se, b.fi);
    }

    int y=0;
    VPI ans;
    repn(i, m) {
        int h=tr.get(0, 0, m, i);
        if(h!=y) {
            ans.emplace_back(xs[i], y);
            ans.emplace_back(xs[i], h);
            y=h;
        }
    }
    printf("%d\n", sz(ans));
    for(const auto& p: ans) {
        printf("%d %d\n", p.fi,p.se);
    }

    return 0;
}