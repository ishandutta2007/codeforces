#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#define _ (int)
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
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=35;

int a[N][N], b[N][N];
int n, m;

int go(int st) {
    int z[N]; 
    rep(j, 1, m) z[j]=(st&(1<<(j-1)))?1:-1;
    rep(j, m+1, n) z[j]=z[m]*z[j-m];
    int ans=0;
    rep(j, 1, n) ans+=a[m][j]*z[j];
    fillchar(b, 0);
    rep(i, 1, m-1) {
        rep(j, 1, n) b[i][j]=a[i][j]+z[j]*a[i+m][j];
        int vp=b[i][m], vn=-vp;
        rep(j, 1, m-1) {
            vp+=std::max(b[i][j]+b[i][j+m], -b[i][j]-b[i][j+m]);
            vn+=std::max(b[i][j]-b[i][j+m], -b[i][j]+b[i][j+m]);
        }
        ans+=std::max(vp, vn);
    }
    return ans;
}

int main() {
    scanf("%d", &n); m=n/2+1;
    rep(i, 1, n) rep(j, 1, n) scanf("%d", &a[i][j]);
    int ans=-1<<30;
    repn(st, 1<<m) setmax(ans, go(st));
    printf("%d\n", ans);

    return 0;
}