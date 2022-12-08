#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

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
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
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

const int MAXN=200010;

string a, b;

void go(string &s, int le, int ri) {
    int len=ri-le;
    if(len%2==1) return;
    int mid=(le+ri)/2;
    go(s, le, mid);
    go(s, mid, ri);

    bool need_swap=false;
    repn(i, len/2) {
        if(s[le+i]<s[mid+i]) break;
        if(s[le+i]>s[mid+i]) {
            need_swap=true; break;
        }
    }
    if(need_swap) {
        repn(i, len/2) swap(s[le+i], s[mid+i]);
    }
}

int main() {
    static char buf[MAXN];
    scanf("%s", buf); a=string(buf);
    scanf("%s", buf); b=string(buf);

    go(a, 0, (int)a.size());
    go(b, 0, (int)b.size());
    printf("%s\n", a==b?"YES":"NO");

    return 0;
}