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

const int N=1010;
const int D=11;

LL f[N][D][N];
LL inv[D];

int main() {
    int n, d; LL mod;
    cin>>n>>d>>mod;
    const auto power=[mod](LL a, LL b) {
        LL c=1;
        for(; b>0; b>>=1, a=a*a%mod)
            if(b&1) c=c*a%mod;
        return c;
    };
    rep(i, 1, D-1) inv[i]=power(i, mod-2);

    fillchar(f, 0);
    rep(j, 0, d) rep(k, 0, n) f[1][j][k]=1;
    rep(i, 2, n) rep(j, 0, d) rep(k, 1, n) {
        LL cur=1, p=f[k][d-1][k-1];
        LL ans=0;
        rep(t, 0, min(j, (i-1)/k)) {
            if(i-t*k!=1 || (i-t*k==1 && j==t)) {
                ans+=f[i-t*k][j-t][k-1]*cur;
            }
            (cur*=p+t)%=mod;
            (cur*=inv[t+1])%=mod;
        }
        f[i][j][k]=ans%mod;
    }
    LL ans=f[n][d][(n-1)/2];
    if(n%2==0) {
        LL tmp=f[n/2][d-1][n/2-1];
        (ans+=tmp*(tmp+1)/2)%=mod;
    }
    cout<<ans<<endl;

    return 0;
}