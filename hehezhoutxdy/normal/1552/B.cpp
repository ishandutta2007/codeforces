// Problem: B. Running for Gold
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/B
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
int a[100003][13];
bool win(int x,int y)
{
	int c=0;
	for(int i=1; i<=5; ++i)c+=(a[x][i]<a[y][i]);
	return c>=3;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),ans=1;
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=5; ++j) 
			{
				a[i][j]=read();
				
			}
		int f=1;
		for(int i=2; i<=n; ++i) if(win(i,ans)) ans=i;
		for(int i=1; i<=n; ++i) if(win(i,ans)) f=0;
		if(f) printf("%lld\n",ans);
		else puts("-1");
	}
	return 0;
}