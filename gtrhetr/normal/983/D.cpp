#include<bits/stdc++.h>
using namespace std;

struct node { int x1,y1,x2,y2; }a[100010];

struct hhhh { int x,l,r,id,tag; }h[200010];

set<int> st[800010];

int mx[1600010],mn[1600010];
int num[200010],L[100010],R[100010],n,tt,tot;
bool vis[100010];

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline int min(const int &x,const int &y) { return (x<y)?x:y; }
inline int max(const int &x,const int &y) { return (x>y)?x:y; }

inline bool cmp(const hhhh &x,const hhhh &y) { return x.x<y.x; }

inline void pushup(const int &o)
{
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	if (st[o].empty()) return;
	int hh=*st[o].rbegin();
	mn[o]=max(mn[o],hh);
	if (hh>mx[o])
	{
		if (vis[hh]||hh<mn[o]) mx[o]=0;
		else mx[o]=hh;
	}
}

inline void modify(int o,int l,int r,int x,int y,int hh)
{
	if (l>=x&&r<=y) { st[o].insert(hh);pushup(o);return; }
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline void del(int o,int l,int r,int x,int y,int hh)
{
	if (l>=x&&r<=y) { st[o].erase(hh);pushup(o);return; }
	int mid=(l+r)>>1;
	if (x<=mid) del(o<<1,l,mid,x,y,hh);
	if (y>mid) del(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline void update(int o,int l,int r,int x,int y,int hh)
{
	if (l>=x&&r<=y) { pushup(o);return; }
	int mid=(l+r)>>1;
	if (x<=mid) update(o<<1,l,mid,x,y,hh);
	if (y>mid) update(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline int gao()
{
	for (int i=1,j;i<=tot;i=j)
	{
		for (j=i;j<=tot&&h[j].x==h[i].x;j++);
		for (int k=i;k<j;k++)
		{
			if (h[k].tag==1) modify(1,1,tt,h[k].l,h[k].r,h[k].id);
			else del(1,1,tt,h[k].l,h[k].r,h[k].id);
		}
		while (mx[1])
		{
			int now=mx[1];
			vis[now]=true;
			update(1,1,tt,L[now],R[now],now);
		}
	}
	int res=0;
	for (int i=1;i<=n;i++) res+=vis[i];
	return res+1;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i].x1=rd(),a[i].y1=rd(),a[i].x2=rd()-1,a[i].y2=rd();
	tt=0;
	for (int i=1;i<=n;i++) num[++tt]=a[i].y1,num[++tt]=a[i].y2;
	sort(num+1,num+tt+1);
	tt=unique(num+1,num+tt+1)-num-1;
	for (int i=1;i<=n;i++)
	{
		a[i].y1=lower_bound(num+1,num+tt+1,a[i].y1)-num;
		a[i].y2=lower_bound(num+1,num+tt+1,a[i].y2)-num-1;
		L[i]=a[i].y1;R[i]=a[i].y2;
	}
	tot=0;
	for (int i=1;i<=n;i++) h[++tot]=(hhhh){a[i].x1,a[i].y1,a[i].y2,i,1},h[++tot]=(hhhh){a[i].x2+1,a[i].y1,a[i].y2,i,-1};
	sort(h+1,h+tot+1,cmp);
	printf("%d\n",gao());
	return 0;
}