// Problem: B. Peculiar Movie Preferences
// Contest: Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[100003][5];
int len[100003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1);
		bool A=0;
		for(int i=1; i<=n; ++i)
		len[i]=strlen(s[i]+1),A|=(len[i]==1);
		if(A)
		{
			puts("YES");continue;
		}
		bool ff=0;
		map<int,bool> mp2,mp3;
		for(int i=1; i<=n; ++i)
		{
			bool f=1;
			int S=0,SS=0;
			for(int j=1; j<=len[i]; ++j) f&=(s[i][j]==s[i][len[i]+1-j]);
			for(int j=1; j<=2; ++j) S=S*1000+s[i][j];
			for(int j=len[i]; j>=len[i]-1; --j) SS=SS*1000+s[i][j];
			if(len[i]==2) {if(mp2[SS]||mp3[SS]) {ff=1; break;} }
			else if(mp2[SS]) {ff=1;break;}
			if(len[i]==2) mp2[S]=1; else mp3[S]=1;
			if(f) {ff=1;break;}
		}
		mp3.clear();
		for(int i=1; i<=n; ++i) if(len[i]==3)
		{
			bool f=1;
			int S=0,SS=0;
			for(int j=1; j<=len[i]; ++j) f&=(s[i][j]==s[i][len[i]+1-j]);
			for(int j=1; j<=3; ++j) S=S*1000+s[i][j];
			for(int j=3; j>=1; --j) SS=SS*1000+s[i][j];
			if(mp3[SS]) {ff=1; break;} else mp3[S]=1;
			if(f) {ff=1;break;}
		}
		if(ff) {puts("YES");continue;}
		puts("NO");
	}
	return 0;
}