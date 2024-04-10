#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 1000001
#define M 2000001
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
bool vis[N];
int top,st[M];
int n,m,s,in[N],d[N],pre[N][2];
int cnt,head[N],to[M],nxt[M];
vector<int> edge[N];
void dfs(int u,bool f)
{
	vis[u]=1;
	for(int i=head[u],v;i;i=nxt[i])
		if(!pre[v=to[i]][f^1])
		{
			pre[v][f^1]=u;
			dfs(v,f^1);
		}
}
bool topu()
{
	for(int i=1;i<=n;++i)
		if(!in[i])
			st[++top]=i;
	while(top)
	{
		int u=st[top--];
		for(int i=head[u],v;i;i=nxt[i])
		{
			--in[v=to[i]];
			if(!in[v])st[++top]=v;
		}
	}
	for(int i=1;i<=n;++i)
		if(in[i])
			return 0;
	return 1;
}
int main()
{
	re(n),re(m);
	for(int i=1,c;i<=n;++i)
	{
		re(c);d[i]=c;
		for(int j;c--;)
		{
			re(j);
			edge[i].push_back(j);
			add_edge(i,j);
		}
	}
	re(s);
	pre[s][0]=1;
	dfs(s,0);
	for(int i=1;i<=n;++i)
		if(!d[i] && pre[i][1])
		{
			puts("Win");
			for(int j=i,k=1;j!=s || k;j=pre[j][k],k^=1)	
				st[++top]=j;
			printf("%d ",s);
			for(int j=top;j;--j)
				printf("%d ",st[j]);
			return 0;
		}
	cnt=0;memset(head,0,sizeof head);
	
	for(int i=1;i<=n;++i)
		if(vis[i])
			for(int j=0;j<edge[i].size();++j)
				if(vis[edge[i][j]])	
				{
					add_edge(i,edge[i][j]);
					++in[edge[i][j]];
				}
	puts(topu()?"Lose":"Draw");
}
/*
5 5
2 2 4
1 3
1 1
1 5
0
1
*/