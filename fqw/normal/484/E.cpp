#include <algorithm>
#include <iostream>
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
const int MAXNodes=8000000;

struct Val {
    int l, m, r;
    friend Val merge(const Val &a, int an, const Val &b, int bn) {
        Val ret;
        ret.l=(a.l<an ? a.l : an+b.l);
        ret.r=(b.r<bn ? b.r : bn+a.r);
        ret.m=max(max(a.m, b.m), a.r+b.l);
        return ret;
    }
};

struct Node {
    Val v;
    int l, r;
} tr[MAXNodes];
int num;

int ins(int x, int s, int t, int ind) {
    ++num; assert(num<MAXNodes);
    tr[num]=tr[x]; x=num;
    if(s==t) {
        tr[x].v.l=tr[x].v.r=tr[x].v.m=1;
        return x;
    }
    int mid=(s+t)/2;
    if(ind<=mid)
        tr[x].l=ins(tr[x].l, s, mid, ind);
    else
        tr[x].r=ins(tr[x].r, mid+1, t, ind);
    tr[x].v=merge(tr[tr[x].l].v, mid-s+1, tr[tr[x].r].v, t-mid);
    return x;
}

Val query(int x, int s, int t, int st, int en) {
    if(st<=s && t<=en)
        return tr[x].v;
    int mid=(s+t)/2; Val ans;
    if(st<=mid) {
        ans=query(tr[x].l, s, mid, st, en);
        if(mid<en) {
            Val tmp=query(tr[x].r, mid+1, t, st, en);
            ans=merge(ans, mid-max(st,s)+1, tmp, min(en,t)-mid);
        }
    } else
        ans=query(tr[x].r, mid+1, t, st, en);
    return ans;
}

int a[MAXN], n; PII as[MAXN];
int roots[MAXN];

int main() {
    //printf("%.2lf\n", sizeof(tr)/1024./1024.);
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]), as[i]=mp(a[i], i);
    //n=100000; rep(i, 1, n) a[i]=rand(), as[i]=mp(a[i], i);
    sort(as+1, as+n+1, greater<PII>());

    fillchar(tr, 0);
    roots[0]=0;
    rep(i, 1, n) roots[i]=ins(roots[i-1], 1, n, as[i].se);

    //printf("%d\n",num);

    int m; scanf("%d", &m);
    while(m--) {
        int l, r, w; scanf("%d%d%d", &l,&r,&w);
        int le=0, ri=n;
        while(le<ri) {
            int mid=(le+ri)/2;
            Val val=query(roots[mid], 1, n, l, r);
            if(val.m>=w)
                ri=mid;
            else
                le=mid+1;
        }
        printf("%d\n", as[le].fi);
    }
    return 0;
}