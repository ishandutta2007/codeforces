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

const int N=500000;
const int M=500000;

struct Uni {
    int fa=-1, add=0, size=1;
    VI sons;
};
int u0[N]; Uni us[N+M];

struct Mil {
    int fa=-1, raid=-1;
};
int m0[N]; Mil ms[N+M];

int find(int i) {
    if(ms[i].fa<0) return i;
    const int j=ms[i].fa;
    ms[i].fa=find(j);
    setmax(ms[i].raid, ms[j].raid);
    return ms[i].fa;
}

VPI qs[N+M];
LL ans[N+M];

int sti[N+M];
LL sts[N+M];
int len;

void dfs(int i) {
    ++len;
    sti[len]=i, sts[len]=sts[len-1]+us[i].add;
    for(const PII& q: qs[i]) {
        const int x=int(lower_bound(sti+1, sti+len+1, q.se, greater<int>())-sti);
        const int y=int(upper_bound(sti+1, sti+len+1, q.fi, greater<int>())-sti);
        ans[q.se]=0;
        if(x<y) ans[q.se]=sts[y-1]-sts[x-1];
    }
    for(const int j: us[i].sons) {
        dfs(j);
    }
    --len;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    repn(i, n) u0[i]=i, m0[i]=i;
    fill(us, us+n+m, Uni());
    fill(ms, ms+n+m, Mil());

    replr(i, n, n+m) {
        char op; int x, y;
        cin>>op>>x; if(op=='U' || op=='M') cin>>y;
        --x, --y;
        if(op=='U') {
            const int a=u0[x], b=u0[y]; u0[x]=i, u0[y]=-1;
            us[i].size=us[a].size+us[b].size;
            us[i].sons.pb(a), us[i].sons.pb(b);
            us[a].fa=us[b].fa=i;
        } else if(op=='M') {
            const int a=m0[x], b=m0[y]; m0[x]=i, m0[y]=-1;
            ms[a].fa=ms[b].fa=i;
        } else if(op=='A') {
            const int a=u0[x]; u0[x]=i;
            us[i].add=us[i].size=us[a].size;
            us[i].sons.pb(a);
            us[a].fa=i;
        } else if(op=='Z') {
            const int a=m0[x];
            setmax(ms[a].raid, i);
        } else if(op=='Q') {
            find(x);
            qs[x].pb(mp(ms[x].raid, i));
        }
    }

    fillchar(ans, 0xff);
    len=0; sts[0]=0;
    repn(i, n) if(u0[i]>=0) {
        dfs(u0[i]);
    }
    repn(i, n+m) if(ans[i]>=0) cout<<ans[i]<<endl;

    return 0;
}