#include<iostream>
#include<vector>
using namespace std;
int n,m,p,q,a,b;
bool r;
int depth[300001];//done
int low[300001];
int cd[300001];//done
int par[300001];//done
bool is[300001];//node done
bool hv[300001];//bcc done
int bcc[300001];//node done
bool vis[300001];//node done
vector<int>edge[300001];//done
vector<bool>art[300001];//done
void dfs(int id){
    low[id]=depth[id];
    vis[id]=true;
    for(int i=0; i<edge[id].size() ;i++){
        int cur=edge[id][i];
        if(cur==par[id]) continue;
        if(vis[cur]){
            low[id]=min(low[id],depth[cur]);
        }
        else{
            depth[cur]=depth[id]+1;
            par[cur]=id;
            is[cur]=art[id][i];
            dfs(cur);
            low[id]=min(low[id],low[cur]);
        }
    }
}
void dfs2(int id){
    vis[id]=false;
    if(low[id]<depth[id]){
        bcc[id]=bcc[par[id]];
        hv[bcc[id]]|=is[id];
    }
    else{
        bcc[id]=id;
        cd[bcc[id]]=cd[bcc[par[id]]]+1;
    }
    for(int i=0; i<edge[id].size() ;i++){
        int cur=edge[id][i];
        if(cur==par[id]) continue;
        if(!vis[cur]) hv[bcc[id]]|=art[id][i];
        else{
            dfs2(cur);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    low[1]=0;
    for(int i=1; i<=m ;i++){
        cin >> p >> q >> r;
        edge[p].push_back(q);
        art[p].push_back(r);
        edge[q].push_back(p);
        art[q].push_back(r);
    }
    cin >> a >> b;
    dfs(1);
    dfs2(1);
    bool ans=false;
    int x=bcc[a],y=bcc[b];
    if(cd[x]<cd[y]) swap(x,y);
    while(cd[x]>cd[y]){
        ans|=hv[x]|is[x];
        x=bcc[par[x]];
    }
    while(x!=y){
        ans|=hv[x]|is[x]|hv[y]|is[y];
        x=bcc[par[x]];
        y=bcc[par[y]];
    }
    ans|=hv[x];
    if(ans) cout << "YES\n";
    else cout << "NO\n";
}