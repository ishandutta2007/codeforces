#include <bits/stdc++.h>

#define ll          long long
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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
vi tree[300005]; // The bridge edge tree formed from the given graph
vi graph[300005];
int U[300005],V[300005];  //edge list representation of the graph. 
bool isbridge[300005]; // if i'th edge is a bridge edge or not 
int visited[300005];int arr[300005],T; //supporting arrays
int cmpno;
queue<int> Q[300005];
 
int adj(int u,int e){
    return U[e]==u?V[e]:U[e];
}
int dfs0(int u,int edge)    //marks all the bridges
{
    visited[u]=1;
    arr[u]=T++;
    int dbe = arr[u];
    for(int i=0;i<(int)graph[u].size();i++)
    {
        int e = graph[u][i];
        int w = adj(u,e);
        if(!visited[w])
            dbe = min(dbe,dfs0(w,e));
        else if(e!=edge)
            dbe = min(dbe,arr[w]);
    }
    if(dbe == arr[u] && edge!=-1)
        isbridge[edge]=true;
    return dbe;
}
 
void dfs1(int v)
{
    int currcmp = cmpno;
    Q[currcmp].push(v);
    visited[v]=1;
    while(!Q[currcmp].empty())    //bfs. Exploring all nodes of this  component
    {
        int u = Q[currcmp].front();    
        Q[currcmp].pop();    
        for(int i=0;i<(int)graph[u].size();i++)
        {
            int e = graph[u][i];
            int w = adj(u,e);
            if(visited[w])continue;
            if(isbridge[e])
            {
                cmpno++;
                tree[currcmp].push_back(cmpno);
                tree[cmpno].push_back(currcmp);
                dfs1(w);
            }
            else     //else continue with our bfs
            {
                Q[currcmp].push(w);
                visited[w]=1;
            }
        }
    }
}
int n,m,vis[300005];
int bfs(int node){
    int ans=node;
    queue<int> q;
    memset(vis,0,sizeof vis);
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
        auto d=q.front();
        q.pop();
        for(auto i:tree[d]){
            if(!vis[i]){
                q.push(i);
                vis[i]=vis[d]+1;
                ans=i;
            }
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        cin>>U[i]>>V[i];
        graph[U[i]].pb(i);
        graph[V[i]].pb(i);
    }
    dfs0(1,-1);
    memset(visited,0,sizeof visited);
    dfs1(1);
    int d=bfs(0);
    d=bfs(d);
    cout<<vis[d]-1<<endl;
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