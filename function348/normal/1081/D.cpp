/*
 * =template=.cpp
 * Copyright (C) 2017 hzw <hzw@huzhenweideMacBook.local>
 *
 * Distributed under terms of the MIT license.
 */

#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cassert>
#define FR first
#define SC second
#define MP make_pair
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define pb push_back
#define ws wss
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
void read(int &x)
{
	char ch;int fu=1;
	while ((ch=getchar())<=32);
	x=0;
	if (ch=='-') fu=-1;else x=ch-48;
	while ((ch=getchar())>32) x=x*10+ch-48;
	x*=fu;
}
void read(LL &x)
{
	char ch;int fu=1;
	while ((ch=getchar())<=32);
	x=0;
	if (ch=='-') fu=-1;else x=ch-48;
	while ((ch=getchar())>32) x=x*10+ch-48;
	x*=fu;
}
const double pi=acos(-1);
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
//-----------------------
const int N=200220,p=998244353,inf=1000000000;
struct Edge{int x,y,z,ne;};
int n,m,k,num,ans;
int v[N],fa[N];
Edge e[N],t[N];int last[N];
void add(int x,int y,int z)
{
	e[++num]=(Edge){x,y,z,last[x]};last[x]=num;
}
void dfs(int i,int fa,int len)
{
	if (v[i]) ans=max(ans,len);
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa)
		dfs(e[j].y,i,max(len,e[j].z));
}
int find(int i) { return fa[i]==i?i:fa[i]=find(fa[i]);}
int cmp(Edge a,Edge b) { return a.z<b.z;}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++)
	{
		int x;scanf("%d",&x);
		v[x]=1;
	}
	for (int i=1;i<=m;i++) scanf("%d%d%d",&t[i].x,&t[i].y,&t[i].z);
	sort(t+1,t+1+m,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x=find(t[i].x),y=find(t[i].y);
		if (x==y) continue;
		fa[y]=x;
		add(t[i].x,t[i].y,t[i].z);
		add(t[i].y,t[i].x,t[i].z);
	}
	ans=0;
	for (int i=1;i<=n;i++)
	if (v[i])
	{
		dfs(i,0,0);
		break;
	}
	for (int i=1;i<=k;i++) printf("%d ",ans);
	puts("");
}