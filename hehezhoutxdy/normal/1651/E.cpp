// Problem: E. Sum of Matchings
// Contest: Codeforces - Educational Codeforces Round 124 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1651/E
// Memory Limit: 512 MB
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
int n=read(),N=n<<1;
int to[3003][2],deg[3003],fa[3003];
int l[3003],r[3003],sizl[3003],sizr[3003];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
signed main()
{
	for(int i=1,x; i<=N; ++i)
		x=read(),to[x][deg[x]++]=read()-n;
	for(int i=1; i<=n; ++i)
		if(to[i][0]>to[i][1])
			swap(to[i][0],to[i][1]);
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j) fa[j]=j;
		for(int j=1; j<=n; ++j) l[j]=j;
		for(int j=1; j<=n; ++j) r[j]=j;
		for(int j=1; j<=n; ++j) sizr[j]=1;
		for(int j=1; j<=n; ++j) sizl[j]=0;
		int res=0;
		for(int j=i; j<=n; ++j)
		{
			int fx=find(to[j][0]),fy=find(to[j][1]);
			if(fx==fy) 
				(sizl[fx]<sizr[fx])&&(res+=l[fx]*(n-r[fx]+1)),
				(++sizl[fx]<sizr[fx])&&(res-=l[fx]*(n-r[fx]+1));
			else
				(sizl[fx]<sizr[fx])&&(res+=l[fx]*(n-r[fx]+1)),
				(sizl[fy]<sizr[fy])&&(res+=l[fy]*(n-r[fy]+1)),
				fa[fy]=fx,sizl[fx]+=sizl[fy]+1,sizr[fx]+=sizr[fy],
				l[fx]=min(l[fx],l[fy]),r[fx]=max(r[fx],r[fy]),
				(sizl[fx]<sizr[fx])&&(res-=l[fx]*(n-r[fx]+1));
			ans+=res;
		}
	}
	printf("%lld\n",ans);
	return 0;
}