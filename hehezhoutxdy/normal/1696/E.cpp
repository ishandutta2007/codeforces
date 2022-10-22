// Problem: E. Placing Jinas
// Contest: Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int fac[1000003],ifac[1000003],ff[1000003],iff[1000003];
signed main()
{
	int n=read(),ans=read();
	fac[0]=ifac[0]=1;
	for(int i=1; i<=500000; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int i=1; i<=n; ++i)
	{
		int x=read();
		if(!x) continue;
		ans=(ans+fac[x+i]*ifac[x-1]%p
		*ifac[i]%p*qp(i+1,p-2)%p)%p;
	}
	printf("%lld\n",ans);
	return 0;
}