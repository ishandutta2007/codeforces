// Problem: A. Color the Picture
// Contest: Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/A
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read(),k=read();
		for(int i=1; i<=k; ++i) a[i]=read();
		bool f3=0;
		for(int i=1; i<=k; ++i) if(a[i]>=n*m) f3=1;
		if(f3)
		{
			puts("Yes");continue;
		}
		bool f1=0,f2=0,o1=0,o2=0;
		int z1=0,z2=0;
		for(int i=1; i<=k; ++i)
		{
			int t=a[i]/n;
			if(t>2) o1=1;
			if(t>1) z1+=t;
		}
		for(int i=1; i<=k; ++i)
		{
			int t=a[i]/m;
			if(t>2) o2=1;
			if(t>1) z2+=t;
		}
		f1=(z1>=m),f2=(z2>=n);
		if(!o1&&(m&1)) f1=0;
		if(!o2&&(n&1)) f2=0; 
		if(m==3) f1=0; 
		if(n==3) f2=0;
		if(f1||f2) puts("Yes"); else puts("No");
	}
	return 0;
}