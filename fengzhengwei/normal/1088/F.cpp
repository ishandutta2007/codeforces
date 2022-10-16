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
	((op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf));
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
const int xx=5e5+5;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int n,f[xx][22];
ll ans,a[xx];
void dfs(int x,int y)
{
	f[x][0]=y;
	for(int j=1;j<=20;j++)f[x][j]=f[f[x][j-1]][j-1];
	if(f[x][0])
	{
		ll mn=1e18;
		for(int i=0;i<=20;i++)
			mn=min(mn,a[x]+a[f[x][i]]*(i+1));
		ans+=mn;
	}
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
	}
	
}
int main(){
	n=read();
	int rt=1;
	a[0]=1e9;
	for(int i=1;i<=n;i++)a[i]=read(),(a[i]<a[rt]?rt=i:0);
//	cerr<<rt<<"\n";
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(rt,rt);
	cout<<ans-a[rt]-a[rt]<<"\n";
	return 0;
}