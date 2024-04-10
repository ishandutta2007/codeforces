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
#include<unordered_map>
#include<unordered_set>
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
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
//-----------------------
const int N=102000,p=1000000007;
int ans;
int gcd(int a,int b) { return b==0?a:gcd(b,a%b);}
void calc(int l,int r,int p,int q) { ans=max(ans,min(r,q)-max(l,p)+1);}
int main()
{
	int la,ra,ta,lb,rb,tb;
	ans=0;
	scanf("%d%d%d",&la,&ra,&ta);
	scanf("%d%d%d",&lb,&rb,&tb);
	if (ra>rb)
	{
		swap(la,lb);
		swap(ra,rb);
		swap(ta,tb);
	}
	int d=gcd(ta,tb);
	int k=(rb-ra)/d;
	calc(la+k*d,ra+k*d,lb,rb);
	k++;
	calc(la+k*d,ra+k*d,lb,rb);
	printf("%d\n",ans);
	return 0;
}