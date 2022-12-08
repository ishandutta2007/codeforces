#include <cassert>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

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
#ifdef DEBUG
#define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
#define _debug(args...) {}
#endif
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const LL MOD=LL(1e9)+7;
const LL CAP=LL(8e18);
const int K=1<<16; static_assert(K>=60000 && K<=70000, "");

typedef complex<long double> Complex;

//*
   void fft(Complex *a, int n, bool inv) {
   static Complex b[K];
   long double arg=acos(-1.0);
   for(int t=n/2; t>=1; t/=2) {
   Complex w(cos(arg), (inv?sin(arg):-sin(arg)));
   Complex p(1.0, 0.0);
   for(int j=0; j<n/2; j+=t, p*=w)
   for(int i=0; i<t; ++i) {
   Complex u=a[i+j*2];
   Complex v=p*a[i+t+j*2];
   b[i+j]=u+v;
   b[i+j+n/2]=u-v;
   }
   memcpy(a, b, sizeof(Complex)*n);
   arg/=2;
   }
   }
   /*/
void fft(Complex a[], int n, bool inv) {
    const int oper = inv ? -1 : 1;
    for (int i = 1, j = 0; i < n; i++) {
        for (int s = n; j ^= s >>= 1, ~j & s; );
        if (i < j) swap(a[i], a[j]);
    }
    const long double PI = acos((long double)-1.);
    for (int m = 1; m < n; m *= 2) {
        long double p = PI / m * oper;
        Complex w = Complex(cos(p), sin(p));
        for (int i = 0; i < n; i += m * 2) {
            Complex unit = 1;
            for (int j = 0; j < m; j++) {
                Complex &x = a[i + j + m], &y = a[i + j], t = unit * x;
                x = y - t;
                y = y + t;
                unit *= w;
            }
        }
    }
}
//*/

void convolute(const LL* a, const LL* b, LL* c, int n) {
    static Complex a1[K], a2[K];
    static Complex b1[K], b2[K];
    static Complex c1[K], c2[K], c3[K];
    static const LL L=30000;
    n*=2; 
    fillchar(a1, 0); fillchar(b1, 0);
    fillchar(a2, 0); fillchar(b2, 0);
    repn(i, n/2) {
        a1[i]=Complex(double(a[i]/L), 0); b1[i]=Complex(double(b[i]/L), 0); 
        a2[i]=Complex(double(a[i]%L), 0); b2[i]=Complex(double(b[i]%L), 0);
    }
    fft(a1, n, false); fft(b1, n, false); 
    fft(a2, n, false); fft(b2, n, false);
    repn(i, n) c1[i]=a1[i]*b1[i];
    repn(i, n) c2[i]=a2[i]*b2[i];
    repn(i, n) c3[i]=(a1[i]+a2[i])*(b1[i]+b2[i]);
    fft(c1, n, true);
    fft(c2, n, true);
    fft(c3, n, true);
    repn(i, n/2) {
        LL x1=LL(c1[i].real()/n+.5)%MOD;
        LL x2=LL(c2[i].real()/n+.5)%MOD;
        LL x3=LL(c3[i].real()/n+.5)%MOD;  x3=((x3-x1-x2)%MOD+MOD)%MOD;
        LL v=((x1*L+x3)%MOD*L+x2)%MOD;
        c[i]=v;
    }
}

int k, kn, k2;
LL fac[30030], inv_fac[30030], m2[30030];

void prepare() {
    m2[0]=1; rep(i, 1, k) m2[i]=m2[i-1]*2%MOD;
    fac[0]=1; rep(i, 1, k) fac[i]=fac[i-1]*i%MOD;
    auto pow=[](LL a, LL b, LL m) {
        LL c=1;
        for(; b>=1; b>>=1, a=a*a%m)
            if(b&1) c=c*a%m;
        return c;
    };
    rep(i, 0, k) inv_fac[i]=pow(fac[i], MOD-2, MOD);
}

struct F {
    LL f[30030];
    int n;
    F(int _n) : n(_n) {
        assert(n==0 || n==1);
        if(n==0) {
            fillchar(f, 0); f[0]=1;
        } else {
            fill(f, f+k2+1, 1);
        }
    }
    void merge(const F& b) {
        static LL x[K], y[K], z[K];
        fillchar(x, 0); fillchar(y, 0); fillchar(z, 0);

        LL m=1;
        rep(i, 0, k2+n) {
            if(i>=n) x[i-n]=f[i-n]*inv_fac[i]%MOD*m%MOD;
            m=m*m2[b.n]%MOD;
        }
        rep(i, 0, k2+b.n) {
            if(i>=b.n) y[i-b.n]=b.f[i-b.n]*inv_fac[i]%MOD;
        }

        convolute(x, y, z, kn);
        n+=b.n;
        rep(i, 0, k2+n) if(i>=n) f[i-n]=z[i-n]%MOD*fac[i]%MOD;
    }
};

LL solve(int n) {
    F f(0), z(1);
    for(; n>=1; n>>=1, z.merge(z))
        if(n&1) f.merge(z);

    LL ans=0;
    auto binom=[](int x, int y) { return fac[x]*inv_fac[y]%MOD*inv_fac[x-y]%MOD; };
    rep(i, f.n, f.n+k2) (ans+=f.f[i-f.n]*binom(k, i))%=MOD;

    return ans;
}

int main() {
    LL n; cin>>n>>k;
    if(n>k) { cout<<0<<endl; return 0; }
    k2=k-(int)n; kn=1; while(kn<=k2+1) kn*=2;
    prepare();
    cout<<solve((int)n)<<endl;
    return 0;
}