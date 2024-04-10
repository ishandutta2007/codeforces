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
const int N=1000010;
int p[N];
int n,a,b;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	int f=0;
	for (int i=0;1LL*i*a<=n;i++)
	if ((n-i*a)%b==0)
	{
		int j=(n-i*a)/b;
		for (int i=1;i<=n;i++) p[i]=i+1;
		for (int k=1;k<=i;k++) p[k*a]=(k-1)*a+1;
		for (int k=1;k<=j;k++) p[i*a+k*b]=i*a+k*b-b+1;
		f=1;break;
	}
	if (f) for (int i=1;i<=n;i++) printf("%d ",p[i]);
	else printf("-1\n");
	return 0;
}