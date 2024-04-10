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
typedef pair<LL,int> PLI;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<PLI> VPLI;
typedef vector<string> VS;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=1000;
const int M=10000;

VPI es[N];
int ea[M], eb[M];
LL ec[M]; bool todo[M];
int n, m, s, t;

pair<LL, VI> dijkstra() {
    VL dis(n, 1LL<<55);
    VI pre(n, -1), prei(n, -1);
    vector<bool> vis(n, false);
    dis[s]=0;
    priority_queue<PLI, VPLI, greater<PLI>> que;
    repn(i, n) que.push(mp(dis[i], i));
    while(!que.empty()) {
        int x=que.top().se; que.pop();
        if(vis[x]) continue;
        vis[x]=true;
        for(const PII& e: es[x]) {
            int y=e.fi, i=e.se;
            if(setmin(dis[y], dis[x]+ec[i])) {
                pre[y]=x, prei[y]=i;
                que.push(mp(dis[y], y));
            }
        }
    }
    VI path;
    for(int x=t; prei[x]>=0; x=pre[x]) {
        path.pb(prei[x]);
    }
    return mp(dis[t], path);
}

bool solve(LL target) {
    repn(i, m) if(todo[i]) ec[i]=1<<30;
    if(dijkstra().fi<target) return false;

    repn(i, m) if(todo[i]) ec[i]=1;
    while(1) {
        auto r=dijkstra();
        if(r.fi>target) return false;
        if(r.fi==target) return true;

        for(int i: r.se) if(todo[i]) {
            ec[i]=target-r.fi+1;
            break;
        }
    }
}

int main() {
    int target;
    scanf("%d%d%d%d%d", &n,&m,&target,&s,&t);
    repn(i, m) {
        int c; scanf("%d%d%d", &ea[i],&eb[i],&c);
        ec[i]=c;
        todo[i]=(ec[i]==0);
        es[ea[i]].pb(mp(eb[i], i));
        es[eb[i]].pb(mp(ea[i], i));
    }
    if(solve(target)) {
        printf("YES\n");
        repn(i, m) printf("%d %d %lld\n",ea[i],eb[i],ec[i]);
    } else {
        printf("NO\n");
    }
    return 0;
}