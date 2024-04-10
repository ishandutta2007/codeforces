// Problem: D1. Game on Sum (Easy Version)
// Contest: Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/D1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7,h=(p+1)>>1;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int hh[1000003],fac[1000003],ifac[1000003];
signed main()
{
	const int N=1000000;
	hh[0]=fac[0]=ifac[0]=1;
	for(int i=1; i<=N; ++i) hh[i]=hh[i-1]*h%p;
	for(int i=1; i<=N; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int T=read();T--;)
	{
		int n=read(),m=read(),k=read();
		if(n==m) printf("%lld\n",n*k%p);
		else{int ans=0;
		for(int i=1; i<=m; ++i) ans=(ans+hh[n-i]*fac[n-1-i]%p*ifac[m-i]%p*i%p)%p;
		printf("%lld\n",ans*ifac[n-1-m]%p*k%p);
		}
	}
	return 0;
}//////////////