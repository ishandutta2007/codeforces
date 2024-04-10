#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u,f) for(int i=fst[u];i;i=nxt[i])if(to[i]!=f)
#define MAXN 200001
int N,D,fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],dep[MAXN],siz[MAXN],son[MAXN],mx[MAXN],pos[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}
void dfs(int u,int f)
{
	mx[u]=dep[u]=dep[f]+1,siz[u]=1;FOR(i,u,f)dfs(to[i],u),siz[u]+=siz[to[i]],mx[u]=max(mx[u],mx[to[i]]);
	FOR(i,u,f)if(mx[to[i]]>=D&&siz[to[i]]>siz[son[u]])son[u]=to[i];
}
void sol()
{
	int u=1;
	while(1)
	{
		if(dep[u]==D){cout<<"d "<<u<<endl;int x;cin>>x;if(!x){cout<<"! "<<u<<endl;return;}u=pos[dep[u]-x/2];cout<<"s "<<u<<endl;cin>>u;if(dep[u]==D){cout<<"! "<<u<<endl;return;}}
		pos[dep[u]]=u;u=son[u];
	}
}
int main(){cin>>N;For(i,1,N-1)add(get(),get());cout<<"d "<<1<<endl;cin>>D;if(!D){cout<<"! "<<1<<endl;return 0;}D++;dfs(1,0);sol();return 0;}