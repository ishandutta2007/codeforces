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
#include <deque>
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

VL interval_min(const VL& a, int d) {
    deque<pair<LL, int>> q;
    VL r;
    repn(i, sz(a)) {
        if(!q.empty() && q.front().se+d<=i) {
            q.pop_front();
        }
        while(!q.empty() && q.back().fi>=a[i]) {
            q.pop_back();
        }
        q.pb(mp(a[i], i));
        if(i+1>=d) {
            r.pb(q.front().fi);
        }
    }
    return r;
}

vector<VL> cal_minv(const vector<VL>& g, int n, int m, int a, int b) {
    vector<VL> t(n, VL(m-b+1));
    repn(i, n) {
        t[i]=interval_min(g[i], b);
    }
    vector<VL> r(n-a+1, VL(m-b+1));
    repn(j, m-b+1) {
        VL tmp; repn(i, n) tmp.pb(t[i][j]);
        tmp=interval_min(tmp, a);
        repn(i, n-a+1) r[i][j]=tmp[i];
    }
    return r;
}

vector<VL> cal_sumv(const vector<VL>& g, int n, int m, int a, int b) {
    vector<VL> s(n+1, VL(m+1));
    repn(i, n) repn(j, m) {
        s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+g[i][j];
    }
    vector<VL> r(n-a+1, VL(m-b+1));
    repn(i, n-a+1) repn(j, m-b+1) {
        r[i][j]=s[i+a][j+b]-s[i][j+b]-s[i+a][j]+s[i][j];
    }
    return r;
}

int main() {
    int n, m, a, b;
    scanf("%d%d%d%d", &n,&m,&a,&b);
    vector<VL> g(n, VL(m));
    repn(i, n) repn(j, m) {
        int x; scanf("%d", &x);
        g[i][j]=x;
    }

    vector<VL> minv=cal_minv(g, n, m, a, b);
    vector<VL> sumv=cal_sumv(g, n, m, a, b);
    vector<pair<LL, PII>> options;
    repn(i, n-a+1) repn(j, m-b+1) {
        options.pb(mp(sumv[i][j]-minv[i][j]*a*b, mp(i, j)));
    }
    sort(all(options));

    vector<vector<bool>> empty(n, vector<bool>(m, true));
    vector<pair<LL, PII>> ans;
    for(const auto& o: options) {
        const int x=o.se.fi, y=o.se.se;
        if(!empty[x][y]) continue;
        ans.pb(o);
        rep(i, max(x-a+1, 0), x+a-1) rep(j, max(y-b+1, 0), y+b-1) {
            empty[i][j]=false;
        }
    }
    printf("%d\n", sz(ans));
    for(const auto& o: ans) {
        printf("%d %d %lld\n", o.se.fi+1,o.se.se+1,o.fi);
    }
    return 0;
}