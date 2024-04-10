#include<bits/stdc++.h>
using namespace std;
 
vector<int> v[100010];
 
int ans[10000010],tt=0;
int dep[100010],mx[100010],son[100010];
int fa[100010],st[100010],ed[100010],nxt[100010],n;
 
inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}
 
inline void pre_dfs(int x)
{
	for (int t:v[x])
	{
		dep[t]=dep[x]+1;
		pre_dfs(t);
		if (!son[x]||mx[t]+1>mx[son[x]]+1) son[x]=t;
		mx[x]=max(mx[x],mx[t]+1);
	}
}

inline void dfs(int x)
{
	if (!son[x]) { st[x]=ed[x]=x;return; }
	dfs(son[x]);
	int now1=st[son[x]],now2=ed[son[x]];
	for (int t:v[x]) if (t!=son[x])
	{
		int hh=0;
		for (int i=t;i;i=son[i]) ans[++tt]=now1,hh=i;
		nxt[hh]=now1;dfs(t);now1=t;
	}
	nxt[x]=now1;st[x]=x;ed[x]=now2;
}

int main()
{
	n=rd();
	for (int i=2;i<=n;i++) fa[i]=rd()+1;
	for (int i=2;i<=n;i++) v[fa[i]].push_back(i);
	dep[1]=1;pre_dfs(1);dfs(1);
	for (int i=1;i;i=nxt[i]) printf("%d ",i-1);
	puts("");
	printf("%d\n",tt);
	for (int j=tt;j;j--) printf("%d ",ans[j]-1);
	puts("");
	return 0;
}