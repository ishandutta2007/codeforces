#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
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

struct LineSet {
    vector<PLL> vec;

    LL better_time(PLL a, PLL b) {
        assert(a.fi<b.fi);
        return (a.se-b.se)/(b.fi-a.fi)+1;
    }

    bool is_eaten(PLL a, PLL b, PLL c) {
        return better_time(a, b)>=better_time(b, c);
    }

    // max (v * p.fi + p.se)
    LL get(LL v) {
        int l=0, r=(int)vec.size()-1;
        while(l<r) {
            int m1=(l+r)/2, m2=m1+1;
            if(v<better_time(vec[m1], vec[m2]))
                r=m1;
            else
                l=m2;
        }
        return v*vec[l].fi+vec[l].se;
    }
    void add(PLL p) {
        while(vec.size()>=2 && is_eaten(vec[vec.size()-2], vec.back(), p)) {
            vec.pop_back();
        }
        vec.push_back(p);
    }
};

int main() {
    const int N=200010;
    int n; cin>>n;
    LL a[N], s[N], t[N]; rep(i, 1, n) cin>>a[i];
    s[0]=t[0]=0;
    rep(i, 1, n) {
        s[i]=s[i-1]+a[i];
        t[i]=t[i-1]+a[i]*LL(i);
    }

    LL ans=0;
    LineSet line_set;
    line_set.add(mp(0, 0));
    rep(i, 1, n) {
        LL cur=t[i]+line_set.get(-s[i]);
        setmax(ans, cur);
        line_set.add(mp(i, -t[i]+i*s[i]));
    }
    cout<<ans<<endl;
    return 0;
}