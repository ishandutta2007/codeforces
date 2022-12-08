#include <cassert>
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

int main() {
    int l[10], r[10], m[10];
    l[1]=1989, r[1]=1998, m[1]=10;
    rep(i, 2, 9) {
        m[i]=m[i-1]*10;
        l[i]=r[i-1]+1, r[i]=l[i]+m[i]-1;
    }
    int cs; cin>>cs;
    while(cs--) {
        string s; cin>>s;
        s=s.substr(4);
        int x=atoi(s.c_str()), i=(int)s.size();
        printf("%d\n", l[i]+((x-l[i])%m[i]+m[i])%m[i]);
    }
    return 0;
}