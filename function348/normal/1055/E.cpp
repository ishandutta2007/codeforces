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
const int N=3020,p=1000000007;
int n,s,m,k;
int a[N],c[N];
int f[N][N];
int b[N];
int check(int mid)
{
	for (int i=1;i<=n;i++) c[i]=c[i-1]+(a[i]<=mid);
	for (int i=1;i<=n;i++)
	{
		for (int k=1;k<=m;k++)
		if (b[i]<=i)
		f[i][k]=max(f[i-1][k],f[b[i]-1][k-1]+c[i]-c[b[i]-1]);
		else f[i][k]=f[i-1][k];
	}
/*	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		printf("%d%c",f[i][j],j<m?' ':'\n');
*/	for (int i=1;i<=m;i++)
		if (f[n][i]>=k) return 1;
	return 0;
}
int main()
{
	scanf("%d%d%d%d",&n,&s,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) b[i]=n+1;
	for (int i=1;i<=s;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		b[y]=min(b[y],x);
	}
	for (int i=n-1;i>=1;i--) b[i]=min(b[i],b[i+1]);
//	printf("%d\n",check(2));
//	return 0;
	int l=1,r=1000000001;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;else l=mid+1;
	}
	if (l==1000000001) l=-1;
	printf("%d\n",l);
	return 0;
}
/*
   5 3 3 4
5 5 2 1 1
1 2
2 3
3 4
   */