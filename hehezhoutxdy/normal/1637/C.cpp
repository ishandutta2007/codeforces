// Problem: C. Andrew and Stones
// Contest: Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/C
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
		int n=read();
		for(int i=1; i<=n; ++i)a[i]=read();
		if(n==3)
		{
			if(a[2]&1) puts("-1"); else 
			printf("%lld\n",a[2]>>1);
			continue;
		}
		int ans=0,cnt=0,ff=0,f=0;
		for(int i=2; i<n; ++i)
		{
			if(a[i]>1) f=1;
			if(a[i]==1) ff=1;
			ans+=(a[i]+1)>>1;
		}
		if(ff&&!f) puts("-1");
		else printf("%lld\n",ans);
	}
	return 0;
}