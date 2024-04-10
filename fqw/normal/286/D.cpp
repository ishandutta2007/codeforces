// 11:59 - 12:28
#include <cassert>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <tuple>
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

struct Wall {
    LL l, r, t;
    Wall(LL l, LL r, LL t) : l(l), r(r), t(t) {}
    bool operator<(const Wall& q) const {
        return r<q.r;
    }
};

vector<Wall> prepare_walls(int num) {
    vector<tuple<int, int, int>> as(num);
    for(auto& a: as) scanf("%d%d%d", &get<1>(a), &get<2>(a), &get<0>(a));
    sort(all(as), greater<tuple<int, int, int>>());

    multiset<Wall> s;
    for(const auto& a: as) {
        int l=get<1>(a), r=get<2>(a), t=get<0>(a);
        while(1) {
            auto it=s.lower_bound(Wall(0, l+1, 0));
            if(it==s.end() || r<=it->l) break;
            Wall q=*it; s.erase(it);
            if(q.l<l) s.insert(Wall(q.l, l, q.t));
            if(r<q.r) s.insert(Wall(r, q.r, q.t));
        }
        s.insert(Wall(l, r, t));
    }
    return vector<Wall>(all(s));
}

void answer_queries(const vector<Wall>& walls, int qn) {
    multiset<PLL> turnings;
    for(const auto& w: walls) {
        turnings.insert(mp(w.t-w.r, 1));
        turnings.insert(mp(w.t-w.l, -1));
    }
    vector<LL> ans(qn);
    vector<PII> queries(qn);
    int _id=0; for(auto& q: queries) scanf("%d", &q.fi), q.se=_id++;
    sort(all(queries));
    LL y=-(1<<30), velocity=0, val=0;
    for(const auto& q: queries) {
        while(y<q.fi) {
            LL delta=q.fi-y;
            if(!turnings.empty()) setmin(delta, turnings.begin()->fi-y);
            val+=velocity*delta;
            y+=delta;
            while(!turnings.empty() && turnings.begin()->fi==y) {
                velocity+=turnings.begin()->se;
                turnings.erase(turnings.begin());
            }
        }
        ans[q.se]=val;
    }
    for(LL x: ans) printf("%d\n", (int)x);
}

int main() {
    int n, m; scanf("%d%d", &n,&m);
    auto walls=prepare_walls(m);
    //for(const auto& w: walls) printf("wall: %lld %lld %lld\n",w.l,w.r,w.t);
    answer_queries(walls, n);
    return 0;
}