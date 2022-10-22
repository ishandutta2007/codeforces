// Problem: F. Colouring Game
// Contest: CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int sg[1000003];
char s[1000003];
signed main()
{
	sg[0]=sg[1]=0;
	for(int i=2; i<=100; ++i)
	{
		set<int> st;
		for(int j=0; j<=i-2; ++j)
			st.insert(sg[j]^sg[i-j-2]);
		while(st.find(sg[i])!=st.end()) ++sg[i];
	}
	for(int i=101; i<=1000000; ++i)
		sg[i]=sg[i-34];
	for(int T=read();T--;)
	{
		int n=read();
		scanf("%s",s+1);
		int A=0,B=0;
		s[n+1]=s[n];
		for(int i=1; i<=n; ++i)
			if(s[i]!=s[i+1])
			{
				int t=i,L=1;
				while(s[t]!=s[t+1]) ++t,++L;
				for(int j=i; j<=t; ++j)
					if(s[j]=='R') ++A;
					else --A;
				B^=sg[L];
				i=t;
			}
			else if(s[i]=='R') ++A;
			else --A;
		// if(B!=0) ++A; else --A;
		if(A>0) puts("Alice");
		else if(A<0) puts("Bob");
		else if(B!=0) puts("Alice");
		else puts("Bob");
	}
	return 0;
}