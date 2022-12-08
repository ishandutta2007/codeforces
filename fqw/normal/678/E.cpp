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

const int N=18;

double f[1<<N][N];
double p[N][N];
int n;

int main() {
    cin>>n; repn(i, n) repn(j, n) cin>>p[i][j];
    fillchar(f, 0);
    rep(s, 1, (1<<n)-1) repn(i, n) if(s&(1<<i)) {
        if((s&-s)==s) {
            f[s][i]=(i==0?1:0);
            continue;
        }
        f[s][i]=0;
        repn(j, n) if(j!=i && (s&(1<<j))) {
            setmax(f[s][i], f[s^(1<<i)][j]*p[j][i]+f[s^(1<<j)][i]*p[i][j]);
        }
    }
    double ans=0;
    repn(i, n) setmax(ans, f[(1<<n)-1][i]);
    printf("%.9lf\n", ans);
    return 0;
}