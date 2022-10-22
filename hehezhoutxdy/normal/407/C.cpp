// Problem: C. Curious Array
// Contest: Codeforces - Codeforces Round #239 (Div. 1)
// URL: https://codeforces.com/problemset/problem/407/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int a[103][100003],f[103][100003];
signed main()
{
	int n=read(),T=read();
	for(int i=1; i<=n; ++i) a[0][i]=read();
	for(int i=0; i<=n; ++i) f[0][i]=1;
	for(int i=1; i<=100; ++i)
	{
		f[i][0]=1;
		for(int j=1; j<=n; ++j)
			f[i][j]=(f[i-1][j]+f[i][j-1])%p;
	}
	for(int i=0; i<=100; ++i)
		for(int j=1; j<=n; ++j)
			f[i][j]=(f[i][j-1]+f[i][j])%p;		
	for(int i=n; i>=1; --i) a[0][i]=(p+a[0][i]-a[0][i-1])%p;
	for(int l,r,k; T--;)
	{
		l=read(),r=read(),k=read(),++a[k][l];
		for(int i=0; i<k; ++i)
			a[i][r+1]=(p+a[i][r+1]-f[k-i-1][r-l])%p;
		a[k][r+1]=(p+a[k][r+1]-1)%p;
	}
	for(int i=100; i>=1; --i)
		for(int j=1; j<=n; ++j)
			a[i][j]=(a[i][j]+a[i][j-1])%p,a[i-1][j]=(a[i-1][j]+a[i][j])%p;
	for(int i=1; i<=n; ++i) 
		a[0][i]=(a[0][i]+a[0][i-1])%p,printf("%d ",a[0][i]);
	return 0;
}