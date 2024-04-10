#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXD = 5e2 + 5;
const int MAXDSC = MAXD*8;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}
inline int min(int a,int b){ return a<b? a: b;}
inline int max(int a,int b){ return a>b? a: b;}

struct Node
{
	int x,y;
}a[MAXD];

int n,m,d;

struct Square
{
	int xl,xr,yl,yr;
}sq[MAXD];

struct Line
{
	int l,r,pos,x;
}p[MAXD*2],q[MAXD*2];
inline bool cmp(const Line &x,const Line &y)
{
	return x.pos==y.pos? x.x>y.x: x.pos<y.pos;
}

int dsc[MAXDSC],cnt=0;

int mn[MAXDSC<<2],tag[MAXDSC<<2];
#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1|1)

inline void push_up(int u){ mn[u] = min(mn[ls(u)], mn[rs(u)]);}
inline void push_down(int u)
{
	mn[ls(u)]+=tag[u]; tag[ls(u)]+=tag[u];
	mn[rs(u)]+=tag[u]; tag[rs(u)]+=tag[u];
	tag[u]=0;
}

void build(int u,int l,int r)
{
	mn[u]=tag[u]=0;
	if(l==r) return;
	int mid = (l+r)>>1;
	build(ls(u),l,mid);
	build(rs(u),mid+1,r);
}

void update(int u,int l,int r, int ql,int qr,int k)
{
	if(ql<=l && r<=qr)
	{
		mn[u]+=k; tag[u]+=k;
		return;
	}
	push_down(u);
	int mid=(l+r)>>1;
	if(ql<=mid) update(ls(u),l,mid, ql,qr,k);
	if(mid<qr) update(rs(u),mid+1,r, ql,qr,k);
	push_up(u);
}

bool chk(int mid)
{
	cnt=0;
	for(int i=1; i<=d; ++i)
	{
		int
			xl = max(a[i].x-mid, 1), xr = min(a[i].x+mid, n),
			yl = max(a[i].y-mid, 1), yr = min(a[i].y+mid, m);
		sq[i] = (Square){xl,xr,yl,yr};
		dsc[++cnt]=xl; dsc[++cnt]=xr; dsc[++cnt]=yl; dsc[++cnt]=yr;
		
		--xl; ++xr; --yl; ++yr;
		if(xl>=1) dsc[++cnt]=xl; if(xr<=n) dsc[++cnt]=xr;
		if(yl>=1) dsc[++cnt]=yl; if(yr<=n) dsc[++cnt]=yr;
	}
	dsc[++cnt]=1; dsc[++cnt]=n; dsc[++cnt]=m;
	sort(dsc+1,dsc+cnt+1);
	cnt = unique(dsc+1,dsc+cnt+1)-dsc-1;
	for(int i=1; i<=d; ++i)
	{
		int
			xl = lower_bound(dsc+1,dsc+cnt+1, sq[i].xl) - dsc,
			xr = lower_bound(dsc+1,dsc+cnt+1, sq[i].xr) - dsc,
			yl = lower_bound(dsc+1,dsc+cnt+1, sq[i].yl) - dsc,
			yr = lower_bound(dsc+1,dsc+cnt+1, sq[i].yr) - dsc;
		p[i] = (Line){yl,yr,xl,1}; p[d+i] = (Line){yl,yr,xr,-1};
		q[i] = (Line){xl,xr,yl,1}; q[d+i] = (Line){xl,xr,yr,-1};
	}
	sort(p+1,p+(d<<1)+1,cmp);
	sort(q+1,q+(d<<1)+1,cmp);
	int nn = lower_bound(dsc+1,dsc+cnt+1, n) - dsc;
	int mm = lower_bound(dsc+1,dsc+cnt+1, m) - dsc;
	
	build(1,1,mm);
	int al=0, ar=0;
	for(int i=1,j=1; i<=nn; ++i)
	{
		while(j<=(d<<1) && p[j].pos==i && p[j].x==1)
			update(1,1,mm, p[j].l,p[j].r,1), ++j;
		if(!mn[1])
		{
			if(!al) al=dsc[i];
			ar=dsc[i];
		}
		while(j<=(d<<1) && p[j].pos==i && p[j].x==-1)
			update(1,1,mm, p[j].l,p[j].r,-1), ++j;
	}
	if(ar-al+1 > (mid<<1)+1) return 0;
	
	build(1,1,nn);
	al=0; ar=0;
	for(int i=1,j=1; i<=mm; ++i)
	{
		while(j<=(d<<1) && q[j].pos==i && q[j].x==1)
			update(1,1,nn, q[j].l,q[j].r,1), ++j;
		if(!mn[1])
		{
			if(!al) al=dsc[i];
			ar=dsc[i];
		}
		while(j<=(d<<1) && q[j].pos==i && q[j].x==-1)
			update(1,1,nn, q[j].l,q[j].r,-1), ++j;
	}
	return ar-al+1 <= (mid<<1)+1;
}

int main(void)
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=d; ++i) scanf("%d%d",&a[i].x,&a[i].y);
	
	int l=0, r=max(n,m);
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}