#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn=100100;
const int maxk=110;

struct edge
{
	int obj;
	edge *Next;
} e[maxn<<1];
edge *head[maxn];
int cur=-1;

int dis[maxn][maxk];

int level[maxn];
int que[maxn];
int he,ta;

int a[maxn];
int n,m,k,s;

void Add(int x,int y)
{
	cur++;
	e[cur].obj=y;
	e[cur].Next=head[x];
	head[x]=e+cur;
}

int main()
{
	
	
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),head[i]=NULL;
	for (int i=1; i<=m; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y);
		Add(y,x);
	}
	
	for (int i=1; i<=k; i++)
	{
		for (int j=1; j<=n; j++) level[j]=-1;
		he=0,ta=0;
		for (int j=1; j<=n; j++)
			if (a[j]==i) que[++ta]=j,level[j]=0;
		
		while (he<ta)
		{
			int node=que[++he];
			for (edge *p=head[node]; p; p=p->Next)
			{
				int to=p->obj;
				if (level[to]>=0) continue;
				
				level[to]=level[node]+1;
				que[++ta]=to;
			}
		}
		
		for (int j=1; j<=n; j++) dis[j][i]=level[j];
	}
	
	for (int i=1; i<=n; i++)
	{
		sort(dis[i]+1,dis[i]+k+1);
		long long ans=0;
		for (int j=1; j<=s; j++) ans+=(long long)dis[i][j];
		printf("%I64d ",ans);
	}
	printf("\n");
	
	return 0;
}