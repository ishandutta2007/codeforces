// Problem: H. Zigu Zagu
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/H
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
char s[1000003];
int f[1000003],g[1000003];
signed main()
{
	int n=read(),m=read();
	scanf("%s",s+1);
	for(int i=2; i<=n; ++i) 
		f[i]=f[i-1]+(s[i]=='0'&&s[i-1]=='0'),
		g[i]=g[i-1]+(s[i]=='1'&&s[i-1]=='1');
	for(int l,r; m--;)
		l=read(),r=read(),printf("%d\n",max(f[r]-f[l],g[r]-g[l])+1);
	return 0;
}