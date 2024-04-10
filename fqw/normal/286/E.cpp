#include <cassert>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=1110000*2;

namespace FFT {
    typedef double Real;
    typedef complex<Real> Complex;
    void fft(Complex *a, Complex *b, int n, bool inv) {
        Real arg=(Real)acos(-1.0);
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
    void convolve(const vector<Real>& a, vector<Real>& c) {
        int n=1; while(n<(int)a.size()*2) n*=2;
        static Complex x[N], t[N];
        for(int i=0; i<n; ++i) x[i]=Complex(i<(int)a.size()?a[i]:(Real)0., (Real)0.);
        fft(x, t, n, false);
        for(int i=0; i<n; ++i) t[i]=t[i]*t[i];
        fft(t, x, n, true);
        for(int i=0; i<min((int)c.size(), n); ++i) c[i]+=(Real)real(t[i])/(Real)n;
    }
};

int main() {
    int n, m; scanf("%d%d", &n,&m);
    vector<int> a(m+1);
    vector<FFT::Real> x(m+1), y(m+1);
    repn(i, n) {
        int t; scanf("%d", &t);
        a[t]=1; x[t]=1.0;
    }
    FFT::convolve(x, y);
    VI ans;
    rep(i, 1, m) {
        if(a[i]>0) {
            if(y[i]<.2) ans.pb(i);
        } else {
            if(y[i]>.2) { printf("NO\n"); return 0; }
        }
    }
    printf("YES\n%d\n", (int)ans.size());
    for(int t: ans) printf("%d ", t); printf("\n");
    return 0;
}