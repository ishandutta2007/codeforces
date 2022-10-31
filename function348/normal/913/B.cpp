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
int n;int c[1010],d[1010],fa[1010];
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
		c[fa[i]]=1;
	}
	int f=1;
	for (int i=2;i<=n;i++)
		if (c[i]==0) d[fa[i]]++;
	for (int i=1;i<=n;i++) 
		if (c[i]&&d[i]<3) f=0;
	cout<<(f?"Yes":"No");
	return 0;
}