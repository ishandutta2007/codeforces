// Problem: F. Tree Recovery
// Contest: Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/F
// Memory Limit: 512 MB
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
bool f[103][103][103];
bool vis[10003],Vis[103];
int d[103][103];
vector<int> e[10003];
vector<int> E[103];
vector<int> A;
void dfs(int x)
{
	vis[x]=1,A.push_back(x);
	for(int y:e[x]) if(!vis[y]) dfs(y);
	return ;
}
int ovo=0,n;
void DFS(int x,int fa,int dep,int rt)
{
	Vis[x]=1,++ovo;
	d[rt][x]=dep;
	for(int y:E[x]) if(!Vis[y]) DFS(y,x,dep+1,rt);
	return ;
}
void DFS_(int x,int fa,int dep,int rt)
{
	d[rt][x]=dep;
	for(int y:E[x]) if(y!=fa) 
		DFS_(y,x,dep+1,rt);
	return ;
}
int F(int x,int y)
{
	if(x>y) swap(x,y);
	return x*n+y;
}
signed main()
{
	for(int T=read(); T--;)
	{
		n=read();
		char ch;
		for(int i=0; i<=n*n; ++i) e[i].clear(),vis[i]=0;
		for(int i=0; i<n; ++i)
			for(int j=i+1; j<n; ++j)
				for(int k=0; k<n; ++k)
				{
					while(!isdigit(ch=getchar()));
					f[i][j][k]=ch&1;
					if(ch&1)
						e[F(i,k)].push_back(F(j,k)),
						e[F(j,k)].push_back(F(i,k));
				}
		A.clear();
		for(int i=0; A.empty()&&i<n; ++i)
			for(int j=i+1; A.empty()&&j<n; ++j)
				if(!vis[F(i,j)])
				{
					dfs(F(i,j));
					if((int)A.size()!=n-1) A.clear();
					else
					{
	for(int i=0; i<n; ++i) E[i].clear(),Vis[i]=0;
	for(int i:A) E[i/n].push_back(i%n),E[i%n].push_back(i/n);
	ovo=0,DFS(0,-1,0,0);
	if(ovo!=n){A.clear();continue;}
	for(int i=1; i<n; ++i) DFS_(i,-1,0,i);
	bool ans=1;
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
			for(int k=0; k<n; ++k)
				ans&=(f[i][j][k]==(d[i][k]==d[j][k]));
				if(!ans) A.clear();
					}
				}
		if(A.empty()) puts("No");
		else
		{
			puts("Yes");
			for(int i:A) printf("%d %d\n",i/n+1,i%n+1);
		}
	}					
	return 0;
}