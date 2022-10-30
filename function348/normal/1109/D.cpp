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
#include<signal.h>
#include<unistd.h>
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
template<class T> void upmax(T &a,T b) { if (a<b) a=b;}
template<class T> void upmin(T &a,T b) { if (a>b) a=b;}

//---------template--------------
const int N=2000000,p=1000000007;
int n,m;
int f[N],g[N];
int ans;
int A(int n,int m) { return 1LL*f[n]*g[n-m]%p;}
int C(int n,int m) { return 1LL*f[n]*g[n-m]%p*g[m]%p;}
int exp(int a,int b,int c)
{
	int d=1;
	while (b)
	{
		if (b&1) d=1LL*d*a%c;
		b>>=1;
		a=1LL*a*a%c;
	}
	return d;
}
int F(int n,int m) 
{
	if (n==m) return 1;
	return 1LL*m*exp(n,n-m-1,p)%p;
}
int main()
{
	scanf("%d%d",&n,&m);
	f[0]=f[1]=g[0]=g[1]=1;
	for (int i=2;i<=1000000;i++) f[i]=i,g[i]=-1LL*g[p%i]*(p/i)%p;
	for (int i=2;i<=1000000;i++) f[i]=1LL*f[i-1]*f[i]%p;
	for (int i=2;i<=1000000;i++) g[i]=1LL*g[i-1]*g[i]%p;
	for (int i=1;i<=m&&i<=n-1;i++)
	{
		ans=(ans+1LL*A(m-1,i-1)*C(n-2,i-1)%p*exp(m,n-1-i,p)%p*F(n,i+1))%p;
	}
	if (ans<0) ans+=p;
	printf("%d\n",ans);
}