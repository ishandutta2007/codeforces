// Problem: B. Integral Array
// Contest: Codeforces Round #775 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1648/problem/B
// Memory Limit: 512 MB
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
int a[2000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),c=read();
		for(int i=1; i<=c*2; ++i) a[i]=0;
		for(int i=1; i<=n; ++i) a[read()]=1;
		// sort(a+1,a+n+1);
		for(int i=1; i<=c*2; ++i) a[i]+=a[i-1];
		if(!a[1]) 
		{
			puts("No");
			continue;
		}
		bool flg=1;
		for(int i=2; i<=c; ++i) if(a[i]!=a[i-1])
		{
			for(int j=1; i*j<=c; ++j)
			{
				if(a[(j+1)*i-1]-a[i*j-1]>0&&a[j]==a[j-1])
				{
					flg=0;
					break;
				}
			}
			if(!flg) break;
		}
		if(flg) puts("Yes");
		else puts("No");
	}
	return 0;
}//////////////////////////////////////////////////////