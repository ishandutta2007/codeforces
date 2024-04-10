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
const int N=3020,p=1000000007;
char s[N][N],t[N][N];
int nxt[N],diff[N],len[N],n;
char a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",s[i]);
	for (int i=1;i<=n;i++) scanf("%s",t[i]);
	for (int i=1;i<=n;i++) len[i]=strlen(s[i]);
	int l=-1,r=-1,k=-1,lmost,rmost;
	for (int i=1;i<=n;i++)
	{
		int left=len[i],right=-1;
		for (int j=0;j<len[i];j++)
		if (s[i][j]!=t[i][j]) upmin(left,j),upmax(right,j);
		diff[i]=right;
		if (right==-1) continue;
		if (l==-1)
		{
			k=i;l=left;r=right;
			lmost=0;rmost=len[i]-1;
			continue;
		}
		if (right-left!=r-l) 
		{
			puts("NO");
			return 0;
		}
		int flag=0;
		for (int j=left;j<=right;j++)
		{
			if (s[k][j-left+l]!=s[i][j]) flag=1;
			if (t[k][j-left+l]!=t[i][j]) flag=1;
		}
		if (flag)
		{
			puts("NO");
			return 0;
		}
		int j;
		for (j=r;j<=rmost&&j-r+right<len[i];j++)
		if (s[i][j-r+right]!=s[k][j]) break;
		rmost=min(rmost,j-1);
		for (j=l;j>=lmost&&j-r+right>=0;j--)
		if (s[i][j-r+right]!=s[k][j]) break;
		lmost=max(lmost,j+1);
	}
	int leng=rmost-lmost+1;
	for (int i=lmost;i<=rmost;i++) a[i-lmost+1]=s[k][i];a[leng+1]=0;
	for (int i=2,j=0;i<=leng;i++)
	{
		while (j>0&&a[i]!=a[j+1]) j=nxt[j];
		if (a[i]==a[j+1]) j++;
		nxt[i]=j;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0,k=0;j<len[i];j++)
		{
			while (k>0&&s[i][j]!=a[k+1]) k=nxt[k];
			if (s[i][j]==a[k+1]) k++;
			if (k==leng)
			{
				if (diff[i]==-1||j!=diff[i]-r+rmost) 
				{
					puts("NO");
					return 0;
				}
				break;
			}
		}
	}
	puts("YES");
	printf("%s\n",a+1);
	for (int i=lmost;i<=rmost;i++) a[i-lmost+1]=t[k][i];a[leng+1]=0;
	printf("%s\n",a+1);
	return 0;
}
/*
2
abcabcz
abcz
abcdbdz
dbdz
   */