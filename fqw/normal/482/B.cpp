#include <algorithm>
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

const int MAXN=100010;
const int MAXM=100010;

int n, m, l[MAXM], r[MAXM], a[MAXN], q[MAXM];
int seq[MAXN], final_seq[MAXN];

bool solve() {
    fillchar(seq, 0);
    int cur=1;
    rep(i, 1, m) if(a[i]==1) {
        cur=max(cur, l[i]);
        while(cur<=r[i]) seq[cur++]=1;
    }
    cur=1;
    rep(i, 1, m) if(a[i]==0) {
        cur=max(cur, l[i]);
        while(cur<=r[i] && seq[cur]==1) ++cur;
        if(cur>r[i]) return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, m) scanf("%d%d%d", &l[i],&r[i],&q[i]);
    static pair<PII, int> lst[MAXM];
    rep(i, 1, m) lst[i]=mp(mp(l[i], r[i]), q[i]);
    sort(lst+1, lst+m+1);
    rep(i, 1, m) l[i]=lst[i].fi.fi, r[i]=lst[i].fi.se, q[i]=lst[i].se;

    bool ok=true;
    fillchar(final_seq, 0);
    repn(k, 30) {
        rep(i, 1, m) a[i]=((q[i]&(1<<k))>0?1:0);
        if(!solve()) { ok=false; break; }
        rep(i, 1, n) if(seq[i]) final_seq[i]|=1<<k;
    }
    if(ok) {
        printf("YES\n");
        rep(i, 1, n) printf("%d ", final_seq[i]); printf("\n");
    } else printf("NO\n");
    return 0;
}