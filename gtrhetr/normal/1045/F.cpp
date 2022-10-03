#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
	ll x,y;
	node(ll xx=0,ll yy=0):x(xx),y(yy) {}
}a[200010],b[200010],fir;

int st[200010],col[200010],n,m,top;

inline node operator -(const node &x,const node &y) { return node(x.x-y.x,x.y-y.y); }
inline ll cross(const node &x,const node &y) { return x.x*y.y-x.y*y.x; }
inline ll dis(const node &x) { return x.x*x.x+x.y*x.y; }

inline bool cmp(const node &x,const node &y)
{
	ll hh=cross(x-fir,y-fir);
	if (hh!=0) return hh>0;
	return dis(x-hh)<dis(y-hh);
}

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void pre_gao()
{
	for (int i=2;i<=n;i++) if (a[i].x<a[1].x||(a[i].x==a[1].x&&a[i].y<a[1].y)) swap(a[1],a[i]);
	fir=a[1];sort(a+2,a+n+1,cmp);
	st[top=1]=1;
	for (int i=2;i<=n;i++)
	{
		while (top>1&&cross(a[i]-a[st[top-1]],a[st[top]]-a[st[top-1]])>=0) top--;
		st[++top]=i;
	}
	for (int i=1;i<=top;i++) if ((a[st[i]].x&1)||(a[st[i]].y&1)) { puts("Ani");exit(0); }
	for (int i=1;i<=(top>>1);i++) col[st[i*2-1]]=1,col[st[i*2]]=2;
	if (top&1) col[st[top]]=3;col[1]=0;
}

inline bool check()
{
	for (int i=2;i<=m;i++) if (b[i].x<b[1].x||(b[i].x==b[1].x&&b[i].y<b[1].y)) swap(b[1],b[i]);
	fir=b[1];sort(b+2,b+m+1,cmp);
	st[top=1]=1;
	for (int i=2;i<=m;i++)
	{
		while (top>1&&cross(b[i]-b[st[top-1]],b[st[top]]-b[st[top-1]])>=0) top--;
		st[++top]=i;
	}
	for (int i=1;i<=top;i++) if ((b[st[i]].x&1)||(b[st[i]].y&1)) return true;
	return false;
}

int main()
{
	n=rd()+1;
	for (int i=2;i<=n;i++) a[i].x=rd(),a[i].y=rd();
	pre_gao();
	m=0;
	for (int i=1;i<=n;i++) if (col[i]!=1) b[++m]=a[i];
	if (check()) { puts("Ani");return 0; }
	m=0;
	for (int i=1;i<=n;i++) if (col[i]!=2) b[++m]=a[i];
	if (check()) { puts("Ani");return 0; }
	m=0;
	for (int i=1;i<=n;i++) if (col[i]!=3) b[++m]=a[i];
	if (check()) { puts("Ani");return 0; }
	puts("Borna"); 
	return 0;
}