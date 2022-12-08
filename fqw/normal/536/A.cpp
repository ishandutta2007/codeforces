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

bool ok(LL a, LL b, LL l, LL r, LL t, LL m) {
    if(a+b*(r-1)>t) return false;
    LL a1=a+b*(l-1);
    LL an=a+b*(r-1);
    LL num=r-l+1;
    if((a1+an)*num/2>t*m) return false;
    return true;
}

int main() {
    LL a, b, n; cin>>a>>b>>n;
    while(n--) {
        LL l, t, m; cin>>l>>t>>m;
        LL le=l, ri=l+t*m;
        while(le<ri) {
            LL r=(le+ri+1)/2;
            if(ok(a, b, l, r, t, m)) le=r;
            else ri=r-1;
        }
        if(!ok(a, b, l, le, t, m)) le=-1;
        cout<<le<<endl;
    }
    return 0;
}