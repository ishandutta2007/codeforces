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
const int N=102000,p=1000000007;
int n,m,l;
LL a[N];
int check(int i) { 
	if (i>n) return 0;
	return a[i]>l&&a[i-1]<=l;}
int main()
{
	scanf("%d%d%d",&n,&m,&l);
	int ans=0;
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (int i=1;i<=n;i++)
	if (check(i)) ans++;
	while (m--)
	{
		int kd,x,y;
		scanf("%d",&kd);
		if (kd==0) printf("%d\n",ans);
		else
		{
			scanf("%d%d",&x,&y);
			ans-=check(x)+check(x+1);
			a[x]+=y;
			ans+=check(x)+check(x+1);
		}
	}
	return 0;
}