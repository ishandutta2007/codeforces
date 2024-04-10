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

const int N=300030;

int size[N], maxsub[N], father[N];
VI es[N];
int n;

void init(int x, int fa) {
    maxsub[x]=0, size[x]=1;
    father[x]=fa;
    for(int y: es[x]) if(y!=fa) {
        init(y, x);
        size[x]+=size[y];
        setmax(maxsub[x], size[y]);
    }
}

int ans[N];

int cost(int x, int y) {
    return max(maxsub[y], size[x]-size[y]);
}

void dfs(int x, int fa) {
    ans[x]=x;
    for(int y: es[x]) if(y!=fa) {
        dfs(y, x);
        int z=ans[y];
        while(z!=x && cost(x, father[z])<=cost(x, z)) {
            z=father[z];
        }
        if(cost(x, z)<cost(x, ans[x])) {
            ans[x]=z;
        }
    }
}

int main() {
    int q; scanf("%d%d", &n,&q);
    rep(i, 2, n) {
        int j; scanf("%d", &j);
        es[i].pb(j), es[j].pb(i);
    }
    init(1, 0);
    dfs(1, 0);
    while(q--) {
        int x; scanf("%d", &x);
        printf("%d\n", ans[x]);
    }

    return 0;
}