#pragma GCC optimize(2) 
#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
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
const int xx=1e5+5e4+5;
int n,q;
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int dep[xx],f[xx][21],lg[xx];
void dfs(int x,int y)
{
	dep[x]=dep[y]+1,f[x][0]=y;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
	}
}
int jump(int x,int y)
{
	for(int i=lg[y];i>=0;i--)if(y>>i&1)x=f[x][i];
	return x;
}
const int B=1024;
struct no{int len,id,tag;bool operator<(const no&w)const{return len<w.len;};};
//B0~ 
vector<no>v[xx];
int ans[xx],a[xx];
namespace trie
{
	struct N{int to[2];}e[xx*32];
	int cst;
	void cls(){cst=0;}
	void ins(int &k,int d,int x)
	{
		if(!k)k=++cst,e[k].to[0]=e[k].to[1]=0;
		if(d==-1)return;
		ins(e[k].to[x>>d&1],d-1,x);
	}
	int get(int &k,int d,int x)
	{
		if(d==-1)return 0;
		if(e[k].to[(x>>d&1)^1])return get(e[k].to[(x>>d&1)^1],d-1,x)+(1<<d);
		return get(e[k].to[x>>d&1],d-1,x);
	}
}
int rt;
void Run(int x,int y)
{
	if(v[x].size())
	{
		rt=0,trie::cls();
		sort(v[x].begin(),v[x].end());
		int T=B,now=x,dp=0,xw=0;
		while(T--)
		{
			if(!now)break;
			trie::ins(rt,15,a[now]^dp);
			while(xw<v[x].size()&&v[x][xw].len==dp)
				ans[v[x][xw].id]=max(ans[v[x][xw].id],trie::get(rt,15,v[x][xw].tag)),xw++;
			if(xw==v[x].size())break;
	//			,puts("ASD");
			dp++,now=f[now][0];
		}
	}
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		Run(e[i].to,x);
	}
}
int main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0);
	for(int i=1;i<=q;i++)
	{
		int u=read(),b=read();
		int x=b,bs=0;
		while(dep[x]-dep[u]>=B)
		{
			v[x].push_back({B-1,i,(bs*B)});
			x=jump(x,B),bs++;
		}
		v[x].push_back({dep[x]-dep[u],i,(bs*B)});
	}
	Run(1,0);
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}