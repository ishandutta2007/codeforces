#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int a[30030], n;

bool check(VI is) {
    if(is.size()==0) return false;
    if(is.size()==1) return true;
    int d=a[is[1]]-a[is[0]];
    repn(k, is.size()-1)
        if(a[is[k+1]]-a[is[k]]!=d)
            return false;
    return true;
}

void answer(VI is) {
    VI js;
    int cur=1;
    for(int i: is) {
        while(cur<i) js.pb(cur++);
        ++cur;
    }
    while(cur<=n) js.pb(cur++);
    if(!check(is)) return;
    if(!check(js)) return;
    for(int i: is) printf("%d ", a[i]); printf("\n");
    for(int j: js) printf("%d ", a[j]); printf("\n");
    exit(0);
}

void solve(int i1, int i2) {
    VI is{i1, i2};
    int d=a[i2]-a[i1], next=a[i2]+d;
    rep(i, i2+1, n)
        if(a[i]==next) {
            is.pb(i);
            next+=d;
        }
    answer(is);
    is.pop_back();
    answer(is);
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    if(n==2) answer({1});
    else {
        solve(1, 2);
        solve(1, 3);
        solve(2, 3);
    }
    printf("No solution\n");
    return 0;
}