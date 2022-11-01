#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
using namespace std;
inline int read()
{
	int t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
inline void write(int x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
const int N=200101;
bool vis[N];
int s[N],top=0,Dis[N],f[N],H;
int n,m,a[N],b[N],Dfn[N],low[N],l[N],tt[N];
int cnt=0,p[N],nxt[N],head[N],dx[N];
inline void Add(int a,int b){
	p[++cnt]=b;nxt[cnt]=head[a];head[a]=cnt;
}
int tot=0;
inline void Dfs(int x){
	Dfn[x]=low[x]=++tot;
	s[++top]=x;vis[x]=1;
	for(int k=head[x];k;k=nxt[k])if(!Dfn[p[k]])
	{
		Dfs(p[k]);low[x]=min(low[x],low[p[k]]);
	}
	else 
		if(vis[p[k]])low[x]=min(low[x],Dfn[p[k]]);
	if(Dfn[x]==low[x])
	{
		tt[0]++;int k=0;
		do
		{
			k=s[top--];vis[k]=0;l[k]=tt[0];tt[tt[0]]++;
		}while(k!=x);
	}
}
int main()
{
	n=read();m=read();
	int h=read();
	For(i,1,n)a[i]=read();
	For(i,1,m)
	{
		int x=read(),y=read();
		if((a[x]+1)%h==a[y])Add(x,y);
		if((a[y]+1)%h==a[x])Add(y,x);
	}
	For(i,1,n)if(!Dfn[i])Dfs(i);
	For(i,1,n)
		for(int k=head[i];k;k=nxt[k])if(l[i]!=l[p[k]])dx[l[i]]++;
	int ans,mn=inf;
	For(i,1,tt[0])if(!dx[i]){
		if(mn>tt[i])mn=tt[i],ans=i;
	}
	cout<<mn<<endl;
	For(i,1,n)if(l[i]==ans)printf("%d ",i);
}