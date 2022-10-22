// Problem: F. Fruit Sequences
// Contest: Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1428/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
char s[1000003];
int f[1000003];
ll ans,t;
signed main()
{
	int n=read();
	scanf("%s",s+1);
	for(int i=1,x=0; i<=n; ++i,ans+=t) 
		if(s[i]=='1') t+=f[x],t+=++x,f[x]+=f[x-1],f[x-1]=0;
		else
		{
			for(int j=0; j<=x; ++j) ++f[j];
			x=0;
		}
	printf("%lld\n",ans);
	return 0;
}