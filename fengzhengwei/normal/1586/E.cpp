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
const int xx=3e5+5;
struct nod
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
vector<pair<int,int> >v;
int n,m,vis[xx];
void dfs(int x,int y)
{
	vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(!vis[e[i].to])dfs(e[i].to,x),v.push_back(make_pair(x,e[i].to));
	}
}
int yh[xx],f[xx],dep[xx];
void dfss(int x,int y)
{
	f[x]=y;dep[x]=dep[y]+1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfss(e[i].to,x);
		yh[x]^=yh[e[i].to];
	}
}
struct node
{
	int a,b;
	node(){a=1e9,b=1e9;}
	node(int x,int y):a(x),b(y){}
	bool operator<(const node&w)const{return a==w.a?b<w.b:a<w.a;}
	node operator+(const node&w)const{return node(a+w.a,b+w.b);}
};
#define f F
#define g G
node updb(node a,int b){a.b+=b;return a;}
node upda(node a,int b){a.a+=b;return a;}
node min(node a,node b){return a<b?a:b;}
node f[xx][8],g[xx];//x0/1(/kk()) 
int size[xx];
void dp(int x,int y)// 
{
	f[x][0]=node(0,0);
	size[x]=1;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y)dp(e[i].to,x);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		for(int a=0;a<=1;a++)g[a]=node();
		for(int a=0;a<=size[x];a++)
		{
			for(int b=0;b<=size[e[i].to];b++)
			{
				if((b&1)==(yh[e[i].to]&1))
				{
					g[a+b-2*min(a,b)]=min(g[a+b-2*min(a,b)],upda(updb(f[x][a]+f[e[i].to][b],b),-min(a,b)));
				}
				// 
			}
		}
		for(int a=0;a<=1;a++)f[x][a]=g[a];
	}
	for(int i=size[x]-1;i>=0;i--)f[x][i]=min(f[x][i],f[x][i+1]);
	for(int i=1;i<=size[x];i++)f[x][i]=min(f[x][i],upda(f[x][i-1],1));
}
#undef f
#undef g
signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0);
	memset(e,0,sizeof(e[0])*(cnt+1));
	memset(h,0,sizeof(h[0])*(n+1));
	cnt=0;
	for(auto it:v)
	{
		add(it.first,it.second);
		add(it.second,it.first);
	}
	int q=read();
	v.clear();
	for(int i=1;i<=q;i++)
	{
		int a=read(),b=read();
		v.push_back(make_pair(a,b));
		yh[a]^=1,yh[b]^=1;
	}
	dfss(1,0);
	int vs=1;
	for(int i=2;i<=n;i++)
	{
		if(yh[i]!=0)
		{
			vs=0;
		}
	}
	if(vs)
	{
		puts("YES");
		for(int i=1;i<=q;i++)
		{
			int x=v[i-1].first,y=v[i-1].second;
			vector<int>v1,v2;
			while(dep[x]>dep[y])v1.push_back(x),x=f[x];
			while(dep[x]<dep[y])v2.push_back(y),y=f[y];
			if(x==y)v1.push_back(x);
			else 
			{
				while(x!=y)
				{
					v1.push_back(x),x=f[x];
					v2.push_back(y),y=f[y];
//					cout<<y<<"ss \n";
				}
//			cout<<x<<" "<<y<<"!!!\n";
				v1.push_back(x);
			}
			reverse(v2.begin(),v2.end());
			cout<<v1.size()+v2.size()<<"\n";
			for(auto it:v1)cout<<it<<" ";
			for(auto it:v2)cout<<it<<" ";
			puts("");
		}
		return 0;
	}
	puts("NO");
	dp(1,0);
	cout<<F[1][0].a<<"\n";
	return 0;
}