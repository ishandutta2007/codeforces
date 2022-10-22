// Problem: F. Minimal String Xoration
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/problemset/problem/1654/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int rk[1000003],a[1000003];
ll val[1000003];
char s[1000003];
signed main()
{
	int n=read(),N=1<<n,cnt=0;
	scanf("%s",s);
	for(int i=0; i<N; ++i) rk[i]=s[i];
	for(int i=0; i<N; ++i) a[i]=i;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<N; ++j)
			val[j]=((ll)rk[j]<<32)|rk[j^(1<<i)];
		sort(a,a+N,[&](int x,int y){return val[x]<val[y];});
		rk[a[0]]=0;
		for(int j=1; j<N; ++j) 
			rk[a[j]]=val[a[j-1]]==val[a[j]]?rk[a[j-1]]:j;
	}
	int ans=a[0];
	for(int i=0; i<N; ++i) putchar(s[i^ans]);
	return 0;
}