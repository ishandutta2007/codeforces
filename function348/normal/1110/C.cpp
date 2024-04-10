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
namespace geometry
{
	typedef double T;
	struct point
	{
		T x,y;
		point(T X=0,T Y=0) { x=X,y=Y;}
	};
	point operator +(point a,point b) { return point(a.x+b.x,a.y+b.y);}
	point operator -(point a,point b) { return point(a.x-b.x,a.y-b.y);}
	point operator *(point a,T d) { return point(a.x*d,a.y*d);}
	point operator /(point a,T d) { return point(a.x/d,a.y/d);}
	T operator ^(point a,point b) { return a.x*b.y-a.y*b.x;}
	double dist(point a) { return sqrt(a.x*a.x+a.y*a.y);}
	int intersect(point a,point b,point c,point d)
	{
		// for seg with line
		double eps=1e-8;
		if (((d-c)^(a-c))*((d-c)^(b-c))<-eps) return 1;
		return 0;
	}
	point getpoint(point a,point b,point c,point d)
	{
		double u=(b-a)^(c-a);
		double v=(d-a)^(b-a);
		return (c*v+d*u)/(u+v);
	}
};
//---------template--------------
const int N=200020,inf=1000000000,p=998244353;
const double eps=1e-8;
int gcd(int a,int b) { return b?gcd(b,a%b):a;}
int main()
{
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int a,ans=0;
		scanf("%d",&a);
		int b=a+1;
		while (b%2==0) b/=2;
		if (b==1)
		{
			b=0;
			for (int i=2;i*i<=a;i++)
				if (a%i==0) 
				{
					printf("%d\n",a/i);
					b=1;
					break;
				}
			if (b==0) printf("1\n");
		}
		else
		{
			b=1;
			while (b<=a) b*=2;
			printf("%d\n",b-1);
		}
	}
}

/*
   0 0 0 0
   0 1 1 0
   1 1 0 1
   */