// Problem: F. Pairwise Modulo
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
const int N=300000,B=1024;
bool f[360003];
int bl1[5003],tr1[360003];
signed bl0[5003],tr0[360003];
inline void add(int x)
{
    f[x]=1;
	for(int i=x/B+1; i<B; ++i) ++bl0[i],bl1[i]+=x;
	int R=((x>>10)+1)<<10;
	for(int i=x; i<R; ++i) ++tr0[i],tr1[i]+=x;
	return ;
}
inline int query1(int l,int r)
{
	return bl1[r>>10]-bl1[(l-1)>>10]+tr1[r]-tr1[l-1];
}
inline signed query0(int l,int r)
{
	return bl0[r>>10]-bl0[(l-1)>>10]+tr0[r]-tr0[l-1];
}
signed main()
{
	int n=read(),ans=0,sum=0;
	for(int i=1; i<=n; ++i) 
	{
		int x=read();
		ans+=sum;
		ans+=x*(i-1);
		//smaller
		int T=sqrt(x);
		for(int j=1; j<T; ++j) (f[j])&&(ans-=(x/j)*j);
		for(int l=sqrt(x),r; l<x; l=r+1)
		{
			r=x/(x/l);
			if(r==x) r=x-1;
			ans-=query1(l,r)*(x/l);
		}
		//bigger
		for(int l=x; l<=N; l+=x)
			ans-=x*query0(l,N);
		add(x);
		sum+=x;
#undef local
#ifdef local
		printf("%lld",ans%10);
#endif
#ifndef local
		printf("%lld ",ans);
#endif
	}
	return 0;
}