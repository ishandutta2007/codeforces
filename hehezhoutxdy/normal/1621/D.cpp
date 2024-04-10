// Problem: D. The Winter Hike
// Contest: Hello 2022
// URL: https://codeforces.com/contest/1621/problem/D
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
int a[503][503];
int b[503][503];
int c[503][503];
int f[503][503];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),N=n<<1;
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=N; ++j)
				b[i][j]=c[i][j]=a[i][j]=read();
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=N; ++j)
				b[i][j]+=b[i][j-1];
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=N; ++j)
				c[i][j]+=c[i-1][j];
		int ans=0;
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				ans+=a[i][j],ans+=a[i+n][j+n];	
				int s=1e18;
		vector<int> A={1,n},B={n+1,N};
		for(int i:A) for(int j:B) s=min(s,a[i][j]),s=min(s,a[j][i]);
		printf("%lld\n",ans+s);
	}
	return 0;
}