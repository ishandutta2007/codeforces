#include<bits/stdc++.h>
using namespace std;

struct node
{
	double s,v;
	node() {}
	node(double s1,double v1):s(s1),v(v1) {}
}h[400010];

double num[400010],V[200010];
int X[200010],Y[200010],id[400010],n,l,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

double mn[1600010],tag[1600010];

inline void pushup(const int &o) { mn[o]=min(mn[o<<1],mn[o<<1|1]); }

inline void gao(const int &o,const double &hh) { mn[o]+=hh;tag[o]+=hh; }

inline void pushdown(const int &o)
{
	if (tag[o]==0) return;
	gao(o<<1,tag[o]);gao(o<<1|1,tag[o]);
	tag[o]=0;
}

inline void build(int o,int l,int r)
{
	tag[o]=0;
	if (l==r) { mn[o]=num[l];return; }
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

inline void modify(int o,int l,int r,int x,int y,double hh)
{
	if (l>=x&&r<=y) { gao(o,hh);return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline double query(int o,int l,int r,int x,int y)
{
	if (l>=x&&r<=y) return mn[o];
	pushdown(o);
	double res=1e100;
	int mid=(l+r)>>1;
	if (x<=mid) res=min(res,query(o<<1,l,mid,x,y));
	if (y>mid) res=min(res,query(o<<1|1,mid+1,r,x,y));
	return res;
}

inline bool cmp(const int &x,const int &y) { return h[x].v<h[y].v; }

int main()
{
	n=rd();l=rd();
	for (int i=1;i<=n;i++)
	{
		X[i]=rd();Y[i]=rd();
		scanf("%lf",&V[i]);
	}
	int lst=0;
	for (int i=1;i<=n;i++)
	{
		if (X[i]>lst) h[++tt]=node(X[i]-lst,0);
		h[++tt]=node(Y[i]-X[i],V[i]);
		lst=Y[i];
	}
	if (lst<l) h[++tt]=node(l-lst,0);
	double ans=0;
	for (int i=1;i<=tt;i++)
	{
		if (h[i].v==0) { ans+=h[i].s;continue; }
		ans+=h[i].s/h[i].v;
		num[i]=((h[i].v+1)/h[i].v-1)*h[i].s;
	}
	for (int i=1;i<=tt;i++) num[i]+=num[i-1];
	build(1,1,tt);
	for (int i=1;i<=tt;i++) id[i]=i;
	sort(id+1,id+tt+1,cmp);
	for (int i=1;i<=tt;i++)
	{
		int x=id[i];
		double hh=min(query(1,1,tt,x,tt),(h[x].v==0)?h[x].s/2:((h[x].v+1)/h[x].v-(h[x].v+1)/(h[x].v+2))*h[x].s);
		ans-=hh/(h[x].v+1);
		modify(1,1,tt,x,tt,-hh);
	}
	printf("%.15lf\n",ans);
	return 0;
}