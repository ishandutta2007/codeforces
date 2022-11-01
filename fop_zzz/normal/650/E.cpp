#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#define eps 1e-10
#define inf 1e9
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define y1 orz
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int n,x,y,F[500001],nxt[2][1000001],cnt[2],poi[2][1000001],f[2][500001];
int fa[2][500001],top;
int ans1[3000001],ans2[3000001],ans3[3000001],ans4[3000001];
inline void add(int x,int y,int z){poi[z][++cnt[z]]=y;nxt[z][cnt[z]]=f[z][x];f[z][x]=cnt[z];}
inline int get(int x){return x==F[x]?F[x]:F[x]=get(F[x]);}
inline void dfs(int x,int FA,int col)
{
	fa[col][x]=FA;
	for(int i=f[col][x];i;i=nxt[col][i])
	{
		if(poi[col][i]==FA)	continue;
		dfs(poi[col][i],x,col);
	}
}
inline void solve(int x,int FA)
{
	for(int i=f[0][x];i;i=nxt[0][i])
	{
		int tmp=poi[0][i];
		if(tmp==FA)	continue;
		solve(tmp,x);
		if(tmp!=fa[1][x]&&x!=fa[1][tmp])	
			ans1[++top]=tmp,ans2[top]=x,ans3[top]=get(tmp),ans4[top]=fa[1][get(tmp)];
	}
}
int main()
{
	n=read();
	For(i,1,n-1)	x=read(),y=read(),add(x,y,0),add(y,x,0);
	For(i,1,n-1)	x=read(),y=read(),add(x,y,1),add(y,x,1);
	dfs(1,-1,0);
	dfs(1,-1,1);
	For(i,1,n)	F[i]=i;
	For(i,1,n)
	{
		int tmp=fa[1][i];
		if(tmp==fa[0][i]||i==fa[0][tmp])	F[i]=tmp;
	}
	solve(1,-1);
	printf("%d\n",top);
	For(i,1,top)	printf("%d %d %d %d\n",ans1[i],ans2[i],ans3[i],ans4[i]);
}