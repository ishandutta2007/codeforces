#include <algorithm>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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

const int MAXN=500000;
const int S=1000;
const int MAXV=int(1e9+7);

int a[MAXN], offset[MAXN/S+10];
int vs[MAXN], ps[MAXN], qs[MAXN];
int n, num;

void make(int k) {
    int x=k*S, y=min(k*S+S, n);
    static PII tmp[S];
    rep(i, x, y-1) tmp[i-x]=mp(a[i], i);
    sort(tmp, tmp+y-x);
    rep(i, x, y-1) vs[i]=tmp[i-x].fi, ps[i]=tmp[i-x].se;
    irep(i, y-1, x) {
        if(i<y-1 && vs[i]==vs[i+1])
            qs[i]=qs[i+1];
        else
            qs[i]=ps[i];
    }
}

int main() {
    int q;
    scanf("%d%d", &n,&q);
    repn(i, n) scanf("%d", &a[i]);


    num=(n-1)/S+1;
    repn(k, num) {
        offset[k]=0;
        make(k);
    }

    while(q--) {
        int t; 
        scanf("%d", &t);
        if(t==1) {
            int l, r, v; 
            scanf("%d%d%d",&l,&r,&v);
            --l;
            repn(k, num) {
                int x=k*S, y=min(k*S+S, n);
                if(r<=x || y<=l) continue;
                if(l<=x && y<=r)
                    offset[k]=min(offset[k]+v, MAXV);
                else {
                    int x1=max(l, x), y1=min(r, y);
                    rep(i, x1, y1-1)
                        a[i]=min(a[i]+v, MAXV);
                    make(k);
                }
            }
        }
        else {
            int val; 
            scanf("%d", &val);
            int first=1<<30, last=-1;
            repn(k, num) {
                int want=val-offset[k];
                if(want<0) continue;
                int x=k*S, y=min(k*S+S, n);
                if(vs[x]>want || vs[y-1]<want) continue;
                int i=int(lower_bound(vs+x, vs+y, want)-vs);
                if(i<y && vs[i]==want) {
                    setmin(first, ps[i]);
                    setmax(last, qs[i]);
                }
            }
            if(first>last) printf("-1\n"); else printf("%d\n", last-first);
        }
    }

    return 0;
}