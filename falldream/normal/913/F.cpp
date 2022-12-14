#include<iostream>
#include<cstdio>
#define MN 2000
#define mod 998244353
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[MN+5],n,a,b,pw[MN+5],PW[MN+5],S[MN+5][MN+5],s[MN+5];
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;} 
inline int pow(int x,int k)
{
	int sum=1;
	for(;k;k>>=1,x=1LL*x*x%mod)
		if(k&1) sum=1LL*sum*x%mod;
	return sum;	
}
int main()
{
	n=read();a=read();b=read(); 
	pw[0]=PW[0]=1;
	a=1LL*a*pow(b,mod-2)%mod;b=(mod+1-a)%mod;
	for(int i=1;i<=MN;++i) pw[i]=1LL*pw[i-1]*a%mod,PW[i]=1LL*PW[i-1]*b%mod;
	S[0][0]=1;
	for(int i=0;i<=n;++i) 
		for(int j=0;j<=n;++j) 
		{
			if(j<n) R(S[i][j+1],1LL*S[i][j]*PW[i]%mod);
			if(i<n) R(S[i+1][j],1LL*S[i][j]*pw[j]%mod);
		}
	s[1]=1;
	for(int i=1;i<=n;++i)
	{
		s[i]=1;
		for(int j=1;j<i;++j) s[i]=(s[i]-1LL*s[j]*S[i-j][j]%mod+mod)%mod;
	}	
	for(int i=3;i<=n;++i)
	{
		for(int j=1;j<i;++j)
			R(f[i],1LL*(f[i-j]+(f[j]+j*(j-1)/2)%mod)*S[i-j][j]%mod*s[j]%mod);
		f[i]=1LL*(f[i]+1LL*s[i]*i*(i-1)/2%mod)*pow((1-s[i]+mod)%mod,mod-2)%mod;
	}
	printf("%d\n",(f[n]+n*(n-1)/2)%mod);
	return 0;
}