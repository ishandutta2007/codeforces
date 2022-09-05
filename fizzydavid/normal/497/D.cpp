//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
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
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
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
//geometry
const double eps=1e-9;
const double pi=acos(-1);
bool is0(double x){return x>-eps&&x<eps;}
struct point
{
	double x,y;
	point(double _x=0,double _y=0){x=_x;y=_y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	point operator*(const double &t)const{return point(x*t,y*t);}
	point operator-()const{return point(-x,-y);}
	double len()const{return sqrt(x*x+y*y);}
	point operator/(const point &t)const{return point(x*t.x+y*t.y,-x*t.y+y*t.x)/t.len()/t.len();}
	point operator/(const double &t)const{return point(x/t,y/t);}
	double det(const point &t)const{return x*t.y-y*t.x;}
	double dot(const point &t)const{return x*t.x+y*t.y;}
	double sqrl()const{return x*x+y*y;}
	point unit()const{return (*this)/len();}
	bool operator<(const point &t)const{return is0(x-t.x)?y<t.y:x<t.x;}
	bool operator==(const point &t)const{return is0(x-t.x)&&is0(y-t.y);}
	void out(){cout<<x<<","<<y<<endl;}
	void in(){cin>>x>>y;}
	double rad(){return atan2(y,x);}
	point conj(const point &p){return point(p.x,-p.y);}
};
double area(double x,double y,double z)
{
	double p=(x+y+z)/2;
	return sqrt(p*(p-x)*(p-y)*(p-z));
}
bool parallel(const point &px,const point &py,const point &qx,const point &qy)
{
	return is0((px-py).det(qx-qy));
}
point intersection(const point &px,const point &py,const point &qx,const point &qy)
{
	double t=-(px-qx).det(qy-qx)/(py-px).det(qy-qx);
	return px+(py-px)*t;
}
point intersection(const pair<point,point> &p,const pair<point,point> &q)
{
	return intersection(p.FF,p.SS,q.FF,q.SS);
}
bool onseg(const point &p,const point &x,const point &y)
{
	return (y-x).dot(p-x)*(x-y).dot(p-y)>-eps;
}
bool inseg(const point &p,const point &x,const point &y)
{
	return (y-x).dot(p-x)*(x-y).dot(p-y)>eps;
}
bool insegcross(const point &px,const point &py,const point &qx,const point &qy)
{
	if(parallel(px,py,qx,qy))return false;
	point p=intersection(px,py,qx,qy);
	return (px-p).dot(py-p)<-eps&&(qx-p).dot(qy-p)<-eps;
}
const int tbmxsz=111;
point tmppt[tbmxsz];
int tb[tbmxsz],tbn;
void calcchull(point a[],int n)
{
	tbn=0;
	int t[tbmxsz],tn;
	tn=0;
	for(int i=1;i<=n;i++)
	{
		t[tn++]=i;
		while(tn>2&&(a[tn-2]-a[tn-3]).det(a[tn-1]-a[tn-3])>-eps)
		{
			a[tn-2]=a[tn-1];
			tn--;
		}
	}
	for(int i=0;i<tn;i++)tb[tbn++]=t[i];
	tn=0;
	for(int i=1;i<=n;i++)
	{
		t[tn++]=i;
		while(tn>2&&(a[tn-2]-a[tn-3]).det(a[tn-1]-a[tn-3])<eps)
		{
			a[tn-2]=a[tn-1];
			tn--;
		}
	}
	for(int i=tn-2;i>0;i--)tb[tbn++]=t[i];
}
int makechull(point a[],int n)
{
	for(int i=1;i<=n;i++)tmppt[i]=a[i];
	calcchull(a,n);
	for(int i=1;i<=tbn;i++)a[i]=tmppt[tb[i-1]];
	return tbn;
}
void inter(point p,double pr,point q,double qr)
{
	double len=(p-q).len();
	if(len>pr+qr+eps||len<fabs(pr-qr)-eps)return;
	if(pr>qr)
	{
		double h=area(pr,qr,len)*2/len;
		double d=sqrt(pr*pr-h*h);
		point(d,h)*(q-p).unit()+p;
		point(d,-h)*(q-p).unit()+p;
	}
	else
	{
		double h=area(pr,qr,len)*2/len;
		double d=sqrt(qr*qr-h*h);
		point tmp=point(d,h)*(p-q).unit();
		point(d,h)*(p-q).unit()+q;
		point(d,-h)*(p-q).unit()+q;
	}
}
//geometry end
int n,m;
point a[1011],b[1011];
bool solve(point Q,point A,point P,point qx,point qy)
{
	point O=A+P-Q;
	point vr=Q-P;
	double R=vr.len();
	double dx=(qx-O).len();
	double dy=(qy-O).len();
	if(dx<R-eps&&dy<R-eps)return false;
	double mn=min(dx,dy);
	if(mn<R+eps)return true;
	point tmp=intersection(O,O+(qx-qy)*point(0,1),qx,qy);
	if(onseg(tmp,qx,qy))return (tmp-O).len()<R+eps;
	else return false;
}
int main()
{
	point P,Q;
	scanf("%lf%lf",&P.x,&P.y);
	geti(n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	a[n+1]=a[1];
	scanf("%lf%lf",&Q.x,&Q.y);
	geti(m);
	for(int i=1;i<=m;i++)scanf("%lf%lf",&b[i].x,&b[i].y);
	b[m+1]=b[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(solve(P,a[i],Q,b[j],b[j+1]))
			{
				puts("YES");
				return 0;
			}
			if(solve(Q,b[j],P,a[i],a[i+1]))
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}