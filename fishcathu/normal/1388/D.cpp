#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2E5+5;
int read()
{
	int a=0;char b=1,c;
	do if((c=getchar())==45)b=-1;while(!(c&16));
	do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16);
	return a*b; 
}
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	char a[10],s=0;
	do a[s++]=x%10|48;while(x/=10);
	do putchar(a[--s]);while(s);
}
ll a[N];vector<int>to[N],v;
void dfs(int x)
{
	for(int i=to[x].size();i--;)
	{
		int t=to[x][i];
		dfs(t);
		if(a[t]>0)a[x]+=a[t],v.push_back(t);
	}
}
void dfs2(int x)
{
	for(int i=to[x].size();i--;)
	{
		int t=to[x][i];
		if(a[t]<=0)v.push_back(t);
		dfs2(t);
	}
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1,t;i<=n;++i)(~(t=read())?to[t]:to[0]).push_back(i);
	dfs(0);
	ll ans=0;
	for(int i=1;i<=n;++i)ans+=a[i];
	printf("%lld\n",ans);
	dfs2(0);
	for(int i=0;i<n;++i)printf("%d ",v[i]);
}