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

VI es[N];
int n;

int color[N];
bool dfs(int x, int c) {
    if(color[x]>=0) return color[x]==c;
    color[x]=c;
    for(int y: es[x]) if(!dfs(y, c^1)) return false;
    return true;
}

int main() {
    int m; scanf("%d%d", &n,&m);
    rep(i, 1, m) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b), es[b].pb(a);
    }
    fillchar(color, 0xff);
    rep(i, 1, n) if(color[i]<0) {
        if(!dfs(i, 0)) { printf("-1\n"); return 0; }
    }
    rep(c, 0, 1) {
        int k=0;
        rep(i, 1, n) if(color[i]==c) ++k;
        printf("%d\n", k);
        rep(i, 1, n) if(color[i]==c) printf("%d ", i);
        printf("\n");
    }
    return 0;
}