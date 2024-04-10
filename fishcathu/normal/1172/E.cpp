#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define MAX 400400
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
namespace LCT
{
#define ls (t[x].ch[0])
#define rs (t[x].ch[1])
	ll Num;
	struct Node{int ff,ch[2],sz,vsz;ll ssz;ll Val(){return 1ll*sz*sz;}}t[MAX];
	bool isroot(int x){return t[t[x].ff].ch[0]!=x&&t[t[x].ff].ch[1]!=x;}
	void pushup(int x){t[x].sz=t[ls].sz+t[rs].sz+t[x].vsz+1;}
	void rotate(int x)
	{
		int y=t[x].ff,z=t[y].ff;
		int k=t[y].ch[1]==x;
		if(!isroot(y))t[z].ch[t[z].ch[1]==y]=x;t[x].ff=z;
		t[y].ch[k]=t[x].ch[k^1];t[t[x].ch[k^1]].ff=y;
		t[x].ch[k^1]=y;t[y].ff=x;
		pushup(y);pushup(x);
	}
	void Splay(int x)
	{
		while(!isroot(x))
		{
			int y=t[x].ff,z=t[y].ff;
			if(!isroot(y))
				(t[y].ch[0]==x)^(t[z].ch[0]==y)?rotate(x):rotate(y);
			rotate(x);
		}
	}
	void access(int x)
	{
		for(int y=0;x;y=x,x=t[x].ff)
		{
			Splay(x);
			t[x].vsz-=t[y].sz;
			t[x].vsz+=t[rs].sz;
			t[x].ssz-=t[y].Val();
			t[x].ssz+=t[rs].Val();
			rs=y;pushup(x);
		}
	}
	int findroot(int x){access(x);Splay(x);while(ls)x=ls;Splay(x);return x;}
	void link(int x,int y)
	{
		Splay(x);
		Num-=t[x].ssz+t[rs].Val();
		int z=findroot(y);
		access(x);Splay(z);
		Num-=t[t[z].ch[1]].Val();
		t[x].ff=y;Splay(y);
		t[y].vsz+=t[x].sz;
		t[y].ssz+=t[x].Val();
		pushup(y);access(x);
		Splay(z);
		Num+=t[t[z].ch[1]].Val();
	}
	void cut(int x,int y)
	{
		access(x);Num+=t[x].ssz;
		int z=findroot(y);
		access(x);Splay(z);
		Num-=t[t[z].ch[1]].Val();
		Splay(x);
		t[x].ch[0]=t[t[x].ch[0]].ff=0;
		pushup(x);Splay(z);
		Num+=t[t[z].ch[1]].Val();
	}
}
using namespace LCT;
vector<int> E[MAX];
vector<pair<int,int> >V[MAX];
int n,m,c[MAX],fa[MAX],col[MAX];ll Ans[MAX];
void dfs(int u,int ff){fa[u]=ff;for(int v:E[u])if(v!=ff)dfs(v,u);}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(int i=1;i<=n;++i)V[c[i]].push_back(make_pair(0,i));
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		V[c[u]].push_back(make_pair(i,u));
		c[u]=v;
		V[c[u]].push_back(make_pair(i,u));
	}
	dfs(1,n+1);
	for(int i=1;i<=n+1;++i)pushup(i);
	for(int i=1;i<=n;++i)link(i,fa[i]);
	for(int i=1;i<=n;++i)
	{
		ll lst=0;
		for(auto a:V[i])
		{
			int u=a.second,t=a.first;
			col[u]?link(u,fa[u]):cut(u,fa[u]);
			col[u]^=1;
			Ans[t]+=1ll*n*n-Num-lst;
			lst=1ll*n*n-Num;
		}
		for(auto a:V[i])
		{
			int u=a.second;
			if(col[u])link(u,fa[u]),col[u]^=1;
		}
	}
	for(int i=1;i<=m;++i)Ans[i]+=Ans[i-1];
	for(int i=0;i<=m;++i)printf("%lld\n",Ans[i]);
	return 0;
}