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

const int N=100010;
typedef long double LD;

LD solve(LD a, LD b, LD c, LD lx, LD rx) {
    LD d=b*b-4*a*c;
    assert(d>-1e-8); if(d<0) d=0;
    LD x1=(-b+sqrt(d))/2/a;
    LD x2=(-b-sqrt(d))/2/a;
    LD d1=abs(x1-(lx+rx)/2), d2=abs(x2-(lx+rx)/2);
    return d1<d2 ? x1 : x2;
}

int main() {
    static double p[N], q[N], r[N];
    static LD a[N], b[N], s[N], t[N];
    int n;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%lf", &q[i]);
    rep(i, 1, n) scanf("%lf", &p[i]);
    rep(i, 1, n) r[i]=p[i]+q[i];
    s[0]=t[0]=0;
    rep(i, 1, n) {
        LD cb=solve(-1, r[i]-t[i-1]+s[i-1], r[i]*t[i-1]-q[i], 0, r[i]);
        LD ca=r[i]-cb;
        a[i]=ca, b[i]=cb;
        s[i]=s[i-1]+a[i], t[i]=t[i-1]+b[i];
    }
    rep(i, 1, n) printf("%.9lf ", (double)a[i]); printf("\n");
    rep(i, 1, n) printf("%.9lf ", (double)b[i]); printf("\n");

    return 0;
}