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
#include<cassert>
#define FR first
#define SC second
#define MP make_pair
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define pb push_back
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
const double pi=acos(-1);
//-----------------------
const int N=4020,p=1000000007;
struct point
{
	int x,y,d,id,kd;
	double beta;
};
vector<point> a;
int n,m,cas;
int cmp(point &p,point &q) { return p.beta<q.beta;} 
void solve(vector<point> &a)
{
	int mx=-1,mxi=0;
	int r=a.size()-1;
	for (int i=0;i<=r;i++)
	if (a[i].d>mx) mx=a[i].d,mxi=i;
	if (mx==1)
	{
		for (int i=0;i<=r;i++)
		if (a[i].d==0)
		{
			swap(a[i],a[0]);
			break;
		}
		assert(a[0].d==0);
		for (int i=1;i<=r;i++) 
		{
			assert(a[i].d==1);
			printf("%d %d\n",a[i].id,a[0].id);
		}
		return;
	}
	swap(a[0],a[mxi]);
	point stdd=a[0];
	int now=0;
	for (int i=1;i<=r;i++) 
	{
		a[i].beta=atan2(a[i].y-stdd.y,a[i].x-stdd.x);
		if (a[i].beta>0) now+=a[i].d-1,a[i].kd=0,a[i].beta-=pi;
		else a[i].kd=1;
	}
	a[0].beta=-1234;
	sort(a.begin(),a.end(),cmp);
	int i;
	for (i=0;i<=r;)
	{
		if (now<=-1&&now>=1-mx) break;
		i++;
		if (a[i].kd) now+=a[i].d-1;
		else now-=a[i].d-1;
	}
	assert(now<=-1&&now>=1-mx);
	vector<point> pl,pr;
	stdd.d=-now;
	pl.pb(stdd);
	stdd.d=now+mx;
	pr.pb(stdd);
	for (int j=1;j<=r;j++)
	if (j<=i&&a[j].kd==1) pl.pb(a[j]);
	else if (j>i&&a[j].kd==0) pl.pb(a[j]);
	else pr.pb(a[j]);
	a.clear();
	solve(pl);
	solve(pr);
}	
int main()
{
	scanf("%d",&cas);
	for (int ii=1;ii<=cas;ii++)
	{
		scanf("%d%d",&n,&m);
		a.clear();
		a.resize(n+m);
		for (int i=0;i<m;i++) read(a[i].d);
		for (int i=m;i<m+n;i++) 
		{
			read(a[i].x),read(a[i].y);
			a[i].id=i-m+1;a[i].d=0;
		}
		for (int i=0;i<m;i++) 
		{
			read(a[i].x),read(a[i].y);
			a[i].id=i+1;
		}
		printf("YES\n");
		solve(a);
	}
	return 0;
}
/*
1350
1 4
1 1 1 1
-6 -7
-1 4
10 9
-1 1
-10 -7
4 1
4
-9 -2
4 -6
9 2
-8 10
0 7
1 4
1 1 1 1
-2 -2
7 -10
2 7
4 -2
5 7
2 3
1 1 2
4 -8
1 -2
5 9
-6 -6
-8 -6
1 4
1 1 1 1
-10 -7
0 6
-4 1
-6 10
-4 -5
3 1
3
3 0
-6 4
2 -2
2 -6
2 1
2
-2 -5
5 7
0 2
3 2
1 3
8 -1
-8 -4
-8 -2
0 9
-10 8
3 2
3 1
9 3
3 -7
5 9
-2 6
5 -4
2 1
2
-2 6
2 -1
7 4
1 4
1 1 1 1
6 -1
-1 -2
-1 -7
1 -7
7 8
2 2
1 2
6 8
-3 4
-10 7
10 4
2 3
1 1 2
0 -8
8 -4
-6 10
-3 0
7 8
   
   */