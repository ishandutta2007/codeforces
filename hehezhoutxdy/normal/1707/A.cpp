// Problem: A. Doremy's IQ
// Contest: Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		for(int i=1,cur=0; i<=n; ++i)
		{
			int x=a[n+1-i];
			if(cur>=x) a[n+1-i]=1;
			else if(cur<m) a[n+1-i]=1,++cur;
			else a[n+1-i]=0;
		}
		for(int i=1; i<=n; ++i) printf("%lld",a[i]);
		puts("");
	}
	return 0;
}