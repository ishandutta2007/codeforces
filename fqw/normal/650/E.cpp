#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <set>
#include <map>
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

const int N=500000;

PII es[2][N]; int n;

// edges shared by es[0] & es[1]; return indices in es[0/1].
VPI shared_es() {
    map<PII, int> w0; repn(k, n-1) w0[es[0][k]]=k;
    VPI r;
    repn(k, n-1) if(w0.count(es[1][k])>0) {
        r.pb(mp(w0[es[1][k]], k));
    }
    return r;
}

int rt[N]; int get(int x) { return rt[x]<0?x:rt[x]=get(rt[x]); }
set<int>* ks[2][N];
set<int> ones;

void unpin(int x) { if(ks[0][x]->size()==1) ones.erase(x); }
void pin(int x) { if(ks[0][x]->size()==1) ones.insert(x); }

void rm(int i, int k) {
    int a=es[i][k].fi, b=es[i][k].se;
    a=get(a), b=get(b);
    unpin(a); ks[i][a]->erase(k); pin(a);
    unpin(b); ks[i][b]->erase(k); pin(b);
}

void merge_set(set<int>*& s1, set<int>*& s2) {
    if(s1->size()>s2->size()) swap(s1, s2);
    for(int x: *s1) s2->insert(x);
    s1->clear();
}

void merge(int a, int b) {
    a=get(a), b=get(b);
    unpin(a), unpin(b);
    merge_set(ks[0][a], ks[0][b]);
    merge_set(ks[1][a], ks[1][b]);
    pin(b); rt[a]=b;
}

int main() {
    scanf("%d", &n);
    repn(i, 2) repn(k, n-1) {
        int a, b; scanf("%d%d", &a,&b);
        --a, --b; if(a>b) swap(a, b);
        es[i][k]=mp(a, b);
    }

    fillchar(rt, -1);
    repn(i, 2) repn(x, n) ks[i][x]=new set<int>;
    repn(i, 2) repn(k, n-1) {
        int a=es[i][k].fi, b=es[i][k].se;
        ks[i][a]->insert(k), ks[i][b]->insert(k);
    }
    ones.clear(); repn(x, n) pin(x);

    int rest=n-1;
    for(PII kk: shared_es()) {
        --rest;
        rm(0, kk.fi); rm(1, kk.se);
        merge(es[0][kk.fi].fi, es[0][kk.fi].se);
    }
    printf("%d\n", rest);
    while(rest--) {
        int x=*ones.begin();
        int k0=*ks[0][x]->begin(); rm(0, k0);
        int k1=*ks[1][x]->begin(); rm(1, k1);
        printf("%d %d %d %d\n", es[0][k0].fi+1, es[0][k0].se+1, es[1][k1].fi+1, es[1][k1].se+1);

        merge(es[1][k1].fi, es[1][k1].se);
    }

    return 0;
}