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
const int N=200220,p=1000000007,inf=1000000000;
int n;
int a[N],b[N],c[N];
int cmp(int i,int j) { return a[i]<a[j];}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) a[i]=n-a[i],b[i]=i;
	sort(b+1,b+1+n,cmp);
	int k=0;
	for (int i=1,j;i<=n;)
	{
		int t=a[b[i]];
		k++;
		if (i+t-1>n)
		{
			puts("Impossible");
			return 0;
		}
		for (int j=i;j<i+t;j++)
		if (a[b[j]]!=t)
		{
			puts("Impossible");
			return 0;
		}
		else c[b[j]]=k;
		i+=t;
	}
	puts("Possible");
	for (int i=1;i<=n;i++) printf("%d ",c[i]);
	return 0;
}