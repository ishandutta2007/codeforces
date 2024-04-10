// Problem: E. Ehab and the Expected GCD Problem
// Contest: Codeforces - Codeforces Round #563 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1174/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
const int p=1e9+7;
int n=read(),m,f[1000003][21][2];
signed main()
{
	for(m=1; (1<<(m+1))<=n; ++m);
	f[1][m][0]=1;
	if((1<<(m-1))*3<=n) f[1][m-1][1]=1;
	for(int i=2; i<=n; ++i) 
		for(int j=0; j<=m; ++j)
			f[i][j][0]=
			(1ll*f[i-1][j][0]*((n>>j)-(i-1))
			+1ll*f[i-1][j+1][0]*((n>>j)-(n>>(j+1)))
			+1ll*f[i-1][j][1]*((n>>j)-(n>>j)/3))%p,
			f[i][j][1]=
			(1ll*f[i-1][j][1]*((n>>j)/3-(i-1))
			+1ll*f[i-1][j+1][1]*((n>>j)/3-(n>>(j+1))/3))%p;
	printf("%d\n",f[n][0][0]);
}