//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
//geometry start
const double eps=1e-7;
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
	point operator/(const double &t)const{return point(x/t,y/t);}
	point operator-()const{return point(-x,-y);}
	double len()const{return sqrt(x*x+y*y);}
	point operator/(const point &t)const{return point(x*t.x+y*t.y,-x*t.y+y*t.x)/t.len()/t.len();}
	double det(const point &t)const{return x*t.y-y*t.x;}
	double dot(const point &t)const{return x*t.x+y*t.y;}
	double len2()const{return x*x+y*y;}
	point unit()const{return (*this)/len();}
	bool operator<(const point &t)const{return is0(x-t.x)?y<t.y:x<t.x;}
	bool operator==(const point &t)const{return is0(x-t.x)&&is0(y-t.y);}
	void out(){cerr<<x<<","<<y<<endl;}
	double rad()const{return atan2(y,x);}
	point conj()const{return point(x,-y);}
};
bool cmpwithangle(point x,point y)
{
	double diff=x.rad()-y.rad();
	if(fabs(diff)>0.001)return diff<0;
	else return x.det(y)>eps;
}
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
bool segcross_in(const point &px,const point &py,const point &qx,const point &qy)// 
{
	if(parallel(px,py,qx,qy))return false;
	point p=intersection(px,py,qx,qy);
	return (px-p).dot(py-p)<eps&&(qx-p).dot(qy-p)<eps;
}
bool segcross_ex(const point &px,const point &py,const point &qx,const point &qy)// 
{
	if(parallel(px,py,qx,qy))return false;
	point p=intersection(px,py,qx,qy);
	return (px-p).dot(py-p)<-eps&&(qx-p).dot(qy-p)<-eps;
}
double pointtoseg(point p,point pl,point pr)
{
	double mndis=min((p-pl).len(),(p-pr).len());
	point q=intersection(pl,pr,p,p+(pr-pl)*point(0,1));
	if((pl-q).dot(pr-q)<0)mndis=min(mndis,(p-q).len());
	return mndis;
}
double pointtoline(point p,point pl,point pr)
{
	point q=intersection(pl,pr,p,p+(pr-pl)*point(0,1));
	return (p-q).len();
}


int n;
point p[80011];
double rd[80011];
double calcarea(double l,double rd)
{
	double x=l,y=l*sin(rd),z=l*cos(rd);
	double p=(x+y+z)/2;
	return sqrt(p*(p-x)*(p-y)*(p-z));
}
double solve()
{
	for(int i=n;i<=2*n;i++)p[i]=p[i-n];
	for(int i=0;i<2*n;i++)
	{
		rd[i]=(p[i+1]-p[i]).rad();
		while(i>0&&rd[i]<rd[i-1])
		{
			rd[i]+=2*pi;
		}
	}
//	for(int i=0;i<2*n;i++)cerr<<rd[i]<<" ";cerr<<endl;
	
	int it=1;
	double ans=1e18;
	double area=0;
	for(int i=0;i<n;i++)
	{
		while(rd[it]<rd[i]+pi/2)
		{
			area+=p[it].det(p[it+1])/2;
			it++;
		}
		double cur=area+p[it].det(p[i+1])/2;
		double ang=min(rd[it]-rd[i]-pi/2,rd[i+1]-rd[i]);
		double trd=(p[it]-p[i+1]).rad();
//		cerr<<i<<":"<<it<<" "<<cur<<" "<<ang<<" "<<trd-rd[i]<<endl;
		double mn=min(calcarea((p[it]-p[i+1]).len(),trd-rd[i]),
		              calcarea((p[it]-p[i+1]).len(),trd-rd[i]-ang));
//		cerr<<"mn="<<mn<<endl;
		ans=min(ans,mn-cur);
		area-=p[i+1].det(p[i+2])/2;
	}
	return ans;
}
int main()
{
	geti(n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		getii(x,y);
		p[i]=point(x,y);
	}
	if((p[1]-p[0]).det(p[2]-p[0])<0)
	{
		reverse(p,p+n);
	}
	double ans=solve();
	for(int i=0;i<n;i++)p[i]=point(-p[i].x,p[i].y);
	reverse(p,p+n);
//	cerr<<ans<<endl;
	ans=min(ans,solve());
	cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}