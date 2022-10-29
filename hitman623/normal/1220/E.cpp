#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define N           200005
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
vi tree[N],graph[N];
int U[N],V[N];
bool isbridge[N]; 
int visited[N],arr[N],T,cmpno;
int n,m,val[N],s,sum[N],id[N],cnt[N];
queue<int> Q[N];
int adj(int u,int e){
    return U[e]==u?V[e]:U[e];
}
int dfs0(int u,int edge){
    visited[u]=1;
    arr[u]=T++;
    int dbe=arr[u];
    rep(i,0,sz(graph[u])){
        int e=graph[u][i];
        int w=adj(u,e);
        if(!visited[w]) dbe=min(dbe,dfs0(w,e));
        else if(e!=edge) dbe=min(dbe,arr[w]);
    }
    if(dbe==arr[u] && edge!=-1) isbridge[edge]=true;
    return dbe;
}
void dfs1(int v){
    int currcmp=cmpno;
    Q[currcmp].push(v);
    id[v]=currcmp;
    sum[currcmp]+=val[v];
    cnt[currcmp]++;
    visited[v]=1;
    while(!Q[currcmp].empty()){
        int u=Q[currcmp].front();    
        Q[currcmp].pop();    
        rep(i,0,sz(graph[u])){
            int e=graph[u][i];
            int w=adj(u,e);
            if(visited[w])continue;
            if(isbridge[e]){
                cmpno++;
                tree[currcmp].push_back(cmpno);
                tree[cmpno].push_back(currcmp);
                dfs1(w);
            }
            else{
                Q[currcmp].push(w);
                visited[w]=1;
                id[w]=currcmp;
                sum[currcmp]+=val[w];
                cnt[currcmp]++;
            }
        }
    }
}
int dp[N][2];
bool canreturn[200005];
void dfs2(int node,int par){
    dp[node][1]=sum[node];
    canreturn[node]=cnt[node]!=1;
    for(auto i:tree[node]){
        if(i!=par){
            dfs2(i,node);
            canreturn[node]|=canreturn[i];
            dp[node][1]+=dp[i][1];
            dp[node][0]=max(dp[node][0],dp[i][0]-dp[i][1]);
        }
    }
    dp[node][0]+=dp[node][1];
    if(canreturn[node]==0) dp[node][1]=0;
}
void solve(){
    cin>>n>>m;
    rep(i,1,n+1) cin>>val[i];
    rep(i,0,m){
        cin>>U[i]>>V[i];
        graph[U[i]].pb(i);
        graph[V[i]].pb(i);
    }
    cin>>s;
    dfs0(s,-1);
    memset(visited,0,sizeof visited);
    dfs1(s);
    dfs2(id[s],id[s]);
    cout<<dp[id[s]][0]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}