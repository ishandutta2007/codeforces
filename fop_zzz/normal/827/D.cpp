#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,dp=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-48,c=getchar();
	return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=2e5+5;
int dep[N],to[N];
int poi[N*2],nxt[N*2],head[N],cnt=1,Fa[N][21],tree[N],F[N],mx[N][21],mi[N][21],ans[N],v[N*2],id[N*2],m,n;
struct node{int x,y,z,num;}	e[N];
inline bool cmp(node x,node y){return x.z<y.z;}
inline int Get(int x){return x==F[x]?x:F[x]=Get(F[x]);}
inline void add(int x,int y,int z,int num)
{
	poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;v[cnt]=z;id[cnt]=num;
	poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;v[cnt]=z;id[cnt]=num;
}
inline void Kruskal()
{
	sort(e+1,e+m+1,cmp);
	For(i,1,n)	F[i]=i;
	For(i,1,m)
	{
		int tx=Get(e[i].x),ty=Get(e[i].y);
		if(tx==ty)	continue;
		tree[e[i].num]=1;
		F[tx]=ty;
	}
}
inline void Dfs(int x,int fa)
{
	Fa[x][0]=fa;
	for(int i=head[x];i;i=nxt[i])	
		if(poi[i]!=fa)	dep[poi[i]]=dep[x]+1,to[poi[i]]=id[i],mx[poi[i]][0]=v[i],Dfs(poi[i],x);
}
inline void Jump(int &x,int i,int &ret,int z)
{
	ret=max(ret,mx[x][i]),mi[x][i]=min(mi[x][i],z);
	x=Fa[x][i];
}
inline void Solve(int x,int y,int z,int num)
{
	if(dep[x]<dep[y])	swap(x,y);
	int del=dep[x]-dep[y],ret=0;
	For(i,0,20)	if(del>>i&1)	Jump(x,i,ret,z);
	if(x==y)	{ans[num]=ret-1;return;}
	Dow(i,0,20)	if(Fa[x][i]!=Fa[y][i])
		Jump(x,i,ret,z),Jump(y,i,ret,z);
	Jump(x,0,ret,z);Jump(y,0,ret,z);
	ans[num]=ret-1;
}
inline void Down()
{
	Dow(j,1,20)
		For(i,1,n)
		{
			mi[i][j-1]=min(mi[i][j-1],mi[i][j]);
			mi[Fa[i][j-1]][j-1]=min(mi[Fa[i][j-1]][j-1],mi[i][j]);
		}
}
int main()
{
	n=read();m=read();
	For(i,1,m)	e[i].x=read(),e[i].y=read(),e[i].z=read(),e[i].num=i;
	Kruskal();
	For(i,1,m)	if(tree[e[i].num])	add(e[i].x,e[i].y,e[i].z,e[i].num);
	Dfs(1,1);
	For(j,1,20)
		For(i,1,n)	Fa[i][j]=Fa[Fa[i][j-1]][j-1],mx[i][j]=max(mx[i][j-1],mx[Fa[i][j-1]][j-1]),mi[i][j]=2e9;
	For(i,1,n)	mi[i][0]=2e9;
	For(i,1,m)
		if(!tree[e[i].num])
			Solve(e[i].x,e[i].y,e[i].z,e[i].num);
	Down();
	For(i,2,n)	ans[to[i]]=mi[i][0]-1;
	For(i,1,m)	if(ans[i]>1e9)	write_p(-1);else	write_p(ans[i]);
}