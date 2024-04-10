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
#define repl(i, a, b) for(LL i=LL(a); i<=LL(b); ++i)
#define irepl(i, a, b) for(LL i=LL(a); i>=LL(b); --i)
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
    LL n; cin>>n;
    LL m=1; while((m+1)*(m+1)<=n) ++m;
    VL f(m+1), g(m+1);
    repl(i, 1, m) f[i]=i-1;
    repl(i, 1, m) g[i]=n/i-1;
    repl(p, 2, m) if(f[p]>f[p-1]) {
        repl(i, 1, min(m, n/p/p)) {
            LL j=LL(i)*LL(p);
            if(j<=m) {
                g[i]-=g[j]-f[p-1];
            } else {
                g[i]-=f[n/j]-f[p-1];
            }
        }
        irepl(i, m, p*p) f[i]-=f[i/p]-f[p-1];
    }

    LL ans=0;
    repl(p, 2, m) if(f[p]>f[p-1]) {
        ans+=g[p]-f[p];
        if(p*p*p<=n) ++ans;
    }
    cout<<ans<<endl;

    return 0;
}