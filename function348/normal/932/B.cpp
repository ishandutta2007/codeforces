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
int f[1001000],g[1100000][12];
int q;
int main()
{
	for (int i=1;i<=1000000;i++)
	{
		if (i<=9) f[i]=i;else
		{
			int r=i,t=1;
			while (r) 
			{
				if (r%10!=0) t*=r%10;
				r/=10;
			}
			f[i]=f[t];
		}
		for (int j=1;j<=9;j++) g[i][j]=g[i-1][j];
		g[i][f[i]]++;
	}
	scanf("%d",&q);
	while (q--)
	{
		int l,r,k;scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",g[r][k]-g[l-1][k]);
	}
	return 0;
}