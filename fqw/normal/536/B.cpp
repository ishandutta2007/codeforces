#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
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

int main() {
    int n, m; cin>>n>>m;
    string p; cin>>p;
    VI ys(m); for(int &y: ys) cin>>y;
    
    reverse(all(p));
    VI pre(p.size()+1);
    int j=0;
    pre[0]=pre[1]=0;
    forint(i, 2, p.size()) {
        while(j>0 && p[j]!=p[i-1]) j=pre[j];
        if(p[j]==p[i-1]) ++j;
        pre[i]=j;
    }

    VI ok(p.size(), 0);
    for(int i=(int)p.size(); i>0; i=pre[i])
        ok[p.size()-i]=1;

    LL ans=1;
    forn(i, ys.size()-1) {
        int i1=ys[i], i2=ys[i+1];
        if(i2-i1<(int)p.size() && !ok[i2-i1])
            ans=0;
    }
    int space=0, last=1;
    for(int y: ys) {
        if(y>last) space+=y-last;
        last=y+(int)p.size();
    }
    space+=n+1-last;
    while(space--) ans=(ans*26)%LL(1e9+7);
    cout<<ans<<endl;

    return 0;
}