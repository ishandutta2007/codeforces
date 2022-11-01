#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define maxm 10011
#define maxn 511
#define pb push_back
#define ll unsigned long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
int poi[700001],nxt[700001],f[700001],to[700001],num[7000001],use[700001],n,m,s,cnt;
int k[700001],x,y,mx,mi;
inline void add(int x,int y,int K,int z)
{
	if(K==1){poi[++cnt]=y;nxt[cnt]=f[x];f[x]=cnt;to[cnt]=z;num[cnt]=3;}
	if(K==2)
	{
		poi[++cnt]=y;nxt[cnt]=f[x];f[x]=cnt;to[cnt]=z;num[cnt]=1;
		poi[++cnt]=x;nxt[cnt]=f[y];f[y]=cnt;to[cnt]=z;num[cnt]=2;
	}
}
int q[700001];
bool vis[700001];
inline void bfs1()
{
	mx=1;
	int l=1,r=1;
	q[1]=s;vis[s]=1;
	while(l<=r)
	{
		int x=q[l];
		for(int i=f[x];i;i=nxt[i])
		{
			if(!vis[poi[i]])
			{
				use[to[i]]=num[i];
				q[++r]=poi[i];
				vis[poi[i]]=1;
			}
		}
		++l;
	}
	mx=r;
}
inline void bfs2()
{
	mi=1;
	int l=1,r=1;
	q[1]=s;
	For(i,1,n)	vis[i]=0;
	vis[s]=1;
	while(l<=r)
	{
		int x=q[l];
		for(int i=f[x];i;i=nxt[i])
		{
			if(vis[poi[i]])	continue;
			if(num[i]!=3&&!use[to[i]])	{use[to[i]]=3-num[i];continue;}
			q[++r]=poi[i];
			vis[poi[i]]=1;
		}
		++l;
	}
	mi=r;
}
int main()
{
	n=read();m=read();s=read();
	For(i,1,m)
	{
		k[i]=read();x=read();y=read();
		add(x,y,k[i],i);
	}
	bfs1();

	printf("%d\n",mx);
	For(i,1,m)	if(k[i]==2)	if(use[i]==1)	putchar('+');else putchar('-');		
	For(i,1,m)	use[i]=0;
	bfs2();
	printf("\n%d\n",mi);
	For(i,1,m)	if(k[i]==2)	if(use[i]==1)	putchar('+');else putchar('-');
}