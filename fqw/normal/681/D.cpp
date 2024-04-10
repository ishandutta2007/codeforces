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
int deg[N], a[N];
int n;
VI ans;

int dfs(int x) {
    int cur=0;
    for(int y: es[x]) {
        int tmp=dfs(y);
        if(tmp<0) return -1;
        if(tmp>0) {
            if(cur>0 && cur!=tmp) return -1;
            cur=tmp;
        }
    }
    if(cur>0 && cur!=a[x]) return -1;
    cur=a[x];
    if(cur==x) {
        ans.pb(cur); cur=0;
    }
    return cur;
}

int main() {
    int m; scanf("%d%d", &n,&m);
    fillchar(deg, 0);
    repn(i, m) {
        int x, y; scanf("%d%d", &x,&y);
        deg[y]++; es[x].pb(y);
    }
    rep(i, 1, n) scanf("%d", &a[i]);

    ans.clear();
    bool ok=true;
    rep(x, 1, n) if(deg[x]==0) {
        if(dfs(x)<0) ok=false;
    }
    if(ok) {
        printf("%d\n", sz(ans));
        for(int x: ans) printf("%d\n", x);
    } else {
        printf("-1\n");
    }
    return 0;
}