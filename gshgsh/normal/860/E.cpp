#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 500001
int N,rt,f[MAXN],dep[MAXN],siz[MAXN],son[MAXN],top[MAXN],tot,dfn[MAXN];ll c1[MAXN],c2[MAXN],ans[MAXN];vector<int>E[MAXN],id[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void dfs(int u){siz[u]=1;for(auto v:E[u])id[dep[v]=dep[u]+1].push_back(v),dfs(v),siz[u]+=siz[v],siz[v]>siz[son[u]]&&(son[u]=v);}
void dfs(int u,int t){top[u]=t;dfn[u]=++tot;if(!son[u])return;dfs(son[u],t);for(auto v:E[u])if(v!=son[u])dfs(v,v);}
void upd(int l,int r,int v){for(int i=l;i<=N;i+=lowbit(i))c1[i]+=v,c2[i]+=l*v;for(int i=r+1;i<=N;i+=lowbit(i))c1[i]-=v,c2[i]-=(r+1)*v;}
ll ask(int l,int r){ll ans=0;for(int i=r;i;i-=lowbit(i))ans+=(r+1)*c1[i]-c2[i];for(int i=l-1;i;i-=lowbit(i))ans-=l*c1[i]-c2[i];return ans;}
void upd(int u,int v){while(u)upd(dfn[top[u]],dfn[u],1),u=f[top[u]];}
ll ask(int u){ll ans=0;while(u)ans+=ask(dfn[top[u]],dfn[u]),u=f[top[u]];return ans;}
int main()
{
	N=get();For(i,1,N)f[i]=get(),f[i]?E[f[i]].push_back(i),0:rt=i;dfs(rt);dfs(rt,rt);
	For(i,1,N-1){for(auto j:id[i])upd(f[j],1);for(auto j:id[i])ans[j]=ask(f[j]);}For(i,1,N)cout<<ans[i]<<" \n"[i==N];return 0;
}