// Problem: C. DFS Trees
// Contest: Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/C
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
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int fa[1000003];
int find(int x)
{
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
int u[1000003],v[1000003],w[1000003];
vector<int> e[1000003];
int a[1000003],dep[100003];
int f[100003][20],in[1000003],out[1000003],cnt;
int id[1000003];
void dfs(int x,int fa)
{
	in[x]=++cnt;id[cnt]=x;
	f[x][0]=fa;
	for(int i=1; i<20; ++i) f[x][i]=f[f[x][i-1]][i-1];
	for(int y:e[x]) if(y!=fa)
		dep[y]=dep[x]+1,dfs(y,x);
	out[x]=cnt;
	return ;
}
int ans[100003];
int F(int x,int d)
{
	for(int i=19; i>=0; --i) if((d>>i)&1) x=f[x][i];
	return x;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) fa[i]=i;
	for(int i=1; i<=m; ++i)
	{
		u[i]=read(),v[i]=read();
		int A=find(u[i]),B=find(v[i]);
		if(A!=B) e[u[i]].push_back(v[i]),
		e[v[i]].push_back(u[i]),w[i]=1,fa[A]=B;
	}
#define Q 1
	dfs(Q,Q);
	for(int i=1; i<=m; ++i) if(!w[i])
	{
		int U=u[i],V=v[i];
		if(dep[U]>dep[V]) swap(U,V);
		if(F(V,dep[V]-dep[U])==U)
		{
			U=F(V,dep[V]-dep[U]-1);
			++a[1],--a[in[U]];
			++a[out[U]+1];
			++a[in[V]],--a[out[V]+1];
		}
		else
		{
			++a[in[U]],--a[out[U]+1];
			++a[in[V]],--a[out[V]+1];
		}
	}
	int s=0;
	for(int i=1; i<=n; ++i)
	{
		s+=a[i];
		if(s==m-(n-1)) ans[id[i]]=1;
	}
	for(int i=1; i<=n; ++i) printf("%d",ans[i]);
	return 0;
}/////////////////