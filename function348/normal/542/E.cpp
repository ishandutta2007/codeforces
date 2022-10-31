#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int N=1010,M=100010,inf=100000000;
struct Edge {int y,ne;};
int c[N],s[N],f[N];
int n,m,num,ans,ok;
Edge e[M*2];int last[N];
queue<int> Q;
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
void dfs(int i,int col)
{
	if (c[i]!=-1&&c[i]!=col) ok=0;
	if (!ok) return;
	if (c[i]!=-1) return;
	c[i]=col;s[++num]=i;
	for (int j=last[i];j;j=e[j].ne)
	dfs(e[j].y,col^1);
}
int work(int p)
{
	int res=0;
	num=0;
	dfs(p,0);
	if (!ok) return 0;
	for (int i=1;i<=num;i++)
	{
		for (int j=1;j<=num;j++) f[s[j]]=inf;
		while (!Q.empty()) Q.pop();
		f[s[i]]=0;Q.push(s[i]);
		while (!Q.empty())
		{
			int now=Q.front();Q.pop();
			for (int j=last[now];j;j=e[j].ne)
			if (f[e[j].y]==inf)
			{
				f[e[j].y]=f[now]+1;
				Q.push(e[j].y);
				res=max(res,f[e[j].y]);
			}
		}
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	ok=1;
	for (int i=1;i<=n;i++) c[i]=-1;
	for (int i=1;i<=n;i++)
	if (c[i]==-1) ans+=work(i);
	if (ok) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}