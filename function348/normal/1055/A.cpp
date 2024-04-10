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
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#define FR first
#define SC second
#define MP make_pair
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define pb push_back
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
const double pi=acos(-1);
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
//-----------------------
const int N=1020,p=1000000007;
int n,s;
int a[N],b[N];
int main()
{
	scanf("%d%d",&n,&s);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	if (a[1]==0)
	{
		puts("NO");
		return 0;
	}
	if (a[s]==1)
	{
		puts("YES");
		return 0;
	}
	if (b[s]==0)
	{
		puts("NO");
		return 0;
	}
	for (int i=s+1;i<=n;i++)
	if (a[i]&&b[i])
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}