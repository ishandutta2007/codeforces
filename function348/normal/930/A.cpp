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
const int N=100010;
const int p=1000000007;
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
int n,m,ans;
int d[N],s[N];
int main()
{
	scanf("%d",&n);
	d[1]=s[1]=1;
	for (int i=2;i<=n;i++)
	{
		int x;scanf("%d",&x);
		d[i]=d[x]+1;s[d[i]]++;
	}
	for (int i=1;i<=n;i++) ans+=s[i]%2;
	cout<<ans<<endl;
	return 0;
}