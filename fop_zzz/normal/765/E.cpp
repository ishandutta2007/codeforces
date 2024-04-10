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
int x,y,n,q[500001],lst[500001],dis[500001],poi[500001],line[500001],f[500001],nxt[500001],cnt,l,r,len,rt;
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=f[x];f[x]=cnt;}
inline void bfs(int x)
{
	For(i,1,n)	lst[i]=0,dis[i]=0;
	l=1,r=1;
	dis[x]=1;q[1]=x;
	while(l<=r)
	{
		for(int i=f[q[l]];i;i=nxt[i])
			if(!dis[poi[i]])	q[++r]=poi[i],dis[poi[i]]=dis[q[l]]+1,lst[poi[i]]=q[l];
		l++;
	}
}
inline int dfs(int x,int fa)
{
	int t1=0,t2=0;
	for(int i=f[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;
		int tmp=dfs(poi[i],x)+1;
		if(t1==0)	t1=tmp;
		else	
			if(tmp!=t1)
			{
				if(x!=rt)	{puts("-1");exit(0);}
				else	if(t2==0)	t2=tmp;else	if(t2!=tmp)	{puts("-1");exit(0);}
			}
	}	
	if(x!=rt)	return t1;
	int ans=t1+t2;
	while(!(ans&1))	ans/=2;
	printf("%d\n",ans);	
}
int main()
{
	n=read();
	For(i,1,n-1)	x=read(),y=read(),add(x,y),add(y,x);
	bfs(1);
	int hed=q[r];
	bfs(q[r]);
	int now=q[r];
	while(1)
	{
		line[++len]=now;
		if(now==hed)	break;
		now=lst[now];
	}
	rt=line[(len+1)/2];
	dfs(rt,0);
}