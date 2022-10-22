// Problem: B. Railway System
// Contest: Codeforces - Codeforces Round #796 (Div. 1)
// URL: https://codeforces.com/contest/1687/problem/B
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
int a[100003];
pair<int,int> p[100003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=m; ++i)
	{
		printf("? ");
		for(int ii=1; ii<=m; ++ii) 
			if(i==ii) printf("1");
			else printf("0");
		puts(""),fflush(stdout);
		p[i].first=read(),p[i].second=i;
	}
	sort(p+1,p+m+1);
#define lst official
	int official=0;
	for(int i=1; i<=m; ++i)
	{
		a[p[i].second]=1;
		printf("? ");
		for(int j=1; j<=m; ++j) printf("%lld",a[j]);
		puts(""),fflush(stdout);
		int w=read();
		if(w-lst!=p[i].first) a[p[i].second]=0;
		else official=w;
	}
	printf("! %lld\n",official);
	return 0;
}