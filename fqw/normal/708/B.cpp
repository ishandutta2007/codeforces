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

LL c2(LL n) { return n*(n-1)/2; }

string solve(LL n0, LL n1, LL a01, LL a10) {
    if(a01+a10!=n0*n1) return "";
    string s="";
    while(n0>0 || n1>0) {
        if(n0>0 && a01>=n1) {
            a01-=n1, --n0;
            s+='0';
        } else {
            assert(n1>0 && a10>=n0);
            a10-=n0, --n1;
            s+='1';
        }
    }
    return s;
}

string solve() {
    LL a00, a01, a10, a11; cin>>a00>>a01>>a10>>a11;
    LL n0_l, n0_r;
    if(a00==0) n0_l=0, n0_r=1;
    else {
        LL n0=0; while(c2(n0)<a00) ++n0; if(c2(n0)!=a00) return "";
        n0_l=n0_r=n0;
    }
    LL n1_l, n1_r;
    if(a11==0) n1_l=0, n1_r=1;
    else {
        LL n1=0; while(c2(n1)<a11) ++n1; if(c2(n1)!=a11) return "";
        n1_l=n1_r=n1;
    }
    rep(n0, n0_l, n0_r) rep(n1, n1_l, n1_r) {
        auto s=solve(n0, n1, a01, a10);
        if(!s.empty()) return s;
    }
    return "";
}

int main() {
    string s=solve();
    if(s.empty()) s="Impossible";
    cout<<s<<endl;
    return 0;
}