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
const int xx=1e6+5,mod=998244353;
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
ll jiec[xx];
ll ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pr()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
int T,n,m,q,k,x,y,z;
char s[505][505];
int d[xx];

struct node
{
	int next,to,v;
}e[xx];
int cnt,h[xx];
void add(int x,int y,int z)
{
	cnt++;
	e[cnt]={h[x],y,z};
	h[x]=cnt;
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int t[xx],a[xx];
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]=1;
	int ans=0;
	for(int i=1e6;i>=1;i--)
	{
		if(t[i]){ans++;continue;}
		int rem=0;
		for(int j=i;j<=1e6;j+=i)
		{
			if(t[j])
			{
				rem=gcd(rem,j/i);
				if(rem==1)
				{
					t[i]=1;
					break;
				}
			}
		}
		if(t[i])ans++;
	}
	cout<<ans-n<<"\n";
//	T=read();
//	while(T--)
//	{
//		
//		
//	}
	pc('1',1);
	return 0;
}