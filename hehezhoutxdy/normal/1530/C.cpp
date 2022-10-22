// Problem: C. Pursuit
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
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
int n;
bool check(int x)
{
	int X=(x+n)>>2;
	int sa=a[n]+x*100,sb=b[n];
	if(X<=n) sa-=a[X];
	else sa-=a[n],sa-=100*(X-n);
	if(X>x)
	{
		sb-=b[X-x];
	}
	return sa>=sb;
}
signed main()
{
	for(int T=read();T--;)
	{
		n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		for(int j=1; j<=n; ++j) b[j]=read();
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
		for(int i=1; i<=n; ++i) a[i]=a[i]+a[i-1];
		for(int j=1; j<=n; ++j) b[j]=b[j]+b[j-1];
		int l=0,r=1e9,ans=1e9;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))
			{
				ans=mid,r=mid-1;
			}
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}