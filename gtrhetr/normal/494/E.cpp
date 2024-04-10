#include<bits/stdc++.h>
using namespace std;
#define y1 DCXISSOHANDSOME

struct tree { int ls,rs,cnt,val; }t[5000010];

struct node
{
	int x,l,r,v;
	node() {}
	node(int x1,int l1,int r1,int v1):x(x1),l(l1),r(r1),v(v1) {}
}h[100010];

int n,m,k,tt,tot,root;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(const node &x,const node &y) { return x.x<y.x; }

inline void modify(int &o,int l,int r,int x,int y,int hh)
{
	if (!o) o=++tot;
	if (l>=x&&r<=y)
	{
		t[o].cnt+=hh;
		t[o].val=(!t[o].cnt)?(t[t[o].ls].val^t[t[o].rs].val):(r^(l-1));
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) modify(t[o].ls,l,mid,x,y,hh);
	if (y>mid) modify(t[o].rs,mid+1,r,x,y,hh);
	t[o].val=(!t[o].cnt)?(t[t[o].ls].val^t[t[o].rs].val):(r^(l-1));
}

int main()
{
	n=rd();m=rd();k=rd();tt=tot=0;
	for (int i=1;i<=m;i++)
	{
		int x1=rd(),y1=rd(),x2=rd(),y2=rd();
		h[++tt]=node(x1,y1,y2,1);
		h[++tt]=node(x2+1,y1,y2,-1);
	}
	sort(h+1,h+tt+1,cmp);
	int hh=0,lst=1;
	for (int i=1,j;i<=tt;i=j)
	{
		hh^=(((lst-1)^(h[i].x-1))&t[root].val);lst=h[i].x;
		for (j=i;j<=tt&&h[j].x==h[i].x;j++) modify(root,1,n,h[j].l,h[j].r,h[j].v);
	}
	int mx=1;
	for (;mx<=k;mx<<=1);
	if (!(hh&(mx-1))) puts("Malek");
	else puts("Hamed");
	return 0;
}