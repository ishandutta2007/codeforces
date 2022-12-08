#include <cassert>
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

const int V=60;
const int MAXN=100010;

struct Val {
    int a[V];
    Val operator +(const Val &v) const {
        Val t;
        repn(i, V) t.a[i]=a[i]+v.a[(i+a[i])%V];
        return t;
    }
};

int a[MAXN];
int n;

Val tr[MAXN*4];

void build(int x, int s, int t) {
    if(s==t) {
        repn(i, V) tr[x].a[i]=(i%a[s]==0)+1;
        return;
    }
    int mid=(s+t)/2;
    build(x*2, s, mid);
    build(x*2+1, mid+1, t);
    tr[x]=tr[x*2]+tr[x*2+1];
}

void modify(int x, int s, int t, int ind, int v) {
    if(s==t) {
        a[s]=v;
        repn(i, V) tr[x].a[i]=(i%a[s]==0)+1;
        return;
    }
    int mid=(s+t)/2;
    if(ind<=mid) modify(x*2, s, mid, ind, v);
        else modify(x*2+1, mid+1, t, ind, v);
    tr[x]=tr[x*2]+tr[x*2+1];
}

Val get(int x, int s, int t, int st, int en) {
    if(st<=s && t<=en) return tr[x];
    int mid=(s+t)/2;
    Val ans;
    if(st<=mid) {
        ans=get(x*2, s, mid, st, en);
        if(mid<en) ans=ans+get(x*2+1, mid+1, t, st, en);
    } else
        ans=get(x*2+1, mid+1, t, st, en);
    return ans;
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    build(1, 1, n);

    int q; scanf("%d", &q);
    while(q--) {
        int x, y; char cmd[9]; 
        scanf("%s%d%d", cmd,&x,&y);
        if(cmd[0]=='A') {
            Val val=get(1, 1, n, x, y-1);
            printf("%d\n", val.a[0]);
        } else {
            modify(1, 1, n, x, y);
        }
    }
    return 0;
}