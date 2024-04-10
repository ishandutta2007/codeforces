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
int n;
int a[N],b[N],x[N];
int main()
{
	scanf("%d",&n);
	n/=2;
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j*j<=x[i];j++)
		if (x[i]%j==0)
		{
			int k=x[i]/j;
			if ((j+k)%2==1) continue;
			if ((k-j)/2<=b[i-1]) continue;
			a[i]=(k-j)/2;
			b[i]=(k+j)/2;
		}
		if (a[i]==0)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for (int i=1;i<=n;i++)
	{
		printf("%I64d ",1LL*a[i]*a[i]-1LL*b[i-1]*b[i-1]);
		printf("%d ",x[i]);
	}
}
/*
   x
   (b+a)(b-a)=x
   */