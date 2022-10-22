//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s;
}
const int N=4000000;
int a[4000003],v[4000003],f[4000003];
int fac[4000003],ifac[4000003];
const int p=1019260817;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=1ll*t*t%p) if(y&1) res=1ll*res*t%p;
	return res;
}
int C(int n,int m)
{
	if(m<0||m>n) return 0;
	return 1ll*fac[n]*ifac[m]%p*ifac[n-m]%p;
}
signed main()
{
	int n=read(),s=0;
	for(int i=1; i<=n; ++i) s=__gcd(s,a[i]=read());
	for(int i=1; i<=n; ++i)	++v[a[i]/=s];
	if(s>1) puts("-1"),exit(0);
	if(v[1]) puts("1"),exit(0);
	int N_=4000000/s,N=0;
	for(int i=1; i<=N_; ++i) if(v[i])
	{
		v[i]=1,N=i;
		for(int j=2; i*j<=N_; ++j) v[i*j]=0;
	} 
	fac[0]=ifac[0]=1;
	for(int i=1; i<=N; ++i) fac[i]=1ll*fac[i-1]*i%p;
	ifac[N]=qp(fac[N],p-2);
	for(int i=N-1; i>=1; --i) ifac[i]=1ll*ifac[i+1]*(i+1)%p;
	for(int i=1; i<=N; ++i) if(!v[i])
		for(int j=2; i*j<=N; ++j)
			v[i]+=v[i*j];
	for(int k=2; ; ++k)
	{
		for(int i=N; i>=1; --i) if(v[i])
		{
			f[i]=C(v[i],k);
			for(int j=2; i*j<=N; ++j)
				f[i]=(f[i]+p-f[i*j])%p;
		}
		if(f[1]) printf("%d\n",k),exit(0);
	}
	return 0;
}