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

struct Node {
    LL buf=0;
    LL lmost, rmost;
    int size=1, lup=1, rup=1, ldown=1, rdown=1, lhill=1, rhill=1, hill=1;

    Node(LL val=0) : lmost(val), rmost(val) {}

    void add(LL val) {
        buf+=val, lmost+=val, rmost+=val;
    }

    void release(Node* l, Node* r) {
        if(buf!=0) {
            l->add(buf), r->add(buf);
            buf=0;
        }
    }

    void update(const Node& l, const Node& r) {
        lmost=l.lmost, rmost=r.rmost;
        size=l.size+r.size;

        if(l.ldown==l.size && l.rmost>r.lmost) {
            ldown=l.size+r.ldown;
        } else {
            ldown=l.ldown;
        }
        if(r.rdown==r.size && r.lmost>l.rmost) {
            rdown=r.size+l.rdown;
        } else {
            rdown=r.rdown;
        }
        if(l.lup==l.size && l.rmost<r.lmost) {
            lup=l.size+r.lup;
        } else {
            lup=l.lup;
        }
        if(r.rup==r.size && r.lmost<l.rmost) {
            rup=r.size+l.rup;
        } else {
            rup=r.rup;
        }

        lhill=max(l.lhill, max(lup, ldown));
        if(l.lhill==l.size && l.rmost>r.lmost) {
            setmax(lhill, l.size+r.ldown);
        }
        if(l.lup==l.size && l.rmost<r.lmost) {
            setmax(lhill, l.size+r.lhill);
        }

        rhill=max(r.rhill, max(rup, rdown));
        if(r.rhill==r.size && r.lmost>l.rmost) {
            setmax(rhill, r.size+l.rdown);
        }
        if(r.rup==r.size && r.lmost<l.rmost) {
            setmax(rhill, r.size+l.rhill);
        }

        hill=max(l.hill, r.hill);
        if(l.rmost<r.lmost) {
            setmax(hill, l.rdown+r.lhill);
        }
        if(l.rmost>r.lmost) {
            setmax(hill, l.rhill+r.ldown);
        }
    }
};

const int N=300010;
Node tr[N*4];

void build(int x, int l, int r, const VI& a) {
    tr[x].buf=0;
    if(l+1==r) {
        tr[x]=Node(a[l]);
        return;
    }
    const int m=(l+r)/2;
    build(x*2+1, l, m, a);
    build(x*2+2, m, r, a);
    tr[x].update(tr[x*2+1], tr[x*2+2]);
}

void add(int x, int l, int r, int begin, int end, LL val) {
    if(begin<=l && r<=end) {
        tr[x].add(val);
        return;
    }
    tr[x].release(&tr[x*2+1], &tr[x*2+2]);
    const int m=(l+r)/2;
    if(begin<m) {
        add(x*2+1, l, m, begin, end, val);
    }
    if(m<end) {
        add(x*2+2, m, r, begin, end, val);
    }
    tr[x].update(tr[x*2+1], tr[x*2+2]);
}

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    repn(i, n) scanf("%d", &a[i]);

    build(0, 0, n, a);
    int num; scanf("%d", &num);
    while(num--) {
        int l, r, d; scanf("%d%d%d", &l,&r,&d);
        --l;
        add(0, 0, n, l, r, d);
        printf("%d\n", tr[0].hill);
    }

    return 0;
}