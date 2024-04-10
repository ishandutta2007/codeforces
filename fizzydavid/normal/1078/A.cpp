//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
    char s[100000];
    int it, len;
    fastio() {it=len=0;}
    inline char get()
    {
        if (it<len) return s[it++]; it=0;
        len=fread(s, 1, 100000, stdin);
        if (len==0) return EOF; else return s[it++];
    }
    bool notend()
    {
        char c=get();
        while (c==' '||c=='\n') c=get();
        if (it>0) it--;
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
    ll r=0; bool ng=0; char c; c=_buff.get();
    while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
    if (c=='-') ng=1, c=_buff.get();
    while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
    return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
    if (x<0) putchar('-'), x=-x;
    register short a[20]={}, sz=0;
    while (x) a[sz++]=x%10, x/=10;
    if(sz==0) putchar('0');
    for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
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
	double sqrl()const{return x*x+y*y;}
	point operator/(const point &t)const{return point(x*t.x+y*t.y,-x*t.y+y*t.x)/t.len()/t.len();}
	double det(const point &t)const{return x*t.y-y*t.x;}
	double dot(const point &t)const{return x*t.x+y*t.y;}
	double len2()const{return x*x+y*y;}
	point unit()const{return (*this)/len();}
	bool operator<(const point &t)const{return is0(x-t.x)?(is0(y-t.y)?0:y<t.y):x<t.x;}
	bool operator==(const point &t)const{return is0(x-t.x)&&is0(y-t.y);}
	bool operator!=(const point &t)const{return !is0(x-t.x)||!is0(y-t.y);}
	void out()const{cerr<<x<<","<<y<<endl;}
	double rad()const{return atan2(y,x);}
	point conj()const{return point(x,-y);}
};
bool cmpwithangle(point x,point y)
{
	return x.rad()<y.rad();
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
double area(double x,double y,double z) 
{
	double p=(x+y+z)/2;
	return sqrt(p*(p-x)*(p-y)*(p-z));
}
bool inseg_in(const point &px,const point &py,const point &p)
{
	return is0((py-px).det(p-px))&&(px-p).dot(py-p)<eps;
}
bool inseg_ex(const point &px,const point &py,const point &p)
{
	return is0((py-px).det(p-px))&&(px-p).dot(py-p)<-eps;
}
bool segcross_in(const point &px,const point &py,const point &qx,const point &qy)
{
	if(parallel(px,py,qx,qy))return false;
	point p=intersection(px,py,qx,qy);
	return (px-p).dot(py-p)<eps&&(qx-p).dot(qy-p)<eps;
}
bool segcross_ex(const point &px,const point &py,const point &qx,const point &qy) 
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

//convex hull
vector<int> construct_ch(const vector<point> &a,int coef)  // 1 /\ -1 \/
{
	vector<int> s;
	for(int i=0;i<a.size();i++)
	{
		int sz=s.size();
		while(sz>=2&&(a[i]-a[s[sz-2]]).det(a[s[sz-1]]-a[s[sz-2]])*coef<eps)
		{
			s.pop_back();
			sz--;
		}
		s.PB(i);
	}
	return s;
}
vector<int> construct_chull(const vector<point> &a)
{
	vector<int> h1=construct_ch(a,-1),h2=construct_ch(a,1),h;
	for(int i=0;i<h1.size();i++)h.PB(h1[i]);
	for(int i=int(h2.size())-2;i>0;i--)h.PB(h2[i]);
	return h;
}

vector<point> v;
void check(point p, point q, point a, point b)
{
	if (!parallel(p, q, a, b))
	{
		v.PB(intersection(p, q, a, b));
	}
}
double mdis(point p, point q) {return fabs(p.x-q.x)+fabs(p.y-q.y);}
int main()
{
	point h(1,0), w(0,1);
	double a, b, c;
	cin>>a>>b>>c;
	point A, B;
	if (!is0(a))
	{
		A = point(-c/a, 0);
		B = point((-c-b)/a, 1);
	}
	else
	{
		A = point(0, -c/b);
		B = point(1, (-c-a)/b);
	}
	point p, q;
	cin>>p.x>>p.y;
	cin>>q.x>>q.y;
	double ans = mdis(p, q);
	check(p, p+h, A, B);
	check(p, p+w, A, B);
	check(q, q+h, A, B);
	check(q, q+w, A, B);
	for (int i=0; i<v.size(); i++)
	{
		for (int j=0; j<v.size(); j++)
		{
			ans = min(ans, mdis(p, v[i]) + (v[j]-v[i]).len() + mdis(v[j], q));
		}
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}