// 6:23 - 6:56
// 9:33 - 9:40 - wa
#include <cassert>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define repn0(i, n) for(i=0; i<n; ++i)
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
template<class T> T max(T a, T b, T c, T d) { return max(max(a, b), max(c, d)); }

struct Point {
    int x=0, y=0;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    void read() { scanf("%d%d", &x,&y); }
};

struct Ans {
    Point p[4];
    int travel=numeric_limits<int>::max();
    bool operator<(const Ans& a) const {
        return travel<a.travel;
    }
    Ans rev() const {
        Ans r=*this;
        repn(i, 4) swap(r.p[i].x, r.p[i].y);
        return r;
    }
};

Ans check(map<int, vector<PII>> cx, map<int, vector<PII>> cy, int x1, int x2, int y1, int y2) {
    if(x2-x1!=y2-y1 || x1==x2) return Ans();

    Point target[4]={Point{x1,y1}, Point{x2,y1}, Point{x1,y2}, Point{x2,y2}};
    int g[4][4]; fillchar(g, 50);
    for(const auto& kv: cx) for(PII p: kv.se) {
        repn(i, 4) if(kv.fi==target[i].x) {
            setmin(g[p.se][i], abs(p.fi-target[i].y));
        }
    }
    for(const auto& kv: cy) for(PII p: kv.se) {
        repn(i, 4) if(kv.fi==target[i].y) {
            setmin(g[p.se][i], abs(p.fi-target[i].x));
        }
    }
    Ans ans;
    repn(i, 4) repn(j, 4) if(j!=i)
        repn(k, 4) if(k!=i && k!=j) {
            int l=0+1+2+3-i-j-k;
            if(setmin(ans.travel, max(g[0][i], g[1][j], g[2][k], g[3][l]))) {
                ans.p[0]=target[i];
                ans.p[1]=target[j];
                ans.p[2]=target[k];
                ans.p[3]=target[l];
            }
        }
    return ans;
}

Ans easy(map<int, vector<PII>> cx) {
    assert(cx.size()==2);
    if(cx.begin()->se.size()!=2) return Ans();
    sort(all(cx.begin()->se));
    sort(all(cx.rbegin()->se));

    int le=0, ri=200000000;

    Point p[4];
    auto ok=[&p,&cx](int len) {
        int d=cx.rbegin()->fi-cx.begin()->fi;
        int l=-1<<30, r=1<<30;
        for(const auto& kv: cx) {
            setmax(l, kv.se[0].fi-len);
            setmin(r, kv.se[0].fi+len);
            setmax(l, kv.se[1].fi-d-len);
            setmin(r, kv.se[1].fi-d+len);
        }
        if(l>r) return false;
        for(const auto& kv: cx) {
            p[kv.se[0].se]=Point(kv.fi, l);
            p[kv.se[1].se]=Point(kv.fi, l+d);
        }
        return true;
    };

    while(le<ri) {
        int mid=(le+ri)/2;
        if(ok(mid)) ri=mid;
            else le=mid+1;
    }
    ok(le);
    Ans ans; ans.travel=le; repn(i, 4) ans.p[i]=p[i];
    return ans;
}

Ans solve(map<int, vector<PII>> cx, map<int, vector<PII>> cy) {
    assert(cx.size()+cy.size()>0);
    if(cx.size()>=3 || cy.size()>=3) return Ans();

    // sum = 1
    if(cx.size()+cy.size()==1) return Ans();

    // sum = 2
    if(cx.size()==2 && cy.size()==0) {
        return easy(cx);
    }
    if(cx.size()==0 && cy.size()==2) return solve(cy, cx).rev();
    if(cx.size()==1 && cy.size()==1) return Ans();

    // sum = 3
    if(cx.size()==2 && cy.size()==1) {
        int x1=cx.begin()->fi, x2=cx.rbegin()->fi, d=x2-x1;
        int y=cy.begin()->fi;
        return min(check(cx, cy, x1, x2, y, y+d), check(cx, cy, x1, x2, y-d, y));
    }
    if(cx.size()==1 && cy.size()==2) return solve(cy, cx).rev();

    // sum = 4
    if(cx.size()==2 && cy.size()==2) {
        return check(cx, cy, cx.begin()->fi, cx.rbegin()->fi, cy.begin()->fi, cy.rbegin()->fi);
    }
    assert(false);
}

int main() {
    int cs; scanf("%d", &cs);
    while(cs--) {
        Point p[4]; repn(i, 4) p[i].read();
        int dir[4];
        Ans ans;
        repn0(dir[0], 2) repn0(dir[1], 2) repn0(dir[2], 2) repn0(dir[3], 2) {
            map<int, vector<PII>> cx, cy;
            repn(i, 4) if(dir[i]==0) {
                cx[p[i].x].pb(mp(p[i].y, i));
            } else {
                cy[p[i].y].pb(mp(p[i].x, i));
            }
            Ans tmp=solve(cx, cy);
            setmin(ans, tmp);
        }
        if(ans.travel<numeric_limits<int>::max()) {
            printf("%d\n", ans.travel);
            repn(i, 4) printf("%d %d\n", ans.p[i].x, ans.p[i].y);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}