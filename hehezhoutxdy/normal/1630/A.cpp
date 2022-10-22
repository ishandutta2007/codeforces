// Problem: A. And Matching
// Contest: Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/contest/1630/problem/A
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
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),k=read();
		if(k==n-1) 
		{
			if(n==2||n==4) puts("-1");
			else
			{
				printf("0 1\n");
				printf("%lld %lld\n",n-1,n-2);
				printf("2 %lld\n",n-4);
				printf("3 %lld\n",n-3);
				for(int i=4; i<n/2; ++i) if(i!=k&&i!=n-1-k)
				printf("%lld %lld\n",i,n-1-i);
			}
		}
		else if(k)
		{
			for(int i=1; i<n/2; ++i) if(i!=k&&i!=n-1-k)
				printf("%lld %lld\n",i,n-1-i);
			printf("%lld %lld\n",n-1,k);
			printf("0 %lld\n",n-1-k);
		}
		else
		{
			for(int i=0; i<n/2; ++i) printf("%lld %lld\n",i,n-1-i);
		}
	}
	return 0;
}