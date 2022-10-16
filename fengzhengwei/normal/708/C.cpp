#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
struct node
{
	int next,to;
}e[800005];
int cnt;
int h[400005];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int f[400005][2];
int to[400005];
int size[400005];
int maxx[400005];//x 
void dfs(int x,int y)
{
	size[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>size[maxx[x]])maxx[x]=e[i].to;
		int tt=0;
		if(size[e[i].to]>n/2)tt=f[e[i].to][0];//0 1 
		else tt=size[e[i].to];
		if(tt>f[x][0])
		{
			f[x][1]=f[x][0];
			f[x][0]=tt;
			to[x]=e[i].to;
		}
		else if(tt>f[x][1])f[x][1]=tt;
	}
}
int part[400005];//n/2 
int ans[400005];
void dp(int x,int y)
{
//	cout<<x<<" "<<part[x]<<endl;
	ans[x]=1;
	if(size[maxx[x]]>n/2)ans[x]=(size[maxx[x]]-f[maxx[x]][0]<=n/2);
	if(size[1]-size[x]>n/2)ans[x]=(size[1]-size[x]-part[x]<=n/2);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		int tt;
		if(size[1]-size[x]>n/2)tt=part[x];
		else tt=size[1]-size[x];
		part[e[i].to]=max(part[e[i].to],tt);
		if(to[x]==e[i].to)tt=f[x][1];
		else tt=f[x][0];
		part[e[i].to]=max(part[e[i].to],tt);
		dp(e[i].to,x);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	dp(1,0);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}