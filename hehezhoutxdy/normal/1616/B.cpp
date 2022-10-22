// Problem: B. Mirror in the String
// Contest: Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/B
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
char s[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		scanf("%s",s+1);
		int ans=1;
		for(int i=2; i<=n&&i<=ans*2; ++i) if(s[i]>s[i-1]) break;
		else if(s[i]==s[i-1])
		{
			if(s[i]!=s[1]) ans=i;
		}
		else ans=i;
		for(int i=1; i<=ans; ++i) putchar(s[i]);
		for(int i=ans; i>=1; --i) putchar(s[i]);
		puts("");
	}
	return 0;
}