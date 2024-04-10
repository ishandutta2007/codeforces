#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
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
const int mod=998244353;
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
int n,p,_p;
const int xx=2005;
int g[xx][xx],f[xx],F[xx];
int pwp[xx],pw_p[xx],a,b;
void ad(int &a,int b){(a+=b)>=mod?a-=mod:a;}
signed main(){
	n=read(),a=read(),b=read();
	p=1ll*a*ksm(b,mod-2)%mod;
	_p=(1+mod-p)%mod;
	pwp[0]=1;
	for(int i=1;i<=n;i++)pwp[i]=1ll*pwp[i-1]*p%mod;
	pw_p[0]=1;
	for(int i=1;i<=n;i++)pw_p[i]=1ll*pw_p[i-1]*_p%mod;
	for(int i=0;i<=n;i++)g[i][0]=1;
	//p_p 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			g[i][j]=(1ll*g[i-1][j]*pwp[j]%mod+1ll*g[i-1][j-1]*pw_p[i-j])%mod;
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<=i-1;j++)
			ad(f[i],mod-1ll*f[j]*g[i][j]*1%mod);
	}
//	cerr<<" "<<g[2][1]<<"WWads\n";
//	for(int i=1;i<=n;i++)cout<<i<<" "<<f[i]<<"!\n";
	F[1]=0;
	for(int i=2;i<=n;i++)
	{
		F[i]=1ll*i*(i-1)/2%mod*f[i]%mod;
		for(int j=1;j<i;j++)
		{
			ad(F[i],1ll*f[j]*g[i][j]%mod*(F[j]+F[i-j]+1ll*j*(i-j)%mod+1ll*j*(j-1)/2%mod)%mod);
//			if(i==2)cerr<<j<<" "<<1ll*f[j]*g[i][j]%mod*(F[j]+F[i-j]+1ll*j*(i-j)%mod+1ll*j*(j-1)/2%mod)%mod<<"@\n";
		}
//		cerr<<i<<" "<<F[i]<<"ASD\n";
		F[i]=1ll*F[i]*ksm(1+mod-f[i],mod-2)%mod;
	}
	cout<<F[n]<<"\n";
	pc('1',1);
	return 0;
}