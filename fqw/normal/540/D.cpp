// 15:08
// 15:09 - 
#include <cassert>
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

double f[110][110][110];

int main() {
    int x, y, z;
    scanf("%d%d%d",&x,&y,&z);
    fillchar(f, 0);
    f[x][y][z]=1;
    irep(i, x, 0) irep(j, y, 0) irep(k, z, 0) {
        int p1=i*j, p2=j*k, p3=k*i, p=p1+p2+p3;
        if(p==0) continue;
        if(p1>0) f[i][j-1][k]+=f[i][j][k]*(double)p1/(double)p;
        if(p2>0) f[i][j][k-1]+=f[i][j][k]*(double)p2/(double)p;
        if(p3>0) f[i-1][j][k]+=f[i][j][k]*(double)p3/(double)p;
    }
    double a1=0, a2=0, a3=0;
    irep(i, x, 0) irep(j, y, 0) irep(k, z, 0) {
        if(j+k==0) a1+=f[i][j][k];
        if(i+k==0) a2+=f[i][j][k];
        if(i+j==0) a3+=f[i][j][k];
    }
    printf("%.15lf %.15lf %.15lf\n", a1,a2,a3);
    return 0;
}