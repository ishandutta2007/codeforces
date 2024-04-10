#include <cassert>
#include <set>
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

char s[10010];
int n;

string os[10010][4];
bool ok[10010][4];

int main() {
    scanf("%s", s+1); n=int(strlen(s+1));
    rep(i, 1, n) rep(c, 2, 3) {
        os[i][2]=string()+s[i]+s[i+1];
        os[i][3]=os[i][2]+s[i+2];
    }
    fillchar(ok, false);
    if(n-1>=6) ok[n-1][2]=true;
    if(n-2>=6) ok[n-2][3]=true;
    irep(i, n-1, 1) rep(c, 2, 3) if(ok[i][c]) {
        if(i-2>=6 && os[i-2][2]!=os[i][c]) ok[i-2][2]=true;
        if(i-3>=6 && os[i-3][3]!=os[i][c]) ok[i-3][3]=true;
    }
    set<string> p;
    rep(i, 1, n) rep(c, 2, 3) if(ok[i][c])
        p.insert(os[i][c]);
    printf("%d\n", int(p.size()));
    for(const auto& str: p) printf("%s\n", str.c_str());

    return 0;
}