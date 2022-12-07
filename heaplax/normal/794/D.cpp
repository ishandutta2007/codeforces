#include<map>
#include<set>
#include<cstdio>
#define N 300001
char ch;void re(int& x)
{
	while(ch=getchar(),ch<33);x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
}
using namespace std;
bool bug;
int n,m,cnt,dfn,mark[N],sy[N];
set<int> go[N],edge[N];
map<set<int>,int> s;
void dfs(int u,int fa)
{
	if(go[u].size()>2)return;
	mark[u]=++dfn;
	set<int>::iterator p=go[u].begin();
	for(int v;p!=go[u].end();++p)
		if(!mark[v=*p])dfs(v,u);
		else if(v!=fa)return (void)(bug=1);
}
int main()
{
	re(n),re(m);
	for(int u,v;m--;)
	{
		re(u),re(v);
		edge[u].insert(v);
		edge[v].insert(u);
	}
	for(int i=1;i<=n;++i)
	{
		edge[i].insert(i);
		if(!s[edge[i]])s[edge[i]]=++cnt;
		sy[i]=s[edge[i]];
	}
	for(int i=1;i<=n;++i)
	{
		set<int>::iterator p=edge[i].begin();
		for(;p!=edge[i].end();++p)
			if(sy[*p] != sy[i])
				go[sy[i]].insert(sy[*p]);
	}
	for(int i=1;i<=cnt;++i)
		if(!mark[i] && go[i].size()<=1)
		{
			dfs(i,i);
			if(bug)return puts("NO"),0;
		}
	if(dfn!=cnt)puts("NO");
	else 
	{
		puts("YES");
		for(int i=1;i<=n;++i)
			printf("%d ",mark[sy[i]]);
	}
}