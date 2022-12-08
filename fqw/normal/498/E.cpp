// 19:33
#include <cassert>
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

const LL MOD=LL(1e9)+7;

struct Mat {
    LL a[1<<7][1<<7];
    int n;
    Mat operator *(const Mat &b) const {
        assert(n==b.n);
        Mat c; c.n=n; fillchar(c.a, 0);
        repn(k, n) repn(i, n) repn(j, n)
            (c.a[i][j]+=a[i][k]*b.a[k][j]) %=MOD;
        return c;
    }
};

Mat go(int n, int m) {
    Mat T; T.n=1<<m;
    fillchar(T.a, 0);
    repn(x, 1<<m) repn(y, 1<<m) repn(z, 1<<(m+1)) {
        if((z&1)==0 || (z&(1<<m))==0) continue;
        bool ok=true;
        repn(i, m)
            if(x&(1<<i) && y&(1<<i) && z&(1<<i) && z&(1<<(i+1)))
                ok=false;
        if(ok) T.a[x][y]++;
    }
    Mat A; A.n=1<<m;
    fillchar(A.a, 0); repn(i, A.n) A.a[i][i]=1;
    for(; n>0; n>>=1, T=T*T)
        if(n&1) A=A*T;
    return A;
}

int main() {
    int w[7];
    repn(i, 7) scanf("%d", &w[i]);

    LL a[1<<7], b[1<<7];
    fillchar(a, 0); a[0]=1;

    repn(i, 7) {
        Mat A=go(w[i], i+1);
        fillchar(b, 0);
        repn(j, 1<<i) repn(k, 1<<(i+1))
            (b[k]+=a[j]*A.a[j|(1<<i)][k]) %=MOD;
        memcpy(a, b, sizeof(a));
    }
    LL ans=a[(1<<7)-1];
    printf("%d\n", (int)ans);
    return 0;
}