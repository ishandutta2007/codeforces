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

const int N=1000000;

int a[N*2], n;

LL solve() {
    static PII q[N*2];
    int ss=0, tt=0;
    LL ans=0;
    repn(i, n*2) {
        if(ss<tt && -q[ss].se+n<=i) ++ss;
        if(i>=n && ss<tt) {
            int k=int(lower_bound(q+ss, q+tt, mp(a[i],0), greater<PII>())-q);
            if(k>ss) --k;
            ans+=tt-k;
        }
        while(ss<tt && q[tt-1].fi<a[i]) --tt;
        q[tt++]=mp(a[i], -i);
    }
    return ans;
}

LL solve2() {
    VI xs;
    repn(i, n) xs.pb(a[i]);
    sort(all(xs), greater<int>());
    int j=1;
    while(j<sz(xs) && xs[j]==xs[1]) ++j;
    if(xs[0]==xs[1]) {
        return LL(j)*LL(j-1)/2;
    } else {
        return j-1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin>>n;
    repn(i, n) {
        cin>>a[i]; a[n+i]=a[i];
    }
    LL ans=solve()-solve2();
    cout<<ans<<endl;
    return 0;
}