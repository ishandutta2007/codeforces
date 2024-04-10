#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	int w=1;
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
	pc(x%10+'0',0);
}
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(c,0);
}
const int xx=1e5+5,mod=1e9+7;
int n;
struct nod
{
	int next,to,v;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}
ll a[xx],b[xx];
int rt,d[xx];
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*a*ans%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
void dfs(int x,int y)
{
	ll to=1,nv=0;
	if(d[x]==1)return a[x]=b[x]=0,void();
	ll V=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y){V=e[i].v;continue;}
		dfs(e[i].to,x);
		to+=mod-1ll*a[e[i].to]*ksm(d[x],mod-2)%mod,nv+=1ll*(b[e[i].to]+e[i].v)*ksm(d[x],mod-2)%mod;
	}
	nv+=V*ksm(d[x],mod-2)%mod;
	to%=mod,nv%=mod;
	a[x]=1ll*ksm(d[x],mod-2)*ksm(to,mod-2)%mod,b[x]=1ll*nv*ksm(to,mod-2)%mod;
	if(x==rt)a[x]=0;
}
ll f[xx];
void down(int x,int y)
{
	if(x==rt)f[x]=b[x];
	if(d[x]==1)f[x]=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		f[e[i].to]=(a[e[i].to]*f[x]%mod+b[e[i].to])%mod;
		down(e[i].to,x);
	}
}
int main(){
	//freopen("a.in","r",stdin);
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read()+1,b=read()+1,c=read();
		d[a]++,d[b]++;
		add(a,b,c),add(b,a,c);
	}
	for(int i=1;i<=n;i++)if(d[i]!=1)rt=i;
	dfs(rt,0);
	down(rt,0);
	cout<<f[1]<<"\n";
	pc('1',1);
	return 0;
}