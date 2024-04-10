// Problem: D. Flipping Range
// Contest: Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/contest/1630/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
////////////////////////////////////////////////////////////////////
//And in that light,I find deliverance.
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int A=read();
		if(A==1) A=0;
		for(int i=1; i<m; ++i) 
		{
			int x=read();
			if(x==1) A=0;
			else if(A!=0) A=__gcd(A,x);
		}
		// printf("%lld ",A);
		if(!A)
		{
			int ans=0;
			for(int i=1; i<=n; ++i) ans+=abs(a[i]);
			printf("%lld\n",ans);
			continue;
		}
		int ans=0,AAA=0,BBB=0;
		for(int i=1; i<=A; ++i)
		{
			int S=0,M=1e18,O=0,OO=0;
			for(int j=i; j<=n; j+=A)
			{
				if(a[j]<0) O^=1;
				else if(a[j]==0) OO=1;
				S+=abs(a[j]);
				M=min(M,abs(a[j]));
			}
			ans+=S;
			if(OO==0)
			{
				if(O) AAA+=M;
				else BBB+=M;
			}
		}
		printf("%lld\n",ans-min(AAA,BBB)*2);
	}
	return 0;
}