// 8:56 - 9:27 - wa 10
#include <iostream>
#include <algorithm>
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

const LL MOD=LL(1e9)+7;
const LL INV_2=500000004;
const int LEN=17;
const int C_W=0;
const int C_Y=1;
const int C_B=2;
const int C_R=3;

bool good(int x, int y) {
    if(x==y) return false;
    if(x==C_W && y==C_Y) return false;
    if(x==C_Y && y==C_W) return false;
    if(x==C_R && y==C_B) return false;
    if(x==C_B && y==C_R) return false;
    return true;
}

bool good(int x, int y, int z) {
    if(!good(x, y)) return false;
    if(!good(y, z)) return false;
    if(x==C_B && y==C_W && z==C_R) return false;
    if(x==C_R && y==C_W && z==C_B) return false;
    return true;
}

struct Vec {
    LL a[LEN];
    Vec() { fillchar(a, 0); }
};

struct Mat {
    LL a[LEN][LEN];
    Mat() { fillchar(a, 0); }
};

Vec operator *(const Vec& a, const Mat& b) {
    Vec c;
    repn(i, LEN) repn(j, LEN)
        (c.a[j]+=a.a[i]*b.a[i][j])%=MOD;
    return c;
}

Mat operator *(const Mat& a, const Mat& b) {
    Mat c;
    repn(i, LEN) repn(k, LEN) repn(j, LEN)
        (c.a[i][j]+=a.a[i][k]*b.a[k][j])%=MOD;
    return c;
}

Mat pow(Mat a, LL b) {
    Mat c; repn(i, LEN) c.a[i][i]=1;
    for(; b>=1; b>>=1, a=a*a)
        if(b&1) c=c*a;
    return c;
}

Vec make_initial_vec() {
    Vec vec;
    repn(x, 4) repn(y, 4) if(good(x, y))
        vec.a[x*4+y]=1;
    vec.a[16]=4;
    return vec;
}

Mat make_mat() {
    Mat mat;
    repn(x, 16) repn(y, 16) {
        int x1=x>>2, x2=x&3, y1=y>>2, y2=y&3;
        if(x2!=y1) continue;
        if(!good(x1, x2, y2)) continue;
        mat.a[x][y]=1;
    }
    repn(x, 16) mat.a[x][16]=1;
    mat.a[16][16]=1;
    return mat;
}

LL solve1(LL N) { // N>=1
    if(N==1) return 4;
    Vec v=make_initial_vec()*pow(make_mat(), N-2);
    return accumulate(v.a, v.a+17, 0LL) % MOD;
}

LL solve2(LL N) { // N>=1
    return solve1((N+1)/2);
    /*
    LL ans=4;
    if(N<=2) return ans;
    // for odd lengths which >=3; even lengths are impossible
    */
}

LL solve(LL N) { // N>=0
    if(N==0) return 0;
    LL ans1=solve1(N);
    LL ans2=solve2(N);
    return (ans1+ans2)%MOD *INV_2 % MOD;
}

int main() {
    assert((2*INV_2)%MOD==1);
    LL L, R; cin>>L>>R;
    LL ans=(solve(R)-solve(L-1)+MOD)%MOD;
    //cout<<solve(L-1)<<" "<<solve(R)<<endl;
    cout<<ans<<endl;
    return 0;
}