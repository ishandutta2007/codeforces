#include<cstdio>
#include<iostream>
using namespace std;
const int N=200010;
struct rec {int len;int a[35];};
int n,q;
int a[N],b[N];
int s[N*4];
rec t[N*4];
void ins(rec &c,int x)
{
	for (int i=1;i<=c.len;i++)
	if (c.a[i]&-c.a[i]&x) x^=c.a[i];
	if (x==0) return;
	for (int i=1;i<=c.len;i++)
	if (x&-x&c.a[i]) c.a[i]^=x;
	c.len++;
	c.a[c.len]=x;
}

rec operator + (rec a,rec b) 
{
	rec c;
	for (int j=1;j<=a.len;j++) c.a[j]=a.a[j];c.len=a.len;
	for (int j=1;j<=b.len;j++) ins(c,b.a[j]);
	return c;
}


void change(int i,int l,int r,int ll,int rr,int k)
{
	if (ll<=l&&r<=rr) { s[i]^=k;return;}
	int mid=(l+r)>>1;
	if (ll<=mid) change(i*2,l,mid,ll,rr,k);
	if (rr> mid) change(i*2+1,mid+1,r,ll,rr,k);
}
int query(int i,int l,int r,int k)
{
	if (l==r) return s[i];
	int mid=(l+r)>>1;
	if (k<=mid) return s[i]^query(i*2,l,mid,k);
	if (k> mid) return s[i]^query(i*2+1,mid+1,r,k);
}
void modify(int i,int l,int r,int k,int p)
{
	if (l==r)
	{
		t[i].a[1]^=p;
		if (t[i].a[1]!=0) t[i].len=1;else t[i].len=0;
		return;
	}
	int mid=(l+r)>>1;
	if (k<=mid) modify(i*2,l,mid,k,p);
	if (k> mid) modify(i*2+1,mid+1,r,k,p);
	t[i]=t[i*2]+t[i*2+1];
}
rec ask(int i,int l,int r,int ll,int rr)
{
	if (ll<=l&&r<=rr) return t[i];
	int mid=(l+r)>>1;
	if (rr<=mid) return ask(i*2,l,mid,ll,rr);
	if (ll> mid) return ask(i*2+1,mid+1,r,ll,rr);
	return ask(i*2,l,mid,ll,rr)+ask(i*2+1,mid+1,r,ll,rr);
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i< n;i++) b[i]=a[i]^a[i+1];
	for (int i=1;i<=n;i++) change(1,1,n,i,i,a[i]);
	for (int i=1;i< n;i++) modify(1,1,n,i,b[i]);
	while (q--)
	{
		int kd,l,r,k;
		scanf("%d%d%d",&kd,&l,&r);
		if (kd==1)
		{
			scanf("%d",&k);
			change(1,1,n,l,r,k);
			if (l>1) modify(1,1,n,l-1,k);
			modify(1,1,n,r,k);
		}
		if (kd==2)
		{
			rec tmp;
			tmp.len=0;
			if (l<r) tmp=ask(1,1,n,l,r-1);
			ins(tmp,query(1,1,n,l));
			printf("%d\n",(1<<tmp.len));
		}
	}
	return 0;
}