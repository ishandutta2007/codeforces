// Problem: C. Penalty
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
char s[13];
signed main()
{
	for(int T=read();T--;)
	{
		scanf("%s",s);
		int ans1=10,ans2=10;
		for(int i=0,c0=5,c1=5,s0=0,s1=0; i<10; ++i) 
		if(i&1)
		{
			if(s[i]=='1') ++s1;
			--c1;
			if(s0>s1+c1){ans1=i+1;break;}
		}
		else
		{
			if(s[i]!='0') ++s0;
			--c0;
			if(s0>s1+c1){ans1=i+1;break;}
		}
		for(int i=0,c0=5,c1=5,s0=0,s1=0; i<10; ++i) 
		if(!(i&1))
		{
			if(s[i]=='1') ++s1;
			--c1;
			if(s0>s1+c1){ans2=i+1;break;}
		}
		else
		{
			if(s[i]!='0') ++s0;
			--c0;
			if(s0>s1+c1){ans2=i+1;break;}
		}
		printf("%lld\n",min(ans1,ans2));
	}
	return 0;
}