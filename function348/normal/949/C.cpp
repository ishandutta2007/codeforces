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
#include<sstream>
#define FR first
#define SC second
#define MP make_pair
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=200010;
//const int p=1000000007,inf=100000000;
int pow(int a,int b,int c)
{
    if (a==0)return 0;
    int d=a,e=1;
    while (b)
    {
        if (b&1) e=(1LL*e*d)%c;
        d=1LL*d*d%c;
        b>>=1;
    }
    return e;
}
int random(int n) { return 1LL*rand()*rand()%n+1;}
struct Edge {int y,ne;};
/*
int read(int &x)
{
	while (buf[pt]<=32&&pt<len) pt++;
	if (pt>=len) return 0;
	x=0;
	while (buf[pt]>32) x=x*10+buf[pt++]-48;
	return 1;
}*/
int n,m,k,sent,num,top;
int a[N],s[N],id[N],stk[N],dfn[N],low[N],out[N];
Edge e[N*2];int last[N];
void dfs(int i)
{
	stk[++top]=i;dfn[i]=low[i]=++num;
	for (int j=last[i];j;j=e[j].ne)
	{
		if (dfn[e[j].y]==0) dfs(e[j].y);
		if (id[e[j].y]==0) low[i]=min(low[i],low[e[j].y]);
	}
	if (dfn[i]==low[i])
	{
		sent++;
		while (stk[top+1]!=i) s[sent]++,id[stk[top]]=sent,top--;
	}
}
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (a[x]==(a[y]+1)%k) add(y,x);
		if (a[y]==(a[x]+1)%k) add(x,y);
	}
	num=0;
	for (int i=1;i<=n;i++) 
		if (dfn[i]==0) dfs(i);
	for (int i=1;i<=n;i++)
	for (int j=last[i];j;j=e[j].ne)
		if (id[i]!=id[e[j].y]) out[id[i]]=1;
	int ans=n+1,ank=0;
	for (int i=1;i<=sent;i++)
	if (out[i]==0&&s[i]<ans) ans=s[i],ank=i;
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)
	if (id[i]==ank) printf("%d ",i);
	return 0;
}