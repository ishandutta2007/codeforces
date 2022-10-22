// Problem: C. Journey
// Contest: Codeforces - Codeforces Round #374 (Div. 2)
// URL: https://codeforces.com/problemset/problem/721/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
int f[5003][5003];
short lst[5003][5003];
vector<pair<int,int>> e[5003];
int deg[5003];
signed main()
{
	int n=read(),m=read(),T=read();
	memset(f,0x3f,sizeof(f));
	for(int i=1,u,v,w; i<=m; ++i)
		u=read(),v=read(),w=read(),
		++deg[v],e[u].push_back(make_pair(v,w));
	queue<int> q;
	for(int i=1; i<=n; ++i) if(!deg[i]) q.push(i);
	f[1][1]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto y:e[x])
		{
			for(int i=n; i>=2; --i) 
				if(f[y.first][i]>f[x][i-1]+y.second)
					f[y.first][i]=f[x][i-1]+y.second,
					lst[y.first][i]=x;
			if(!--deg[y.first]) q.push(y.first);
		}
	}
	for(int i=n; i>=1; --i) if(f[n][i]<=T) 
	{
		printf("%d\n",i);
		stack<int> stk;
		int X=n,Y=i;
		while(X!=1) stk.push(lst[X][Y]),X=lst[X][Y],--Y;
		while(!stk.empty()) printf("%d ",stk.top()),stk.pop();
		printf("%d\n",n),exit(0);
	}
	puts("0");
	return 0;
}