// Problem: D. Potion Brewing Class
// Contest: Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/D
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
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int inv[200003],a[200003];
int u[200003],v[200003],vx[200003],vy[200003],ans=0;
int f[200003],mx[200003];
bool vis[200003];
vector<int> V;
vector<int> e[200003],d[200003];
void dfs(int x,int fa)
{
	for(int id:e[x])
	{
		int y=u[id]^v[id]^x;
		if(fa==y) continue;
		if(x==v[id]) swap(u[id],v[id]),swap(vx[id],vy[id]);
		for(int i:d[vy[id]]) --f[i];
		for(int i:d[vx[id]]) 
		{
			++f[i],mx[i]=max(mx[i],f[i]);
			if(f[i]>0&&!vis[i]) 
			{
				vis[i]=1,V.push_back(i);
			}
		}
		dfs(y,x);
		for(int i:d[vx[id]]) --f[i];
		for(int i:d[vy[id]]) ++f[i];
	}
	return ;
}
void calc(int x,int fa)
{
	ans=(ans+a[x])%p;
	for(int id:e[x])
	{
		int y=u[id]^v[id]^x;
		if(fa==y) continue;
		a[y]=a[x]*inv[vx[id]]%p*vy[id]%p;
		calc(y,x);
	}
	return ;
}
signed main()
{
	inv[0]=1;
	for(int i=1;i<=200000; ++i) inv[i]=qp(i,p-2);
	for(int i=1; i<=200000; ++i)
	{
		int t=i;
		for(int j=2; j*j<=t; ++j)
			while(t%j==0) d[i].push_back(j),t/=j;
		if(t>1) d[i].push_back(t); 
	}
	for(int T=read();T--;)
	{
		int n=read();
		V.clear();
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=1; i<n; ++i)
		{
			u[i]=read(),v[i]=read(),vx[i]=read(),vy[i]=read();
			e[u[i]].push_back(i),e[v[i]].push_back(i);
		}
		dfs(1,1);
		int v=1;
		for(int i:V) v=v*qp(i,mx[i])%p;
		a[1]=v,ans=0,calc(1,1);
		printf("%lld\n",ans);
		for(int i:V) vis[i]=0,mx[i]=0,assert(f[i]==0);
	}
	return 0;//////////////////
}