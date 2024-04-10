// Problem: F. Juju and Binary String
// Contest: Codeforces - Codeforces Round #779 (Div. 2)
// URL: https://codeforces.com/contest/1658/problem/F
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
char s[1000003];
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		scanf("%s",s+1);
		int c0=0;
		for(int i=1; i<=n; ++i) c0+=s[i]=='1';
		if((m*c0)%n)
		{
			puts("-1");
			continue;
		}
		for(int i=1; i<=n; ++i)
			a[i]=s[i]-48,a[n+i]=s[i]-48;
		int N=n<<1;
		for(int i=1; i<=N; ++i) if(a[i]) a[i]=n-c0; else a[i]=-c0;
		for(int i=1; i<=N; ++i) a[i]+=a[i-1];
		int l=0,r=0;
		for(int i=m; i<=N; ++i)
			if(a[i-m]==a[i])
			{
				l=i-m+1,r=i;
				break;
			}
		assert(l);
		if(r<=n) puts("1"),printf("%lld %lld\n",l,r);
		else puts("2"),printf("%lld %lld\n",1ll,r-n),printf("%lld %lld\n",l,n);
	}
	return 0;
}