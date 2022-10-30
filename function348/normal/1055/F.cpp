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
const int N=1000020,p=1000000007;
int n;
LL k;
LL w[N];
int l[N],r[N],pre[N];
int main()
{
	scanf("%d%I64d",&n,&k);
	for (int i=2;i<=n;i++)
	{
		int fa;
		scanf("%d%I64d",&fa,&w[i]);
		w[i]^=w[fa];
	}
	sort(w+1,w+1+n);
	for (int i=1;i<=n;i++) l[i]=1,r[i]=n;
	LL ans=0;
	// 001011
	//  
	for (int i=61;i>=0;i--)
	{
		LL cnt=0;
		for (int j=1,k=1;j<=n;j++)
		{
			if ((~w[j])&(1LL<<i)) k=j;
			pre[j]=k;
		}
		for (int j=1;j<=n;j++)
		if (l[j]<=r[j])
		{
			if (pre[r[j]]<l[j]) pre[r[j]]=l[j]-1;
			if (w[j]&(1LL<<i)) cnt+=r[j]-pre[r[j]];
			else cnt+=pre[r[j]]-l[j]+1;
		}
		if (k<=cnt)
		{
			for (int j=1;j<=n;j++)
				if (l[j]<=r[j])
				{
					if (w[j]&(1LL<<i)) l[j]=pre[r[j]]+1;
					else r[j]=pre[r[j]];
				}

		}
		else
		{
			k-=cnt;
			ans|=1LL<<i;
			for (int j=1;j<=n;j++)
				if (l[j]<=r[j])
				{
					if (w[j]&(1LL<<i)) r[j]=pre[r[j]];
					else l[j]=pre[r[j]]+1;
				}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
   */