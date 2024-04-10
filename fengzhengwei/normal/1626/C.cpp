#include<bits/stdc++.h>
#define ll long long
//#define int long long
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
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5,yy=2e5+5,mod=998244353;
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
//ll jiec[xx];
//ll ni[xx];
//ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
//void pr()
//{
//	jiec[0]=1;
//	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
//	ni[xx-1]=ksm(jiec[xx-1],mod-2);
//	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
//}
int T,n,m,k,x,y,z;
//struct node{int next,to,v;}e[xx];
//int cnt,h[xx];
//void add(int x,int y,int z){cnt++;e[cnt]={h[x],y,z};h[x]=cnt;}
int a[xx];
char s[xx];
struct node
{
	int t,k;
	bool operator<(const node&w)const{return t<w.t;}
}e[xx];
int mn[xx];
ll G(ll n){return n*(n+1)/2;}
ll get(ll l,ll r){return G(r-l+1);}
signed main(){
	T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)e[i].t=read();
		for(int i=1;i<=n;i++)e[i].k=read();
		sort(e+1,e+n+1);
		for(int i=1;i<=n;i++)a[i]=e[i].t-e[i].k+1;//1 
		mn[n+1]=1e9+1;
		for(int i=n;i>=1;i--)mn[i]=min(mn[i+1],a[i]);
		int nl=1,nr=0;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			if(nr<mn[i])
			{
				ans+=get(nl,nr);
				nl=mn[i],nr=e[i].t;
			}
			else nr=e[i].t;
		}
		ans+=get(nl,nr);
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}