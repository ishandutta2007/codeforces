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
    int n, m; scanf("%d%d", &n,&m);
    static int a[100000]; fillchar(a, 0);
    repn(i, n) {
        static char s[100010]; scanf("%s", s);
        repn(j, m) if(s[j]=='1') a[j]|=(1<<i);
    }
    static int f[21][1<<20]; fillchar(f, 0);
    repn(j, m) f[0][a[j]]++;
    repn(k, n) {
        irep(i, n, 1) repn(s, 1<<n) f[i][s]+=f[i-1][s^(1<<k)];
    }
    int ans=1<<30;
    repn(s, 1<<n) {
        int cur=0;
        rep(i, 0, n) cur+=min(i, n-i)*f[i][s];
        setmin(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}