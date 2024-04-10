// Problem: C. XOR Triangle
// Contest: Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/C
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
char s[300003];
int n;
int f[300003][8][8];
//1,2,3
//
inline int F(int x)
{
	if(x==0||x==1||x==2||x==4) return x;
	return 7-x;
}
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	f[0][0][7]=1;
	for(int i=1; i<=n; ++i) 
	if(s[i]=='1')
	{
		for(int j=0; j<8; ++j)
			for(int k=0; k<8; ++k)
				for(int l=0; l<8; ++l)
					(f[i][j|F(l)][k&l]
					+=f[i-1][j][k])%=p;
	}
	else
	{
		for(int j=0; j<8; ++j)
			for(int k=0; k<8; ++k)
				for(int l=0; l<8; ++l) if((l&k)==0)
					(f[i][j|F(l)][k]
					+=f[i-1][j][k])%=p;
	}
	int ss=0;
	for(int i=0; i<8; ++i)
		ss=(ss+f[n][7][i])%p;
	printf("%lld\n",ss);
	return 0;
}