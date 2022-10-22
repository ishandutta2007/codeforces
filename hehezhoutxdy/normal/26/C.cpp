// Problem: C. Parquet
// Contest: Codeforces - Codeforces Beta Round #26 (Codeforces format)
// URL: https://codeforces.com/problemset/problem/26/C
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
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char f[103][103];
signed main()
{
	int n=read(),m=read(),a=read(),b=read(),c=read();
	if(n&m&1) puts("IMPOSSIBLE"),exit(0);
	if(n&1)
	{
		for(int j=1; j<m; j+=2)
			if(!a) puts("IMPOSSIBLE"),exit(0);
			else --a,f[n][j]=f[n][j+1]='a'+(n+j)%26;
	}
	if(m&1)
	{
		for(int i=1; i<n; i+=2)
			if(!b) puts("IMPOSSIBLE"),exit(0);
			else --b,f[i][m]=f[i+1][m]='a'+(i+m)%26;
	}
	int N=n,M=m;
	n-=n&1,m-=m&1;
	for(int i=1; i<n; i+=2)
		for(int j=1; j<m; j+=2)
			if(c) --c,f[i][j]=f[i][j+1]=f[i+1][j]=f[i+1][j+1]='a'+(i+j)%26;
			else if(a>1) a-=2,f[i][j]=f[i][j+1]='a'+(i+j)%26,f[i+1][j]=f[i+1][j+1]='a'+(i+j+1)%26;
			else if(b>1) b-=2,f[i][j]=f[i+1][j]='a'+(i+j)%26,f[i][j+1]=f[i+1][j+1]='a'+(i+j+1)%26;
			else puts("IMPOSSIBLE"),exit(0);
	for(int i=1; i<=N; ++i,puts(""))
		for(int j=1; j<=M; ++j)
			putchar(f[i][j]);
	return 0;
}