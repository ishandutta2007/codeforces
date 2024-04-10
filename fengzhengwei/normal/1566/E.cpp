#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int f[xx];
void dfs(int x,int y)
{
	f[x]=y;
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=y)dfs(e[i].to,x);
}
int tans=0,rans=0,tt=0,vis[xx];
void find(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		find(e[i].to,x);
	}
	if(x==1)return;
	int son=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!vis[e[i].to]&&e[i].to!=y)son++;
	}
	if(!son)
	{
		if(f[x]==1)tans++,tt++;
		return;
	}
	tans+=son,rans++;
	vis[x]=1;
//	cout<<x<<" "<<son<<"!!!\n";
}
signed main(){
	int T=read();
	while(T--)
	{
		int n=read();
		tans=rans=tt=0;
		memset(vis,0,sizeof(vis[0])*(n+1));
		memset(e,0,sizeof(e[0])*(cnt+1));
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read();
			add(a,b);add(b,a);
		}
		dfs(1,0);
		find(1,0);
		cout<<tans-rans+(tt==0)<<"\n";// 
	}
	return 0;
}