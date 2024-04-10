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
vector<pair<int,int>> e[1000003];
int a[1000003],dep[100003];
int f[100003][20],g[100003][20],cnt;
void dfs(int x,int fa)
{
	f[x][0]=fa;
	for(int i=1; i<20; ++i) 
		f[x][i]=f[f[x][i-1]][i-1],
		g[x][i]=max(g[x][i-1],g[f[x][i-1]][i-1]);
	for(auto [y,z]:e[x]) if(y!=fa)
		dep[y]=dep[x]+1,g[y][0]=z,dfs(y,x);
	return ;
}
int ans[100003];
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19; i>=0; --i) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19; i>=0; --i) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int F(int x,int d)
{
	int ans=0;
	for(int i=19; i>=0; --i) if((d>>i)&1) 
	ans=max(ans,g[x][i]),x=f[x][i];
	return ans;
}
struct st_table
{
	int st[100003][21],l2[100003],n;
	inline void init(int l)
	{
		for(int i=1; i<=20; i++) 
		st[l][i]=max(st[l][i-1],st[min(l+(1<<(i-1)),n)][i-1]);
	}
	inline int query(int l,int r)
	{
		int L=l2[r-l+1];
		return max(st[l][L],st[min(r-(1<<L)+1,n)][L]);
	}
	void main()
	{
	    for(int i=2; i<=n; i++) l2[i]=l2[i>>1]+1;
		for(int i=n; i; --i) init(i);
		return ;
	}
}ST;
signed mian()
{
	int n=read(),m=read(),q=read();
	for(int i=1; i<=n; ++i) e[i].clear();
	for(int i=1; i<=n; ++i) fa[i]=i;
	for(int i=1; i<=m; ++i)
	{
		u[i]=read(),v[i]=read();
		int A=find(u[i]),B=find(v[i]);
		if(A!=B) e[u[i]].push_back(make_pair(v[i],i)),
		e[v[i]].push_back(make_pair(u[i],i)),w[i]=1,fa[A]=B;
	}
	dfs(1,1);
	for(int i=1; i<n; ++i) 
	{
		int x=i,y=i+1,z=LCA(x,y);
		ST.st[i][0]=
		max(F(x,dep[x]-dep[z]),F(y,dep[y]-dep[z]));
		for(int j=1; j<=20; ++j)
			ST.st[i][j]=0;
	}
	ST.n=n-1,ST.main();
	for(int i=1,x,y; i<=q; ++i)
	{
		x=read(),y=read();
		if(x==y) printf("0 ");
		else printf("%d ",ST.query(x,y-1));
	}
	puts("");
	return 0;
}
signed main(){for(int T=read();T--;)mian();return 0;}