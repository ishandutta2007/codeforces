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
int T;
const int mod=998244353;
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
const int xx=1e5+5;
int mn[xx],prim[xx];
void pre(int n)
{
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])
		{
			prim[++cnt]=i;
			mn[i]=i;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int cr,a[xx],size[xx],op;
void dfs(int x,int y)
{
	size[x]=1;a[x]=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
	}
	if((size[x]-1)%op&&size[x]%op)cr=0;
	if(size[x]%op)a[y]++;//+1 
	else a[x]++;//1 
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int n;
int get(int V)
{
	cr=1;op=V;
	dfs(1,0);
	if(!cr)return 0;
	int w=0;
	for(int i=1;i<=n;i++)w=gcd(w,a[i]);
	return w;
}
int ans[xx];
int main(){
	pre(100000);
	T=read();
	while(T--)
	{
		n=read();
		memset(e,0,sizeof(e[0])*(cnt+1));
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read();
			add(a,b),add(b,a);
		}
		memset(ans,0,sizeof(ans[0])*(n+1));
		int x=n-1;
		while(x!=1)
		{
			int t=mn[x];
//			cout<<t<<"\n";
			while(x%t==0)x/=t;
			int a;if((a=get(t)))ans[a]=1;// 
		}
		ans[1]=ksm(2,n-1);
		for(int i=2;i<=n;i++)ans[1]-=ans[i];
		ans[1]+=mod,ans[1]%=mod;
		for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	}
	pc('1',1);
	return 0;
}