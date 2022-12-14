#include<iostream>
#include<cstdio>
#include<vector> 
#define MN 300000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,ans2=0,head[MN+5],cnt=0,B[MN+5],b[MN+5],S,res[MN+5],ans1=0;
struct edge{int k,f,t;}e[MN+5];
vector<int> v[MN+5];

void dfs(int x)
{
	b[x]=1;++ans2;
	for(int i=0;i<v[x].size();++i) if(!b[v[x][i]]) dfs(v[x][i]);
}
void Clear(){for(int i=1;i<=n;++i) v[i].clear();}

void Solve1(int x)
{
	++ans1;B[x]=1;
	for(int i=0;i<v[x].size();++i)
		if(e[v[x][i]].k==1) 
		{
			if(!B[e[v[x][i]].t]) Solve1(e[v[x][i]].t);
		}
		else
		{
			if((e[v[x][i]].f==x&&B[e[v[x][i]].t])||(e[v[x][i]].t==x&&B[e[v[x][i]].f]))
			{
				if(!res[v[x][i]]) res[v[x][i]]=1;	
			}
			else 
			{
				if(e[v[x][i]].f==x) res[v[x][i]]=1,Solve1(e[v[x][i]].t);
				else res[v[x][i]]=2,Solve1(e[v[x][i]].f);	
			}
		}
}

int main()
{
	n=read();m=read();S=read();
	for(int i=1;i<=m;++i) e[i].k=read(),e[i].f=read(),e[i].t=read();
	for(int i=1;i<=m;++i) if(e[i].k==1) v[e[i].f].push_back(e[i].t);
	dfs(S);Clear();
	for(int i=1;i<=m;++i)
	{
		v[e[i].f].push_back(i);
		if(e[i].k==2) v[e[i].t].push_back(i);	
	}
	Solve1(S);
	printf("%d\n",ans1);
	for(int i=1;i<=m;++i)
		if(e[i].k==2)
			 printf(res[i]==1?"+":"-");
	printf("\n%d\n",ans2);
	for(int i=1;i<=m;++i) if(e[i].k==2)
	{
		if(b[e[i].f]^b[e[i].t]) printf(b[e[i].f]?"-":"+");
		else printf("+");
	}
	return 0;
}