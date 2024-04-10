#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#define N 100010
using namespace std;
map<int,vector<int> >road[N];
set<int>to[N];
int f[N];
int find(int x){return x==f[x]?f[x]:(f[x]=find(f[x]));}
void merge(int u,int v)
{
	if(to[u].size()<to[v].size()) swap(u,v);
	for(auto i:to[v]) to[u].insert(i);
	f[v]=u;
}
void add(int u,int v,int w)
{
	int hu=find(u),hv=find(v);
	to[hu].insert(v),to[hv].insert(u);
	road[u][w].push_back(v);
	if(hv!=find(road[u][w][0])) merge(hv,find(road[u][w][0]));
	road[v][w].push_back(u);
	if(hu!=find(road[v][w][0])) merge(hu,find(road[v][w][0]));
}
int main()
{
	int n,m,c,q;
	scanf("%d%d%d%d",&n,&m,&c,&q);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	while(q--)
    {
    	char opt[2];
		int u,v,w;
        scanf("%s%d%d",opt,&u,&v);
        if(opt[0]=='?') puts((find(u)==find(v) || to[find(u)].count(v))?"Yes":"No");
        else
        {
        	scanf("%d",&w);
        	add(u,v,w);
		}
    }
	return 0;
}