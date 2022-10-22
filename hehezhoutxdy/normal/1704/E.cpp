// Problem: E. Count Seconds
// Contest: CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/E
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
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int f[1003][1003],deg[1003];
bool g[1003][1003];
vector<int> e[1003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i)
		{
			for(int j=0; j<=n; ++j)
				g[i][j]=0;
			for(int j=1; j<=n; ++j)
				f[i][j]=0;
			f[i][0]=read();
			if(f[i][0]>=p) 
			f[i][0]-=p,g[i][0]=1;
		}
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=1,u,v; i<=m; ++i) 
			u=read(),v=read(),e[u].push_back(v),++deg[v];
		int lst=0;
		for(int i=1; i<=n; ++i) if(e[i].empty()) lst=i;
		queue<int> q;
		for(int i=1; i<=n; ++i) if(!deg[i]) q.push(i);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int y:e[x])
			{
				for(int i=0; i<n; ++i)
				{
					g[y][i+1]|=g[x][i];
					if(f[y][i+1]+f[x][i]>=p) g[y][i+1]=1;
					f[y][i+1]=(f[y][i+1]+f[x][i])%p;
				}
				if(!--deg[y]) q.push(y);
			}
		}
		int que=0,lstt=-1,qf=0;
		for(int i=0; i<=n; ++i)
		{
			if(que+f[lst][i]>=p||g[lst][i]) qf=1;
			que=(que+f[lst][i])%p;
			if(que||qf)
				que=(que+p-1)%p,lstt=i;
		}
		printf("%lld\n",(lstt+que+1)%p);
	}
	return 0;
}