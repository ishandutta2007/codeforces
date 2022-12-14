#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 1000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int mod,a,A,xa,ya,b,B,xb,yb;
int vis[MN+5],top,now=1;
long long q[MN+5];
void Check(long long x)
{
	while(now<top&&q[now+1]<=x) ++now;
	if(q[now]==x) {printf("%lld\n",x);exit(0);}	
}
int main()
{
	mod=read();
	a=read();A=read();xa=read();ya=read();
	b=read();B=read();xb=read();yb=read();
	memset(vis,-1,sizeof(vis));vis[a]=0;
	for(int i=1;;++i)
	{
		a=(1LL*a*xa+ya)%mod;
		if(vis[a]==-1) vis[a]=i;
		else 
		{
			int len=i-vis[a];
			if(vis[A]>=vis[a])
				for(;top<MN;) ++top,q[top]=q[top-1]+len;	
			break;	
		}
		if(a==A) q[++top]=i;
	}
	memset(vis,-1,sizeof(vis));vis[b]=0;
	for(int i=1;;++i)
	{
		b=(1LL*b*xb+yb)%mod;
		if(vis[b]==-1) vis[b]=i;
		else 
		{
			int len=i-vis[b];
			if(vis[B]>=vis[b])
				for(int j=0;j<=MN;++j) Check(1LL*j*len+vis[B]);	
			break;	
		}
		if(b==B) Check(i);
	}
	puts("-1");
	return 0;
}