#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 100005
#define M 2000005
#define seed 23333

using namespace std;
typedef double db;
const db eps=1e-8;
const db inf=1e10;
int i,j,m,n,p,k,x,y;
struct Point{
		db x,y;
}A[N],B[N];
struct Han{
		Point sx,sy;
		db st,ed;
};
db s;
vector<Han>v[N],vB[N];
double sqr(double x)
{
		return x*x;
}
inline Point operator *(Point a,db b)
{
		return (Point){a.x*b,a.y*b};
}
inline Point operator /(Point a,db b)
{
		return (Point){a.x/b,a.y/b};
}
inline Point operator +(Point a,Point b)
{
		return (Point){a.x+b.x,a.y+b.y};
}
inline Point operator -(Point a,Point b)
{
		return (Point){a.x-b.x,a.y-b.y};
}
double dis(Point a,Point b)
{
		return abs(a.x-b.x)+abs(a.y-b.y);
}
struct Seg{
		double l,r;
};
double E[M];
int tot=0;
vector<Seg>Ans[N];
void Setin(Han a,Han b,int c,double x)
{
		double A=0.,B=0.,C=0.,st,ed;
		C=sqr(a.sx.x-b.sx.x)+sqr(a.sx.y-b.sx.y);
		B=2*(a.sx.x-b.sx.x)*(a.sy.x-b.sy.x)+2*(a.sx.y-b.sx.y)*(a.sy.y-b.sy.y);
		A=sqr(a.sy.x-b.sy.x)+sqr(a.sy.y-b.sy.y);
		if (A==0.)
		{
				if (B==0.) 
				{
						if (C<x) st=-inf,ed=inf;
						else st=inf,ed=-inf;
				}
				else 
				{
						if (B<0) st=(x-C)/B,ed=inf;
						else st=-inf,ed=(x-C)/B;
				}
		}
		else 
		{
				C-=x;
				if (sqr(B)-4*A*C<0) return;
				st=(-B-sqrt(sqr(B)-4*A*C))/(2*A);
				ed=(-B+sqrt(sqr(B)-4*A*C))/(2*A); 
		}
		st=max(st,max(a.st,b.st));
		ed=min(ed,min(a.ed,b.ed));
		if	(st>ed) return;
		E[++tot]=st; E[++tot]=ed;
		Ans[c].pb((Seg){st,ed});
}
int f[M];
int check(double x)
{
		int i;
		for (i=1;i<=m;++i) Ans[i].clear();
		tot=0;
		for (i=1;i<=m;++i)
		{
				int l=0,L=0;
				while (l<(int)v[i].size()&&L<(int)v[i+1].size())
				{
						Setin(v[i][l],v[i+1][L],i,x); 
						if (v[i][l].ed<v[i+1][L].ed) v[i+1][L].st=v[i][l].ed+eps,++l;
						else v[i][l].st=v[i+1][L].ed+eps,++L;
				}
				v[i+1]=vB[i+1];
		}
		sort(E+1,E+tot+1); tot=unique(E+1,E+tot+1)-(E+1);
		memset(f,0,sizeof(f)); 
		for (i=1;i<=m;++i) 
		{
				//printf("%d\n",i);
				for (j=0;j<(int)Ans[i].size();++j)
				{
						double l=Ans[i][j].l,r=Ans[i][j].r;
					//	printf("%.10lf %.10lf\n",l,r);
						f[lower_bound(E+1,E+tot+1,l-eps/10)-E]++;
						f[lower_bound(E+1,E+tot+1,r+eps/10)-E]--;
				}
		}
		for (i=1;i<=tot;++i) f[i]+=f[i-1];
		for (i=1;i<=tot;++i) if (f[i]==m) return 1;
		return 0;
}
int main()
{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;++i) scanf("%d%d",&x,&y),A[i]=(Point){(db)x,(db)y}; A[n+1]=A[1];
		for (i=1;i<=n;++i) 
			B[i]=(Point){A[i].x<A[i+1].x?1.:(A[i].x==A[i+1].x?0.:-1.),
						 A[i].y<A[i+1].y?1.:(A[i].y==A[i+1].y?0.:-1.)};
		for (i=1;i<=n;++i) s+=abs(A[i].x-A[i+1].x)+abs(A[i].y-A[i+1].y);
		Point P=A[1];
		int now=1;
		s/=m;
		for (i=1;i<=m;++i)
		{
				double time=0;
				for (;time<s;)
				{
						double dist=dis(P,A[now+1]);
						if (dist>=s-time)
						{
							v[i].pb((Han){P-B[now]*time,B[now],time+eps,s});
							P=P+(A[now+1]-P)/dist*(s-time); 
							time=s;
						}
						else 
						{
							v[i].pb((Han){P-B[now]*time,B[now],time+eps,time+dist});
							++now;
							time+=dist;
							P=A[now];
						}
				}
		}
		v[m+1]=v[1];
		for (i=1;i<=m+1;++i) vB[i]=v[i];
		double l=0,r=1e4,mid=0;
		for (i=1;i<=60;++i)
		{
				mid=(l+r)/2.;
				if (check(mid*mid)) r=mid;
				else l=mid; 
				for (j=1;j<=m+1;++j) v[j]=vB[j];
		}
		printf("%.10lf\n",r);
}