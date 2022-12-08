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

VI decomp(int n) {
    VI r;
    if(n==0) r.pb(0);
    while(n>0) r.pb(n%7), n/=7;
    return r;
}

LL f[2][1<<7];

void go(VI xs) {
    irepn(i, sz(xs)) {
        static LL g[2][1<<7];
        fillchar(g, 0);
        repn(o, 2) repn(s, 1<<7) {
            repn(cur, o==0?7:xs[i]+1) if((s&(1<<cur))==0) {
                g[o && cur==xs[i]][s|(1<<cur)]+=f[o][s];
            }
        }
        memmove(f, g, sizeof(f));
    }
}

int main() {
    int n, m; cin>>n>>m;

    fillchar(f, 0);
    f[1][0]=1;
    go(decomp(n-1));
    //repn(o, 2) repn(s, 1<<7) if(f[o][s]) printf("%d %d -> %lld\n",o,s,f[o][s]);

    repn(s, 1<<7) f[1][s]+=f[0][s], f[0][s]=0;
    go(decomp(m-1));

    LL ans=0;
    repn(o, 2) repn(s, 1<<7) ans+=f[o][s];
    cout<<ans<<endl;

    return 0;
}