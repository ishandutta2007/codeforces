#include<cstdio>
#include<iostream>
using namespace std;
const int N=300010;
struct Edge {int y,ne;};
int n,q,num;
int r[N],de[N],s[N],f[N],fa[N];
Edge e[N];int last[N];
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
void dfs(int i)
{
	s[i]=1;de[i]=de[fa[i]]+1;
//	for (int p=0;g[i][p];p++) g[i][p+1]=g[g[i][p]][p];
	for (int j=last[i];j;j=e[j].ne)
	{
		dfs(e[j].y);
		r[i]=max(r[i],s[e[j].y]);
		s[i]+=s[e[j].y];
	}
}
void work(int i)
{
	int k=0,mx=n+10;
	for (int j=last[i];j;j=e[j].ne)
	{
		work(e[j].y);
		int tmp=max(s[i]-s[e[j].y],r[e[j].y]);
		if (tmp<mx) k=e[j].y,mx=tmp;
	}
	if (r[i]*2<s[i]) { f[i]=i;return;}
	int now=f[k];
	while (fa[now]!=i)
	{
		int p=fa[now];
		if (max(s[i]-s[p],r[p])<=max(s[i]-s[now],r[now]))
			now=p;else break;
	}
	f[i]=now;
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++) 
	{
		scanf("%d",&fa[i]);
		add(fa[i],i);
	}
	dfs(1);
	work(1);
	while (q--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",f[x]);
	}
	return 0;
}