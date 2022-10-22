// Problem: A. Declined Finalists
// Contest: Codeforces - MemSQL Start[c]UP 3.0 - Round 1
// URL: https://codeforces.com/problemset/problem/859/A
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[103];
signed main()
{
	int n=read(),mx=1;
	for(int i=1; i<=n;  ++i) {a[i]=read();if(a[i]>=mx) mx=a[i];}
	printf("%lld\n",max(mx-25,0ll));
	return 0;
}