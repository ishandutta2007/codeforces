#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
typedef long long LL;
int n,m;
int a[N];
LL s[N*4],t[N*4];
void build(int i,int l,int r)
{
	if (l==r) {s[i]=t[i]=a[l];return;}
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	s[i]=s[i*2]+s[i*2+1];
	t[i]=max(t[i*2],t[i*2+1]);
}
LL ask(int i,int l,int r,int ll,int rr)
{
	if (ll<=l&&r<=rr) return s[i];
	int mid=(l+r)>>1;
	if (rr<=mid) return ask(i*2,l,mid,ll,rr);
	if (ll> mid) return ask(i*2+1,mid+1,r,ll,rr);
	return ask(i*2,l,mid,ll,rr)+ask(i*2+1,mid+1,r,ll,rr);
}
void change1(int i,int l,int r,int ll,int rr,int x)
{
	if (l==r) {s[i]%=x;t[i]%=x;return;}
	if (t[i]<x) return;
	int mid=(l+r)>>1;
	if (ll<=mid) change1(i*2,l,mid,ll,rr,x);
	if (rr> mid) change1(i*2+1,mid+1,r,ll,rr,x);
	s[i]=s[i*2]+s[i*2+1];
	t[i]=max(t[i*2],t[i*2+1]);
}
void change2(int i,int l,int r,int k,int dlt)
{
	if (l==r) {s[i]=t[i]=dlt;return;}
	int mid=(l+r)>>1;
	if (k<=mid) change2(i*2,l,mid,k,dlt);
	if (k> mid) change2(i*2+1,mid+1,r,k,dlt);
	s[i]=s[i*2]+s[i*2+1];
	t[i]=max(t[i*2],t[i*2+1]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	while (m--)
	{
		int kd,x,y,z;
		scanf("%d%d%d",&kd,&x,&y);
		if (kd==2) scanf("%d",&z);
		if (kd==1) printf("%I64d\n",ask(1,1,n,x,y));
		if (kd==2) change1(1,1,n,x,y,z);
		if (kd==3) change2(1,1,n,x,y);
	}
	return 0;
}