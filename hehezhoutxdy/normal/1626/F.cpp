// Problem: F. A Random Code Problem
// Contest: Codeforces - Educational Codeforces Round 121 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1626/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
int dp[20][1000003];
signed main()
{
	int n=read(),a0=read(),x=read(),y=read(),k=read(),M=read(),z=qp(n,p-2);
	for(int i=k-1; i>=1; --i)
		for(int j=0; j<720720; ++j)
			dp[i][j]=(dp[i+1][j]*z%p*(n-1)+dp[i+1][(j/i)*i]*z+(j%i)*(k-i)%p*z%p*z)%p;
	int ans=0;
	for(int a=a0,T=n; T--; a=(a*x+y)%M)
		ans=(ans+a*k%p*z+p-dp[1][a%720720])%p;
	printf("%lld\n",ans*qp(n,k)%p);
	return 0;
}