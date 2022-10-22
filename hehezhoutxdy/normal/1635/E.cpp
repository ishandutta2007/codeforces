// Problem: E. Cars 
// Contest: Codeforces Round #772 (Div. 2)
// URL: https://codeforces.com/contest/1635/problem/E
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
int op[200003],x[200003],y[200003];
vector<int> e[200003],ee[200003];
int col[200003];
int ans[200003],deg[200003];
void dfs(int x)
{
	for(int y:e[x]) if(y!=x) 
	{
		if(col[y]==-1) col[y]=col[x]^1,dfs(y);
		else if(col[x]==col[y]) puts("NO"),exit(0);
	}
}
signed main()
{
	memset(col,-1,sizeof(col));
	int n=read(),m=read();
	for(int i=1; i<=m; ++i) op[i]=read(),x[i]=read(),y[i]=read(),
	e[x[i]].push_back(y[i]),e[y[i]].push_back(x[i]);
	for(int i=1; i<=n; ++i) if(col[i]==-1) col[i]=0,dfs(i);
	queue<int> q;
	for(int i=1; i<=m; ++i)
		if(op[i]==1)
		{
			if(col[x[i]])//<-- y[i] x[i] --> 
			{
				++deg[x[i]],ee[y[i]].push_back(x[i]);
			}
			else
			{
				++deg[y[i]],ee[x[i]].push_back(y[i]);
			}
		}
		else
		{
			if(col[x[i]])//x[i] --> <-- y[i] 
			{
				++deg[y[i]],ee[x[i]].push_back(y[i]);
			}
			else
			{
				++deg[x[i]],ee[y[i]].push_back(x[i]);
			}
		}
	for(int i=1; i<=n; ++i) if(!deg[i]) q.push(i);
	int cnt=0;
	while(!q.empty())
	{
		int x=q.front();
		ans[x]=++cnt;q.pop();
		for(int y:ee[x]) if(!--deg[y]) q.push(y);
	}
	if(cnt!=n) puts("NO"),exit(0);
	puts("YES");
	for(int i=1; i<=n; ++i)
	{
		if(col[i]) putchar('R');
		else putchar('L');
		printf(" %d\n",ans[i]);
	}
	return 0;
}