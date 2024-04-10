#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 100000
#define mod 1000000007 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int k,p,ans=1,vis[1000005],a[1000005],flag;

void dfs(int x)
{
	vis[x]=1;int to=1LL*k*x%p,val=1LL*k*a[x]%p;
	if(vis[to]) {if(a[to]!=val)flag=0;}
	else a[to]=val,dfs(to);
}

int main()
{
	p=read();k=read();
	if(k<=1) 
	{
		for(int i=1;i<=p-(!k);++i) ans=1LL*ans*p%mod;
		return 0*printf("%d\n",ans);
	}
	for(int i=1;i<p;++i) if(!vis[i]) flag=1,a[i]=1,dfs(i),ans=1LL*ans*(flag?p:1)%mod;
	cout<<ans;
	return 0;
}