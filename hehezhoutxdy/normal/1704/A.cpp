// Problem: A. Two 0-1 sequences
// Contest: CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/A
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char s[1003],t[1003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		scanf("%s",s+1);
		scanf("%s",t+1);
		bool f=1;
		for(int i=1; i<m; ++i)
			if(s[n+1-i]!=t[m+1-i])f=0;
			bool g=0;
		for(int i=1; i<=n-m+1; ++i)
			if(s[i]==t[1]) g=1;
		if(f&&g) puts("YES"); else puts("NO");
	}
	return 0;
}