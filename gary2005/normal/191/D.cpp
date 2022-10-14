/**
 *    author:  gary
 *    created: 09.06.2022 18:51:52
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e5+20;
int n,m,fa[MAXN];
bool vis[MAXN];
int dep[MAXN];
vector<int> g[MAXN];
vector<vector<int> > cycs;
void dfs(int now,int pre){
    bool ok=0;
    vis[now]=1;
    fa[now]=pre;
    for(auto it:g[now]){
        if(!ok&&it==pre){ok=1;continue;}
        if(vis[it]){
            if(dep[it]<dep[now]){
            int z=now;
            vector<int> tmp;
            while (true){
                tmp.PB(z);
                if(z==it) break;
                z=fa[z];
            }
            cycs.PB(tmp);
            }
        }
        else{
            dep[it]=dep[now]+1;
            dfs(it,now);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0);
    int ans=0;
    rb(i,1,n) ans+=g[i].size()&1;
    ans/=2;
    if(cycs.size()&&cycs[0].size()==n){
        cout<<1<<' '<<m<<endl;
        return 0;
    }
    for(auto it:cycs) {
        int t=0;
        for(auto it2:it)
        t+=g[it2].size()!=2;
        if(t==1) ans++;
    }
    cout<<ans<<' '<<m<<endl;
    return 0;
}