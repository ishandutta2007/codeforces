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
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
//-----------------------
const int N=2020,inf=1000000000,p=998244353;
int n,q;
int f[N][N];
int a[N][N];
int bit[N],b[N],v[N];
void C(int *bit,int i,int d) { for (;i<=n;i+=i&-i) bit[i]+=d;}
int  Q(int *bit,int i) { int res=0;for (;i;i-=i&-i) res+=bit[i];return res;}
int exp(int a,int b,int c)
{
	int d=1;
	while (b)
	{
		if (b&1) d=1LL*d*a%c;
		b>>=1;a=1LL*a*a%c;
	}
	return d;
}
int get(int k)
{
	int res=0;
	for (int i=1;i<=n;i++) bit[i]=v[i]=0;
	if (k==1)
	{
		for (int i=1;i<=n;i++) C(bit,i,1);
		for (int i=1;i<=n;i++)
		{
			res=(res+1LL*Q(bit,a[k][i]-1)*f[n-i][0])%p;
			C(bit,a[k][i],-1);
		}
	}
	else
	{
		int t=0;
		for (int i=1;i<=n;i++) C(b,i,1);
		for (int i=1;i<=n;i++)
		{
			int d=Q(bit,a[k][i]-1);
			v[a[k-1][i]]--;
			if (v[a[k-1][i]]==0) t++;else C(bit,a[k-1][i],1),C(b,a[k-1][i],-1);
			int e=Q(b,a[k][i]-1);

			res=(res+1LL*d*f[i-t-1][n-i-i+t+1])%p;
			res=(res+1LL*e*f[i-t][n-i-i+t])%p;

			v[a[k][i]]++;
			if (v[a[k][i]]==0) t++,C(bit,a[k][i],-1);else C(b,a[k][i],-1);
		}
	}
	return res;
}
/*
   f[i][0]=i!
   */
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	for (int j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	int ans=0;
	for (int i=0;i<=n;i++)
	for (int j=0;i+j<=n;j++)
	if (i==0&&j==0) f[i][j]=1;else
	if (i==0) f[i][j]=1LL*(j-1)*(f[i][j-2]+f[i][j-1])%p;
	else f[i][j]=(1LL*i*f[i-1][j]+1LL*j*f[i][j-1])%p;
	for (int i=1;i<=n;i++)
	{
		int k=get(i);
		ans=(ans+1LL*k*exp(f[0][n],n-i,p))%p;
	}
	printf("%d\n",ans);
	return 0;
}