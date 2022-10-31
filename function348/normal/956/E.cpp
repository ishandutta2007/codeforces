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
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
int pow(int a,int b,int c)
{
    if (a==0)return 0;
	b=(b%(c-1)+c-1)%(c-1);
	int d=1;
    while (b)
    {
        if (b&1) d=(1LL*d*a)%c;
        a=1LL*a*a%c;b>>=1;
    }
    return d;
}
const int N=15010,p=985661441,inf=200000000;
int random(int n) { return 1LL*rand()*rand()%n+1;}
//struct Edge {int y,z,ne;};
inline void up(int &x,int y) { x+=y;if (x>=p) x-=p;if (x<=-p) x+=p;}


//inline void add(int x,int y,int z) { e[++num]=(Edge){y,z,last[x]};last[x]=num;}
void read(int &x)
{
	char ch;
	while ((ch=getchar())<=32);
	x=ch-48;
	while ((ch=getchar())>32) x=x*10+ch-48;
}
int n,l,r;
int a[N],b[N],f[N],g[N];
int main()
{
	scanf("%d%d%d",&n,&l,&r);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	f[0]=1;int num=0,sum=0,ans=0;
	for (int i=1;i<=n;i++)
	if (b[i]==0)
		for (int j=r;j>=a[i];j--) up(f[j],f[j-a[i]]);
	else a[++num]=a[i];
	sort(a+1,a+1+num);
	for (int i=1;i<=num;i++) sum+=a[i];
	for (int i=0;i<=r;i++) g[i]=f[i];
	int s=0;
	for (int i=num;i>=1;i--)
	{
		for (int j=r;j>=a[i];j--) up(f[j],f[j-a[i]]);
		s+=a[i];
		if (sum-a[i]<=r-l) 
		{
			for (int j=l;j+sum-a[i]<=r;j++) 
			if (f[j]) 
			{ if (j>=s&&f[j]==g[j-s]) continue;ans=i;break;}
			if (ans) break;		
		}
		sum-=a[i];
	}
	printf("%d\n",ans);
	return 0;
}
/*
	-x[j]*v[i]+x[i]*(w+v[j])=x[j]*w
	(x[i]-x[j])*(v[i]+v[j])=x[i]*v[i]-x[j]*v[j]+w*(x[j]-x[i])
	(x[i]-v[i])*(x[j]+v[j])=x[i]*x[j]-v[i]*v[j]+w*(x[j]-x[i])
 */