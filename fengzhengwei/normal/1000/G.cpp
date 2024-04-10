#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
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
const int xx=5e5+5;
struct nod{int next,to,v;}e[xx<<1];
int cnt,h[xx],a[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z};h[x]=cnt;}
int n,m,f[xx][21],dep[xx],lg[xx];
ll dp[xx],fv[xx],d[xx];
void dfs(int x,int y)
{
	f[x][0]=y,dep[x]=dep[y]+1;
	dp[x]=a[x];
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		fv[e[i].to]=e[i].v,d[e[i].to]=d[x]+e[i].v;
		dfs(e[i].to,x);
		dp[x]+=max(0ll,dp[e[i].to]-e[i].v-e[i].v);
	}
//	cout<<x<<" "<<dp[x]<<"!!\n";
}
ll fa[xx];//dp 
void dfss(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		fa[e[i].to]=dp[x]+max(0ll,fa[x]-fv[x]-fv[x])-max(0ll,dp[e[i].to]-e[i].v-e[i].v);
		dfss(e[i].to,x);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y])x=f[x][lg[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=lg[dep[x]];i>=0;i--)(f[x][i]^f[y][i])?(x=f[x][i],y=f[y][i]):0;
	return f[x][0];
}
int jump(int x,int y)
{
	for(int i=lg[y];i>=0;i--)if(y>>i&1)x=f[x][i];
	return x;
}
ll g[xx][21];
ll gv(int x,int y)
{
	ll ans=0;
	for(int i=lg[y];i>=0;i--)if(y>>i&1)ans+=g[x][i]/*,cerr<<g[x][i]<<" "<<x<<" "<<i<<"!ASD\n"*/,x=f[x][i];
	return ans;
}
int main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i)); 
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read(),c=read();
		add(a,b,c),add(b,a,c);
	}
	dfs(1,0),dfss(1,0);
	for(int i=1;i<=n;i++)g[i][0]=dp[f[i][0]]-max(0ll,dp[i]-fv[i]-fv[i]);
//	g[1][0]=0;// 
//	,cerr<<g[i][0]<<" "<<i<<"ASC\n";
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
//		{
			g[i][j]=g[i][j-1]+g[f[i][j-1]][j-1];
//			cout<<i<<" "<<j<<" "<<g[i][j]<<"!\n";
//		}
	
	for(int i=1;i<=m;i++)
	{
		int s=read(),t=read();
		if(s==t)
			cout<<dp[s]+max(0ll,fa[s]-fv[s]-fv[s])<<"\n";
		else 
		{
			int L=lca(s,t);
			if(dep[s]<dep[t])swap(s,t);
			ll ans=0;
			if(L==t)
			{
				ans+=dp[s];
				ans+=gv(s,dep[s]-dep[L]);
//				cout<<ans<<"!!\n";
				ans+=max(0ll,fa[L]-fv[L]-fv[L]);
			}
			else 
			{
				ans+=dp[s],ans+=dp[t];
				ans+=gv(s,dep[s]-dep[L]);
				ans+=gv(t,dep[t]-dep[L]);
				ans+=max(0ll,fa[L]-fv[L]-fv[L]);
				ans-=dp[L];
//				int tl=jump(s,dep[s]-dep[L]),tr=jump(t,dep[t]-dep[L]);
//				ans-=(dp[L]-V tl)+(dp[L]- Vtr);
//				ans+=dp[L]-
			}
			cout<<ans-(d[s]+d[t]-d[L]-d[L])<<"\n";
		}
	}
	pc('1',1);
	return 0;
}