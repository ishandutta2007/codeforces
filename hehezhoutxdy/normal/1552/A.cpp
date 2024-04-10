// Problem: A. Subsequence Permutation
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
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
char s[100003],t[100003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		scanf("%s",s+1);
		for(int i=1; i<=n; ++i) t[i]=s[i];
		sort(s+1,s+n+1);
		int c=0;
		for(int i=1; i<=n; ++i) if(s[i]!=t[i]) ++c;
		printf("%lld\n",c);
	}
	return 0;
}