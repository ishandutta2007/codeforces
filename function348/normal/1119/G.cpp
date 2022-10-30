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
#include<signal.h>
#include<unistd.h>
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
template<class T> void upmax(T &a,T b) { if (a<b) a=b;}
template<class T> void upmin(T &a,T b) { if (a>b) a=b;}

//---------template--------------
const int N=1000100,p=998244353,inv2=(p+1)/2;
int n,m;
int a[N],c[N];
int main()
{
	scanf("%d%d",&n,&m);
	int s=0;
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	for (int i=1,k=0;i<=m;i++)
	{
		k+=a[i]%n;s+=a[i];
		if (k>=n) k-=n;
		c[i]=k;
	}
	sort(c+1,c+m);
	c[m]=n;
	for (int i=n;i>=1;i--) c[i]=c[i]-c[i-1];
	s=(s+n-1)/n;
	printf("%d\n",s);
	for (int i=1;i<=m;i++) printf("%d ",c[i]);puts("");
	int j=1;
	for (int i=1,k=0;i<=m;i++)
	{
		while (a[i]>0)
		{
			if (j==m+1) 
			{
				puts("");
				j=1;
			}
			printf("%d ",i);
			a[i]-=c[j];j++;
		}
	}
	while (j<=m) { printf("%d ",m);j++;}
	return 0;
}