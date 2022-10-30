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
const int N=200020,inf=1000000000;
int n,q;
int rbit[N],sbit[N],pbit[N];
set<int> P,R,S;
char c[123],t[N];
// r>s>p>r
void C(int *bit,int i,int d) { for (;i<=n;i+=i&-i) bit[i]+=d;}
int  Q(int *bit,int i) { int res=0;for (;i;i-=i&-i) res+=bit[i];return res;}
int  Q(int *bit,int l,int r)
{
	if (l>r) return 0;
	return Q(bit,r)-Q(bit,l);
}
void get()
{
	if (R.size()==0)
	{
		if (S.size()==0) printf("%lu\n",P.size());
		else printf("%lu\n",S.size());
		return;
	}
	if (S.size()==0)
	{
		if (P.size()==0) printf("%lu\n",R.size());
		else printf("%lu\n",P.size());
		return;
	}
	if (P.size()==0)
	{
		printf("%lu\n",R.size());
		return;
	}
	set<int>::iterator it;
	int fr=(*R.begin());
	int fs=(*S.begin());
	int fp=(*P.begin());
	it=R.end();it--;int lr=*it;
	it=S.end();it--;int ls=*it;
	it=P.end();it--;int lp=*it;
	int ans=n;
	ans-=Q(rbit,fp,fs);
	ans-=Q(rbit,ls,lp);
	ans-=Q(sbit,fr,fp);
	ans-=Q(sbit,lp,lr);
	ans-=Q(pbit,fs,fr);
	ans-=Q(pbit,lr,ls);
	printf("%d\n",ans);
}
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",t+1);
	for (int i=1;i<=n;i++)
	{
		if (t[i]=='R') { R.insert(i);C(rbit,i,1);}else
		if (t[i]=='S') { S.insert(i);C(sbit,i,1);}
		else {P.insert(i);C(pbit,i,1);}
	}
	get();
	while (q--)
	{
		int i;
		scanf("%d%s",&i,c);
		if (t[i]=='R') { R.erase(i);C(rbit,i,-1);}else
		if (t[i]=='S') { S.erase(i);C(sbit,i,-1);}
		else { P.erase(i);C(pbit,i,-1);}
		t[i]=c[0];
		if (t[i]=='R') { R.insert(i);C(rbit,i,1);}else
		if (t[i]=='S') { S.insert(i);C(sbit,i,1);}
		else { P.insert(i);C(pbit,i,1);}
		get();
	}
	return 0;
}