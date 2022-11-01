#include<bits/stdc++.h>
using namespace std;
const int N=1E5+5;
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
int sum[N],fm[N],ans;vector<int>to[N];
void dfs(int f,int x)
{
	int s=0;
	for(int i=to[x].size();i--;)
	{
		int t=to[x][i];
		if(t!=f)dfs(x,t),sum[x]+=sum[t],s+=sum[t]+fm[t];
	}
	int t=sum[x]+fm[x]; 
	if((t&1)||t<s||sum[x]<fm[x])ans=0;
}
int main()
{
	for(int x=read();x--;)
	{
		int n=read();
		read(),memset(sum,0,sizeof sum),memset(fm,0,sizeof fm),ans=1;
		for(int i=1;i<=n;++i)to[i].clear();
		for(int i=1;i<=n;++i)sum[i]=read();
		for(int i=1;i<=n;++i)fm[i]=read();
		for(int i=1,u,v;i<n;++i)u=read(),v=read(),to[u].push_back(v),to[v].push_back(u);
		dfs(0,1),puts(ans?"YES":"NO");
	}
}