#include <algorithm>
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

const int N=5050;

int x[N], a[N], b[N], c[N], d[N];
LL in_l[N], in_r[N], out_l[N], out_r[N];
LL f[N][N];
int n, st, en;

int main() {
    scanf("%d%d%d", &n,&st,&en);
    rep(i, 1, n) scanf("%d", &x[i]);
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 1, n) scanf("%d", &b[i]);
    rep(i, 1, n) scanf("%d", &c[i]);
    rep(i, 1, n) scanf("%d", &d[i]);
    rep(i, 1, n) {
        in_l[i]=a[i]+x[i], in_r[i]=b[i]-x[i];
        out_l[i]=x[i]+c[i], out_r[i]=d[i]-x[i];
    }

    fillchar(f, 50); LL inf=f[0][0];
    f[0][0]=0;
    rep(i, 1, n) rep(z, 0, n) if(f[i-1][z]<inf) {
        int in=z, out=z;
        if(st<i && i<=en) ++out;
        if(en<i && i<=st) ++in;
        if(i>1 && in==0 && out==0) continue;

        if(i==st) {
            if(en<i) {
                setmin(f[i][z], f[i-1][z]+out_l[i]);
                setmin(f[i][z+1], f[i-1][z]+out_r[i]);
            } else {
                setmin(f[i][z], f[i-1][z]+out_r[i]);
                if(z>0) setmin(f[i][z-1], f[i-1][z]+out_l[i]);
            }
        } else if(i==en) {
            if(st<i) {
                setmin(f[i][z], f[i-1][z]+in_l[i]);
                setmin(f[i][z+1], f[i-1][z]+in_r[i]);
            } else {
                if(z>0) setmin(f[i][z-1], f[i-1][z]+in_l[i]);
                setmin(f[i][z], f[i-1][z]+in_r[i]);
            }
        } else {
            if(z>0) setmin(f[i][z-1], f[i-1][z]+in_l[i]+out_l[i]);
            setmin(f[i][z+1], f[i-1][z]+in_r[i]+out_r[i]);
            if(out>0) setmin(f[i][z], f[i-1][z]+in_l[i]+out_r[i]);
            if(in>0) setmin(f[i][z], f[i-1][z]+in_r[i]+out_l[i]);
        }
    }
    LL ans=f[n][0];
    cout<<ans<<endl;

    return 0;
}