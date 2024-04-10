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
const int p=998244353,N=2020;
int n,a,b,ni;
int u[N],v[N],f[N],g[N],h[N][N],C[N][N],inv[N];
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
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	a=1LL*a*exp(b,p-2,p)%p;u[0]=v[0]=1;
	for (int i=1;i<=n;i++) u[i]=1LL*u[i-1]*a%p,v[i]=1LL*v[i-1]*(1-a)%p;
	for (int i=1;i<=n;i++) inv[i]=exp(i,p-2,p);
	C[0][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=i;j++)
		C[i][j]=j?(C[i-1][j-1]+C[i-1][j])%p:1;
	h[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		h[i][0]=1;
		for (int j=1;j<=i;j++)
			h[i][j]=(1LL*j*inv[i]%p*u[i-j]%p*h[i-1][j-1]+(1-1LL*j*inv[i]%p)*v[j]%p*h[i-1][j])%p;
	}
	for (int i=1;i<=n;i++)
	{
		g[i]=1;
		for (int j=1;j<i;j++)
			g[i]=(g[i]-1LL*C[i][j]*h[i][j]%p*g[j])%p;
	}
	for (int j=1;j<=n;j++)
	{
		int tmp=0,t;
		for (int i=1;i<j;i++)
		tmp=(tmp+1LL*C[j][i]*g[i]%p*h[j][i]%p*(f[i]+f[j-i]+i*(i-1)/2+i*(j-i)))%p;
		f[j]=(tmp+1LL*g[j]*j*(j-1)/2%p)*exp(1-g[j],p-2,p)%p;
	}
	f[n]=(f[n]+p)%p;
	cout<<f[n];
	return 0;
}