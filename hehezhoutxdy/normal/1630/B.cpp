// Problem: B. Range and Partition
// Contest: Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/contest/1630/problem/B
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
int c[1000003],a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),k=read(),ans=n+100,ll=0,rr=n+100;
		for(int i=1; i<=n; ++i) c[i]=0;
		for(int i=1; i<=n; ++i) ++c[a[i]=read()];	
		for(int l=1,r=1,s=-n; r<=n; ++r)
		{
			s+=c[r]*2;
			while(s-k>=c[l]*2) s-=c[l]*2,++l;
			if(s>=k&&r-l<ans) ans=r-l,ll=l,rr=r; 
		}
		printf("%lld %lld\n",ll,rr);
		for(int i=1,s=0,lst=1,cc=0; i<=n; ++i)
		{
			if(ll<=a[i]&&a[i]<=rr) ++s; else --s;
			if((cc+1<k||i==n)&&s>0)
			{
				printf("%lld %lld\n",lst,i);
				lst=i+1,++cc,s=0;
			}
			if(i==n) assert(cc==k);
		}
	}
	return 0;
}