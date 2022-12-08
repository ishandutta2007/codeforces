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
    LL a[2][2];
};

Mat mul(Mat a, Mat b) {
    Mat c; fillchar(c.a, 0);
    repn(k, 2) repn(i, 2) repn(j, 2) {
        (c.a[i][j]+=a.a[i][k]*b.a[k][j])%=MOD;
    }
    return c;
}

Mat pow(Mat a, LL b) {
    Mat c; fillchar(c.a, 0); c.a[0][0]=c.a[1][1]=1;
    for(; b>0; b>>=1, a=mul(a, a)) {
        if(b&1) c=mul(c, a);
    }
    return c;
}

int main() {
    LL A, B, n, x; cin>>A>>B>>n>>x;
    Mat t;
    t.a[0][0]=A, t.a[0][1]=B;
    t.a[1][0]=0, t.a[1][1]=1;
    t=pow(t, n);
    LL ans=(t.a[0][0]*x+t.a[0][1])%MOD;
    cout<<ans<<endl;
    return 0;
}