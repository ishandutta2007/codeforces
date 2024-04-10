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
const int N=400020,inf=1000000000;
int abs(int n) { return n>0?n:-n;}
void print(int x,int y,int u,int v)
{
	while (x!=u||y!=v)
	{
		printf("%d %d\n",x,y);
		if (x<u) x++;else 
		if (x>u) x--;else
		if (y<v) y++;else 
			y--;
	}
}
int get(int x,int y,int z)
{
	if (x>y) swap(x,y);
	if (x>z) swap(x,z);
	if (y>z) swap(y,z);
	return y;
}
int main()
{
	int x1,y1,x2,y2,x3,y3;
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	int u=get(x1,x2,x3);
	int v=get(y1,y2,y3);
	int ans=abs(x1-u)+abs(x2-u)+abs(x3-u)+abs(y1-v)+abs(y2-v)+abs(y3-v);
	printf("%d\n",ans+1);
	printf("%d %d\n",u,v);
	print(x1,y1,u,v);
	print(x2,y2,u,v);
	print(x3,y3,u,v);
	return 0;
}