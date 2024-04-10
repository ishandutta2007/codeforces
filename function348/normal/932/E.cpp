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
const int N=5010;
const int p=1000000007;
int n,m;
int c[N][N],pw[N],f[N];
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
int main()
{
	/*
	sigma(C[n][i]*i^k)=f[k];1<=i<=n
		 (C[n][i-1]*(n-i+1)*i^(k-1))
		 (n+1)*C[n][i-1]*i^(k-1)-C[n][i-1]*i^k

		 (n+1)*C[n][i-1]*C[k-1][l]*(i-1)^l 0<=l<=k-1
		-C[n][i-1]*C[k][l]*(i-1)^l 0<=l<=k

	2*f[k]=(n+1)*C[k-1][l]*(f[l]-n^l)
		-C[k][l]*(f[l]-n^l)+n^k
	 */
	scanf("%d%d",&n,&m);
	c[0][0]=1;
    for (int i=1;i<=m;i++)
    for (int j=0;j<=i;j++)
        c[i][j]=(c[i-1][j]+(j?c[i-1][j-1]:0))%p;
	f[0]=pow(2,n,p);
	pw[0]=1;int inv2=(p+1)/2;
	for (int i=1;i<=m;i++) pw[i]=1LL*pw[i-1]*n%p;
	for (int k=1;k<=m;k++)
	{
		for (int l=0;l<=k-1;l++) f[k]=(f[k]+1LL*c[k-1][l]*(f[l]-pw[l]))%p;
		f[k]=1LL*f[k]*(n+1)%p;
		for (int l=0;l<=k-1;l++) f[k]=(f[k]-1LL*c[k][l]*(f[l]-pw[l]))%p;
		f[k]=1LL*(f[k]+pw[k])*inv2%p;
	}
	f[m]=(f[m]+p)%p;
	cout<<f[m];
	return 0;
}