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
char s[N];
int p[N],a[N],b[N];
int n,k0,k1;
void print(int i,int len)
{
	if (p[i]==0)  printf("%d ",len);else print(p[i],len+1);
	printf("%d ",i);
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int f=0;
	for (int i=1;i<=n;i++)
	if (s[i]=='0')
	{
		if (k1>0) a[++k0]=i,k1--,p[i]=b[k1+1];
		else a[++k0]=i;
	}
	else 
	{
		if (k0>0) b[++k1]=i,k0--,p[i]=a[k0+1];
		else f=1;
	}
	if (f||k1>0) printf("-1\n");
	else
	{
		printf("%d\n",k0);
		for (int i=1;i<=k0;i++) 
		{print(a[i],1);
		printf("\n");
		}
	}
	return 0;
}