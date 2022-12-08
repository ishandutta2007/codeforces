#include <cassert>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
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

const int MAXN=100010;

int a[MAXN], n;
int s[2][MAXN];
VPI ans;

void go(int y) {
    int cur=1, cnt1=0, cnt2=0, la1=0, la2=0;
    while(cur<=n) {
        int i=int(lower_bound(s[0]+cur, s[0]+n+1, s[0][cur-1]+y)-s[0]);
        int j=int(lower_bound(s[1]+cur, s[1]+n+1, s[1][cur-1]+y)-s[1]);
        if(i>n && j>n) return;
        cur=min(i, j)+1;
        la1=(i<j), la2=1-la1;
        cnt1+=la1, cnt2+=la2;
    }
    if(cnt1!=cnt2) {
        if((cnt1>cnt2) != (la1>la2)) return;
        ans.pb(mp(max(cnt1, cnt2), y));
    }
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    fillchar(s, 0);
    rep(i, 1, n) {
        s[0][i]=s[0][i-1];
        s[1][i]=s[1][i-1];
        s[a[i]-1][i]++;
    }

    ans.clear();
    rep(t, 1, n) go(t);
    sort(all(ans));

    printf("%d\n", (int)ans.size());
    for(PII p: ans) printf("%d %d\n", p.fi,p.se);
    return 0;
}