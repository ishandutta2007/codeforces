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

const LL MOD=LL(1e9)+7;

struct Mat {
    int a[2][2];
    void mul(const Mat& b) {
        Mat c;
        repn(i, 2) repn(j, 2) {
            LL r=0;
            repn(k, 2) r+=LL(a[i][k])*LL(b.a[k][j]);
            c.a[i][j]=int(r%MOD);
        }
        *this=c;
    }
    friend Mat pow(Mat a, LL b) {
        Mat c; fillchar(c.a, 0);
        repn(i, 2) c.a[i][i]=1;
        for(; b>0; b>>=1, a.mul(a))
            if(b&1) c.mul(a);
        return c;
    }
};

LL ipow(LL a, LL b) {
    LL c=1;
    for(; b>0; b>>=1, (a*=a)%=MOD)
        if(b&1) (c*=a)%=MOD;
    return c;
}

LL inv2() {
    return ipow(2, MOD-2);
}

int main() {
    Mat a; fillchar(a.a, 0);
    a.a[0][0]=1, a.a[0][1]=2;
    a.a[1][0]=1, a.a[1][2]=0;
    LL b=2;

    //rep(n, 1, 10) { printf("%d: %lld\n",n,pow(a,n).a[1][1]); }

    int k; 
    scanf("%d", &k);
    //k=100000;
    while(k--) {
        LL x;
        scanf("%lld", &x);
        //x=(1LL<<62)-1;
        a=pow(a, x);
        b=ipow(b, x);
    }

    LL ia=a.a[1][1];
    (ia*=inv2())%=MOD;
    (b*=inv2())%=MOD;
    printf("%d/%d\n", int(ia), int(b));
    return 0;
}