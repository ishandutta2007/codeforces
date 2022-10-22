// Problem: A. Great Sequence
// Contest: Codeforces - Codeforces Round #773 (Div. 1)
// URL: https://codeforces.com/contest/1641/problem/0
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
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read(),ans=n;
		map<int,int> mp;
		for(int i=1; i<=n; ++i) ++mp[read()];
		for(auto i:mp)
		{
		    if(i.second==0) continue;
			int z=min(mp[i.first*m],mp[i.first]);
			if(!z) continue;
			ans-=z*2;
			mp[i.first*m]-=z;
		}
		printf("%lld\n",ans);
	}
	return 0;
}