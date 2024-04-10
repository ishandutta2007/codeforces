// Problem: E. Power or XOR?
// Contest: Codeforces - Codeforces Round #785 (Div. 2)
// URL: https://codeforces.com/contest/1673/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1500003];
bool ans[1500003];
int F(int n,int m)
{
	//n,m
	m=max(m,0ll);
	if(n<m) return 0;
	if(m==0) return n==0;
	else return ((n-1)|(m-1))==(n-1);
}
signed main()
{
	int n=read(),k=read(),N=1<<20;
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=n; ++i)
		for(int j=i,cst=0,sum=0,mul=a[i]; 
		sum<=30&&((1ll<<sum)*mul)<N&&j<=n; 
		++j,++cst,sum+=a[j])
			if(F(n-1-cst-(i!=1)-(j!=n),k-(i!=1)-(j!=n)))
				ans[(1ll<<sum)*mul]^=1;
	for(int i=N-1; i>=0; --i) if(ans[i]) 
	{
		for(int j=i; j>=0; --j) putchar(48+ans[j]);
		return 0;
	}
	puts("0");
	return 0;
}
//(2^a)^(2^b)=2^(a2^b)
//(2^(a2^b))^(2^c)=2^(a2^(b+c))