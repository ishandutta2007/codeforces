// Problem: C. Watching Fireworks is Fun
// Contest: Codeforces - Codeforces Round #219 (Div. 1)
// URL: https://codeforces.com/problemset/problem/372/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
int f[2][150003];
signed main()
{
	int n=read(),m=read(),d=read();
	for(int i=1,x,y,z,w,lst=0; i<=m; ++i)
	{
		memset(f[i&1],0xc0,sizeof(f[i&1]));
		x=read(),y=read(),z=read(),w=(z-lst)*d,lst=z;
		deque<int> q;
		for(int j=1; j<=n; ++j)
		{
			while(!q.empty()&&j-q.back()>w) q.pop_back();
			while(!q.empty()&&f[(i-1)&1][j]>=f[(i-1)&1][q.front()]) q.pop_front();
			q.push_front(j);
			f[i&1][j]=max(f[i&1][j],f[(i-1)&1][q.back()]);
		}
		while(!q.empty()) q.pop_back();
		for(int j=n; j>=1; --j)
		{
			while(!q.empty()&&q.back()-j>w) q.pop_back();
			while(!q.empty()&&f[(i-1)&1][j]>=f[(i-1)&1][q.front()]) q.pop_front();
			q.push_front(j);
			f[i&1][j]=max(f[i&1][j],f[(i-1)&1][q.back()]);
		}
		for(int j=1; j<=n; ++j) f[i&1][j]+=y-abs(x-j);
	}
	int ans=-1e18;
	for(int i=1; i<=n; ++i) ans=max(ans,f[m&1][i]);
	printf("%lld\n",ans);
	return 0;
}