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
#define FR first
#define SC second
#define MP make_pair
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=200010;
pair<int,pair<int,int> > a[N];
int n,m;
int ok(int mid)
{
	int now=0,cnt=0;
	for (int i=1;i<=n;i++)
	if (a[i].SC.FR>=mid) 
	{ 
		now+=a[i].FR;cnt++;
		if (cnt==mid) return now<=m;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].SC.FR,&a[i].FR),a[i].SC.SC=i;
	sort(a+1,a+1+n);
	int l=0,r=n;
	while (l<r)
	{
		int mid=(l+r+1)>>1;
		if (ok(mid)) l=mid;else r=mid-1;
	}
	cout<<l<<endl;
	cout<<l<<endl;
	int cnt=0;
	for (int i=1;i<=n;i++)
	if (a[i].SC.FR>=l)
	{
		if (cnt==l) break;
		cnt++;cout<<a[i].SC.SC<<' ';
	}
	return 0;
}