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
const int N=200010;
//const int p=1000000007,inf=100000000;
int pow(int a,int b,int c)
{
    if (a==0)return 0;
    int d=a,e=1;
    while (b)
    {
        if (b&1) e=(1LL*e*d)%c;
        d=1LL*d*d%c;
        b>>=1;
    }
    return e;
}
int random(int n) { return 1LL*rand()*rand()%n+1;}
struct Edge {int y,ne;};
/*
int read(int &x)
{
	while (buf[pt]<=32&&pt<len) pt++;
	if (pt>=len) return 0;
	x=0;
	while (buf[pt]>32) x=x*10+buf[pt++]-48;
	return 1;
}*/
int n,k,d;
int a[N],b[N];
int check(int mid)
{
	for (int i=1;i<=n;i++) b[i]=a[i];
	int p=1,q=1,sum=a[1];
	for (int i=mid+1;i+mid<=n;i++)
	{
		int l=max(i-1LL*min(i,n+1-i)*d,1LL);
		int r=min(i+1LL*min(i,n+1-i)*d,0LL+n);
		while (p<l) sum-=b[p],p++;
		while (q<r&&sum<k) q++,sum+=b[q];
		if (sum<k) return 0;
		sum-=k;
		int tmp=k;
		while (tmp>b[p]) tmp-=b[p],p++;
		b[p]-=tmp;
	}
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
//	a[n]=n*k;
	int l=0,r=n/2;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}