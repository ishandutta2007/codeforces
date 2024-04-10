// Problem: C. Fishingprince Plays With Array
// Contest: Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/C
// Memory Limit: 512 MB
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003],b[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int k=read();
		for(int i=1; i<=k; ++i) b[i]=read();
		int l=1,r=1;
		int lx=0,ly=0,rx=0,ry=0;
		while(1)
		{
			int ovo=0;
			if(!lx&&l<=n) 
			{
				lx=1,ly=a[l++];
				while(ly%m==0) ly/=m,lx*=m;
				ovo=1;
			}
			if(!rx&&r<=k)
			{
				rx=1,ry=b[r++];
				while(ry%m==0) ry/=m,rx*=m;
				ovo=1;
			}
			if(ly==ry)
			{
				int A=min(lx,rx);
				lx-=A,rx-=A;
			}
			if(!ovo) break;
		}
		if(lx==rx&&lx==0) puts("Yes"); else puts("No");
	}
	return 0;
}