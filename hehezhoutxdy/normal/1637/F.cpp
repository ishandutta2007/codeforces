// Problem: F. Towers
// Contest: Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/F
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
vector<int> e[1000003];
int mx[1000003],se[1000003],deg[1000003],a[1000003];
bool vis[1000003];
signed main()
{
	int n=read(),ans=0;
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<n; ++i)
	{
		// int u=i+1,v=rand()%i+1; 
		int u=read(),v=read();
		e[u].push_back(v),e[v].push_back(u);
	}
	queue<int> q;
	int rt=1;
	for(int i=1; i<=n; ++i) 
	{
		if(a[i]>a[rt]) rt=i;
		deg[i]=(int)e[i].size();
	}
	deg[rt]=998244353;
	for(int i=1; i<=n; ++i)
		if(deg[i]==1) q.push(i),mx[i]=a[i],ans+=a[i];
	for(int i=1; i<=n-1; ++i)
	{
		assert(!q.empty());
		int x=q.front();
		q.pop();
		vis[x]=1;
		for(int y:e[x]) if((--deg[y])==1)
		{
			if(mx[y]<mx[x]) se[y]=mx[y],mx[y]=mx[x];
			else se[y]=max(mx[x],se[y]);
			if(mx[y]<a[y]) ans+=a[y]-mx[y],mx[y]=a[y];
			q.push(y);
		}
		else 
		{
			if(mx[y]<mx[x]) se[y]=mx[y],mx[y]=mx[x];
			else se[y]=max(mx[x],se[y]);
		}
	}
	int fi=0;
	for(int i=1; i<=n; ++i) if(!vis[i]) fi=i;
	assert(fi==rt);
	printf("%lld\n",ans+a[fi]+a[fi]-mx[fi]-se[fi]);
	return 0;
}