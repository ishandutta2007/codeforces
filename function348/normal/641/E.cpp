#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
const int N=100010,C=1000000000;
int n,num;
int kd[N],t[N],x[N],fr[N],nxt[N],ans[N];
map<int,int> S;
int lc[N*40],rc[N*40],s[N*40];
void change(int &i,int l,int r,int k,int d)
{
	if (i==0) i=++num;
	s[i]+=d;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (k<=mid) change(lc[i],l,mid,k,d);
	if (k> mid) change(rc[i],mid+1,r,k,d);
}
int query(int i,int l,int r,int rr)
{
	if (i==0) return 0;
	if (r<=rr) return s[i];
	int mid=(l+r)>>1,res=0;
	res+=query(lc[i],l,mid,rr);
	if (mid<rr) res+=query(rc[i],mid+1,r,rr);
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&kd[i],&t[i],&x[i]);
		fr[i]=1;
		if (S.count(x[i]))
		{
			nxt[S[x[i]]]=i;
			fr[i]=0;
		}
		S[x[i]]=i;
	}
	for (int i=1;i<=n;i++)
	if (fr[i])
	{
		for (int j=1;j<=num;j++) lc[j]=rc[j]=s[j]=0;
		num=1;
		int rt=1;
		for (int j=i;j;j=nxt[j])
		{
			if (kd[j]==1) change(rt,1,C,t[j], 1);
			if (kd[j]==2) change(rt,1,C,t[j],-1);
			if (kd[j]==3) ans[j]=query(1,1,C,t[j]);
		}
	}
	for (int i=1;i<=n;i++)
	if (kd[i]==3) printf("%d\n",ans[i]);
	return 0;
}