// 9:51
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
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
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=200000;

struct Node {
    LL c=0, s=0, max_d=-1<<30, min_u=1<<30;
    LL buf=0;
    friend Node operator+(const Node& a, const Node& b) {
        Node t;
        t.c=a.c+b.c;
        if(a.c%2==0) {
            t.s=a.s+b.s;
            t.max_d=max(a.max_d, a.s+b.max_d);
            t.min_u=min(a.min_u, a.s+b.min_u);
        } else {
            t.s=a.s-b.s;
            t.max_d=max(a.max_d, a.s-b.min_u);
            t.min_u=min(a.min_u, a.s-b.max_d);
        }
        return t;
    }
    void print() {
        printf("c=%lld s=%lld md=%lld mu=%lld\n",c,s,max_d,min_u);
    }
} tr[N*4];

void build(const VI& a, int x, int l, int r) {
    if(l+1==r) {
        tr[x].c=1, tr[x].s=a[l]+1, tr[x].max_d=-1<<30, tr[x].min_u=a[l]+1;
        tr[x].buf=0;
        return;
    }
    const int m=(l+r)/2;
    build(a, x*2+1, l, m);
    build(a, x*2+2, m, r);
    tr[x]=tr[x*2+1]+tr[x*2+2];
}

void push(int x, LL val) {
    tr[x].buf+=val;
    if(tr[x].c%2==1) tr[x].s+=val;
    tr[x].min_u+=val;
}

void release(int x) {
    if(tr[x].buf!=0) {
        push(x*2+1, tr[x].buf);
        push(x*2+2, tr[x].buf);
        tr[x].buf=0;
    }
}

void add(int x, int l, int r, int s, int t, LL val) {
    if(s<=l && r<=t) {
        push(x, val);
        return;
    }
    release(x);
    const int m=(l+r)/2;
    if(s<m) add(x*2+1, l, m, s, t, val);
    if(m<t) add(x*2+2, m, r, s, t, val);
    tr[x]=tr[x*2+1]+tr[x*2+2];
}

Node get(int x, int l, int r, int s, int t) {
    if(s<=l && r<=t) {
        return tr[x];
    }
    release(x);
    const int m=(l+r)/2;
    Node tmp;
    if(s<m) tmp=tmp+get(x*2+1, l, m, s, t);
    if(m<t) tmp=tmp+get(x*2+2, m, r, s, t);
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);

    /*
    Node tmp;
    tmp.c=1, tmp.s=3, tmp.min_u=3, tmp.max_d=0;
    (Node()+tmp).print();
    */

    int n; cin>>n;
    VI a(n); for(int& x: a) cin>>x;
    build(a, 0, 0, n);

    int q; cin>>q;
    while(q--) {
        int op, s, t; cin>>op>>s>>t;
        ++t;
        if(op==1) {
            int k; cin>>k;
            add(0, 0, n, s, t, k);
        } else {
            Node r=get(0, 0, n, s, t);
            //r.print();
            bool ans=(r.s==(r.c%2==0?0:2) && r.max_d<=0 && r.min_u>=2);
            cout<<(ans?1:0)<<endl;
        }
    }
    return 0;
}