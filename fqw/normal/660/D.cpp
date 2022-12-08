#include <cassert>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define _ (int)
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

pair<PII, LL> get_id(int x, int y) {
    LL d=LL(x)*LL(x)+LL(y)*LL(y);
    int g=gcd(x, y); x/=g, y/=g;
    if(x+y<0) x=-x, y=-y;
    return mp(mp(x, y), d);
}

int main() {
    int n; cin>>n;
    VPI as(n); for(auto& a: as) cin>>a.fi>>a.se;
    LL ans=0;
    map<pair<PII, LL>, int> t;
    repn(i, n) rep(j, i+1, n-1) {
        auto id=get_id(as[j].fi-as[i].fi, as[j].se-as[i].se);
        ans+=t[id];
        t[id]++;
    }
    ans/=2; cout<<ans<<endl;
    return 0;
}