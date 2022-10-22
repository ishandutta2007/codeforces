// Problem: C. Representative Edges
// Contest: Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
		int n=read(),ans=n;
		for(int i=1; i<=n; ++i) a[i]=read();
				if(n<=2)
		{
			puts("0");
			continue;
		}
		for(int i=1; i<=n; ++i)
			for(int j=i+1; j<=n; ++j)
		{
			//d=(a[j]-a[i])/(j-i)
			int c=0;
			for(int k=1; k<=n; ++k)
				if((a[k]-a[i])*(j-i)==(a[j]-a[i])*(k-i)) ++c;
			ans=min(ans,n-c);
		}
		printf("%lld\n",ans);
	}
	return 0;
}