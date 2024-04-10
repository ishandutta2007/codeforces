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
const int N=300100,p=1000000007;
int a[N],n;
int check(LL mid)
{
	LL s=0;
	for (int i=n;i>=1;i--)
	{
		int t;
		if (a[i]>=mid*2) t=a[i]-mid*2,s+=mid,mid=0;
		else s+=a[i]/2,mid-=a[i]/2,t=a[i]%2;
		if (s>=t) s-=t;else s=0;
	}
	if (mid==0&&s==0) return 1;
	else return 0;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	LL l=0,r=1LL<<60;
	while (l<r)
	{
		LL mid=(l+r+1)/2;
		if (check(mid)) l=mid;else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}