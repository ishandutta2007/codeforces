// Problem: B. Difference Array
// Contest: Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		map<int,int> mp;
		for(int i=1; i<=n; ++i) ++mp[read()];
		for(int i=1; i<n; ++i)
		{
			map<int,int> o;
			for(auto it=mp.begin();it!=mp.end();++it)
				if(it->second>1)o[0]+=it->second-1;
			for(auto it=mp.begin();next(it)!=mp.end();++it)
				++o[(next(it)->first)-(it->first)];
			swap(o,mp);
		}
		printf("%d\n",mp.begin()->first);
	}
	return 0;
}