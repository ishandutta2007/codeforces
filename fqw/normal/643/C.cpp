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

const int N=200010;

int t[N]; double s[N], u[N], v[N];
int n, k;

double f[N], g[N];

double cal(int i, int j) {
    return f[i]+(u[j]-u[i])-(v[j]-v[i])*s[i];
}

double critical_v(int i1, int i2) {
    double z1=f[i1]-u[i1]+v[i1]*s[i1];
    double z2=f[i2]-u[i2]+v[i2]*s[i2];
    return (z2-z1)/(s[i2]-s[i1]);
}

int main() {
    scanf("%d%d", &n,&k);
    rep(i, 1, n) scanf("%d", &t[i]);
    s[0]=u[0]=v[0]=0;
    rep(i, 1, n) {
        s[i]=s[i-1]+t[i];
        u[i]=u[i-1]+s[i]/(double)t[i];
        v[i]=v[i-1]+1./(double)t[i];
    }

    f[0]=0; rep(i, 1, n) f[i]=1e30;
    rep(c, 1, k) {
        static int q[N];
        int ss=1, tt=1; q[1]=0;
        rep(i, 1, n) {
            while(ss<tt && v[i]>=critical_v(q[ss], q[ss+1]))
                ++ss;
            g[i]=cal(q[ss], i);
            while(ss<tt && critical_v(q[tt], i)<critical_v(q[tt-1], q[tt]))
                --tt;
            q[++tt]=i;
        }
        memmove(f, g, sizeof(f));
    }
    printf("%.9lf\n", f[n]);

    return 0;
}