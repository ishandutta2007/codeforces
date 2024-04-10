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
	pc(x%10+'0',0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
int n,m;
int a[2005][2005];
bool check()
{
	int vs=1;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]&&!l)l=j;
			if(a[i][j])r=j;
		}
		if(!l&&!r)vs=0;
		for(int k=l;k<=r;k++)
			if(!a[i][k])vs=0;
		for(int j=1;j<=m;j++)a[i][j]^=1;
	}
	for(int i=m;i>=1;i--)
	{
		int l=0,r=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]&&!l)l=j;
			if(a[j][i])r=j;
		}
		if(!l&&!r)vs=0;
		for(int k=l;k<=r;k++)
			if(!a[k][i])vs=0;
	}
//	if(vs)
//	{
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=m;j++)
//				cout<<(!a[i][j])<<" \n"[j==m];
//		puts("");
//	}
	return vs;
}
int id(int x,int y){return (x-1)*m+y;}
// 
const int xx=4122;
ll jiec[xx],ni[xx];
const int mod=998244353;
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
ll val1[2022],val2[2022];
ll calc(int n,int m)
{
	ll ans=0;
	for(int j=1;j<m;j++)
	{
		for(int i=1;i<n;i++)
			val1[i]=C(i+j-1,j)*C(n-i+j-1,j-1)%mod;
		for(int i=1;i<n;i++)
			val2[i]=C(n-i-1+m-j,m-j)*C(m-j-1+i,i)%mod;
		for(int i=n-1;i>=1;i--)val2[i]+=val2[i+1],val2[i]%=mod;
		for(int i=1;i<n;i++)ans+=val1[i]*val2[i],ans%=mod;
	}
	return ans*2;
}
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
int main(){
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
//	cout<<sizeof(f)/1024/1024<<"\n";
	n=read(),m=read();
	if(n>m)swap(n,m);
//	if(n*m<=20)
//	{
//		int ans=0;
//		for(int s=0;s<(1<<(n*m));s++)
//		{
//			for(int i=1;i<=n;i++)
//				for(int j=1;j<=m;j++)
//					a[i][j]=(s>>(id(i,j)-1)&1);
//			ans+=check();
//		}
//		cout<<ans<<'\n';
//		exit(0);
//	
	ll ans=(calc(n,m)+calc(m,n))%mod;
//	cout<<ans<<"\n";
	for(int j=1;j<m;j++)
	{
		for(int i=1;i<n;i++)
			val1[i]=C(i+j-1,j)*C(n-i+j-1,j-1)%mod;
		for(int i=1;i<n;i++)
			val2[i]=C(n-i-1+m-j,m-j)*C(m-j-1+i,i)%mod;
		for(int i=1;i<n;i++)ans+=mod-2*val1[i]*val2[i]%mod,ans%=mod;
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}