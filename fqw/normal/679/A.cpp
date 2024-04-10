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

bool prime[111]; 

bool ask(int x) {
    printf("%d\n", x); fflush(stdout);
    char s[99]; scanf("%s", s);
    return s[0]=='y';
}

bool is_composite() {
    rep(p, 2, 10) if(prime[p]) {
        if(!ask(p)) continue;
        rep(p2, 2, 100/p) if(prime[p2]) {
            if(ask(p*p2)) return true;
        }
        return false;
    }
    return false;
}

int main() {
    fillchar(prime, true);
    for(int i=2; i<=100; ++i) if(prime[i]) {
        for(int j=i*2; j<=100; j+=i) prime[j]=false;
    }
    bool ans=is_composite();
    printf("%s\n", ans?"composite":"prime"); fflush(stdout);
    return 0;
}