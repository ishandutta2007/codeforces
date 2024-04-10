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
int n,m,k;
int C[2010][2010];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int ans=m;
	for (int i=1;i<=k;i++) 
		ans=1LL*ans*(m-1)%p;
	C[0][0]=1;
	for (int i=1;i<=n-1;i++)
	for (int j=0;j<=i;j++)
		if (j==0) C[i][j]=1;
		else C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	ans=1LL*ans*C[n-1][k]%p;
	printf("%d\n",ans);
	return 0;
}