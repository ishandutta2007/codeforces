// Problem: C. Paint the Middle
// Contest: Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/contest/1630/problem/C
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
pair<int,int> a[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i)
	{
		int x=read();
		if(!a[x].first) a[x].first=a[x].second=i;
		else a[x].second=i;
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1,lst=0; i<=n; ++i) if(a[i].first<a[i].second)
	{
		if(a[i].first<lst) 
		{
			int Q=a[i].second;
			while(i<n&&a[i+1].first<lst) ++i,Q=max(Q,a[i].second);
			if(Q>lst){
			ans+=Q-lst-1;
			lst=Q;}
		}
		else if(a[i].first<a[i].second)
		{
			ans+=a[i].second-a[i].first-1;
			lst=a[i].second;
		}
		// printf("%lld %lld\n",a[i].first,a[i].second);
		// printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
}