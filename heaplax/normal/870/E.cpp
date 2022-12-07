#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100001
#define mod 1000000007
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,t[N+N],f[N],x[N],y[N];
struct node
{
	int x,y,z;
}p[N];
bool cmp1(node a,node b)
{
	return a.x<b.x;
}
bool cmp2(node a,node b)
{
	return a.y<b.y;
}
int fa(int x)
{
	return f[x]==x?x:f[x]=fa(f[x]);
}
void unit(int a,int b)
{
	a=fa(a),b=fa(b);
	if(a==b)
		++y[a];
	else 
	{
		f[b]=a;
		x[a]+=x[b];
		y[a]+=y[b]+1;
	}
}
int main()
{
	re(n);
	for(int i=1;i<=n;++i)
	{
		re(p[i].x),re(p[i].y);
		p[i].z=f[i]=i;
		x[i]=1;
	}
	sort(p+1,p+n+1,cmp1);
	for(int i=2;i<=n;++i)
		if(p[i].x==p[i-1].x)
			unit(p[i].z,p[i-1].z);
	sort(p+1,p+n+1,cmp2);
	for(int i=2;i<=n;++i)
		if(p[i].y==p[i-1].y)
			unit(p[i].z,p[i-1].z);	
	t[0]=1;
	for(int i=1;i<=n+n;++i)
		t[i]=t[i-1]*2%mod;
	int ans=1;
	for(int i=1;i<=n;++i)
		if(fa(p[i].z)==p[i].z)
		{
			if(y[p[i].z]==x[p[i].z]-1)
				ans=1ll*ans*(t[2*x[p[i].z]-y[p[i].z]]-1)%mod;
			else 
				ans=1ll*ans*t[2*x[p[i].z]-y[p[i].z]]%mod;
		}
	printf("%d\n",ans);
}