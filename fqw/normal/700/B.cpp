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

const int N=200020;

VI es[N];
bool is[N];
int n, k;
LL ans;

PII dfs(int x, int fa) {
    int size=0, out=0;
    if(is[x]) ++size, ++out;
    for(int y: es[x]) if(y!=fa) {
        PII p=dfs(y, x);
        size+=p.fi;
        out+=p.se;
        ans+=p.se;
    }
    setmin(out, k*2-size);
    return mp(size, out);
}

int main() {
    scanf("%d%d", &n,&k);
    fillchar(is, false);
    repn(i, k*2) {
        int x; scanf("%d", &x);
        is[x]=true;
    }
    repn(i, n-1) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b), es[b].pb(a);
    }
    ans=0;
    dfs(1, 0);
    cout<<ans<<endl;


    return 0;
}