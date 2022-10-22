// Problem: E. In a Trap
// Contest: Codeforces - Codeforces Round #429 (Div. 1)
// URL: https://codeforces.com/problemset/problem/840/E
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
int n=read(),m=read(),cnt=n;
int ls[20000003],rs[20000003];
unsigned short v[20000003];
void insert(int pos,int x,int y)
{
	for(int i=64; i; i>>=1) 
		pos=(x&i)
			?(rs[pos]?rs[pos]:(rs[pos]=++cnt))
			:(ls[pos]?ls[pos]:(ls[pos]=++cnt));
	(v[pos]<y)&&(v[pos]=y);
}
int query(int pos,int x)
{
	int res=0;
	for(int i=64; i; i>>=1) 
		pos=(x&i)
			?(ls[pos]?(res+=i,ls[pos]):rs[pos])
			:(rs[pos]?(res+=i,rs[pos]):ls[pos]);
	return (res<<9)+v[pos];
}
int a[100003],dep[100003],f[100003],ff[100003];
vector<int> e[100003];
void dfs(int x,int fa=0)
{
	dep[x]=dep[fa]+1;
	for(int y:e[x]) if(y!=fa) f[y]=x,dfs(y,x);
	if(dep[x]>=512)
	{
		int t=x; 
		for(int i=0; i<512; ++i,t=f[t]) 
			insert(x,(a[t]^i)>>9,(a[t]^i)&511);	
		ff[x]=t;
	}
	return ;
}
signed main()
{
	double S=clock();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1,u,v; i<n; ++i) 
		u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	dfs(1);
	for(int u,v; m--;)
	{
		u=read(),v=read();
		int c=0,dd=dep[v],ans=0;
		while(dep[v]-dep[u]>=511) 
			ans=max(ans,query(v,c++)),v=ff[v];
		while(dep[v]>=dep[u])
			ans=max(ans,a[v]^(dd-dep[v])),v=f[v];
		printf("%d\n",ans);
		if((clock()-S)/CLOCKS_PER_SEC>2.9) exit(m);
	}
	return 0;
}