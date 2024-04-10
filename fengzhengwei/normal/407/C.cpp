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
const int mod=1e9+7,xx=1e5+5;
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
ll cf[xx][105],a[xx];
ll C(int n,int m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
int main(){
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	int n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read(),s=read();
		cf[l][103-s-1]++;
//		cout<<100-s-1<<"\n";
		for(int j=103-s-1;j<103;j++)cf[r+1][j]+=mod-C(r+1-l+j-(103-s-1)-1,j-(103-s-1)),cf[r+1][j]%=mod;
	}
	for(int j=0;j<103;j++)
		for(int i=1;i<=n;i++)cf[i][j]+=cf[i-1][j],cf[i][j]%=mod,cf[i][j+1]+=cf[i][j];
	for(int i=1;i<=n;i++)cout<<(cf[i][103]+a[i])%mod<<" \n"[i==n];
	return 0;
}