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
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

int main() {
    int n, k; scanf("%d%d", &n,&k);
    VPI ps;
    for(int t=2; t*t<=k; ++t) if(k%t==0) {
        int c=0;
        while(k%t==0) ++c, k/=t;
        ps.pb(mp(t, c));
    }
    if(k>1) ps.pb(mp(k, 1));

    rep(i, 1, n) {
        int x; scanf("%d", &x);
        for(auto& p: ps) {
            int c=0;
            while(x%p.fi==0) ++c, x/=p.fi;
            if(c>=p.se) p.se=0;
        }
    }
    bool ok=true;
    for(const auto& p: ps) if(p.se>0) ok=false;
    printf("%s\n", ok?"Yes":"No");
    return 0;
}