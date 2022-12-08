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

const int N=100000;

VI es[N];
VPI es2[N];
int n;

void solve() {
    VI belong(n), dfn(n, -1), low(n), color(n);
    VI stack;
    int num=0, counter=0;
    const function<void(int)> dfs=[&](int x) {
        dfn[x]=low[x]=counter++;
        color[x]=-1;
        stack.pb(x);
        for(int y: es[x]) {
            if(color[y]==0) {
                dfs(y);
                setmin(low[x], low[y]);
            } else if(color[y]<0) {
                setmin(low[x], dfn[y]);
            }
        }
        color[x]=1;
        if(low[x]==dfn[x]) {
            while(1) {
                const int y=stack.back(); stack.pop_back();
                belong[y]=num;
                if(y==x) break;
            }
            ++num;
        }
    };
    repn(i, n) if(color[i]==0) dfs(i);
    vector<VI> inside(num);
    repn(i, n) inside[belong[i]].pb(i);
    
    vector<bool> needs(num, true);
    needs[belong[0]]=false;
    repn(i, n) for(int j: es[i]) {
        if(belong[i]!=belong[j]) {
            needs[belong[j]]=false;
        }
    }
    vector<bool> vis(num, false);
    queue<int> que;
    VI ans;
    vis[belong[0]]=true, que.push(belong[0]);
    while(!que.empty()) {
        const int b=que.front(); que.pop();
        for(int i: inside[b]) {
            for(int j: es[i]) if(!vis[belong[j]]) {
                vis[belong[j]]=true;
                que.push(belong[j]);
            }
            for(const auto& e: es2[i]) if(!vis[belong[e.fi]] && needs[belong[e.fi]]) {
                vis[belong[e.fi]]=true;
                que.push(belong[e.fi]);
                ans.pb(e.se);
            }
        }
    }

    if(any_of(all(vis), [](bool b) { return !b; })) {
        cout<<-1<<endl;
    } else {
        cout<<sz(ans)<<endl;
        for (int e: ans) cout<<(e+1)<<" ";
        cout<<endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    int m; cin>>n>>m;
    repn(i, m) {
        int a, b, c; cin>>a>>b>>c;
        --a, --b;
        if(c==0) {
            es[a].pb(b);
        } else {
            es2[a].pb(mp(b, i));
        }
    }
    solve();
    return 0;
}