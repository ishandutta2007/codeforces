#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,c,to[N];
bool vis[N],isleaf[N];
vector<int> g[N];
struct st{int x,y,z;};
vector<st> v;
struct disj
{
    int p[N];
    disj(){for(int i=1;i<=200000;i++) p[i]=i;}
    int fi(int x){
        if(p[x]==x) return x;
        return p[x]=fi(p[x]);
    }
    void un(int x,int y){
        x=fi(x); y=fi(y);
        if(x==y) return;
        p[y]=x;
    }
}dsu;
int dfs(int x,int par)
{
    vis[x]=true;
    int st=0;
    vector<int> pre;
    for(auto &it : g[x]){
        if(it==par) continue;
        int y=dfs(it,x);
        st++;
        if(isleaf[it]||!y) pre.push_back(it);
        else v.push_back({y,it,x});
    }
    for(int i=0;i+1<pre.size();i+=2) v.push_back({pre[i],x,pre[i+1]});
    if(pre.size()%2) return pre.back();
    if(!st) isleaf[x]=true;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    c=n;
    for(int i=1;i<=n;i++) to[i]=i;
    for(int u,v,i=1;i<=m;i++){
        cin>>u>>v;
        if(dsu.fi(u)!=dsu.fi(v)){
            g[u].push_back(v);
            g[v].push_back(u);
            dsu.un(u,v);
        }
        else{
            c++;
            g[v].push_back(c);
            g[c].push_back(v);
            to[c]=u;
        }
    }
    for(int i=1;i<=c;i++)
        if(!vis[i]) dfs(i,0);
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
        cout<<to[v[i].x]<<" "<<to[v[i].y]<<" "<<to[v[i].z]<<"\n";
    return 0;
}