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
int n,l;
int a[40];
LL f[40];
int main()
{
	scanf("%d%d",&n,&l);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) a[i]=min(a[i],a[i-1]*2);
	if (l&1) f[0]=a[0];else f[0]=0;
	for (int i=1;i<n;i++) 
	if (l&(1<<i)) f[i]=f[i-1]+a[i];else f[i]=min(f[i-1],0LL+a[i]);
	cout<<min(f[n-1]+2LL*(l>>n)*a[n-1],2LL*(((l-1)>>n)+1)*a[n-1]);
	return 0;
}