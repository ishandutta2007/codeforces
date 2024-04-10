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
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
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
int T;
const int xx=2e5+5;
struct node{int next,to;}e[xx<<1];
vector<int>v[xx];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
//	cerr<<x<<" "<<y<<"!@#\n";
}
int n,m;
vector<pair<int,int> >s;// 
int dfn[xx],low[xx],dep[xx],val[xx],ck[xx],cst;
void tj(int x,int y)
{
	dfn[x]=low[x]=++cst;
	for(auto to:v[x])
	{
		if(!dfn[to])
		{
			dep[to]=dep[x]+1;
			add(x,to),add(to,x);
			tj(to,x);low[x]=min(low[x],low[to]);
		}
		else 
		{
			low[x]=min(low[x],dfn[to]);
			if(dep[to]<dep[x]&&to!=y)s.push_back(make_pair(x,to));
		}
	}
}
void lk(int x,int y){v[x].push_back(y),v[y].push_back(x);}
void dfs(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=y)dfs(e[i].to,x),val[x]+=val[e[i].to];
}
int f[xx][22],lg[xx];
void down(int x,int y)
{
	f[x][0]=y;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	ck[x]=ck[y]+(val[x]>1);
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=y)down(e[i].to,x);
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y])x=f[x][lg[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=lg[dep[x]];i>=0;i--)(f[x][i]^f[y][i])?(x=f[x][i],y=f[y][i]):0;
	return f[x][0];
}
void out(vector<int>v)
{
	cout<<v.size()<<" ";
	for(auto it:v)cout<<it<<" ";
	puts("");
}
void jump(vector<int>&v,int x,int to)
{
	v.push_back(x);
//	cerr<<x<<"!@## "<<to<<"\n";
	while(x!=to)v.push_back(x=f[x][0]);
}
int main(){
//    freopen("grand.in","r",stdin);
//    freopen("grand.out","w",stdout);
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	n=read(),m=read();
	memset(e,0,sizeof(e[0])*(cnt+1));
	memset(h,0,sizeof(h[0])*(n+1));
	cnt=0;
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=1;i<=m;i++){int a=read(),b=read();lk(a,b);}
	for(int i=1;i<=n;i++)dfn[i]=val[i]=0;
	cst=0;
	int vs=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			s.clear();
			dep[i]=0;
			tj(i,0);
			for(auto it:s)val[it.first]++,val[it.second]--;
			//val 
			dfs(i,0);f[i][0]=0;
			down(i,0);
			for(auto it:s)
			{
				int a=it.first,b=it.second;
				if(ck[a]-ck[b])// 
				{
					for(auto se:s)
					{
						int c=se.first,d=se.second;
						if(c==a&&d==b)continue;
						int L=lca(c,a);
						if(dep[L]>dep[d]&&dep[L]>dep[b])
						{
							if(dep[a]<dep[c])swap(a,c),swap(b,d);
//							cerr<<a<<" "<<b<<" qq "<<c<<" "<<d<<" "<<f[a][0]<<" "<<f[c][0]<<"\n";
							int up=dep[d]>dep[b]?d:b;
//							cout<<L<<" "<<up<<"\n";
							puts("YES");
							vector<int>v;
							jump(v,L,up);
							out(v);v.clear();
							vector<int>v1,v2;
							jump(v1,a,L);
							jump(v2,up,b);
							reverse(v1.begin(),v1.end());
							reverse(v2.begin(),v2.end());
							for(auto it:v1)v.push_back(it);
							for(auto it:v2)v.push_back(it);
							out(v);v.clear();
							v1.clear(),v2.clear();
							jump(v1,c,L);
							jump(v2,up,d);
							reverse(v1.begin(),v1.end());
							reverse(v2.begin(),v2.end());
							for(auto it:v1)v.push_back(it);
							for(auto it:v2)v.push_back(it);
							out(v);v.clear();
							vs=1;break;
						}
					}
					if(vs)break;
				}
				if(vs)break;
			}
			if(vs)break;
		}
	}
	if(!vs)puts("NO");
	pc('1',1);
	return 0;
}