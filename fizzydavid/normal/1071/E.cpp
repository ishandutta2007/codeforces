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
bool inseg_in(const point &px,const point &py,const point &p)
{
	return is0((py-px).det(p-px))&&(px-p).dot(py-p)<eps;
}
struct solution
{
	bool emp;
	point p,q;
	solution(){emp=1;}
	void init(point P,point Q){p=P;q=Q;emp=0;}
	void intersect(point a,point b)
	{
		if(emp)return;
		if(a==b)
		{
			if(p==q)
			{
				if(a!=p)emp=1;
			}
			else
			{
				if(inseg_in(p,q,a))p=q=a;
				else emp=1;
			}
		}
		else
		{
			bool tp=(b-a).det(p-a)>-eps;
			bool tq=(b-a).det(q-a)>-eps;
			if(p==q)
			{
				if(!tp)emp=1;
			}
			else
			{
				if(parallel(a,b,p,q))
				{
					if(!tp)emp=1;
				}
				else
				{
					if(!tp&&!tq)emp=1;
					else if(!tp&&tq)p=intersection(p,q,a,b);
					else if(tp&&!tq)q=intersection(p,q,a,b);
				}
			}
		}
	}
	void limit(int L)
	{
		intersect(point(0,0),point(L,0));
		intersect(point(L,0),point(L,L));
		intersect(point(L,L),point(0,L));
		intersect(point(0,L),point(0,0));
	}
	void debug()
	{
		cerr<<"emp="<<emp<<" p="<<p.x<<","<<p.y<<" q="<<q.x<<","<<q.y<<endl;
	}
};
const int maxn=100111;
int n;
int L,H;
bool type[maxn];
pair<int,point> P[maxn];
solution getseg(point x)
{
	point S=point(0,x.x/x.y*H);
	point T=point(L,L-(L-x.x)/x.y*H);
	solution ret;
	ret.init(S,T);
	ret.limit(L);
	return ret;
}
solution getnxt(solution a,solution b,double r)
{
	vector<point> v;
	for(int i=-1;i<=1;i+=2)
	{
		for(int j=-1;j<=2;j+=2)
		{
			point dlt(i*r,j*r);
			v.PB(a.p+dlt);
			v.PB(a.q+dlt);
		}
	}
	sort(v.begin(),v.end());
	vector<int> h=construct_chull(v);
	assert(h.size()>0);
	h.PB(h[0]);
	for(int i=0;i+1<h.size();i++)b.intersect(v[h[i]],v[h[i+1]]);
	b.limit(L);
	return b;
}
solution pp[maxn];
bool check(double v)
{
	solution cur;
	cur.init(P[0].SS,P[0].SS);
	for(int i=1;i<=n;i++)
	{
		int dlt=P[i].FF-P[i-1].FF;
		if(pp[i].emp)return false;
		cur=getnxt(cur,pp[i],dlt*v);
		if(cur.emp)return false;
	}
	return true;
}
int main()
{
	getiii(n,L,H);
	int Sx,Sy;
	getii(Sx,Sy);
	P[0]=MP(0,point(Sx,Sy));
	for(int i=1;i<=n;i++)
	{
		int t,x,y;
		getiii(t,x,y);
		P[i]=MP(t,point(x,y));
		pp[i]=getseg(P[i].SS);
	}
	double l=0,r=1001;
	for(int i=0;i<30;i++)
	{
		double mid=(l+r)/2;
		if(check(mid))r=mid;else l=mid;
	}
	if(l>1000.5)puts("-1");
	else cout<<fixed<<setprecision(6)<<l<<endl;
	return 0;
}