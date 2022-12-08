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

void solve() {
    int n, m; scanf("%d%d", &n,&m);
    vector<vector<bool>> g(n, vector<bool>(n, false));
    VI deg(n);
    repn(i, m) {
        int a, b; scanf("%d%d", &a,&b);
        --a, --b;
        g[a][b]=g[b][a]=true;
        ++deg[a], ++deg[b];
    }

    int cnt=0;
    repn(i, n) if(deg[i]%2==0) ++cnt;
    VPI ans;
    while(1) {
        int start=-1;
        repn(i, n) {
            if(deg[i]>0 && start<0) start=i;
            if(deg[i]%2==1) start=i;
        }
        if(start<0) break;
        for(int x=start; deg[x]>0; ) {
            int y=0; while(!g[x][y]) ++y;
            g[x][y]=g[y][x]=false;
            --deg[x], --deg[y];
            ans.pb(mp(x, y));
            x=y;
        }
    }
    printf("%d\n", cnt);
    for(const auto& p: ans) printf("%d %d\n", p.fi+1,p.se+1);
}

int main() {
    int t; scanf("%d", &t);
    while(t--) solve();
    return 0;
}