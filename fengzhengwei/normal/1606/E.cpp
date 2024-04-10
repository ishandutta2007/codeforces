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
const int mod=998244353;
const int xx=505;
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
ll F[505][505];
int vis[505][505];
ll f(ll n,ll m)
{
	if(!n)return 1;
	if(n==1)return 0;
	if(vis[n][m])return F[n][m];
	if(m<=(n-1))// 
	{return vis[n][m]=1,F[n][m]=ksm(m,n);}
	ll res=0;
	ll KM=1;
	for(int j=0;j<=n;j++)
	{
		res+=f(n-j,m-(n-1))*KM%mod*C(n,j)%mod;
		res%=mod;
		KM*=n-1,KM%=mod;
	}
//	cout<<n<<" "<<m<<" "<<res<<"\n";
	vis[n][m]=1;
	return F[n][m]=res;
}
int main(){
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	int n=read(),m=read();
	cout<<f(n,m)<<"\n";
	return 0;
}