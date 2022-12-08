#include <cassert>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
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

int x[MAXN], y[MAXN], rx[MAXN], ry[MAXN];
bool is_left[MAXN];
int ans[MAXN];
int n;

void dis(int a[], int r[]) {
    VI p;
    rep(i, 1, n) p.pb(a[i]);
    sort(all(p));
    p.erase(unique(all(p)), p.end());
    rep(i, 1, n) a[i]=(int)(lower_bound(all(p), a[i])-p.begin()+1);
    repn(i, p.size()) r[i+1]=p[i];
}

int tr1[MAXN*4], tr2[MAXN*4];

void paint(int tr[], int x, int s, int t, int st, int en, int c) {
    if(st<=s && t<=en) {
        setmax(tr[x], c); return;
    }
    if(tr[x]>=0) {
        setmax(tr[x*2], tr[x]);
        setmax(tr[x*2+1], tr[x]);
        tr[x]=-1;
    }
    int mid=(s+t)/2;
    if(st<=mid) paint(tr, x*2, s, mid, st, en, c);
    if(mid<en) paint(tr, x*2+1, mid+1, t, st, en, c);
}

int get(int tr[], int x, int s, int t, int ind) {
    if(s==t) return tr[x];
    if(tr[x]>=0) {
        setmax(tr[x*2], tr[x]);
        setmax(tr[x*2+1], tr[x]);
        tr[x]=-1;
    }
    int mid=(s+t)/2;
    if(ind<=mid) return get(tr, x*2, s, mid, ind);
        else return get(tr, x*2+1, mid+1, t, ind);
}

void solve() {
    dis(x, rx); dis(y, ry);
    fillchar(tr1, 0);
    fillchar(tr2, 0);
    set<int> xs;
    rep(i, 1, n) {
        if(xs.count(x[i])>0) { ans[i]=0; continue; } else xs.insert(x[i]);
        if(is_left[i]) {
            int c=get(tr1, 1, 1, n, y[i]);
            paint(tr2, 1, 1, n, c+1, x[i], y[i]);
            int d=(c==0?0:rx[c]);
            ans[i]=rx[x[i]]-d;
        } else {
            int c=get(tr2, 1, 1, n, x[i]);
            paint(tr1, 1, 1, n, c+1, y[i], x[i]);
            int d=(c==0?0:ry[c]);
            ans[i]=ry[y[i]]-d;
        }
    }
}

int main() {
    int size;
    scanf("%d%d", &size,&n);
    rep(i, 1, n) {
        char buf[9];
        scanf("%d%d%s", &x[i],&y[i],buf);
        is_left[i]=(buf[0]=='L');
    }
    solve();
    rep(i, 1, n) printf("%d\n", ans[i]);
    
    return 0;
}