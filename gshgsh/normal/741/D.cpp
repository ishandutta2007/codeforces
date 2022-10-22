#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffff
#define MAXN 500001
int N,dis[MAXN],dep[MAXN],siz[MAXN],son[MAXN],ans[MAXN],mx[1<<22];vector<pair<int,int>>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c<'a'||c>'z')c=getchar();return c-'a';}
void dfs0(int u){siz[u]=1;for(auto v:E[u])dep[v.first]=dep[u]+1,dis[v.first]=dis[u]^v.second,dfs0(v.first),siz[u]+=siz[v.first],siz[v.first]>siz[son[u]]&&(son[u]=v.first);}
void clear(int u){mx[dis[u]]=-INF;for(auto v:E[u])clear(v.first);}
void upd(int u,int id){ans[id]=max(ans[id],dep[u]+mx[dis[u]]);For(i,0,21)ans[id]=max(ans[id],dep[u]+mx[dis[u]^(1<<i)]);for(auto v:E[u])upd(v.first,id);}
void mrg(int u){mx[dis[u]]=max(mx[dis[u]],dep[u]);for(auto v:E[u])mrg(v.first);}
void dfs(int u)
{
	for(auto v:E[u])if(v.first!=son[u])dfs(v.first),clear(v.first);
	if(son[u])dfs(son[u]);for(auto v:E[u])if(v.first!=son[u])upd(v.first,u),mrg(v.first);mx[dis[u]]=max(mx[dis[u]],dep[u]);
	ans[u]=max(ans[u],dep[u]+mx[dis[u]]);For(i,0,21)ans[u]=max(ans[u],dep[u]+mx[dis[u]^(1<<i)]);ans[u]-=dep[u]<<1;for(auto v:E[u])ans[u]=max(ans[u],ans[v.first]);

}
int main(){N=get();For(i,0,(1<<22)-1)mx[i]=-INF;For(i,2,N){int f=get(),w=1<<getc();E[f].push_back({i,w});}dfs0(1);dfs(1);For(i,1,N)cout<<ans[i]<<" \n"[i==N];return 0;}