#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000

struct node { int l,r,v; }a[100010];
struct Node { int x,y; }b[100010];
struct hhhh { int p,x,y,l,r,v,id; }h[400010];
struct tree { int ls,rs,sum; }t[15000010];

int ans[100010],n,m,tt,rt1,rt2,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline bool cmp(const hhhh &x,const hhhh &y) { return (x.x!=y.x)?x.x<y.x:x.p<y.p; }

inline void modify(int &o,ll l,ll r,int x,int hh)
{
	if (!o) o=++tot;
	t[o].sum+=hh;
	if (l==r) return;
	ll mid=(l+r)>>1;
	if (x<=mid) modify(t[o].ls,l,mid,x,hh);
	else modify(t[o].rs,mid+1,r,x,hh);
}

inline int query(int o,ll l,ll r,int x,int y)
{
	if (!o) return 0;
	if (l>=x&&r<=y) return t[o].sum;
	ll mid=(l+r)>>1,res=0;
	if (x<=mid) res+=query(t[o].ls,l,mid,x,y);
	if (y>mid) res+=query(t[o].rs,mid+1,r,x,y);
	return res;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) a[i].l=rd();
	for (int i=1;i<=n;i++) a[i].r=rd();
	for (int i=1;i<=n;i++) a[i].v=rd();
	for (int i=1;i<=m;i++) b[i].x=rd();
	for (int i=1;i<=m;i++) b[i].y=rd();
	tt=0;
	for (int i=1;i<=n;i++)
	{
		h[++tt]=(hhhh){0,a[i].l,0,a[i].l,a[i].r,a[i].v,0};
		h[++tt]=(hhhh){0,a[i].r+1,1,a[i].l,a[i].r,a[i].v,0};
	}
	for (int i=1;i<=m;i++) h[++tt]=(hhhh){1,b[i].x,b[i].y,0,0,0,i};
	sort(h+1,h+tt+1,cmp);
	tot=0;
	int now=0;
	for (int i=1;i<=tt;i++)
	{
		if (h[i].p==0)
		{
			if (!h[i].y) modify(rt1,0,inf*2,h[i].l+h[i].v,1),modify(rt2,-inf,inf,h[i].l-h[i].v,1),now++;
			else modify(rt1,0,inf*2,h[i].l+h[i].v,-1),modify(rt2,-inf,inf,h[i].l-h[i].v,-1),now--;
		}
		else ans[h[i].id]=query(rt1,0,inf*2,0,h[i].x+h[i].y)+query(rt2,-inf,inf,-inf,h[i].x-h[i].y)-now;
	}
	for (int i=1;i<=m;i++) print(ans[i]);
	putchar('\n');
	return 0;
}