#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
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

const int N=200020;
const int V=200000;

VI pos[V+1];
int a[N];
int n;
LL ans;

struct Node {
    LL sum, minv, maxv;
    LL buf;
} tr[N*4];

void update(int x) {
    tr[x].sum=tr[x*2].sum+tr[x*2+1].sum;
    tr[x].minv=tr[x*2].minv;
    tr[x].maxv=tr[x*2+1].maxv;
}

void push(int x, int s, int t, LL v) {
    tr[x].buf=tr[x].minv=tr[x].maxv=v;
    tr[x].sum=v*(t-s+1);
}

void release(int x, int s, int m, int t) {
    if(tr[x].buf>=0) {
        push(x*2, s, m, tr[x].buf);
        push(x*2+1, m+1, t, tr[x].buf);
        tr[x].buf=-1;
    }
}

void build(int x, int s, int t) {
    tr[x].buf=-1;
    if(s==t) {
        tr[x].sum=tr[x].minv=tr[x].maxv=s;
        return;
    }
    int m=(s+t)/2;
    build(x*2, s, m);
    build(x*2+1, m+1, t);
    update(x);
}

int find(int x, int s, int t, LL v) {
    if(tr[x].maxv<=v) return t;
    if(tr[x].minv>v) return s-1;
    int m=(s+t)/2;
    release(x, s, m, t);
    if(tr[x*2+1].minv<=v)
        return find(x*2+1, m+1, t, v);
    else
        return find(x*2, s, m, v);
}

LL get_sum(int x, int s, int t, int st, int en) {
    if(st<=s && t<=en) return tr[x].sum;
    int m=(s+t)/2;
    release(x, s, m, t);
    LL r=0;
    if(st<=m) r+=get_sum(x*2, s, m, st, en);
    if(m<en) r+=get_sum(x*2+1, m+1, t, st, en);
    return r;
}

void set_val(int x, int s, int t, int st, int en, LL v) {
    if(st<=s && t<=en) {
        push(x, s, t, v);
        return;
    }
    int m=(s+t)/2;
    release(x, s, m, t);
    if(st<=m) set_val(x*2, s, m, st, en, v);
    if(m<en) set_val(x*2+1, m+1, t, st, en, v);
    update(x);
}

void go(int i, int j, LL val) {
    if(i>j) return;
    int j0=find(1, 1, n, j); if(j0<i) return;
    LL s=get_sum(1, 1, n, i, j0);
    ans+=(LL(j0-i+1)*LL(j+1)-s)*val;
    set_val(1, 1, n, i, j0, j+1);
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 1, V) pos[i].clear();
    rep(i, 1, n) {
        int x=a[i];
        for(int y=1; y*y<=x; ++y)
            if(x%y==0) {
                pos[y].pb(i);
                if(y*y<x) pos[x/y].pb(i);
            }
    }

    build(1, 1, n);
    ans=0;
    irep(v, V, 1) {
        int l=sz(pos[v]);
        if(l<=1) continue;
        int p0=pos[v][0], p1=pos[v][1];
        int p2=pos[v][l-2], p3=pos[v][l-1];
        go(1, p2-1, v);
        go(p0+1, p3-1, v);
        go(p1+1, n, v);
    }
    cout<<ans<<endl;

    return 0;
}