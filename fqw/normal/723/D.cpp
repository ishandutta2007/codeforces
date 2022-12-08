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

int main() {
    int n, m, k; cin>>n>>m>>k;
    VS g(n); repn(i, n) cin>>g[i];

    const function<void(int, int, VPI*)> dfs=[&](int x, int y, VPI* lake) {
        if(x<0 || x>=n || y<0 || y>=m || g[x][y]!='.') {
            return;
        }
        g[x][y]='*';
        lake->pb(mp(x, y));
        const int dx[4]={-1, 0, 1, 0};
        const int dy[4]={0, 1, 0, -1};
        repn(i, 4) dfs(x+dx[i], y+dy[i], lake);
    };
    vector<VPI> lakes;
    repn(i, n) repn(j, m) if(g[i][j]=='.') {
        VPI tmp;
        dfs(i, j, &tmp);
        bool is_lake=true;
        for(const auto& p: tmp) {
            if(p.fi==0 || p.fi==n-1 || p.se==0 || p.se==m-1) {
                is_lake=false;
            }
        }
        if(is_lake) {
            lakes.pb(tmp);
        } else {
            for(const auto& p: tmp) {
                g[p.fi][p.se]='.';
            }
        }
    }
    sort(all(lakes), [](const VPI& a, const VPI& b) { return sz(a)>sz(b); });
    int cnt=0;
    replr(i, k, sz(lakes)) cnt+=sz(lakes[i]);
    lakes.resize(k);
    for(const auto& lake: lakes) {
        for(const auto& p: lake) {
            g[p.fi][p.se]='.';
        }
    }
    cout<<cnt<<endl;
    repn(i, n) cout<<g[i]<<endl;

    return 0;
}