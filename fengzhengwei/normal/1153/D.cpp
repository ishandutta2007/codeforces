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
}e[1000005];
int cnt;
int h[1000005];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int f[1000005];
int c[1000005];
int res;
void dfs(int x)
{
	if(!h[x])
	{
		res++;
		f[x]=1;return;
	}
	int ooo=0;
	for(int i=h[x];i;i=e[i].next)
	{
		dfs(e[i].to);
		if(c[x]==1)
		{
			if(ooo==0)ooo=2147483647;
			ooo=min(ooo,f[e[i].to]);
		}
		else 
		{
			ooo+=f[e[i].to];
		}
	}
	f[x]=ooo;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=2;i<=n;i++)add(read(),i);
	dfs(1);
	cout<<res+1-f[1]<<endl;
	return 0;
}