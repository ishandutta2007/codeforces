#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > g[1000005], rg[1000005], gg[1000005], rgg[1000005];
pair<int,pair<int,int> > edge[1000005];
int vis[1000005], cc[1000005], cn = 0, st;
long long int val[1000005], dp[1000005];
stack<int> myS;

void dfs(int v){
    if(vis[v] == 1)return;
    vis[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        dfs(g[v][i].first);
    }
    myS.push(v);
}

void dfs2(int v){
    if(vis[v] == 0)return;
    vis[v] = 0;
    cc[v] = cn;
    for(int i = 0; i < rg[v].size(); i++){
        dfs2(rg[v][i].first);
    }
}

void addVal(int cmp, long long int v){
    long long int sv = sqrt(2*v);
    sv--;
    while(sv*(sv+1) <= 2*v)sv++;
    sv--;
    long long int tmp = v*(sv + 1) - sv*(sv+1)*(sv+2)/6;
    val[cmp] += tmp;
}

long long int dfs3(int v){
    if(dp[v] != -1)return dp[v];
    if(v == st)return dp[v] = val[v];
    long long int ret = val[v];
    int ttmp = 0;
    for(int i = 0; i < rgg[v].size(); i++){
        pair<int,int> x = rgg[v][i];
        long long int tmp = dfs3(x.first);
        if(tmp != -10)ttmp = 1;
        if(tmp >= 0)ret = max(ret, val[v] + tmp + x.second);
    }
    if(ttmp == 0){
        return dp[v] = -10;
    }
    if(rgg[v].size() == 0){
        return dp[v] = -10;
    }
    return dp[v] = ret;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w));
        rg[v].push_back(make_pair(u,w));
        edge[i] = make_pair(w, make_pair(u,v));
    }
    cin>>st;
    memset(vis,0,sizeof(vis));
    memset(val,0,sizeof(val));
    memset(dp,-1,sizeof(dp));
    for(int i = 1; i <= n; i++){
        dfs(i);
    }
    while(!myS.empty()){
        v = myS.top();
        myS.pop();
        if(vis[v] == 1){
            dfs2(v);
            cn++;
        }
    }
    for(int i = 0; i < m; i++){
        w = edge[i].first, u = edge[i].second.first, v = edge[i].second.second;
        if(cc[u] == cc[v]){
            addVal(cc[u], w);
        }else{
            gg[cc[u]].push_back(make_pair(cc[v],w));
            rgg[cc[v]].push_back(make_pair(cc[u],w));
        }
    }
    st = cc[st];
    for(int i = 0; i < cn; i++){
        if(gg[i].size() == 0){
            dfs3(i);
        }
    }
    long long int maxi = 0;
    for(int i = 0; i < cn; i++){
        maxi = max(maxi, dp[i]);
    }
    cout<<maxi<<endl;
}