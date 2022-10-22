// Problem: D. Magical Array
// Contest: CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int a[1000003];
__int128 f[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i)
		{
			__int128 sp=0;
			int pre=0;
			for(int j=1; j<=m; ++j)
				pre+=read(),sp+=pre;
			f[i]=sp;
		}
		int ovo=0;
		for(int i=2; i<=n; ++i) if(f[i]!=f[1])
		{ovo=i;break;} 
		int qwq=2;
		if(ovo==2) qwq=3;
		if(f[1]==f[qwq])
		{printf("%lld %lld\n",ovo,(int)(f[1]-f[ovo]));}
		else printf("1 %lld\n",(int)(f[ovo]-f[1]));
	}
	return 0;
}