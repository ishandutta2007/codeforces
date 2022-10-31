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
#define FR first
#define SC second
#define MP make_pair
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
int n,all,f,ans;
int c[100],d[100];
char s[100100],t[101000];
int main()
{
	scanf("%d",&n);
	rep(i,0,25) c[i]=1;all=26;f=0;ans=0;
	rep(i,1,n) 
	{
		scanf("%s",s);scanf("%s",t);
		if (f) 
		{
			if (s[0]!='.'&&i<n) ans++;
			continue;
		}
		int m=strlen(t);
		if (s[0]=='!') 
		{
			rep(j,0,25) d[j]=0;
			rep(j,0,m-1) d[t[j]-'a']=1;
			rep(j,0,25) all-=c[j],c[j]&=d[j],all+=c[j];
		}
		if (s[0]=='?') all-=c[t[0]-'a'],c[t[0]-'a']=0;
		if (s[0]=='.') rep(j,0,m-1) all-=c[t[j]-'a'],c[t[j]-'a']=0;
		if (all==1) f=1;
	}
	cout<<ans;
	return 0;
}