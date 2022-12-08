#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
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

const int N=100000;

struct Node {
    double a, b, c, d;

    friend Node operator+(const Node& n1, const Node& n2) {
        Node t;
        t.a=n1.a+n1.b/(1-n2.a*n1.d)*n2.a*n1.c;
        t.b=n1.b/(1-n2.a*n1.d)*n2.b;
        t.c=n2.c/(1-n1.d*n2.a)*n1.c;
        t.d=n2.c/(1-n1.d*n2.a)*n1.d*n2.b+n2.d;
        return t;
    }

    void reset(double p) {
        a=c=1-p;
        b=d=p;
    }
} tr[N*4];

void build(const vector<double>& p, int x, int l, int r) {
    if(l+1==r) {
        tr[x].reset(p[l]);
        return;
    }
    const int m=(l+r)/2;
    build(p, x*2+1, l, m);
    build(p, x*2+2, m, r);
    tr[x]=tr[x*2+1]+tr[x*2+2];
}

void setval(int x, int l, int r, int i, double val) {
    if(l+1==r) {
        tr[x].reset(val);
        return;
    }
    const int m=(l+r)/2;
    if(i<m) {
        setval(x*2+1, l, m, i, val);
    } else {
        setval(x*2+2, m, r, i, val);
    }
    tr[x]=tr[x*2+1]+tr[x*2+2];
}

Node get(int x, int l, int r, int s, int t) {
    //printf("x=%d \n",x);
    if(s<=l && r<=t) {
        return tr[x];
    }
    const int m=(l+r)/2;
    if(t<=m) return get(x*2+1, l, m, s, t);
    if(m<=s) return get(x*2+2, m, r, s, t);
    return get(x*2+1, l, m, s, t)+get(x*2+2, m, r, s, t);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, q; cin>>n>>q;
    vector<double> p(n);
    repn(i, n) {
        double a, b; cin>>a>>b;
        p[i]=a/b;
    }
    build(p, 0, 0, n);
    cout<<setprecision(20);
    while(q--) {
        int op; cin>>op;
        if(op==1) {
            int i; double a, b;
            cin>>i>>a>>b;
            --i;
            setval(0, 0, n, i, a/b);
        } else {
            int l, r; cin>>l>>r;
            --l;
            Node t=get(0, 0, n, l, r);
            cout<<t.b<<endl;
        }
    }
    return 0;
}