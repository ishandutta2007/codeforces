#include<iostream>
#include<vector>
using namespace std;
int n,m;
int d[300001];
vector<pair<int,int> >adj[300001];
vector<int>c[300001];
int n1=0;
vector<int>one;
int bad[300001];
int cnt[300001];
bool vis[300001];
int par[300001];
void dfs(int id){
    vis[id]=true;
    for(int i=0; i<adj[id].size() ;i++){
        if(vis[adj[id][i].first]) continue;
        int newi=adj[id][i].first;
        par[newi]=adj[id][i].second;
        c[id].push_back(newi);
        dfs(newi);
    }
}
int ans=0;
void cal(int id){
    for(int i=0; i<c[id].size() ;i++){
        cal(c[id][i]);
        cnt[id]+=cnt[c[id][i]];
    }
    if(bad[id]) cnt[id]++;
    if(cnt[id]%2==1) ans++;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=n ;i++){
        cin >> d[i];
        if(d[i]==-1) n1=i;
        if(d[i]==1) one.push_back(i);
    }
    if(n1==0 && one.size()%2!=0){
        cout << -1 << endl;
        return 0;
    }
    if(one.size()%2==1){
        one.push_back(n1);
    }
    for(int i=0; i<one.size() ;i++){
        bad[one[i]]=1;
    }
    int u,v;
    for(int i=1; i<=m ;i++){
        cin >> u >> v;
        adj[u].push_back(make_pair(v,i));
        adj[v].push_back(make_pair(u,i));
    }
    dfs(1);
    cal(1);
    cout << ans << endl;
    for(int i=1; i<=n ;i++){
        if(cnt[i]%2==1){
            cout << par[i] << '\n';
        }
    }
}