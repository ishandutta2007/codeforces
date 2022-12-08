#include <algorithm>
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

int n, a[1010];

bool good(int limit, int* first, int* delta) {
    rep(d, 0, 20000) {
        int l=-1<<30, r=1<<30;
        rep(i, 1, n) {
            int zl=a[i]-d*i-limit, zr=a[i]-d*i+limit;
            setmax(l, zl);
            setmin(r, zr);
            if(l>r) break;
        }
        if(l<=r) {
            *first=l+d, *delta=d;
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int le=0, ri=10000, first=0, delta=0;
    while(le<ri) {
        int mid=(le+ri)/2;
        if(good(mid, &first, &delta)) ri=mid;
            else le=mid+1;
    }
    assert(good(le, &first, &delta));
    printf("%d\n%d %d\n", le, first, delta);
    return 0;
}