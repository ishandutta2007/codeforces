#include <algorithm>
#include <cassert>
#include <set>
#include <limits>
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

const LL NONE=numeric_limits<LL>::min();
const LL INF=1LL<<40;

LL mult(PLL p0, PLL p1, PLL p2) {
    return (p1.fi-p0.fi)*(p2.se-p0.se)-(p1.se-p0.se)*(p2.fi-p0.fi);
}

class Hull {
    vector<PLL> s;
public:
    void add(PLL p) {
        s.pb(p);
    }
    void prepare() {
        if(s.empty()) return;
        sort(all(s));
        vector<PLL> tmp=move(s); s.clear();
        for(const auto& p: tmp) {
            while(sz(s)>=2 && mult(s[sz(s)-2], s.back(), p)>=0) {
                s.pop_back();
            }
            s.pb(p); 
        }
    }
    LL f(LL a, int i) {
        return s[i].fi*a+s[i].se;
    }
    // returns max(a x + y)
    LL query(LL a) {
        if(s.empty()) return NONE;
        if(sz(s)==1) return f(a, 0);
        int le=1, ri=sz(s)-1;
        while(le<ri) {
            int mid=(le+ri)/2;
            if(f(a, mid-1)>f(a, mid)) {
                ri=mid;
            } else {
                le=mid+1;
            }
        }
        return max(f(a, le-1), f(a, le));
    }
};

const int N=300010;

Hull tr[N*4];
int qt[N], qa[N], qb[N];
int n;

void add(int x, int s, int t, int st, int en, LL vx, LL vy) {
    if(st<=s && t<=en) {
        tr[x].add(mp(vx, vy));
        return;
    }
    int mid=(s+t)/2;
    if(st<=mid) add(x*2, s, mid, st, en, vx, vy);
    if(mid<en) add(x*2+1, mid+1, t, st, en, vx, vy);
}

LL query(int x, int s, int t, int ind, LL q) {
    LL ans=tr[x].query(q);
    if(s==t) return ans;
    int mid=(s+t)/2;
    if(ind<=mid) setmax(ans, query(x*2, s, mid, ind, q));
        else setmax(ans, query(x*2+1, mid+1, t, ind, q));
    return ans;
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) {
        scanf("%d%d", &qt[i],&qa[i]);
        if(qt[i]==1) scanf("%d", &qb[i]);
    }
    rep(i, 1, n) if(qt[i]==2) {
        add(1, 1, n, qa[i], i, qa[qa[i]], qb[qa[i]]);
        qt[qa[i]]=0;
    }
    rep(i, 1, n) if(qt[i]==1) {
        add(1, 1, n, i, n, qa[i], qb[i]);
    }
    repn(i, N*4) {
        tr[i].prepare();
    }
    rep(i, 1, n) if(qt[i]==3) {
        LL ans=query(1, 1, n, i, qa[i]);
        if(ans==NONE) {
            printf("EMPTY SET\n");
        } else {
            printf("%lld\n", ans);
        }
    }
    return 0;
}