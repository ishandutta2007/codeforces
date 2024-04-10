#include<cstdio>
#include<iostream>
const int N=100010;
struct Edge{int y,ne;};
int v[N],dfn[N],fa[N],s[N],a[N],p[N];
Edge e[N*2];int last[N];
int n,num;
void add(int x,int y)
{
	e[++num].y=y;e[num].ne=last[x];last[x]=num;
}
void dfs(int i,int f)
{
	dfn[++num]=i;
	fa[i]=f;
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=f) dfs(e[j].y,i);
	fa[i]=fa[fa[i]];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	num=0;
	dfs(1,0);
	int q=0;
	for (int i=1;i<=n;i++) scanf("%d",&v[i]);
	for (int i=1;i<=n;i++) 
	{
		int x;
		scanf("%d",&x);
		v[i]^=x;
	}
	
	for (int i=1;i<=n;i++)
	{ 
		if (v[dfn[i]]) s[i]^=1;
		if (v[fa[dfn[i]]]) s[i]^=1;
		q+=s[i];
	}
	printf("%d\n",q);
	for (int i=1;i<=n;i++) 
	if (s[i]) printf("%d\n",dfn[i]);
	return 0;
}