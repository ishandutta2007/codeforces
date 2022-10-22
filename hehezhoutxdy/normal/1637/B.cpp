// Problem: B. MEX and Array
// Contest: Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/B
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
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int ans=0;
		for(int i=1; i<=n; ++i)
		{
			int s=0;
			for(int j=i; j<=n; ++j)
			{
				++s;
				if(a[j]==0) ++s;
				ans+=s;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}