#include <iostream>
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

const int N=70;

pair<int,LL> f[N+1][4];
int a[N], b[N];

void make(LL x, int v[]) {
    repn(i, N) v[i]=(int)(x&1), x>>=1;
}

int main() {
    int cs; scanf("%d", &cs);
    rep(ics, 1, cs) {
        LL l, r; cin>>l>>r;
        make(l, a);
        make(r, b);
        
        fillchar(f, 0xff);
        f[N][3]=mp(0, 0LL);
        irepn(i, N) repn(k, 4) if(f[i+1][k].fi>=0) {
            repn(cur, 2) {
                if((k&1)>0 && cur<a[i]) continue;
                if((k&2)>0 && cur>b[i]) continue;
                int k2=0; 
                if((k&1)>0 && cur==a[i]) k2|=1;
                if((k&2)>0 && cur==b[i]) k2|=2;
                int c=f[i+1][k].fi+cur;
                LL v=(-f[i+1][k].se)*2+cur;
                setmax(f[i][k2], mp(c, -v));
            }
        }

        pair<int, LL> ans=f[0][0];
        repn(i, 4) setmax(ans, f[0][i]);
        cout<<(-ans.se)<<endl;
    }
    return 0;
}