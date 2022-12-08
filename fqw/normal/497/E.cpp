// 11:04
#include <iostream>
#include <set>
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
typedef unsigned long long ULL;
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
const LL LIM=LL(1e17);

struct Mat {
    LL a[31][31];
    int n;
    static Mat eye(int size) {
        Mat m; m.n=size;
        fillchar(m.a, 0);
        repn(i, size) m.a[i][i]=1;
        return m;
    }
    Mat operator *(const Mat &b) const {
        Mat c; fillchar(c.a, 0);
        assert(n==b.n); c.n=n;
        repn(i, n) repn(j, n) {
            ULL r=0;
            int n1=min(n, 15);
            repn(k, n1) r+=a[i][k]*b.a[k][j];
            r%=MOD;
            rep(k, n1, n-1) r+=a[i][k]*b.a[k][j];
            c.a[i][j]=LL(r%MOD);
        }
        return c;
    }
};

Mat t[70][30];

int main() {
    LL n; int k;
    cin>>n>>k;

    int m=0; LL mp=1, powers[70];
    while(mp<=n/k) ++m, mp*=k;
    powers[0]=1; rep(i, 1, m) powers[i]=powers[i-1]*k;

    repn(c, k) {
        t[0][c]=Mat::eye(k+1);
        repn(j, k+1) t[0][c].a[c][j]=1;
    }
    rep(i, 1, m) repn(c, k) {
        t[i][c]=Mat::eye(k+1);
        repn(j, k) t[i][c]=t[i-1][(j+c)%k]*t[i][c];
    }

    Mat r=Mat::eye(k+1);
    int cur=0;
    irep(i, m, 0) {
        while(n>=powers[i]) {
            n-=powers[i];
            r=t[i][cur]*r;
            cur=(cur+1)%k;
        }
    }
    LL ans=0;
    repn(i, k+1) (ans+=r.a[i][k])%=MOD;
    cout<<ans<<endl;


    return 0;
}