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

VI generate(int n, int maxv, int sum) {
    assert(1*n<=sum && maxv*n>=sum);
    VI r; sum-=n;
    rep(i, 1, n) {
        int cur=min(sum, maxv-1);
        r.pb(cur+1), sum-=cur;
    }
    assert(sum==0);
    return r;
}

int main() {
    VI ops;
    while(1) {
        char s[99]; scanf("%*s%s", s);
        if(strcmp(s, "=")==0) break;
        if(strcmp(s, "+")==0) ops.pb(+1); else ops.pb(-1);
    }
    int n; scanf("%d", &n);

    int pos=1, neg=0;
    for(int op: ops) if(op>0) pos++; else neg++;

    int l=max(pos*1, neg*1+n), r=min(pos*n, neg*n+n);
    if(l>r) printf("Impossible\n");
    else {
        printf("Possible\n");
        auto xs=generate(pos, n, l);
        auto ys=generate(neg, n, l-n);
        printf("%d", xs.back()); xs.pop_back();
        for(int op: ops) {
            if(op>0) printf(" + %d", xs.back()), xs.pop_back();
                else printf(" - %d", ys.back()), ys.pop_back();
        }
        printf(" = %d\n", n);
    }




    return 0;
}