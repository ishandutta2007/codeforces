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
#include<unordered_map>
#define FR first
#define SC second
#define MP make_pair
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define pb push_back
#define ws wss
#define left lll
#define right rrr
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
template<class T> void upmax(T &a,T b) { if (a<b) a=b;}
template<class T> void upmin(T &a,T b) { if (a>b) a=b;}
void read(int &x)
{
	char ch;int fu=1;
	while ((ch=getchar())<=32);
	x=0;
	if (ch=='-') fu=-1;else x=ch-48;
	while ((ch=getchar())>32) x=x*10+ch-48;
	x*=fu;
}
void read(unsigned long long &x)
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


int gcd(int a,int b) { return b>0?gcd(b,a%b):a;}
//-----------------------
const int N=110000;//,p=1000000007,inv2=(p+1)/2;
int cas,n;
int f[N];
int main()
{
	int p;
	scanf("%d%d",&n,&p);
	for (int i=0;i<32;i++)
	{
		int m=n-i*p;
		if (m<0||m<i) continue;
		int k=0;
		while (m)
		{
			k+=m%2;
			m/=2;
		}
		if (k<=i) 
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
}