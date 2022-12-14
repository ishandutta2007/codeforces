#include<bits/stdc++.h>
#define MN 1000000
#define N 1048576
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5],p[MN+5],T[N*2+5],ans,s;
inline int All(int x){return 1LL*x*(x-1)/2%mod*p[x]%mod*(mod+1)/2%mod;}
inline void Mod(int x){for(T[x+=N]=1;x>>=1;)++T[x];}
inline int Query(int l,int r)
{
	int res=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) res+=T[l+1];
		if( r&1) res+=T[r-1];
	}
	return res;
}
int main()
{
	n=read();p[0]=1;
	for(int i=1;i<=n;++i) p[i]=1LL*p[i-1]*i%mod,a[i]=read();
	for(int i=1;i<=n;++i)
	{
		int downnum=Query(1,a[i]),rk=a[i]-downnum-1;
		ans=(ans+1LL*(rk-1)*rk/2%mod*p[n-i])%mod; 
		ans=(ans+1LL*rk*All(n-i))%mod;
		ans=(ans+1LL*rk*p[n-i]%mod*s)%mod;
		s=(s+rk)%mod;Mod(a[i]);
	}
	cout<<(ans+s)%mod;
	return 0;
}