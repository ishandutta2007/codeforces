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

LL solve_naive(LL n) {
    VI v(1001);
    rep(i, 2, 1000) {
        int j=i-1;
        while(i%j!=0) --j;
        v[i]=j;
    }
    VL f(1001);
    f[0]=0, f[1]=1<<30;
    rep(i, 2, 1000) {
        f[i]=1<<30;
        rep(j, 2, i) setmin(f[i], f[i-j]+v[j]);
    }
    return f[n];
}

bool is_prime(LL n) {
    for(LL x=2; x*x<=n; ++x) {
        if(n%x==0) {
            return false;
        }
    }
    return true;
}

LL solve(LL n) {
    if(n<1000) {
        return solve_naive(n);
    }
    if(is_prime(n)) {
        return 1;
    }
    if(n%2==0) {
        return 2;
    } else {
        if(is_prime(n-2)) {
            return 2;
        } else {
            return 3;
        }
    }
}

int main() {
    LL n; cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}