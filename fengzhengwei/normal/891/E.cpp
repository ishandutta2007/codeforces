#include<bits/stdc++.h>
#define ll long long 
//#define int long long 
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;else if(c==EOF)assert(0);
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
	wt(x),pc(op,0);
}
const int xx=5e3+5,mod=1e9+7;
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
int n,m,f[xx][xx];
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
int jc[xx],a[xx];
signed main(){
	n=read(),m=read();
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*(m-i+1)%mod;
	for(int i=1;i<=n;i++)a[i]=read();
	f[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
			ad(f[i+1][j+1],mod-f[i][j]);
		for(int j=0;j<=i;j++)
			ad(f[i+1][j],1ll*a[i+1]*f[i][j]%mod);
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		if(m<i)continue;
//		cout<<f[n][i]<<" "<<i<<"@\n";
		ad(ans,1ll*jc[i]*f[n][i]%mod*ksm(n,m-i)%mod);
	}
	int re=1;
	for(int i=1;i<=n;i++)re=1ll*re*a[i]%mod;
	cout<<(1ll*re-1ll*ans%mod*ksm(ksm(n,m),mod-2)%mod+mod)%mod<<"\n";
	pc('1',1);
	return 0;
}