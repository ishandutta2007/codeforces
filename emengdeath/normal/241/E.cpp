#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int n,m;
vector<pair<int,int>>g[N];
struct node{
    int x,y;
}a[N*5];
int sum[N],dis[N],bz1[N],bz[N];
priority_queue<pair<int,int>>h;
bool spfa(){
    int l=0,r=1;
    for (int i=2;i<=n;i++)dis[i]=-1e9;
    h.push(make_pair(dis[1],1));
    while (!h.empty()){
        pair<int,int>u=h.top();
        h.pop();
        if (dis[u.second]!=u.first)continue;
        for (auto v:g[u.second])
            if (bz[v.first]&&dis[v.first]<u.first+v.second){
                dis[v.first]=u.first+v.second;
                h.push(make_pair(dis[v.first],v.first));
                if ((++sum[v.first])>n*10)return 0;
            }
    }
    return 1;
}
void dfs(int x){
    bz1[x]=1;
    for (auto u:g[x])
        if (u.second>0)
        if (bz1[u.first])bz[x]|=bz[u.first];
        else
           dfs(u.first),bz[x]|=bz[u.first];
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y;
        g[a[i].x].push_back(make_pair(a[i].y,1));
        g[a[i].y].push_back(make_pair(a[i].x,-2));
    }
    bz[n]=1;
    dfs(1);
    if (!spfa()){
        cout<<"No";
        return 0;
    }
    cout<<"Yes"<<endl;
    for (int i=1;i<=m;i++)
        if (!bz[a[i].y]||!bz[a[i].x])cout<<2<<endl;
        else
        cout<<dis[a[i].y]-dis[a[i].x]<<endl;
    return 0;
}