#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int n;
vector<int>adj[100001];
vector<int>chi[100001];
bool vis[100001];
int dis[100001];
long double val[100001];
int cnt[100001];
void dfs(int id){
    vis[id]=true;
    for(int i=0; i<adj[id].size() ;i++){
        if(vis[adj[id][i]]) continue;
        dis[adj[id][i]]=dis[id]+1;
        chi[id].push_back(adj[id][i]);
        dfs(adj[id][i]);
    }
}
void cal(int id){
    for(int i=0; i<chi[id].size() ;i++){
        cal(chi[id][i]);
        val[id]+=val[chi[id][i]];
    }
    if(chi[id].empty()){
        val[id]=dis[id];
    }
    else{
        val[id]/=chi[id].size();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    if(n==1){
        cout << "0.0" << endl;
        return 0;
    }
    int u,v;
    for(int i=2; i<=n ;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cal(1);
    cout << fixed << setprecision(10) << val[1] << endl;
}