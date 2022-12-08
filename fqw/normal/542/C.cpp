// 11:31
// 11:36 - 11:39 - wa
#include <cassert>
#include <iostream>
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

int main() {
    int n, f[222];
    scanf("%d", &n); rep(i, 1, n) scanf("%d", &f[i]);
    bool in[222]; fillchar(in, false);
    rep(i, 1, n) {
        int x=i; repn(k, n*2) x=f[x];
        while(!in[x]) in[x]=true, x=f[x];
    }
    LL g=1;
    rep(i, 1, n) if(in[i]) {
        int x=f[i], cnt=1;
        while(x!=i) x=f[x], ++cnt;
        g=g/gcd(g,LL(cnt))*cnt;
    }
    LL ans=g;
    rep(i, 1, n) if(!in[i]) {
        int x=i, cnt=0;
        while(!in[x]) x=f[x], ++cnt;
        while(ans<cnt) ans+=g;
    }
    cout<<ans<<endl;
    return 0;
}