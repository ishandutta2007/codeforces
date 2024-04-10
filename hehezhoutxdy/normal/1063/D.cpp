// Problem: A. Candies for Children
// Contest: Codeforces - Z Flip #define insert push_back(3)
// URL: https://codeforces.com/gym/376169/problem/A
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
	int n=read(),l=read(),r=read(),k=read(),ans=-1,d=(n+r-l+1)%n;
	if(n==k&&d==0) ans=1;
	for(int l=0,r=0; l<=n; l=r+1)
	{
		if(k/(n+l)==0)
		{
			r=n;
			int m=k-d;
			if(m<0||m>d) break;
			int L=k-d;
			int R=n+k-d*2;
			L=max(L,l),R=min(R,r);
			if(L<=R) ans=max(ans,R);
			break;
		}
		r=min(k/(k/(n+l)),n*2)-n;
		int g=k/(n+l);
		int L=ceil(max(1.0L*(k-d*2-g*n)/g,1.0L*(k-d-g*n)/(g+1)));
		int R=floor(min(1.0L*(k-d-g*n)/g,1.0L*(k-d*2+n-g*n)/(g+1)));
		L=max(L,l),R=min(R,r);
		if(L<=R) ans=max(ans,R);
	}
	++k;
	for(int l=0,r=0; l<=n; l=r+1)
	{
		if(k/(n+l)==0)
		{
			r=n;
			int m=k-d;
			if(m<0||m>d) break;
			int L=k-d;
			int R=n+k-d*2;
			L=max(L,l),R=min(R,r);
			if(L<=R) ans=max(ans,R);
			break;
		}
		r=min(k/(k/(n+l)),n*2)-n;
		int g=k/(n+l);
		int L=ceil(max(1.0L*(k-d*2-g*n)/g,1.0L*(k-d-g*n)/(g+1)));
		int R=floor(min(1.0L*(k-d-g*n-1)/g,1.0L*(k-d*2+n-g*n)/(g+1)));
		L=max(L,l),R=min(R,r);
		if(L<=R) ans=max(ans,R);
	}
	
	printf("%lld\n",ans);
	return 0;
}