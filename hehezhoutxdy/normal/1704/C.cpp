// Problem: C. Virus
// Contest: CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
int a[1000003],b[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=m; ++i) a[i]=read();
		sort(a+1,a+m+1);
		for(int i=2; i<=m; ++i) b[i]=a[i]-a[i-1]-1;
		b[1]=(a[1]+n-a[m])-1;
		sort(b+1,b+m+1),reverse(b+1,b+m+1);
		int ans=m,c=0;
		for(int i=1; i<=m; ++i)
		{
			ans+=min(c*2,b[i]);
			b[i]-=c*2;
			if(b[i]>0) ++c,--b[i];
			if(b[i]==1) ++ans;
			else if(b[i]>1) ++ans,++c;
		}
		printf("%lld\n",ans);
	}
	return 0;
}