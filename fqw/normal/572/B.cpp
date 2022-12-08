#include <cassert>
#include <algorithm>
#include <map>
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
    map<int,int> s, b;
    int n, m; scanf("%d%d", &n,&m);
    while(n--) {
        char t; int p, q;
        scanf(" %c%d%d", &t,&p,&q);
        if(t=='S') s[p]+=q;
            else b[p]+=q;
    }
    
    VPI vs(all(s)); sort(all(vs)); if(vs.size()>m) vs.resize(m);
    VPI vb(all(b)); sort(all(vb), greater<PII>()); if(vb.size()>m) vb.resize(m);
    sort(all(vs), greater<PII>());
    for(PII p: vs) printf("S %d %d\n", p.fi,p.se);
    for(PII p: vb) printf("B %d %d\n", p.fi,p.se);
    return 0;
}