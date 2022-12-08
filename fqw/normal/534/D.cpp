// 20:18
// 20:29 - 20:33 - wa
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <set>
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

const int MAXN=200010;

VI v[MAXN];
int a[MAXN], rt[MAXN];
int n;

int main() {
    VI ans;
    scanf("%d", &n); rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 0, n) v[i].clear();
    rep(i, 1, n) v[a[i]].pb(i);
    fillchar(rt, 0);

    int cur=-1;
    while((int)ans.size()<n) {
        ++cur;
        while(v[cur].empty()) {
            cur-=3; if(cur<0) break;
        }
        if(cur<0) break;
        ans.pb(v[cur].back());
        v[cur].pop_back();
    }
    if((int)ans.size()<n) printf("Impossible\n");
    else {
        printf("Possible\n");
        for(int x: ans) printf("%d ", x); printf("\n");
    }
    return 0;
}