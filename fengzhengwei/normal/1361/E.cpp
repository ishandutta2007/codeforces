#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ull unsigned ll 
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e5+5;
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx],n,m;
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
vector<int>ans;
bool res;
int dfn[xx],low[xx],slow[xx],dep[xx],id[xx],vis[xx],cst;
void dfs(int x)
{
	dfn[x]=low[x]=slow[x]=++cst,vis[x]=1,id[cst]=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!dfn[e[i].to])
		{
			dfs(e[i].to);
			// 
//			cerr<<x<<" "<<e[i].to<<" ss "<<slow[e[i].to]<<" "<<slow[x]<<"##\n";
			if(low[x]>low[e[i].to])slow[x]=low[x],low[x]=low[e[i].to];
			else slow[x]=min(slow[x],low[e[i].to]);
			slow[x]=min(slow[x],slow[e[i].to]);
//			cerr<<x<<" "<<e[i].to<<" ss "<<slow[e[i].to]<<" "<<slow[x]<<"##\n";
		}
		else 
		{
			if(!vis[e[i].to])res=0;
			if(low[x]>dfn[e[i].to])slow[x]=low[x],low[x]=dfn[e[i].to];
			else slow[x]=min(slow[x],dfn[e[i].to]);
		}
	}
//	cerr<<slow[4]<<"&&&\n";
	vis[x]=0;
}
int cr[xx];
void run(int rt)
{
//	cerr<<rt<<"@\n";
//	for(int i=1;i<=n;i++)cerr<<low[i]<<" "<<slow[i]<<" "<<dfn[i]<<"@@\n";
	for(int i=1;i<=n;i++)
	{
		int x=id[i];
		cr[x]=1;
		if(low[x]<dfn[x]&&slow[x]<dfn[x])cr[x]=0;
		cr[x]&=cr[id[low[x]]];
	}
	for(int i=1;i<=n;i++)if(cr[i])ans.push_back(i);
//	,cerr<<i<<"!!!!\n";
	if(ans.size()<(n+4)/5){return puts("-1"),void();}
	for(auto it:ans)cout<<it<<" ";
	puts("");
}
bool check(int rt)
{
	cst=0;
	for(int i=1;i<=n;i++)dfn[i]=low[i]=slow[i]=dep[i]=vis[i]=0;
	res=1,dfs(rt);
//	cerr<<rt<<" "<<res<<"!!\n";
	for(int i=1;i<=n;i++)if(!dfn[i])return 0;
	if(!res)return 0;
	return 1;
}
int main(){
//	freopen("a.in","r",stdin);
	mt19937 G(218);
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=m;i++)
		{
			int a=read(),b=read();
			add(a,b);
		}
		int rt=0,t=40;
		while(t--)
		{
			if(check(rt=uniform_int_distribution<int>(1,n)(G)))break;
			rt=0;
		}
		if(!rt)puts("-1");
		else run(rt);
		
		cst=0;
		for(int i=1;i<=n;i++)h[i]=0;
		cnt=0;
		ans.clear();
	}
	pc('1',1);
	return 0;
}

}int main(){return ifzw::main();}