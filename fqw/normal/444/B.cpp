#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
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
    int d, n; LL x;
    cin>>n>>d>>x;
    auto get_next=[&x]() -> int {
        x=(x*37+10007)%1000000007;
        return (int)x;
    };
    int a[100000], b[100000], c[100000];
    repn(i, n) a[i]=i+1;
    repn(i, n) swap(a[i], a[get_next()%(i+1)]);
    repn(i, n) b[i]=(i<d);
    repn(i, n) swap(b[i], b[get_next()%(i+1)]);
    //repn(i, n) printf("%d ", a[i]); printf("\n");
    //repn(i, n) printf("%d ", b[i]); printf("\n");

    VI bs;
    repn(i, n) if(b[i]) bs.pb(i);
    int where[100001];
    repn(i, n) where[a[i]]=i;

    repn(k, n) {
        c[k]=0;
        irep(v, n, max(n-200,1)) {
            int i=where[v];
            int j=k-i;
            if(j>=0 && b[j]) {
                c[k]=v; break;
            }
        }
        if(c[k]>0) continue;
        for(int j: bs) {
            int i=k-j; if(i<0) break;
            setmax(c[k], a[i]*b[j]);
        }
    }
    repn(i, n) printf("%d\n", c[i]);

    return 0;
}