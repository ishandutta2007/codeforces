// Problem: D. Turtles
// Contest: Codeforces - Codeforces Round #202 (Div. 1)
// URL: https://codeforces.com/contest/348/problem/D
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
const int p=1e9+7;
char s[3003][3003];
int f[3003][3003];
int F(int x1,int y1,int x2,int y2)
{
	memset(f,0,sizeof(f)),f[x1][y1-1]=1;
	for(int i=x1; i<=x2; ++i)
		for(int j=y1; j<=y2; ++j)
			if(s[i][j]=='.')
				f[i][j]=(f[i-1][j]+f[i][j-1])%p;
	return f[x2][y2];
}
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1);
	printf("%lld\n",(F(1,2,n-1,m)*F(2,1,n,m-1)+p-F(1,2,n,m-1)*F(2,1,n-1,m)%p)%p);
	return 0;
}