// Problem: A. Search for Pretty Integers
// Contest: Codeforces - Technocup 2018 - Elimination Round 2
// URL: https://codeforces.com/problemset/problem/870/A
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[33],b[33];
signed main()
{
	int n=read(),m=read();
	int s=10,t=10,S=10;
	for(int i=1; i<=n; ++i) a[i]=read(),s=min(s,a[i]);
	for(int j=1; j<=m; ++j) b[j]=read(),t=min(t,b[j]);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(a[i]==b[j]) S=min(S,a[i]);
	if(S<10) printf("%d\n",S);
	else printf("%d%d\n",min(s,t),max(s,t));
	return 0;
}