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

const int N=300010;

int a[N], s[N];
int n, k;

int main() {
    scanf("%d%d", &n,&k);
    s[0]=0;
    rep(i, 1, n) {
        scanf("%d", &a[i]);
        s[i]=s[i-1]+(1-a[i]);
    }
    int le=0, ri=n;
    while(le<ri) {
        int mid=(le+ri+1)/2;
        bool ok=false;
        rep(i, mid, n) if(s[i]-s[i-mid]<=k) ok=true;
        if(ok) le=mid; else ri=mid-1;
    }
    printf("%d\n", le);
    rep(i, le, n) if(s[i]-s[i-le]<=k) {
        rep(j, i-le+1, i) a[j]=1;
        break;
    }
    rep(i, 1, n) printf("%d ", a[i]);
    printf("\n");
    return 0;
}