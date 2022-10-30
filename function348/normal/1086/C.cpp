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
const int N=1000020,inf=1000000000;
int cas,n,flag,k;
char a[N],b[N],s[N];
int v[50],p[50],ans[50];
void dfs(int i,int f1,int f2)
{
	if (flag) return;
	if (i==n||(f1==0&&f2==0))
	{
		flag=1;
		for (int ii=0,jj=0;ii<k;ii++)
		if (p[ii]==-1)
		{
			while (v[jj]) jj++;
			p[ii]=jj;jj++;
		}
		for (int j=0;j<k;j++) ans[j]=p[j];
		return;
	}
	int l=0,r=k-1;
	if (f1) l=a[i];
	if (f2) r=b[i];
	if (p[s[i]]!=-1)
	{
		if (l<=p[s[i]]&&p[s[i]]<=r) dfs(i+1,f1&&p[s[i]]==a[i],f2&&p[s[i]]==b[i]);
		return;
	}
	for (int j=l;j<=r;j++)
	if (v[j]==0)
	{
		v[j]=1;p[s[i]]=j;
		dfs(i+1,f1&&j==a[i],f2&&j==b[i]);
		v[j]=0;p[s[i]]=-1;
		if (flag) return;
	}
}
int main()
{
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&k);
		scanf("%s",s);
		scanf("%s",a);
		scanf("%s",b);
		n=strlen(s);
		for (int i=0;i<n;i++) 
		{
			s[i]-='a';
			a[i]-='a';
			b[i]-='a';
		}
		for (int i=0;i<k;i++) p[i]=-1,v[i]=0;
		flag=0;
		dfs(0,1,1);
		if (flag) 
		{
			puts("YES");
			for (int i=0;i<k;i++) putchar(ans[i]+97);
			puts("");
		}
		else puts("NO");
	}
	return 0;
}