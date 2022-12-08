#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }

char s[20][25];
int a[20][20];
int n, m;

int main() {
    scanf("%d%d", &n,&m);
    forn(i, n) scanf("%s", s[i]);
    forn(i, n) forn(j, m) scanf("%d", &a[i][j]);

    VPI chs[20];
    int free[20];
    forn(j, m) {
        free[j]=0;
        chs[j].clear();
        for(char ch='a'; ch<='z'; ++ch) {
            int x=0, num=0;
            forn(i, n) if(s[i][j]==ch) x|=(1<<i), ++num;
            if(num==0) continue;
            if(num==1) {
                free[j]|=x;
                continue;
            }
            int sum=0, maxv=0;
            forn(i, n) if(x&(1<<i)) {
                chs[j].PB(MP(1<<i, a[i][j]));
                sum+=a[i][j];
                setmax(maxv, a[i][j]);
            }
            chs[j].PB(MP(x, sum-maxv));
        }
    }

    static int f[1<<20];
    fillchar(f, 50);
    f[0]=0;
    forn(j, m) {
        forn(st, 1<<n)
            setmin(f[st|free[j]], f[st]);
        for(PII ch: chs[j])
            forn(st, 1<<n)
                setmin(f[st|ch.fi], f[st]+ch.se);
    }
    int ans=f[(1<<n)-1];
    printf("%d\n", ans);

    return 0;
}