#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
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
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=400040;

VI es[N];
int n, size[N], m[N];
bool ans[N];

void dfs(int x, int fa) {
    size[x]=1;
    for(int y: es[x]) if(y!=fa) {
        dfs(y, x);
        size[x]+=size[y];
    }
}

void dfs_up(int x, int fa) {
    m[x]=0;
    int mx=0;
    for(int y: es[x]) if(y!=fa) {
        dfs_up(y, x);
        if(m[y]>0) {
            m[x]=m[y];
            if(size[y]-m[y]>n/2) ans[x]=false;
        }
        setmax(mx, size[y]);
    }
    if(m[x]==0 && size[x]>n/2) m[x]=mx;
}

void dfs_down(int x, int fa, int m_fa) {
    if(n-size[x]-m_fa>n/2) ans[x]=false;

    if(m_fa>0) {
        for(int y: es[x]) if(y!=fa) dfs_down(y, x, m_fa);
        return;
    }

    int y0=0;
    for(int y: es[x]) if(y!=fa) if(m[y]>0) y0=y;
    if(y0>0) {
        for(int y: es[x]) if(y!=fa) {
            if(y==y0) dfs_down(y, x, 0);
                else dfs_down(y, x, m[y0]);
        }
        return;
    }

    PII y1=mp(n-size[x],0), y2=mp(0,0);
    for(int y: es[x]) if(y!=fa) {
        setmax(y2, mp(size[y], y));
        if(y2>y1) swap(y2, y1);
    }
    for(int y: es[x]) if(y!=fa) {
        if(n-size[y]>n/2) {
            dfs_down(y, x, (y!=y1.se?y1.fi:y2.fi));
        } else {
            dfs_down(y, x, 0);
        }
    }
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n-1) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b), es[b].pb(a);
    }
    dfs(1, 0);

    fillchar(ans, true);
    dfs_up(1, 0);
    dfs_down(1, 0, 0);
    rep(i, 1, n) printf("%d ", ans[i]);
    return 0;
}