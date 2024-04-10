// Problem: F. Parametric MST
// Contest: CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],f1[1000003],f2[1000003];
int n;
pair<int,int> A[1000003];
int chk(int t)
{
	int l=2,r=n-1,R=1;
	while(l<=r)
	{
		int i=(l+r)>>1;
		if(t*a[1]+min((t+a[1])*a[i+1],(t+a[1])*a[n])<=
		t*a[i]+min((t+a[i])*a[i+1],(t+a[i])*a[n])) 
			R=i,l=i+1;
		else r=i-1;
	}
	int Q=min(R,lower_bound(a+1,a+n+1,-t)-a);
	__int128 res=0;
	res+=(__int128)t*f1[n-1];
	res+=(__int128)a[n]*f1[Q];
	res+=(__int128)a[1]*(f1[R]-f1[Q]);
	res+=(__int128)Q*t*a[n];
	res+=(__int128)(R-Q)*t*a[1];
	res+=(__int128)t*(f1[n-1]-f1[R]);
	res+=f2[R+1];
	//part 1:1~Q
	//t*a[i]+a[i]*a[n]+t*a[n]
	//Part 2:Q+1~R
	//t*a[i]+a[i]*a[1]+t*a[1]
	//part 3:R+1~n
	// t*a[i]+a[i]*a[i+1]+a[i+1]*t
	// printf("%lld %lld\n",t,(long long)res);
	return (long long)min(res,(__int128)2e18);
}
signed main()
{
	for(int T=read();T--;)
	{
		n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		sort(a+1,a+n+1);
		for(int i=1; i<=n; ++i) f1[i]=a[i];
		for(int i=1; i<=n; ++i) f1[i]+=f1[i-1];
		for(int i=1; i<n; ++i) f2[i]=a[i]*a[i+1];
		f2[n]=0;
		for(int i=n-1; i>=1; --i) f2[i]+=f2[i+1];
		int sum=0,minT=0,maxT=0;
		for(int i=1; i<=n; ++i) sum+=a[i];
		minT=sum+(n-2)*a[1],maxT=sum+(n-2)*a[n];		
		if(maxT<0||minT>0)
		{
			puts("INF");
			continue;
		}
		int ans=-2e18;
		for(int i=1; i<=n; ++i)
			ans=max(ans,chk(-a[i]));
		printf("%lld\n",ans);
	}
	return 0;
}