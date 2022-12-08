#include <set>
#include <cassert>
#include <algorithm>
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
typedef vector<PLL> VPL;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

struct Prob {
    LL p, t, x1, x2;
    bool operator<(const Prob& other) const {
        return p*other.t>other.p*t;
    }
    double min_score(double c, LL T) const {
        return (double)p*(1-c*(double)x2/(double)T);
    }
    double max_score(double c, LL T) const {
        return (double)p*(1-c*(double)x1/(double)T);
    }
};

void solve(vector<Prob> ps, LL T) {
    sort(all(ps), [](const Prob& a, const Prob& b) { return a.p<b.p; });
    double le=0, ri=1;
    repn(_t, 60) {
        double c=(le+ri)/2;
        double max_score=0;
        bool ok=true;
        for(int i=0, j; i<sz(ps); i=j) {
            for(j=i; j<sz(ps) && ps[i].p==ps[j].p; ++j);
            rep(k, i, j-1) if(ps[k].min_score(c, T)+1e-8<max_score) {
                ok=false; break;
            }
            if(!ok) break;
            rep(k, i, j-1) setmax(max_score, ps[k].max_score(c, T));
        }
        if(ok) le=c;
            else ri=c;
    }
    printf("%.9lf\n", le);
}

int main() {
    int n; scanf("%d", &n);
    vector<Prob> ps(n);
    for(auto& p: ps) { int x; scanf("%d", &x); p.p=x; }
    for(auto& p: ps) { int x; scanf("%d", &x); p.t=x; }
    sort(all(ps));
    LL sx=0;
    for(int i=0, j; i<n; i=j) {
        for(j=i; j<n && !(ps[i]<ps[j]); ++j);
        LL tx=sx; rep(k, i, j-1) tx+=ps[k].t;
        rep(k, i, j-1) {
            ps[k].x1=sx+ps[k].t;
            ps[k].x2=tx;
        }
        sx=tx;
    }
    solve(ps, sx);
    return 0;
}