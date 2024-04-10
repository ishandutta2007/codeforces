// 13:47
// 13:48
#include <cassert>
#include <cstring>
#include <iostream>
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
    int n, l, r, x; cin>>n>>l>>r>>x;
    int c[15]; repn(i, n) cin>>c[i];
    int ans=0;
    repn(s, 1<<n) {
        int sum=0, minv=1<<30, maxv=0;
        repn(i, n) if(s&(1<<i)) {
            sum+=c[i];
            setmin(minv, c[i]);
            setmax(maxv, c[i]);
        }
        if(sum>=l && sum<=r && maxv-minv>=x)
            ++ans;
    }
    cout<<ans<<endl;
    return 0;
}