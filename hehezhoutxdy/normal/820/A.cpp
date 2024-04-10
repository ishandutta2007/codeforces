// Problem: A. Mister B and Book Reading
// Contest: Codeforces - Codeforces Round #421 (Div. 2)
// URL: https://codeforces.com/problemset/problem/820/A
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
signed main()
{
	int a=read(),b=read(),c=read(),d=read(),e=read();
	int t=1,ans=b,res=1;
	while(ans<a)
	{
		ans+=min(b+(d*t),c)-e;
		++t,++res;
	}
	printf("%lld\n",res);
	return 0;
}