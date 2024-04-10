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
LL n,x;
int m;
LL calc(LL n,LL m)
{
	if (m%2==1) return (m+1)/2;
	else return calc(n-m/2,n-m/2)+m/2;
}
int main()
{
	cin>>n>>m;
	while (m--)
	{
		cin>>x;
		cout<<calc(n,x)<<endl;
	}
	return 0;
}