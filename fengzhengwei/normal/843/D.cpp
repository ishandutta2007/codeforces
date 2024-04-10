#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
int n,m,q;
const int xx=1e5+5;
struct nod
{
	int next,to,v;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}
int id[xx];
struct nd
{
	int x;
	ll ds;
	bool operator<(const nd&w)const{return ds>w.ds;}
};
ll dis[xx];
int vis[xx];
void dij()
{
priority_queue<nd>q;
	for(int i=1;i<=n;i++)vis[i]=0,dis[i]=1e15;
	dis[1]=0;
	q.push({1,0});
	while(!q.empty())
	{
		int x=q.top().x;q.pop();
		if(vis[x])continue;
		vis[x]=1;
//		cerr<<x<<" "<<dis[x]<<" "<<h[x]<<"Asd\n";
		for(int i=h[x];i;i=e[i].next)
		{
			if(dis[e[i].to]>dis[x]+e[i].v)
			{
				dis[e[i].to]=dis[x]+e[i].v;
				q.push({e[i].to,dis[e[i].to]});
			}
		}
	}
}
namespace lst
{
	struct nod{int next,to;}E[xx<<1];
	int cnt,H[xx];
	void add(int x,int y){cnt++,E[cnt]={H[x],y},H[x]=cnt;}
	void cl(){memset(H,0,sizeof(H[0])*(n+1));cnt=0;}
	ll ad[xx];
	void run()
	{
		for(int i=1;i<=n;i++)ad[i]=1e15,vis[i]=0;
		ad[1]=0,add(0,1);
		for(int v=0;v<=n;v++)
		{
			// 
			for(int &I=H[v];I;)
			{
				int x=E[I].to;I=E[I].next;
				if(vis[x])continue;
				vis[x]=1;
//				cerr<<x<<" "<<h[x]<<"SDAD\n";
				for(int i=h[x];i;i=e[i].next)
				{
//				cerr<<x<<" "<<ad[x]<<" "<<e[i].to<<" "<<e[i].v<<" "<<ad[e[i].to]<<"asd\n";
					if(ad[e[i].to]>ad[x]+e[i].v-(dis[e[i].to]-dis[x]))
					{
						ad[e[i].to]=ad[x]+e[i].v-(dis[e[i].to]-dis[x]);
						if(ad[e[i].to]<=n)add(ad[e[i].to],e[i].to);
					}
				}
			}
		}
	}
}
signed main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		id[i]=cnt+1;
		add(a,b,c);
	}
	dij();
	for(int i=1;i<=q;i++)
	{
		int s=read();
		if(s==1)
		{
			int t=read();
//	cerr<<dis[t]<<" "<<t<<"asd\n";
			if(dis[t]>=1e15)puts("-1");
			else cout<<dis[t]<<"\n";
		}
		else 
		{
//	cout<<h[1]<<"%%^%^\n";
			lst::cl();
			int num=read();
			for(int j=1;j<=num;j++)e[id[read()]].v++;
			lst::run();
			for(int j=1;j<=n;j++)dis[j]+=lst::ad[j];
		}
	}
	pc('1',1);
	return 0;
}