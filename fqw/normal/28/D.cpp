#include <unordered_map> //
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

struct Truck {
    int v, c, l, r, i;
    void read() { scanf("%d%d%d%d",&v,&c,&l,&r); }
};

pair<int, VI> solve(const vector<Truck>& a, int tot) {
    struct Entry {
        int v, i;
        Entry* prev;
    };
    unordered_map<int, Entry*> m;
    m[0]=new Entry{0, -1, nullptr};
    for(const auto& cur: a) {
        if(m.count(cur.l)) {
            Entry* e=new Entry{m[cur.l]->v+cur.v, cur.i, m[cur.l]};
            if(m.count(cur.l+cur.c)==0 || m[cur.l+cur.c]->v<e->v) {
                m[cur.l+cur.c]=e;
            }
        }
    }
    if(m.count(tot)) {
        int value=m[tot]->v;
        VI ids;
        for(auto e=m[tot]; e->i>=0; e=e->prev) {
            ids.pb(e->i);
        }
        reverse(all(ids));
        return mp(value, ids);
    } else {
        return mp(0, VI());
    }
}

int main() {
    int n; scanf("%d", &n);
    unordered_map<int, vector<Truck>> m;
    repn(i, n) {
        Truck t; t.read();
        t.i=i;
        m[t.l+t.c+t.r].pb(t);
    }
    pair<int, VI> ans;
    for(const auto& kv: m) {
        const auto tmp=solve(kv.se, kv.fi);
        setmax(ans, tmp);
    }
    printf("%d\n", sz(ans.se));
    for(int i: ans.se) printf("%d ", i+1);
    printf("\n");
    return 0;
}