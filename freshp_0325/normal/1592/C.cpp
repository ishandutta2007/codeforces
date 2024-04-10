#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
vector<int> G[100005];
int n,k,a[100005],sum,ans;
int dfs(int now,int pre)
{
	int tek=a[now];
	for(auto st:G[now])
	{
		if(st==pre)	continue;
		int val=dfs(st,now);
		if(val==sum)	++ans;
		else	tek^=val;
	}
	return tek;
}
int main(){
	int T=read();
	while(T-->0)
	{
		n=read(),k=read();
		for(int i=1;i<=n;++i)	G[i].clear();
		sum=0;
		for(int i=1;i<=n;++i)	a[i]=read(),sum^=a[i];
		for(int i=1;i<n;++i)
		{
			int u=read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(sum==0)
		{
			puts("Yes");
			continue;
		}
		if(k==2)
		{
			puts("No");
			continue;
		}
		ans=0;
		dfs(1,0);
		puts(ans>=2?"YES":"NO");
	}
	return 0;
}