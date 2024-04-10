// Problem: C. Prince's Problem
// Contest: Codeforces - Z Flip #define insert push_back(3)
// URL: https://codeforces.com/gym/376169/problem/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#define ll long long
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
vector<int> e[100003];
bool vis[100003];
int prime[100003],pcnt;
int dep[100003],a[200003],C,dfn[100003],lst[100003],l2[200003];
int c[10000003],st[200003][18];
int Fa[100003];
void dfs2(int x,int fa)
{
	Fa[x]=fa;
	a[++C]=x,dfn[x]=C;
    for(int y:e[x]) if(y!=fa)
        dep[y]=dep[x]+1,dfs2(y,x),a[++C]=x;
    lst[x]=C;
    return ;
}
int pmax(int x,int y){return dep[x]<dep[y]?x:y;}
void init(int x)
{
	st[x][0]=a[x];
	for(int i=1; i<=17; ++i) 
		st[x][i]=pmax(st[x][i-1],st[min(x+(1<<(i-1)),C)][i-1]);
	return ;
}
int LCA(int l,int r)
{
	l=dfn[l],r=dfn[r];
	if(l>r) swap(l,r);
	int d=l2[r-l+1];
	return pmax(st[l][d],st[min(r-(1<<d)+1,C)][d]);
}
vector<int> d[100003];
int ans[1000003];
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=1ll*t*t%p) if(y&1) res=1ll*res*t%p;
	return res;
}
struct node{int w,o,id;};
vector<node> vec[100003];
void calc(int x,int fa=0)
{
	for(int i:d[x]) ++c[i];
	for(node i:vec[x])
	{
		int v=i.w,r=1;
		for(int j=1; prime[j]*prime[j]<=v; ++j) if(v%prime[j]==0)
		{
			int q=1;
			while(v%prime[j]==0) q*=prime[j],v/=prime[j];
			for(ll g=prime[j]; g<=10000000; g*=prime[j])
				r=1ll*r*qp(min((int)g,q),c[g])%p;
		}
		if(v>1) for(ll g=v; g<=10000000; g*=v)
			r=1ll*r*qp(v,c[g])%p;
		ans[i.id]=1ll*ans[i.id]*qp(r,i.o)%p;
	}
	for(int y:e[x]) if(y!=fa) calc(y,x);
	for(int i:d[x]) --c[i];
	return ;
}
signed main()
{
	int n=read();
	for(int i=2; i<=200000; ++i) l2[i]=l2[i>>1]+1;
	for(int i=1,u,v; i<n; ++i) 
		u=read(),v=read(),
		e[u].push_back(v),e[v].push_back(u);
	dfs2(1,0);
	for(int i=C; i>=1; --i) init(i);
	for(int i=2; i<=100000; ++i) if(!vis[i])
	{
		prime[++pcnt]=i;
		for(int j=2; i*j<=100000; ++j) vis[i*j]=1;
	}
	for(int i=1; i<=n; ++i)
	{
		int v=read();
		for(int j=1; prime[j]*prime[j]<=v; ++j) if(v%prime[j]==0)
		{
			int q=1;
			while(v%prime[j]==0) q*=prime[j],v/=prime[j];
			d[i].push_back(q);
		}
		if(v>1) d[i].push_back(v);
	}
	int q=read();
	for(int i=1; i<=q; ++i)
	{
		ans[i]=1;
		int u=read(),v=read(),w=LCA(u,v),g=read();
		vec[u].push_back((node){g,1,i}),
		vec[v].push_back((node){g,1,i}),
		vec[Fa[w]].push_back((node){g,p-2,i}),
		vec[w].push_back((node){g,p-2,i});
	}
	calc(1);
	for(int i=1; i<=q; ++i) printf("%d\n",ans[i]);
	return 0;
}