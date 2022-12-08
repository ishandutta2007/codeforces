#include <algorithm>
#include <cassert>
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

LL root(LL m) {
    LL le=0, ri=min(m,100000LL);
    while(le<ri) {
        LL mid=(le+ri+1)/2;
        if(mid*mid*mid<=m) le=mid;
            else ri=mid-1;
    }
    return le;
}

PLL operator+(const PLL& a, const PLL& b) {
    return mp(a.fi+b.fi, a.se+b.se);
}

PLL dfs(LL m) {
    if(m<=7) return mp(m, m);
    LL x=root(m), x1=x*x*x, x2=(x-1)*(x-1)*(x-1);
    return max(dfs(m-x1)+mp(1,x1), dfs(x1-1-x2)+mp(1,x2));
}

int main() {
    LL m; cin>>m;
    PLL r=dfs(m);
    cout<<r.fi<<" "<<r.se<<endl;
    return 0;
}