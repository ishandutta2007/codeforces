#include<bits/stdc++.h>
#define ll long long 
#define dd double
#define u unsigned
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
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
const int xx=505,dlt=124753+500;
int n,mod,f[xx][xx*xx+500+500+10];
ll sum[xx*xx+500+500+10];
// xy+dlt() 
//xy 
//x->=t 
ll jc[xx];
int main(){
//	cout<<xx*xx+500+500<<"\n";
//	int res=0;
//	for(int i=1;i<=500;i++)
//	{
//		f[i].resize(i*i*2+10);
//		res+=i*i*2;
//	}
//	cout<<res<<"\n";
//	return 0;
//	cout<<(sizeof(f)+sizeof(sum))/1024/1024<<"\n";
	n=read(),mod=read();
	f[1][0+dlt]=1;
	for(int i=2;i<=n;i++)
	{
		int L=dlt-i*(i-1)/2,R=dlt+i*(i-1)/2;
		for(int j=L-i;j<=R+i;j++)// 
		{
			sum[j]=f[i-1][j];
			if(j)sum[j]+=sum[j-1];
			sum[j]>=mod?sum[j]-=mod:0;
		}
		for(int j=L;j<=R;j++)
		{
			f[i][j]=((sum[j]-sum[j-i]+mod)*(i-j+mod)+f[i][j])%mod;
			f[i][j]=((sum[j+i-1]-sum[j]+mod)*(i+j)+f[i][j])%mod;
		}
		for(int j=L-i;j<=R+i;j++)// 
		{
			sum[j]=1ll*f[i-1][j]*j%mod;
			if(j)sum[j]+=sum[j-1];
			sum[j]>=mod?sum[j]-=mod:0;
		}
		for(int j=L;j<=R;j++)
		{
			f[i][j]=((sum[j]-sum[j-i]+mod)+f[i][j])%mod;
			f[i][j]=((sum[j+i-1]-sum[j]+mod)*(mod-1)+f[i][j])%mod;
		}
//		cerr<<i<<"\n";
		
		
//		if(i!=1)
//		{
//			for(int j=1;j<=i*i;j++)
//				//0~i-1
//				f[i][j]+=(f[i-1][j]-f[i-1][j-i]+mod)%mod,f[i][j]%=mod;
//		}
//		for(int j=1;j<=n*n;j++)f[i][j]+=f[i][j-1],f[i][j]%=mod;
	}
	
//	puts("QWEQ");
	for(int i=1;i<=n;i++)
		for(int j=256025;j>=0;j--)
		{
//			if(f[i][j])cout<<i<<" "<<j-dlt<<" "<<f[i][j]<<"\n";
			f[i][j]+=f[i][j+1];
			f[i][j]>=mod?f[i][j]-=mod:0;
		}
//	return 0;
//	puts("qWEQ");
	ll ans=0;
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*(n-i+1)%mod;
	for(int i=2;i<=n;i++)// 
	{
		for(int j=0;j<i;j++)
			for(int k=j+1;k<i;k++)// 
				ans+=f[i-1][k-j+1+dlt]*jc[n-i],ans%=mod;
//		cerr<<i<<"\n";
//		for(int j=0;j<=n*n;j++)
//			if(j>n)sum[i][n]+=1ll*(f[i][j]-f[i][j-1]+mod)*f[i][j-n]%mod,sum[i][n]%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}