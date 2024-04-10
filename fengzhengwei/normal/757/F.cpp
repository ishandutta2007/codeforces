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
const int xx=3e5+5;
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
int n,m,s;
struct nod{int x,y,z;};
vector<nod>v;
struct no{int x;ll ds;bool operator<(const no&w)const{return ds>w.ds;};};
ll dis[xx];
int vis[xx],rd[xx];
void dij(int x)
{
	memset(dis,0x3f,sizeof(dis));
	priority_queue<no>q;
	dis[x]=0;
	q.push({x,0});
	while(!q.empty())
	{
		x=q.top().x;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
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
vector<int>inv[xx];
int f[xx][21],dep[xx],lg[xx];
int lca(int x,int y)
{
	if(!x||!y)return x+y;
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y])x=f[x][lg[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=lg[dep[x]];i>=0;i--)(f[x][i]^f[y][i])?(x=f[x][i],y=f[y][i]):0;
	return f[x][0];
}
int sz[xx];
signed main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	n=read(),m=read(),s=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		add(a,b,c),add(b,a,c);
		v.push_back({a,b,c});
	}
	dij(s);
	memset(e,0,sizeof(e[0])*(cnt+1));
	memset(h,0,sizeof(h));
	cnt=0;
	for(auto it:v)
	{
		int a=it.x,b=it.y,c=it.z;
		if(dis[a]+c==dis[b])add(a,b,0),inv[b].push_back(a),rd[b]++;
		if(dis[b]+c==dis[a])add(b,a,0),inv[a].push_back(b),rd[a]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)if(!rd[i])q.push(i);
	vector<int>v;
	while(!q.empty())
	{
		int x=q.front();
		v.push_back(x);
		q.pop();
		if(x!=s)
		{
			int L=0;
			for(auto it:inv[x])L=lca(L,it);
			f[x][0]=L;
			for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
			dep[x]=dep[L]+1;
		}
		for(int i=h[x];i;i=e[i].next)
			if(!(--rd[e[i].to]))q.push(e[i].to);
	}
	reverse(v.begin(),v.end());
	for(auto it:v)sz[it]++,sz[f[it][0]]+=sz[it];
	int mx=0;
	for(int i=1;i<=n;i++)if(i!=s&&dis[i]<1e18)mx=max(mx,sz[i]);
	cout<<mx<<"\n";
	pc('1',1);
	return 0;
}