/**
 *    author:  gary
 *    created: 06.05.2022 23:32:25
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
const int MAXN=1<<17;
int p,n;
int ans[MAXN+1],ansedge[MAXN+1];
vector<mp> g[MAXN+1];
int cnt=0;
void dfs(int now,int pre){
    for(auto it:g[now]) if(it.first!=pre){
        dfs(it.first,now);
        ++cnt;
        ans[it.first]=cnt+(n);
        ansedge[it.second]=cnt;
    }
}
void dfs2(int now,int pre,int col){
    for(auto it:g[now]) if(it.first!=pre){
        dfs2(it.first,now,col^1);
        if(col==0) swap(ans[it.first],ansedge[it.second]);
    }
}
void solve(){
    cnt=0;
    cin>>p;
    n=1<<p;
    rb(i,1,n) g[i].clear();
    rb(i,1,n-1){
        int u,v;
        cin>>u>>v;
        g[u].PB(II(v,i));
        g[v].PB(II(u,i));
    }
    dfs(1,0);
    dfs2(1,0,0);
    ans[1]=n;
    cout<<1<<endl;
    rb(i,1,n) cout<<ans[i]<<" ";
    cout<<endl;
    rb(i,1,n-1) cout<<ansedge[i]<<" ";
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}