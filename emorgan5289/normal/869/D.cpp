#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

const int MAXN=255;

const int Mod=1000000007;
inline void add_mod(int &x,int y)
{
    x=(x+y<Mod ? x+y : x+y-Mod);
}

int u[MAXN],v[MAXN];

map<int,int> mp;
inline int get_id(int x)
{
    if(!mp[x])mp[x]=(int)mp.size();
    return mp[x];
}

vector<int> e[MAXN];
void add_edge(int u,int v)
{
    e[u].push_back(v);
    e[v].push_back(u);
}

inline int cal_size(int u,int n,int d)
{
    int t=u,c=0,res;
    while(t)c++,t>>=1;
    res=(1<<(d-c+1))-1,t=c;
    while(t<d)t++,u=u<<1|1;
    return res-max(min(u-n,1<<(d-c)),0);
}

int num[MAXN];
void pre_dp(int u,int f)
{
    for(auto &v:e[u])
    {
        if(v==f)continue;
        num[u]-=num[v];
        pre_dp(v,u);
    }
}

int vis[MAXN];
void dfs(int u,int &tot)
{
    add_mod(tot,num[u]);
    vis[u]=1;
    for(auto &v:e[u])
        if(!vis[v])dfs(v,tot);
    vis[u]=0;
}

int main()
{
    int n,m,d=0;
    scanf("%d%d",&n,&m);
    while((1<<d)<=n)d++;
    get_id(1);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        int t=u[i];
        while(t)get_id(t),t>>=1;
        t=v[i];
        while(t)get_id(t),t>>=1;
    }
    for(auto &t:mp)
    {
        int u=t.first,id=t.second;
        if(u>1)add_edge(get_id(u),get_id(u>>1));
        num[id]=cal_size(u,n,d);
    }
    pre_dp(1,0);
    for(int i=0;i<m;i++)
        add_edge(get_id(u[i]),get_id(v[i]));
    int res=0;
    for(int i=1;i<=(int)mp.size();i++)
    {
        int tot=0;
        dfs(i,tot);
        add_mod(res,1LL*tot*num[i]%Mod);
    }
    printf("%d\n",res);
    return 0;
}