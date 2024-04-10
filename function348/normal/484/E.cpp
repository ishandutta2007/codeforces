#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
struct rec { int len,l,r,c;};
int a[N],id[N];
rec t[N*20];
int lc[N*20],rc[N*20];
int T[N];
int num,n,m;
int cmp(int i,int j) { return a[i]<a[j];}
rec operator + (rec a,rec b)
{
	rec c;
	c.len=a.len+b.len;
	c.c=max( a.r+b.l,max(a.c,b.c));
	if (a.l==a.len) c.l=a.len+b.l;else c.l=a.l;
	if (b.r==b.len) c.r=b.len+a.r;else c.r=b.r;
	return c;
}
int change(int i,int l,int r,int k)
{
	int mid=(l+r)/2,j=++num;
	t[j]=t[i];
	lc[j]=lc[i];rc[j]=rc[i];
	if (l==r) 
	{ 
		t[j].len=1;
		t[j].c=1;
		t[j].l=t[j].r=1;
		return j;
	}
	if (k<=mid) lc[j]=change(lc[i],l,mid,k);
		else    rc[j]=change(rc[i],mid+1,r,k);
	t[j]=t[lc[j]]+t[rc[j]];
	t[j].len=r-l+1;
	return j;
}
rec query(int i,int l,int r,int ll,int rr)
{
	if (i==0) return (rec){r-l+1,0,0,0};
	if (ll<=l&&r<=rr) return t[i];
	int mid=(l+r)/2;
	if (rr<=mid) return query(lc[i],l,mid,ll,rr);
	if (ll> mid) return query(rc[i],mid+1,r,ll,rr);
	return query(lc[i],l,mid,ll,rr)+query(rc[i],mid+1,r,ll,rr);
}
int main()
{
	scanf("%d",&n);
	t[0].len=-1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (int i=n;i>=1;i--) 
	T[i]=change(T[i+1],1,n,id[i]);
	scanf("%d",&m);
	while (m--)
	{
		int p,q,w;
		scanf("%d%d%d",&p,&q,&w);
		int l=1,r=n;
		while (l<r)
		{
			int mid=(l+r+1)/2;
			rec tmp=query(T[mid],1,n,p,q);
			if (tmp.c>=w) l=mid;else r=mid-1;
		}
		printf("%d\n",a[id[l]]);
	}
	return 0;
}