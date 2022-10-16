#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
//char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m,a,b;
const int xx=5e5+5;
struct node
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int low[xx],dfn[xx],cst,size[xx],gsz[xx],vis[xx];
void tj(int x)
{
	low[x]=dfn[x]=++cst,size[x]=1,gsz[x]=0,vis[x]=(x==b);
	for(int i=h[x];i;i=e[i].next)
	{
		if(!dfn[e[i].to])
		{
			tj(e[i].to),low[x]=min(low[x],low[e[i].to]),size[x]+=size[e[i].to];
			((low[e[i].to]>=dfn[x]&&x!=a)?gsz[x]+=size[e[i].to]:0);
			vis[x]|=vis[e[i].to];
			(x==a?gsz[x]+=(!vis[e[i].to])*size[e[i].to]:0);
		}
		else low[x]=min(low[x],dfn[e[i].to]);
	}
}
int main(){
	int T=read();
	while(T--)
	{
		n=read(),m=read(),a=read(),b=read();
		memset(e,0,sizeof(e[0])*(cnt+1));
		memset(h,0,sizeof(h[0])*(n+1));
		memset(dfn,0,sizeof(dfn[0])*(n+1));
		cnt=0,cst=0;
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read();
			add(x,y),add(y,x);
		}
		tj(a);
		cout<<1ll*gsz[a]*gsz[b]<<"\n";
	}
	return 0;
}