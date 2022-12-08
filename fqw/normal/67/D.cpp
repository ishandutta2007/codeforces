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

int solve(VI a) {
    const int n=sz(a);
    VI tr(n+1);
    const auto upt=[&tr,n](int x, int v) {
        for(; x<=n; x+=x&-x) setmax(tr[x], v);
    };
    const auto get=[&tr](int x) {
        int r=0;
        for(; x>=1; x-=x&-x) setmax(r, tr[x]);
        return r;
    };
    int ans=0;
    repn(i, n) {
        int cur=get(n-a[i])+1;
        upt(n-a[i], cur);
        setmax(ans, cur);
    }
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    VI a(n);
    repn(i, n) {
        int x; scanf("%d", &x);
        --x; a[x]=i;
    }
    VI b(n);
    repn(i, n) {
        int x; scanf("%d", &x);
        --x; b[i]=a[x];
    }
    int ans=solve(b);
    printf("%d\n", ans);
    return 0;
}