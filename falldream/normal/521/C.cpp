#include<iostream>
#include<cstdio>
#define MN 100000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5];
int P[MN+5],inv[MN+5],p[10][MN+5],n,K,ans=0;
inline int C(int n,int m){return n<m?0:1LL*P[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	n=read();K=read();scanf("%s",st+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<10;++j)p[j][i]=p[j][i-1];
		++p[st[i]-'0'][i];	
	}
	if(!K)
	{
		for(int i=1;i<=n;++i) ans=(10LL*ans+st[i]-'0')%mod;
		return 0*printf("%d",ans);
	}
	P[0]=inv[0]=P[1]=inv[1]=1;
	for(int i=2;i<=n;++i) P[i]=1LL*P[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;++i) inv[i]=1LL*inv[i-1]*inv[i]%mod;
	for(int i=1;i<10;++i)
		for(int j=1,k=i;j<=n-K;++j,k=10LL*k%mod)
		{
			ans=(ans+1LL*k*p[i][n-j]%mod*C(n-j-1,K-1))%mod; 
			if(st[n-j+1]==i+'0') ans=(ans+1LL*k*C(n-j,K))%mod;
		}
	cout<<ans;
	return 0;
}