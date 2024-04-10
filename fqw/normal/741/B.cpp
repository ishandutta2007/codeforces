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

int main() {
    int n, m, lim; scanf("%d%d%d", &n, &m, &lim);
    VI w(n), v(n);
    repn(i, n) scanf("%d", &w[i]);
    repn(i, n) scanf("%d", &v[i]);

    VI f(n, -1);
    const function<int(int)> get=[&](int x) { return f[x]<0 ? x : f[x]=get(f[x]); };
    repn(i, m) {
        int a, b; scanf("%d%d", &a,&b);
        --a, --b;
        a=get(a), b=get(b);
        if(a!=b) f[a]=b;
    }

    VL ans(lim+1);
    repn(group, n) if(f[group]<0) {
        VL tmp=ans;
        int ws=0, vs=0;
        repn(i, n) if(get(i)==group) {
            ws+=w[i], vs+=v[i];
            rep(k, 0, lim-w[i]) setmax(tmp[k+w[i]], ans[k]+v[i]);
        }
        rep(k, 0, lim-ws) setmax(tmp[k+ws], ans[k]+vs);
        ans=tmp;
    }
    printf("%lld\n", ans[lim]);
    return 0;
}