#include <cassert>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
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

const int N=550000;
    typedef complex<double> Complex;
    typedef double Real;
    void fft(Complex *a, Complex *b, int n, bool inv) {
        double arg=acos(-1.0);
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
    void convolve(const Real *a, int na, const Real *b, int nb, Real *c, int nc) {
        na=min(na, nc);
        nb=min(nb, nc);
        int n=1; 
        while(n<na+nb) n*=2;
        static Complex x[N], y[N], z[N], t[N];
        for(int i=0; i<n; ++i) x[i]=Complex(i<na?a[i]:0., 0.);
        for(int i=0; i<n; ++i) y[i]=Complex(i<nb?b[i]:0., 0.);
        fft(x, z, n, false);
        fft(y, t, n, false);
        for(int i=0; i<n; ++i) t[i]=t[i]*z[i];
        fft(t, z, n, true);
        for(int i=0; i<min(nc, n); ++i) c[i]+=(Real)real(z[i])/(Real)n;
    }

const int MAXN=200010;

double x[MAXN], y[MAXN], z[MAXN];
char s[MAXN], t[MAXN];
int u1[MAXN], u2[MAXN], u3[MAXN], u4[MAXN];
int n, m, threshold;

void cal(char ch, int u[]) {
    static int cnt[MAXN];
    cnt[0]=0;
    repn(i, n) cnt[i+1]=cnt[i]+(s[i]==ch);
    repn(i, n) {
        int l=max(i-threshold, 0);
        int r=min(i+threshold, n-1);
        x[i]=(cnt[r+1]-cnt[l]>0?1.:0.);
    }
    repn(i, m)
        y[i]=(t[m-i-1]==ch?1.:0.);

    fillchar(z, 0);
    convolve(x, n, y, m, z, n);
    repn(i, n) u[i]=int(z[i]+0.5);
}

int main() {
    scanf("%d%d%d", &n,&m,&threshold);
    scanf("%s%s", s,t);
    cal('A', u1);
    cal('T', u2);
    cal('G', u3);
    cal('C', u4);
    int ans=0;
    rep(i, m-1, n-1)
        if(u1[i]+u2[i]+u3[i]+u4[i]==m)
            ++ans;
    printf("%d\n", ans);
    return 0;
}