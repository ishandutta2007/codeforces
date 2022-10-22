// Problem: D. X(or)-mas Tree
// Contest: Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define fi first
#define se second
#define mp make_pair
#define pb push_back
vector<int> e[200003];
int fa[1000003],val[1000003],qwq[1000003];
int U[200003],V[200003],W[200003];
void dfs(int x,int f=0)
{
	for(int y:e[x]) if((x^U[y]^V[y])!=f)
	{
		int t=x^U[y]^V[y];
		if(W[y]==-1) fa[t]=t;  
		else fa[t]=fa[x],val[t]=val[x]^W[y];
		dfs(t,x);
	}
	else qwq[x]=y;
	return ;
}
int find(int x)
{
	if(x==fa[x]) return x;
	int q=fa[x];
	fa[x]=find(fa[x]);
	val[x]^=val[q];
	return fa[x];
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();	
		for(int i=1; i<=n; ++i) e[i].clear(),val[i]=0;
		for(int i=1; i<n; ++i)
		{
			int u=read(),v=read(),w=read();
			U[i]=u,V[i]=v,W[i]=w;
			e[u].pb(i),e[v].pb(i);
		}
		fa[1]=1;
		dfs(1);
		bool flg=0;
		for(int i=1; i<=m; ++i)
		{
			int u=read(),v=read(),w=read(),z=0;
			int tu=find(u),tv=find(v);
			z^=val[u],z^=val[v];
			if(tu==tv) 
			{
				if((__builtin_popcount(z)&1)!=w)
				{
					for(int j=i+1; j<=m; ++j) read(),read(),read();
					flg=1;
					break;
				}
			}
			else
			{
				// printf("%d %d %d\n",tu,tv,(__builtin_popcount(z)&1)^w);
				fa[tu]=tv,val[tu]=(__builtin_popcount(z)&1)^w;
			}
		}

		if(flg) 
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			for(int i=1; i<n; ++i) if(W[i]==-1)
			{
				int A=find(U[i]),B=find(V[i]);
				if(A!=B)
				{
					fa[A]=B,val[A]=0;
					int C=find(U[i]),D=find(V[i]);
					printf("%d %d %d\n",U[i],V[i],val[U[i]]^val[V[i]]);
				}
				else 
				{
					printf("%d %d %d\n",U[i],V[i],val[U[i]]^val[V[i]]);
				}
			}
			else printf("%d %d %d\n",U[i],V[i],W[i]);
		}
	}
	return 0;
}