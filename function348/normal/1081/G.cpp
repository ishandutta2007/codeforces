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
const int N=200220,inf=1000000000;
int n,k,p,ans;
int a[N],inv[N],s[N];
void get(int n,int k)
{
	if (k==1||n==1) {a[n]++;return;}
	get(n/2,k-1);
	get((n+1)/2,k-1);
}
int calc(int n,int m)
{
	int res=1LL*n*m%p*inv[2]%p;
	for (int i=1;i<=m;i++) res=(0LL+res-s[n+i]+s[i])%p;
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&k,&p);
	inv[1]=1;
	for (int i=2;i<=max(n*2,4);i++) inv[i]=-1LL*inv[p%i]*(p/i)%p;
	for (int i=1;i<=n*2;i++) s[i]=(s[i-1]+inv[i])%p;
	get(n,k);
	for (int i=1;i<=n;i++)
	if (a[i])
	{
		ans=(ans+1LL*i*(i-1)%p*inv[4]%p*a[i])%p;
	}
	ans=(ans+p)%p;
	for (int i=1;i<=n;i++)
	if (a[i])
		ans=(ans+1LL*a[i]*(a[i]-1)%p*inv[2]%p*calc(i,i))%p;
	for (int i=1;i<=n;i++) if (a[i])
	for (int j=i+1;j<=n;j++) if (a[j])
		ans=(ans+1LL*a[i]*a[j]%p*calc(i,j))%p;
	ans=(ans+p)%p;
	printf("%d\n",ans);
	return 0;
}