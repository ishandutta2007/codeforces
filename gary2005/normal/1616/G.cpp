/**
 *    author:  gary
 *    created: 13.01.2022 22:00:18
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
const int MAXN=150000+1;
int n,m;
bool ok[MAXN];
int tor[MAXN];
vector<int> g[MAXN];
vector<int> rg[MAXN];
bool vis[MAXN][2];
void dfs1(int now,bool p=0){
    vis[now][p]=1;
    for(auto it:rg[now]) if(!vis[it][p^1]) dfs1(it,p^1);
}
void dfs2(int now,bool p=0){
    vis[now][p]=1;
    for(auto it:g[now]) if(!vis[it][p^1]) dfs2(it,p^1);
}
void solve(){
    cin>>n>>m;
    rb(i,1,n) ok[i]=0,vis[i][0]=vis[i][1]=false;
    rb(i,1,n) g[i].clear(),rg[i].clear();
    vector<mp> edge;
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        if(u==v-1) ok[u]=1;
        else edge.PB(II(u,v));
    }
    rl(i,n,1){
        if(ok[i]) tor[i]=tor[i+1];
        else tor[i]=i;
    }
    int L,R;
    L=tor[1];
    rl(i,n,1) if(tor[i]==n) R=i-1;
    if(L==n){
        cout<<1ll*n*(n-1)/2<<endl;
        return ;
    }
    for(auto it:edge){
        int u,v;
        tie(u,v)=it;
        if(tor[u+1]>=v-1);
        else continue;
        g[u].PB(v-1),rg[v-1].PB(u);
    }
    dfs1(L);
    dfs2(L);
    int cnt[2][2];
    memset(cnt,0,sizeof(cnt));
    int cntl,cntr;
    cntl=cntr=0;
    rb(i,1,n){
        if(i<=L) cnt[0][0]+=vis[i][0],cnt[0][1]+=vis[i][1],cntl+=vis[i][0]&&vis[i][1];
        if(i>=R) cnt[1][0]+=vis[i][0],cnt[1][1]+=vis[i][1],cntr+=vis[i][0]&&vis[i][1];
    }
    LL answer=0;
    answer+=1ll*cnt[0][0]*cnt[1][0];
    answer+=1ll*cnt[0][1]*cnt[1][1];
    answer+=(1ll*cnt[0][0]*cnt[1][0])||(1ll*cnt[0][1]*cnt[1][1]);
    rb(i,1,L) answer+=(vis[i][0]&&cnt[1][1])||(vis[i][1]&&cnt[1][0]);
    rb(i,R,n) answer+=(vis[i][0]&&cnt[0][1])||(vis[i][1]&&cnt[0][0]);
    cout<<answer-(L==R)-1ll*cntl*cntr<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}