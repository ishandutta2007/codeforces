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
//geometry start
const double eps=1;
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
	void out(){cerr<<x<<","<<y<<endl;}
	double rad()const{return atan2(y,x);}
	point conj()const{return point(x,-y);}
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
int n,n1,n2;
point A[100011],B[100011];
map<point,int> mp;
ll rnd(){return 1ll*rand()*RAND_MAX+rand();}
bool fA[100111],fB[100111];

pair<double,int> da[100111];
pair<double,int> db[100111];
void check(int xa,int xb,int ya,int yb)
{
//	cerr<<(A[xb]-A[xa]).len()<<" "<<(B[yb]-B[ya]).len()<<endl;
	point r=(A[xb]-A[xa])/(B[yb]-B[ya]);
	point c=A[xa]-B[ya]*r;
	int cnt1=0,cnt0=0;
	for(int i=1;i<=n2;i++)
	{
		point p=r*B[i]+c;
		if(mp.find(p)!=mp.end())cnt1++;
		else cnt0++;
		if(cnt1+cnt0>=20&&1.0*cnt1/(cnt0+cnt1)<0.1)
		{
			break;
		}
	}
	if(cnt1>0.9*n)
	{
//	cerr<<r.x<<","<<r.y<<" "<<c.x<<","<<c.y<<endl;	
		vector<pair<int,int> >v;
		for(int j=1;j<=n2;j++)
		{
			point cur=B[j]*r+c;
			if(mp.find(cur)!=mp.end())
			{
				int nxt=mp[B[j]*r+c];
//				cerr<<B[j].x<<" "<<B[j].y<<"|"<<cur.x<<" "<<cur.y<<endl;
//				cerr<<nxt<<","<<j<<endl;
				if(v.size()<n)
				{
					v.PB(MP(nxt,j));
					fA[nxt]=1;fB[j]=1;
				}
			}
		}
		int itA=1,itB=1;
		while(v.size()<n)
		{
			while(fA[itA])itA++;
			while(fB[itB])itB++;
			v.PB(MP(itA,itB));
			fA[itA]=1;fB[itB]=1;
		}
		for(int i=0;i<n;i++)
		{
			printf("%d %d\n",v[i].FF,v[i].SS);
		}
		exit(0);
	}
}
void solve(int x,int y)
{
//	cerr<<"solve:"<<x<<","<<y<<endl;
	for(int i=1;i<=n1;i++)
	{
		da[i]=MP((A[x]-A[i]).sqrl(),i);
	}
	sort(da+1,da+n1+1);
	for(int i=1;i<=n2;i++)
	{
		db[i]=MP((B[i]-B[y]).sqrl(),i);
	}
	sort(db+1,db+n2+1);
//	for(int i=1;i<=n1;i++)cerr<<da[i].FF<<" ";cerr<<endl;
//	for(int i=1;i<=n2;i++)cerr<<db[i].FF<<" ";cerr<<endl;
	
	int j=2;
	for(int i=2;i<n1;i++)
	{
		while(j<n2&&db[j].FF+1<da[i].FF)
		{
			j++;
		}
		for(int t=j;db[t].FF<da[i].FF+5&&t<n2;t++)
		{
//			cerr<<da[i].FF<<"-"<<db[t].FF<<endl;
			check(x,da[i].SS,y,db[t].SS);
			check(x,da[i].SS,db[t].SS,y);
		}
	}
}
int main()
{
//	freopen("input.txt","r",stdin);
	srand(20020626);
	scanf("%d",&n);
	scanf("%d",&n1);
	for(int i=1;i<=n1;i++)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		A[i]=point(x,y);
//		assert(mp[A[i]]==0);
		mp[A[i]]=i;
	}
	scanf("%d",&n2);
	for(int i=1;i<=n2;i++)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		B[i]=point(x,y);
	}
	while(true)
	{
		int x=rnd()%n1+1;
		int y=rnd()%n2+1;
		solve(x,y);
	}
	return 0;
}