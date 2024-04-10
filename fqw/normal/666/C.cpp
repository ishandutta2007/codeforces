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

const int N=100000;
const LL MOD=LL(1e9)+7;

LL inv[N+1], v25d26;
void prepare() {
    auto pow=[](LL a, LL b, LL m) {
        LL c=1;
        for(; b>0; b>>=1, a=a*a%m)
            if(b&1) c=c*a%m;
        return c;
    };
    rep(i, 1, N) inv[i]=pow(i, MOD-2, MOD);
    v25d26=25*inv[26]%MOD;
}

VI ans[N+1];

void compute(int m) {
    if(!ans[m].empty()) return;
    ans[m].resize(N+1);
    rep(i, 0, m-1) ans[m][i]=0;
    LL c0=1, s=0, la=1;
    rep(k, 0, N-m) {
        //printf("m=%d k=%d\n",m,k);
        s=(s+la)%MOD;
        ans[m][m+k]=int(c0*s%MOD);
        (la*=v25d26)%=MOD;
        (la*=m-1+k+1)%=MOD;
        (la*=inv[k+1])%=MOD;
        c0=c0*26%MOD;
    }
}

int main() {
    prepare();

    static char buf[100010];
    int cs, m=0; scanf("%d%s", &cs,buf);
    compute(m=int(strlen(buf)));
    while(cs--) {
        int t; scanf("%d", &t);
        if(t==1) {
            scanf("%s", buf);
            compute(m=int(strlen(buf)));
        } else {
            int n; scanf("%d", &n);
            printf("%d\n", ans[m][n]);
        }
    }
    return 0;
}