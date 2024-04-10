// Problem: B. Prefix Removals
// Contest: Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/B
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
char s[1000003];
int c[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=0; i<256; ++i) c[i]=0;
		for(int i=1; i<=n; ++i) ++c[s[i]];
		int x=1;
		while(x<=n&&c[s[x]]>1) --c[s[x]],++x;
		for(int i=x; i<=n; ++i) putchar(s[i]);
		puts("");
	}
	return 0;
}