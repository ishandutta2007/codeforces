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
const int N=100010;
const int p=1000000007;
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
int n,m,ans;
int a[N],f[N],g[N],h[N];
int find(int x)
{
	int l=0,r=m;
	while (l<r)
	{
		int mid=(l+r+1)>>1;
		if (g[mid]<=x) l=mid;else r=mid-1;
	}
	return l;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		a[x]++;a[y+1]--;
	}
	for (int i=1;i<=m;i++) a[i]+=a[i-1];
	for (int i=1;i<=m;i++) g[i]=m+100;
	for (int i=1;i<=m;i++)
	{
		f[i]=find(a[i])+1;
		g[f[i]]=min(a[i],g[f[i]]);
	}
	for (int i=1;i<=m;i++) g[i]=m+100;
	for (int i=m;i>=1;i--)
	{
		h[i]=find(a[i])+1;
		g[h[i]]=min(a[i],g[h[i]]);
	}
	for (int i=1;i<=m;i++) ans=max(ans,f[i]+h[i]-1);
	for (int i=1;i<=m;i++) f[i]=max(f[i],f[i-1]);
	for (int i=m;i>=1;i--) h[i]=max(h[i],h[i+1]);
	for (int i=1;i<=m;i++) ans=max(ans,f[i]+h[i]-2);
	printf("%d\n",ans);
	return 0;
}