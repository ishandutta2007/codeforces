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

const LL MOD=LL(1e9)+7;

VL solve(int k, int t) {
    VL f(k*t+1);
    f[0]=1;
    while(t--) {
        VL g(sz(f));
        LL cur=0;
        repn(i, sz(f)) {
            (cur+=f[i])%=MOD;
            if(i>k) cur=((cur-f[i-k-1])%MOD+MOD)%MOD;
            g[i]=cur;
        }
        f=g;
    }
    return f;
}

int main() {
    int a, b, k, t;
    cin>>a>>b>>k>>t;

    VL ways=solve(k*2, t);

    VL s(sz(ways)+1);
    irepn(i, sz(ways)) s[i]=(s[i+1]+ways[i])%MOD;

    LL ans=0;
    repn(i, sz(ways)) {
        int j=i+b-a+1;
        setmax(j, 0);
        setmin(j, sz(s)-1);
        (ans+=ways[i]*s[j])%=MOD;
    }
    cout<<ans<<endl;

    return 0;
}