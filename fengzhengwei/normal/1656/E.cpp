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
namespace zhs
{
	const int xx=5e5+5,mod=998244353;
	ll jiec[xx],ni[xx];
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
	ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
	void pre()
	{
		jiec[0]=1;
		for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
		ni[xx-1]=ksm(jiec[xx-1],mod-2);
		for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	}
}
namespace pr
{
	const int xx=5e5+5,mod=998244353;
	int prim[xx],mn[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!mn[i])mn[i]=i,prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				mn[i*prim[j]]=prim[j];
				if(i%prim[j]==0)break;
			}
		}
	}
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
// 
const int xx=5e5+5,mod=998244353;
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
int n,m,k,q,a[xx];
char s[xx];
int d[xx],rt;
ll xs1[xx],xs2[xx],q1,q2;
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++,e[cnt]={h[x],y},h[x]=cnt;
}
void dfs(int x,int y,ll tt1,ll tt2)
{
	if(x==rt)xs1[x]=1,xs2[x]=0;
	else if(y==rt)xs1[x]=0,xs2[x]=1;
	if(x==rt)
	{
		for(int i=h[x];i;i=e[i].next)dfs(e[i].to,x,0,0);
	}
	else if(y==rt)
	{
		q1=0,q2=0;q1++;q2++;
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			q1++;
		}
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			dfs(e[i].to,x,1,0);
		}
	}
	else 
	{
		ll y1=q1-tt1,y2=q2-tt2;
		xs1[x]=q1,xs2[x]=q2;
		xs1[x]-=y1,xs2[x]-=y2;
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			xs1[x]-=y1,xs2[x]-=y2;
		}
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			dfs(e[i].to,x,y1,y2);
		}
	}
}
int c[xx];
void col(int x,int y)
{
	c[x]=c[y]^1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		col(e[i].to,x);
	}
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		
		for(int i=1;i<=n;i++)d[i]=c[i]=0;
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read();
			add(a,b),add(b,a);
			d[a]++,d[b]++;
		}
		col(1,0);
		for(int i=1;i<=n;i++)if(c[i])cout<<d[i]<<" ";else cout<<-d[i]<<" ";
		continue;
		rt=0;
		for(int i=1;i<=n;i++)if(d[i]==1)rt=i;
		dfs(rt,0,0,0);
//		for(int i=1;i<=n;i++)cout<<xs1[i]<<" "<<xs2[i]<<"\n";
//		exit(0);
		int is=0;
		for(int i=-1;i<=1;i++)
		{
//			if(i==0)continue;
			for(int j=-1;j<=1;j++)
			{
//				if(j==0)continue;
				int cr=1;
				for(int k=1;k<=n;k++)
				{
					if(i*xs1[k]+j*xs2[k]>1e5||i*xs1[k]+j*xs2[k]<-1e5||i*xs1[k]+j*xs2[k]==0)
					{
						cr=0;
						break;
					}
				}
				if(cr)
				{
					is=1;
					for(int k=1;k<=n;k++)cout<<i*xs1[k]+j*xs2[k]<<" ";
					puts("");
					break;
				}
				if(is)break;
			}
			if(is)break;
		}
		if(is)continue;
		
		for(int i=-5;i<=5;i++)
		{
//			if(i==0)continue;
			for(int j=-5;j<=5;j++)
			{
//				if(j==0)continue;
				int cr=1;
				for(int k=1;k<=n;k++)
				{
					if(i*xs1[k]+j*xs2[k]>1e5||i*xs1[k]+j*xs2[k]<-1e5||i*xs1[k]+j*xs2[k]==0)
					{
						cr=0;
						break;
					}
				}
				if(cr)
				{
					is=1;
					for(int k=1;k<=n;k++)cout<<i*xs1[k]+j*xs2[k]<<" ";
					puts("");
					break;
				}
				if(is)break;
			}
			if(is)break;
		}
		if(is)continue;
		
		
		for(int i=-20;i<=20;i++)
		{
//			if(i==0)continue;
			for(int j=-20;j<=20;j++)
			{
//				if(j==0)continue;
				int cr=1;
				for(int k=1;k<=n;k++)
				{
					if(i*xs1[k]+j*xs2[k]>1e5||i*xs1[k]+j*xs2[k]<-1e5||i*xs1[k]+j*xs2[k]==0)
					{
						cr=0;
						break;
					}
				}
				if(cr)
				{
					is=1;
					for(int k=1;k<=n;k++)cout<<i*xs1[k]+j*xs2[k]<<" ";
					puts("");
					break;
				}
				if(is)break;
			}
			if(is)break;
		}
		if(is)continue;
		for(int i=-1e5;i<=1e5;i++)
		{
			if(i==0)continue;
			//=1 
			ll L=-1e5,R=1e5;
			for(int i=1;i<=n;i++)
			{
				if(xs2[i]==0)continue;
				if(xs2[i]>0)
				{
					R=min(R,((int)1e5-xs1[i]*i)/xs2[i]+1);
					L=max(L,(-(int)1e5-xs1[i]*i)/xs2[i]-1);
				}
				if(xs2[i]<0)
				{
					R=min(R,(-(int)1e5-xs1[i]*i)/xs2[i]+1);
					L=max(L,((int)1e5-xs1[i]*i)/xs2[i]-1);
				}
				if(L>R)break;
			}
			if(L>R)continue;
	//		int i=1;
			for(int j=L;j<=R;j++)
			{
				int cr=1;
				for(int k=1;k<=n;k++)
				{
					if(i*xs1[k]+j*xs2[k]>1e5||i*xs1[k]+j*xs2[k]<-1e5||i*xs1[k]+j*xs2[k]==0)
					{
						cr=0;
						break;
					}
				}
				if(cr)
				{
					is=1;
					for(int k=1;k<=n;k++)cout<<i*xs1[k]+j*xs2[k]<<" ";
					puts("");
					break;
				}
				if(is)break;
			}
			if(is)break;
		}
		if(is)continue;
//		for(int i=-400;i<=400;i++)
//		{
////			if(i==0)continue;
//			for(int j=-400;j<=400;j++)
//			{
////				if(j==0)continue;
//				int cr=1;
//				for(int k=1;k<=n;k++)
//				{
//					if(i*xs1[k]+j*xs2[k]>1e5||i*xs1[k]+j*xs2[k]<-1e5||i*xs1[k]+j*xs2[k]==0)
//					{
//						cr=0;
//						break;
//					}
//				}
//				if(cr)
//				{
//					is=1;
//					for(int k=1;k<=n;k++)cout<<i*xs1[k]+j*xs2[k]<<" ";
//					puts("");
//					break;
//				}
//				if(is)break;
//			}
//			if(is)break;
//		}
//		if(is)continue;
		assert(0);
//		for(int i=1;i<=n;i++)cout<<xs1[i]<<" "<<xs2[i]<<"\n";
	}
	pc('1',1);
	return 0;
}