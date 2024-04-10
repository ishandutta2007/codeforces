// Problem: F1. Array Shuffling
// Contest: Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/F1
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
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
pair<int,int> a[1000003],b[1000003];
int A[1000003],B[1000003],deg[1000003];
vector<int> e[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=make_pair(A[i]=read(),i);
		sort(a+1,a+n+1);
		for(int i=1; i<=n; ++i) e[i].clear(),deg[i]=0;
		int sz=0;
		for(int i=1; i<=n; ++i)
		{
			int z=i,g=1;
			++sz;
			while(i<n&&a[i].first==a[i+1].first) ++i,++g;
			b[sz]=make_pair(g,a[i].first);
		}
		sort(b+1,b+sz+1);
		for(int i=1; i<=n; ++i) B[i]=read();
		int o=b[sz].second;
		// printf("%d\n",o);
		for(int i=1; i<=n; ++i) if(A[i]!=o) 
			// printf("%d %d\n",A[i],B[i]),
			++deg[B[i]],e[A[i]].push_back(B[i]);
		queue<int> q;
		int qwq=0;
		for(int i=1; i<=n; ++i) if(!deg[i]) q.push(i);
		while(!q.empty())
		{
			int x=q.front();
			++qwq,q.pop();
			for(int y:e[x]) if(!--deg[y]) q.push(y);
		} 
		if(qwq==n) puts("AC"); else puts("WA");
	}
	return 0;
}