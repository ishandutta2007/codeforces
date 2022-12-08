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

LL inv(LL a) {
    LL b=MOD-2, c=1;
    for(; b>0; b>>=1, (a*=a)%=MOD)
        if(b&1) (c*=a)%=MOD;
    return c;
}

VL cal_q(int m, int k, LL p) {
    VL fac(k+1), inv_fac(k+1);
    fac[0]=1; rep(i, 1, k) fac[i]=fac[i-1]*i%MOD;
    rep(i, 0, k) inv_fac[i]=inv(fac[i]);

    VL mp(k+1), mnp(k+1);
    mp[0]=mnp[0]=1;
    rep(i, 1, k) {
        mp[i]=mp[i-1]*p%MOD;
        mnp[i]=mnp[i-1]*(1-p+MOD)%MOD;
    }

    const auto binom=[&](int x, int y) {
        return fac[x]*inv_fac[y]%MOD*inv_fac[x-y]%MOD;
    };
    VL q(m);
    repn(i, m) {
        if(i>k) break;
        q[i]=binom(k, i)*mp[i]%MOD*mnp[k-i]%MOD;
    }
    return q;
}

int main() {
    int n, m, k; LL a, b;
    cin>>n>>m>>a>>b>>k;
    const LL p=a*inv(b)%MOD;

    VL q=cal_q(m, k, p);
    VL sq(m+1); repn(i, m) sq[i+1]=(sq[i]+q[i])%MOD;

    vector<VL> fl(n+1, VL(m)), sfl(n+1, VL(m+1));
    vector<VL> fr(n+1, VL(m)), sfr(n+1, VL(m+1));
    fl[0][0]=sfl[0][0]=1;
    fr[0][0]=sfr[0][0]=1;
    rep(i, 1, n) {
        const LL tot=sfl[i-1][0];
        {
            VL buf(m+1);
            repn(j, m) buf[j+1]=(buf[j]+q[j]*sfl[i-1][m-j])%MOD;
            repn(j, m) {
                fl[i][j]=q[j]*(sq[m-j]*(tot-sfr[i-1][m-j])%MOD-buf[m-j])%MOD;
                if(fl[i][j]<0) fl[i][j]+=MOD;
            }
        }
        {
            VL buf(m+1);
            repn(j, m) buf[j+1]=(buf[j]+q[j]*sfr[i-1][m-j])%MOD;
            repn(j, m) {
                fr[i][j]=q[j]*(sq[m-j]*(tot-sfl[i-1][m-j])%MOD-buf[m-j])%MOD;
                if(fr[i][j]<0) fr[i][j]+=MOD;
            }
        }
        irepn(j, m) {
            sfl[i][j]=(sfl[i][j+1]+fl[i][j])%MOD;
            sfr[i][j]=(sfr[i][j+1]+fr[i][j])%MOD;
        }
    }
    const LL ans=sfl[n][0];
    cout<<ans<<endl;

    return 0;
}