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

const int MAXN=200010;
const LL MOD=LL(1e9)+7;

VI es[MAXN];
int n;

LL f[MAXN], g[MAXN], tf[MAXN], tg[MAXN];
int fa[MAXN];

void dfs(int x, int father) {
    fa[x]=father;
    f[x]=g[x]=1;
    for(int y: es[x]) if(y!=fa[x]) {
        dfs(y, x);
        (f[x]*=f[y]+g[y])%=MOD;
        (g[x]*=g[y])%=MOD;
    }
}

void dfs2(int x) {
    VI ys; for(int y: es[x]) if(y!=fa[x]) ys.PB(y);
    int num=(int)ys.size();
    VL lf(num+1), lg(num+1);
    VL rf(num+1), rg(num+1);
    lf[0]=lg[0]=1;
    forn(i, num) {
        lf[i+1]=lf[i]*(f[ys[i]]+g[ys[i]])%MOD;
        lg[i+1]=lg[i]*g[ys[i]]%MOD;
    }
    rf[num]=rg[num]=1;
    forndown(i, num) {
        rf[i]=rf[i+1]*(f[ys[i]]+g[ys[i]])%MOD;
        rg[i]=rg[i+1]*g[ys[i]]%MOD;
    }
    forn(i, num) {
        tf[ys[i]]=(lf[i]*rf[i+1])%MOD;
        tg[ys[i]]=(lg[i]*rg[i+1])%MOD;
        if(fa[x]>0) {
            (tf[ys[i]]*=tf[x]+tg[x])%=MOD;
            (tg[ys[i]]*=tg[x])%=MOD;
        }
    }
    forn(i, num) dfs2(ys[i]);
}

int main() {
    scanf("%d", &n);
    forint(i, 1, n) es[i].clear();
    forint(i, 1, n-1) {
        int a, b; scanf("%d",&b); a=i+1;
        es[a].PB(b), es[b].PB(a);
    }

    dfs(1, 0);
    dfs2(1);
    forint(x, 1, n) {
        LL ans=f[x];
        if(fa[x]>0)
            (ans*=tf[x]+tg[x])%=MOD;
        printf("%d ", (int)ans);
    }
    printf("\n");
    return 0;
}