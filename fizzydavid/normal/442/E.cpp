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
//geometry start
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
	point rot90(){return point(-y,x);}
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
pair<point,point> circleinter(point p,double pr,point q,double qr)
{
	double c=(p.x*p.x-q.x*q.x+p.y*p.y-q.y*q.y-pr*pr+qr*qr)/2;
	point p1,p2;
	if(is0(p.x-q.x))
	{
		p1=point(0,c/(p.y-q.y));
		p2=point(1,c/(p.y-q.y));
	}
	else
	{
		p1=point(c/(p.x-q.x),0);
		p2=point((c-(p.y-q.y))/(p.x-q.x),1);
	}
	point O=intersection(p1,p2,p,q);
	double len=sqrt(pr*pr-(p-O).sqrl());
	return MP(O+(p-q).rot90().unit()*len,O+(q-p).rot90().unit()*len);
}
//geometry end
point a[1011];
int w,h,n;
vector<pair<double,int> >v;
bool check(int cur,double R)
{
//	cout<<"check:"<<cur<<" "<<R<<endl;
	point p=a[cur];
	v.clear();
	int st=0;
	a[n+1]=point(2*w-p.x,p.y);
	a[n+2]=point(p.x,2*h-p.y);
	a[n+3]=point(-p.x,p.y);
	a[n+4]=point(p.x,-p.y);
	for(int i=1;i<=n+4;i++)
	{
		if(i==cur)continue;
		if((a[i]-p).len()>2*R)continue;
		double l,r;
		if((a[i]-p).len()<eps)
		{
			if(i==n+1)l=-pi/2,r=pi/2;
			else if(i==n+2)l=0,r=pi;
			else if(i==n+3)l=pi/2,r=-pi/2;
			else if(i==n+4)l=pi,r=0;
			else continue;
		}
		else
		{
			pair<point,point> pp=circleinter(p,R,a[i],R);
			l=(pp.FF-p).rad(),r=(pp.SS-p).rad();
		}
		int c=1+(i>n);
		if(l<r)
		{
			v.PB(MP(l,+c));
			v.PB(MP(r,-c));
		}
		else
		{
			st+=c;
			v.PB(MP(r,-c));
			v.PB(MP(l,c));
		}
//		cout<<l<<","<<r<<endl;
	}
	sort(v.begin(),v.end());
//	cout<<"st="<<st<<endl;
//	for(int i=0;i<v.size();i++)cout<<v[i].FF<<","<<v[i].SS<<endl;
	int cnt=st;
	if(st<=1)return true;
	for(int i=0;i<v.size()&&v[i].FF+eps<pi;i++)
	{
		cnt+=v[i].SS;
		if(cnt<=1)return true;
	}
	return false;
}
pair<int,int> tmpa[1011];
int main()
{
	getiii(w,h,n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	srand(time(NULL));
	random_shuffle(a+1,a+n+1);
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!check(i,ans+ans*eps))continue;
		double l=ans,r=2e6;
		for(int j=0;j<59;j++)
		{
			if(check(i,(l+r)/2))l=(l+r)/2;
			else r=(l+r)/2;
		}
		ans=l;
	}
	printf("%.10lf\n",ans);
	return 0;
}