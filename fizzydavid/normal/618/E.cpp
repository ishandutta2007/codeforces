//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
double eps=1e-7;
struct cpx
{
	double x,y;//x+yi
	cpx(double X=0,double Y=0){x=X;y=Y;}
	cpx operator+(cpx t){return cpx(x+t.x,y+t.y);}
	cpx operator-(cpx t){return cpx(x-t.x,y-t.y);}
	cpx operator*(cpx t){return cpx(x*t.x-y*t.y,x*t.y+y*t.x);}
	cpx operator*(double t){return cpx(x*t,y*t);}
	cpx operator/(double t){return cpx(x/t,y/t);}
	void go()
	{
		if(x<eps&&x>-eps)x=0;
		if(y<eps&&y>-eps)y=0;
	}
	double len(){return sqrt(x*x+y*y);}
	cpx rad(){return (*this)/(*this).len();}
};
double Sin[360],Cos[360];
struct SGT
{
	struct node
	{
		int l,r;
		cpx v,last;
	}a[1200111];
	node update(node x,node y)
	{
		node ans;
		ans.l=x.l;
		ans.r=y.r;
		ans.v=x.v+y.v*x.last;
		ans.v.go();
		ans.last=x.last*y.last;
		return ans;
	}
	#define ls p<<1
	#define rs p<<1|1
	void build(int l,int r,int p=1)
	{
		if(l==r)
		{
			a[p].l=l;
			a[p].r=r;
			a[p].v.x=a[p].last.x=1;
			a[p].v.y=a[p].last.y=0;
			return;
		}
		int m=l+r>>1;
		build(l,m,ls);
		build(m+1,r,rs);
		a[p]=update(a[ls],a[rs]);
	}
	void addrad(int x,int v,int p=1)
	{
		int l=a[p].l,r=a[p].r;
		if(l==x&&r==x)
		{
			a[p].v=a[p].v*cpx(Cos[v],-Sin[v]);
			a[p].last=a[p].last*cpx(Cos[v],-Sin[v]);
			return;
		}
		int m=l+r>>1;
		if(x<=m)addrad(x,v,ls);else addrad(x,v,rs);
		a[p]=update(a[ls],a[rs]);
	}
	void addlen(int x,double v,int p=1)
	{
		int l=a[p].l,r=a[p].r;
		if(l==x&&r==x)
		{
			a[p].v=a[p].v.rad()*(a[p].v.len()+v);
			return;
		}
		int m=l+r>>1;
		if(x<=m)addlen(x,v,ls);else addlen(x,v,rs);
		a[p]=update(a[ls],a[rs]);
	}
	void see(int p=1)
	{
		cout<<a[p].l<<" "<<a[p].r<<" "<<a[p].v.x<<","<<a[p].v.y<<endl;
		if(a[p].l==a[p].r)return;
		see(ls);
		see(rs);
	}
}sgt;
int n,m;
const double pi=acos(-1);
int main()
{
	for(int i=0;i<360;i++)Sin[i]=sin(1.0*i/180*pi),Cos[i]=cos(1.0*i/180*pi);
	getii(n,m);
	sgt.build(1,n);
	while(m--)
	{
		int op,x,v;
		getiii(op,x,v);
		if(op==1)
		{
			sgt.addlen(x,v);
		}
		else
		{
			sgt.addrad(x,v);
		}
//		sgt.see();
		printf("%.10lf %.10lf\n",sgt.a[1].v.x,sgt.a[1].v.y);
	}
	return 0;
}