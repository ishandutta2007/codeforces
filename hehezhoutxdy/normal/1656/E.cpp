// Problem: E. Equal Tree Sums
// Contest: CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
vector<int> e[1000003];
int dep[1000003];
void dfs(int x,int fa=0)
{
	for(int y:e[x]) if(y!=fa) dep[y]=dep[x]+1,dfs(y,x);
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=1; i<n; ++i)
		{
			int u=read(),v=read();
			e[u].push_back(v),e[v].push_back(u);
		}
		dfs(1);
		for(int i=1; i<=n; ++i) if(dep[i]&1) 
			printf("%d ",(int)e[i].size());
			else printf("%d ",-1*(int)e[i].size());
		puts("");
	}
	return 0;
}