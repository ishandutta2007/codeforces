#include<bits/stdc++.h>
#define ll long long
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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=1e5+5;
int n,m;
struct node{int next,to,v;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	e[cnt].v=z;
}
int d[xx],ton[xx],Pr[xx];
void bfs(int a)//a 
{
	memset(d,0x3f,sizeof(d));d[a]=0;
	queue<int>q;q.push(a);Pr[a]=-1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=h[x];i;i=e[i].next)//
			if(d[e[i].to]>d[x]+1)d[e[i].to]=d[x]+1,q.push(e[i].to),Pr[e[i].to]=x;
	}
}
void Bfs(int a)//a0 
{
	memset(d,0x3f,sizeof(d));d[a]=0;
	queue<int>q;q.push(a);Pr[a]=-1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=h[x];i;i=e[i].next)//
			if(d[e[i].to]>d[x]+1&&!e[i].v)d[e[i].to]=d[x]+1,q.push(e[i].to),Pr[e[i].to]=x;
	}
}
int rc[xx];
void dfs(int x)
{
	rc[x]=1;
	for(int i=h[x];i;i=e[i].next)//
		if(!e[i].v&&!rc[e[i].to])dfs(e[i].to);
}
vector<int>v[xx];
int vis[xx],pre[xx],Pv[xx],Id;
vector<int>ans,ansv,gt;
void dg(int x)
{
	if(pre[x]==-1)return Id=x,void();
	ans.push_back(x);
	ansv.push_back(Pv[x]);
	dg(pre[x]);
}
int Pid[xx];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read()+1,b=read()+1,c=read();
		add(a,b,c),add(b,a,c);
	}
	Bfs(n);dfs(n);
	memcpy(ton,d,sizeof(d));
	bfs(1);
	int mn=1e9;
	for(int i=1;i<=n;i++)if(mn>d[i]&&rc[i])mn=d[i];//
	for(int i=1;i<=n;i++)if(d[i]<=n)v[d[i]].push_back(i);
	for(int i=1;i<=n;i++)if(rc[i]&&d[i]==mn)vis[i]=1,pre[i]=-1,Pid[i]=i;
//	cout<<mn<<"\n";
	for(int j=mn;j>=1;j--)
	{
		int Mn=1e9;
		for(auto x:v[j])
		{
			if(!vis[x])continue;
			for(int i=h[x];i;i=e[i].next)
				if(d[e[i].to]==d[x]-1)Mn=min(Mn,e[i].v);
		}
		for(auto x:v[j])
		{
			if(!vis[x])continue;
			for(int i=h[x];i;i=e[i].next)
				if(d[e[i].to]==d[x]-1&&e[i].v==Mn)
				{
					if(!vis[e[i].to]||ton[Pid[e[i].to]]>ton[Pid[x]])
					vis[e[i].to]=1,pre[e[i].to]=x,Pv[e[i].to]=Mn,Pid[e[i].to]=Pid[x];
				}
		}
	}
	dg(1);
	reverse(ansv.begin(),ansv.end());
	for(auto it:ansv)cout<<it;
	if(!ansv.size())cout<<0;
	puts("");
	memset(rc,0,sizeof(rc));
	Bfs(n);
	int x=Id;
	while(x!=-1)ans.push_back(x),x=Pr[x];
	cout<<ans.size()<<"\n";
	for(auto it:ans)cout<<it-1<<" ";
	puts("");
	pc('1',1);
	return 0;
}