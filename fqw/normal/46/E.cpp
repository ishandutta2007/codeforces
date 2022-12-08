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

const LL kInf=1LL<<50;

int main() {
    int n, m; scanf("%d%d", &n,&m);
    vector<VI> a(n, VI(m));
    repn(i, n) repn(j, m) scanf("%d", &a[i][j]);
    
    vector<VL> f(n+1, VL(m, -kInf));
    f[0][0]=0;
    repn(i, n) {
        VL s(m);
        repn(j, m) s[j]=a[i][j]+(j>0?s[j-1]:0);
        if(i%2==0) {
            VL t(m);
            repn(j, m) t[j]=max(f[i][j], j>0?t[j-1]:-kInf);
            replr(j, 1, m) f[i+1][j]=t[j-1]+s[j];
        } else {
            VL t(m);
            irepn(j, m) t[j]=max(f[i][j], j<m-1?t[j+1]:-kInf);
            replr(j, 0, m-1) f[i+1][j]=t[j+1]+s[j];
        }
    }
    LL ans=-kInf;
    repn(j, m) setmax(ans, f[n][j]);
    printf("%lld\n", ans);

    return 0;
}