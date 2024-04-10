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
int d[N],c[N],a[N];
char s[N*2];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++) s[i+n]=s[i],c[s[i]-'a']++;
	for (int i=0;i<26;i++)
	if (c[i]>0)
	{
		int t=0,num=0;
		for (int j=0;j<n;j++) if (s[j]==i+'a') a[num++]=j;
		for (int j=1;j<n;j++)
		{
			int tmp=0;
			for (int k=0;k<26;k++) d[k]=0;
			for (int k=0;k<num;k++) d[s[a[k]+j]-'a']++;
			for (int k=0;k<26;k++) if (d[k]==1) tmp++;
			t=max(t,tmp);
		}
		ans+=t;
	}
	printf("%.9f\n",ans*1.0/n);
	return 0;
}