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

const int N=100010;
LL next42(LL x) { LL y=1; while(y<x) y*=42; return y; }

struct Node {
    LL buf=0;
    LL v=0, nv=1;
    LL diff=1;

    void set(LL _v, LL _nv) {
        buf=0;
        v=_v, nv=_nv, diff=nv-v;
    }
    void add(LL _v) {
        if(v>=0) v+=_v;
            else buf+=_v;
        diff-=_v;
    }
} tr[N*4];

void release(int x) {
    if(tr[x].v>=0) {
        tr[x*2].set(tr[x].v, tr[x].nv);
        tr[x*2+1].set(tr[x].v, tr[x].nv);
        tr[x].v=-1;
    } else if(tr[x].buf>0) {
        tr[x*2].add(tr[x].buf);
        tr[x*2+1].add(tr[x].buf);
        tr[x].buf=0;
    }
}

void update(int x) {
    tr[x].diff=min(tr[x*2].diff, tr[x*2+1].diff);
}

void setval(int x, int s, int t, int st, int en, LL val) {
    if(st<=s && t<=en) {
        tr[x].set(val, next42(val));
        return;
    }
    int mid=(s+t)/2;
    release(x);
    if(st<=mid) setval(x*2, s, mid, st, en, val);
    if(mid<en) setval(x*2+1, mid+1, t, st, en, val);
    update(x);
}

LL getval(int x, int s, int t, int ind) {
    if(s==t) return tr[x].v;
    int mid=(s+t)/2;
    release(x);
    if(ind<=mid) return getval(x*2, s, mid, ind);
        else return getval(x*2+1, mid+1, t, ind);
    update(x);
}

void fix(int x) {
    if(tr[x].diff>=0) return;
    if(tr[x].v>=0) {
        tr[x].nv=next42(tr[x].v);
        tr[x].diff=tr[x].nv-tr[x].v;
        return;
    }
    release(x);
    fix(x*2); fix(x*2+1);
    update(x);
}

void addval(int x, int s, int t, int st, int en, LL val) {
    if(st<=s && t<=en) {
        tr[x].add(val);
        fix(x);
        return;
    }
    int mid=(s+t)/2;
    release(x);
    if(st<=mid) addval(x*2, s, mid, st, en, val);
    if(mid<en) addval(x*2+1, mid+1, t, st, en, val);
    update(x);
}

int main() {
    int n, q; scanf("%d%d", &n,&q);
    fill(tr, tr+N*4, Node());
    rep(i, 1, n) {
        int x; scanf("%d", &x);
        setval(1, 1, n, i, i, x);
    }
    while(q--) {
        int t; scanf("%d", &t);
        if(t==1) {
            int i; scanf("%d", &i);
            LL r=getval(1, 1, n, i);
            cout<<r<<endl;
        } else if(t==2) {
            int a, b, c; scanf("%d%d%d", &a,&b,&c);
            setval(1, 1, n, a, b, c);
        } else if(t==3) {
            int a, b, c; scanf("%d%d%d", &a,&b,&c);
            while(1) {
                addval(1, 1, n, a, b, c);
                if(tr[1].diff>0) break;
            }
        }
    }
    return 0;
}