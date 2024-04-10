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
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
int n,m;
const int xx=5e5+5;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx],ds[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int id[xx];
namespace s6000
{
	short f[6005][6005],g[6005][6005];//fg 
	int t[6005];
	// 
	void dfs(int x,int y)
	{
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			dfs(e[i].to,x);
			t[x]=max(t[x],t[e[i].to]);
			t[x]=max(t[x],1+g[x][id[x]+1]+f[e[i].to][id[x]-1]);
			t[x]=max(t[x],1+g[e[i].to][id[x]+1]+f[x][id[x]-1]);
			for(int j=1;j<=6000;j++)
			{
				t[x]=max(t[x],f[x][j-1]+g[e[i].to][j]);
				t[x]=max(t[x],f[e[i].to][j-1]+g[x][j]);
			}
			for(int j=0;j<=6000;j++)f[x][j]=max(f[x][j],f[e[i].to][j]);
			for(int j=0;j<=6000;j++)g[x][j]=max(g[x][j],g[e[i].to][j]);
		}
		for(int j=0;j<=6000;j++)
		{
			f[x][j]=max(f[x][j-1],f[x][j]);
			if(j==id[x])f[x][j]=max(f[x][j],(short)(f[x][j-1]+1));
		}
		for(int j=6000;j>=0;j--)
		{
			g[x][j]=max(g[x][j+1],g[x][j]);
			if(j==id[x])g[x][j]=max(g[x][j],(short)(g[x][j+1]+1));
		}
		t[x]=max(t[x],(int)f[x][6000]);
		t[x]=max(t[x],(int)g[x][0]);
	}
	void solve()
	{
//		int mn=1e9;
//		for(int x=1;x<=n;x++)
//		{
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(t,0,sizeof(t));
		dfs(1,0);
//		}
		cout<<t[1]<<"\n";
	}
}
int a[6005];
int main(){
	n=read();
	for(int i=1;i<=n;i++)id[i]=a[i]=read();
	sort(a+1,a+n+1);
	int O=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;i++)id[i]=lower_bound(a+1,a+O+1,id[i])-a;
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
		s6000::solve();
		return 0;
	pc('1',1);
	return 0;
}