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

PII pos(int x) {
    if(x==0) return mp(4, 2);
    return mp((x-1)/3+1, (x-1)%3+1);
}

bool inside(PII p) {
    if(p.fi==4) return p.se==2;
    return p.fi>=1 && p.fi<=3 && p.se>=1 && p.se<=3;
}

int main() {
    scanf("%*d"); string s; cin>>s;
    VPI a; for(char c: s) a.pb(pos(int(c-'0')));
    for(const PII& d: VPI{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
        bool ok=true;
        for(const auto& p: a) {
            PII p2(p.fi+d.fi, p.se+d.se);
            if(!inside(p2)) ok=false;
        }
        if(ok) { printf("NO\n"); return 0; }
    }
    printf("YES\n");

    return 0;
}