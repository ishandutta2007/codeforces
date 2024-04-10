// Problem: A. Weird Sum
// Contest: Codeforces - Codeforces Round #775 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1648/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
vector<int> a[100003],b[100003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			int x=read();
			a[x].push_back(i);
			b[x].push_back(j);
		}
		int ans=0;
	for(int i=1; i<=100000; ++i)
	{
		sort(a[i].begin(),a[i].end());
		sort(b[i].begin(),b[i].end());
		int N=(int)a[i].size();
		if(N<=1) continue;
		for(int ii=0; ii+1<N; ++ii)
		{
			ans+=(ii+1)*(N-ii-1)*(a[i][ii+1]-a[i][ii]);
			ans+=(ii+1)*(N-ii-1)*(b[i][ii+1]-b[i][ii]);
		}
	}
	printf("%lld\n",ans);
	return 0;////////////////////
}