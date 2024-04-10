#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long   
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=2e5+10;
int low[N],dfn[N],tim,inq[N],q[N],top,id[N],up[N],dow[N],Fa[N][21],cnt=1,poi[N*2],nxt[N*2],head[N],num,dep[N];
int n,m,x[N],y[N],Q;
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void Tar(int x,int fa)
{
	low[x]=dfn[x]=++tim;inq[x]=1;q[++top]=x;
	for(int i=head[x];i;i=nxt[i])
	{
		if((i^1)==fa)	continue;
		if(!dfn[poi[i]])	Tar(poi[i],i),low[x]=min(low[x],low[poi[i]]);
		else	if(inq[poi[i]])	low[x]=min(low[x],low[poi[i]]);
	}
	if(low[x]==dfn[x])
	{
		++num;
		for(;;)
		{
			id[q[top]]=num;top--;
			if(q[top+1]==x)	break;
		}
	}
}
map<int,int> mp[N];
inline void Dfs(int x,int fa)
{
	Fa[x][0]=fa;dfn[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;
		dep[poi[i]]=dep[x]+1;
		Dfs(poi[i],x);
	}
}
inline void Dfs1(int x,int fa)
{
	dfn[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;//cout<<x<<' '<<poi[i]<<endl;
		Dfs1(poi[i],x);
		up[x]+=up[poi[i]];dow[x]+=dow[poi[i]];
	}
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])	swap(x,y);
	int dis=dep[x]-dep[y];
	For(i,0,20)	if(dis>>i&1)	x=Fa[x][i];
	if(x==y)	return x;
	Dow(i,0,20)	if(Fa[x][i]!=Fa[y][i])	x=Fa[x][i],y=Fa[y][i];
	return Fa[x][0];
}
int main()
{
	n=read();m=read();Q=read();
	For(i,1,m)	x[i]=read(),y[i]=read(),add(x[i],y[i]),add(y[i],x[i]);
	For(i,1,n)	if(!dfn[i])	Tar(i,0);
	For(i,1,n)	head[i]=0;cnt=0;
	For(i,1,m)	if(id[x[i]]!=id[y[i]])
	{
		if(!mp[id[x[i]]][id[y[i]]])	
		{
			mp[id[x[i]]][id[y[i]]]=mp[id[y[i]]][id[x[i]]]=1;
			add(id[x[i]],id[y[i]]);add(id[y[i]],id[x[i]]);
		}
	}  
	memset(dfn,0,sizeof dfn);
	n=num;
	For(i,1,n)	if(!dfn[i])	Dfs(i,i);
	For(j,1,20)	For(i,1,num)	Fa[i][j]=Fa[Fa[i][j-1]][j-1];
	For(i,1,Q)
	{
		int x=read(),y=read();
		x=id[x];y=id[y];
		int lca=LCA(x,y);
		if(x==y)	continue;
		up[x]++;up[lca]--;dow[y]++;dow[lca]--;
//		cout<<x<<' '<<y<<endl;
	}
	memset(dfn,0,sizeof dfn);
	For(i,1,n)	if(!dfn[i])Dfs1(i,i);
	For(i,1,n)	if(up[i]>0&&dow[i]>0)
	{
		puts("No");return 0;
	}
	puts("Yes");
}