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

const int N=100010;

int a[N], s[N], n, k;

bool ok(int limit) {
    rep(i, 1, n) if(a[i]==1) {
        int l=max(1, i-limit), r=min(n, i+limit);
        if(s[r]-s[l-1]>=k+1) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n,&k);
    static char buf[N]; scanf("%s", buf+1);
    rep(i, 1, n) a[i]=(buf[i]=='0'?1:0);
    s[0]=0; rep(i, 1, n) s[i]=s[i-1]+a[i];
    int le=0, ri=100000;
    while(le<ri) {
        int mid=(le+ri)/2;
        if(ok(mid)) ri=mid;
            else le=mid+1;
    }
    printf("%d\n", le);
    return 0;
}