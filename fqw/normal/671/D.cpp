#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <functional>
#include <map>
#include <memory>
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
typedef vector<PLL> VPL;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=300010;

VI es[N]; int dep[N];
VPL offers[N];
int n;

void init() {
    int m; scanf("%d%d", &n,&m);
    repn(i, n-1) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b), es[b].pb(a);
    }
    function<void(int, int, int)> dfs=[&](int x, int fa, int d) {
        dep[x]=d;
        for(int y: es[x]) if(y!=fa) {
            dfs(y, x, d-1);
        }
    };
    dfs(1, 0, n);

    repn(i, m) {
        int a, b, c; scanf("%d%d%d", &a,&b,&c);
        if(a!=b) offers[a].pb(mp(dep[b], c));
    }
}

struct Set {
    map<LL, LL>* s;
    LL offset;

    Set() {
        s=new map<LL, LL>;
        offset=0;
    }

    LL minv() const {
        assert(!s->empty());
        return offset+s->begin()->se;
    }

    void insert(PLL x) {
        x.se-=offset;
        if(s->find(x.fi)!=s->end()) {
            if((*s)[x.fi]<x.se) return;
            s->erase(x.fi);
        }
        auto it=s->insert(x).fi;

        auto y=next(it); if(y!=s->end()) {
            if(y->se<=it->se) {
                s->erase(it); return;
            }
        }
        while(it!=s->begin()) {
            y=prev(it);
            if(y->se>=it->se) {
                s->erase(y);
            } else {
                return;
            }
        }

    }
};

Set merge(Set a, Set b) {
    if(a.s->size()<b.s->size()) return merge(b, a);
    LL ma=a.minv(), mb=b.minv();
    //cout<<ma<<" "<<mb<<endl;
    a.offset+=mb, b.offset+=ma;
    for(const auto& x: *b.s) a.insert(mp(x.fi, x.se+b.offset));
    delete b.s;
    return a;
}


Set go(int x, int fa) {
    Set r; r.s->insert(mp(dep[x], 0));
    for(PLL offer: offers[x]) r.insert(offer);
    for(int y: es[x]) if(y!=fa) {
        auto t=go(y, x);
        if(t.s->empty()) return Set();
        if(t.s->begin()->fi<dep[x]) {
            t.s->erase(t.s->begin());
            if(t.s->empty()) return Set();
        }
        r=merge(r, t);
    }
    //cout<<"x="<<x<<" minv="<<r.minv()<<endl;
    return r;
}

void solve() {
    auto r=go(1, 0);
    LL ans=r.s->empty()?-1:r.minv();
    cout<<ans<<endl;
}

int main() {
    init();
    solve();
    return 0;
}