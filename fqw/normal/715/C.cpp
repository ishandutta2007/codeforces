#include <map>
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

const int N=100000;

VPI es[N];
int n, MOD;
LL ans, inv10;

LL ext_gcd(LL a, LL b, LL* x, LL* y) {
    if(b==0) { *x=1, *y=0; return a; }
    LL u, v; LL g=ext_gcd(b, a%b, &u, &v);
    *x=v, *y=u-a/b*v;
    return g;
}

LL inv(LL a) {
    LL x, y; ext_gcd(a, MOD, &x, &y);
    if(x<0) x+=MOD;
    return x;
}

struct Set {
    map<LL, int>* s;
    LL u, inv_u, v;   // real_val = val * u + v, forall val in s
    Set() {
        s=new map<LL, int>;
        u=inv_u=1, v=0;
    }
    Set& insert(LL x, int val=1) {
        LL x0=(x-v+MOD)*inv_u%MOD;
        (*s)[x0]+=val;
        return *this;
    }
    Set& all_add(LL c) {
        (v+=c)%=MOD;
        return *this;
    }
    Set& all_mult(LL c) {
        (u*=c)%=MOD;
        (v*=c)%=MOD;
        (inv_u*=inv(c))%=MOD;
        return *this;
    }
    int count(LL x) const {
        LL x0=(x-v+MOD)*inv_u%MOD;
        const auto it=s->find(x0);
        return it!=s->end() ? it->se : 0;
    }
    int size() const { return int(s->size()); }
};

void count(Set a, Set b) {
    if(a.size()<b.size()) { count(b, a); return; }
    for(const auto kv: *b.s) {
        LL x0=(kv.fi*b.u+b.v)%MOD;
        ans+=LL(a.count((MOD-x0)%MOD))*LL(kv.se);
    }
}

Set merge(Set a, Set b) {
    if(a.size()<b.size()) return merge(b, a);
    for(const auto& kv: *b.s) {
        LL x0=(kv.fi*b.u+b.v)%MOD;
        a.insert(x0, kv.se);
    }
    return a;
}

pair<Set, Set> dfs(int x, int fa) {
    pair<Set, Set> r;
    r.fi.insert(0);
    r.se.insert(0);
    for(const auto& e: es[x]) if(e.fi!=fa) {
        auto tmp=dfs(e.fi, x);
        tmp.fi.all_mult(10).all_add(e.se);
        tmp.se.all_add(e.se).all_mult(inv10);
        count(r.fi, tmp.se);
        count(tmp.fi, r.se);
        r.fi=merge(r.fi, tmp.fi);
        r.se=merge(r.se, tmp.se);
    }
    return r;
}

int main() {
    scanf("%d%d", &n,&MOD);
    if(MOD==1) {
    }
    inv10=inv(10);
    repn(i, n-1) {
        int a, b, c; scanf("%d%d%d", &a,&b,&c);
        es[a].pb(mp(b, c));
        es[b].pb(mp(a, c));
    }
    ans=0;
    dfs(0, -1);
    printf("%lld\n", ans);
    return 0;
}