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
const int N=300100,p=998244353,inv2=(p+1)/2;
int a[N],b[N],c[N],n,k,x,y,z;
int r[N],s[N],t[N],ans[N];
int exp(int a,int b,int c)
{
	if (b<0) b+=c-1;
	int d=1;
	while (b)
	{
		if (b&1) d=1LL*d*a%c;
		a=1LL*a*a%c;b>>=1;
	}
	return d;
}
void fwt(int *a,int n)
{
	if (n==1) return;
	for (int i=0;i<n/2;i++)
	{
		int u=a[i],t=a[i+n/2];
		a[i]=u+t;a[i+n/2]=u-t;
	}
	fwt(a,n/2);fwt(a+n/2,n/2);
}
void fwt_rev(int *a,int n)
{
	if (n==1) return;
	fwt_rev(a,n/2);fwt_rev(a+n/2,n/2);
	for (int i=0;i<n/2;i++)
	{
		int u=a[i],t=a[i+n/2];
		a[i]=1LL*(u+t)*inv2%p;
		a[i+n/2]=1LL*(u-t)*inv2%p;
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%d%d%d",&x,&y,&z);
	int tmp=0;
	for (int i=1;i<=n;i++) 
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		b[i]^=a[i];c[i]^=a[i];
		tmp^=a[i];
		r[b[i]]++;s[c[i]]++;t[b[i]^c[i]]++;
	}
	fwt(r,1<<k);
	fwt(s,1<<k);
	fwt(t,1<<k);
	for (int i=0;i<(1<<k);i++)
	{
		/*
		   x+y+z+w=n
		   x+y-z-w=r[i]
		   x-y+z-w=s[i]
		   x-y-z+w=t[i]
		   */
		int u=1LL*(0LL+n+r[i]+s[i]+t[i])*inv2%p*inv2%p;
		ans[i]=exp((0LL+x+y+z)%p,u,p);
		u=1LL*(0LL+n+r[i]-s[i]-t[i])*inv2%p*inv2%p;
		ans[i]=1LL*ans[i]*exp(x+y-z,u,p)%p;
		u=1LL*(0LL+n-r[i]+s[i]-t[i])*inv2%p*inv2%p;
		ans[i]=1LL*ans[i]*exp(x-y+z,u,p)%p;
		u=1LL*(0LL+n-r[i]-s[i]+t[i])*inv2%p*inv2%p;
		ans[i]=1LL*ans[i]*exp(x-y-z,u,p)%p;
	}
	fwt_rev(ans,1<<k);
	for (int i=0;i<(1<<k);i++)
	{
		if (ans[i^tmp]<0) ans[i^tmp]+=p;
		printf("%d ",ans[i^tmp]);
	}
	return 0;
}