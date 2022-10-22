#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n,m;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second

struct Point{
	double x,y;
	Point(){x=y=0.0;}
	Point(double _x,double _y){x=_x;y=_y;}
	friend Point operator +(Point t1,Point t2){return Point(t1.x+t2.x,t1.y+t2.y);}
	friend Point operator *(Point a,double t){return Point(a.x*t,a.y*t);}
	friend Point operator /(Point a,double t){return Point(a.x/t,a.y/t);}
	friend Point operator -(Point t1,Point t2){return Point(t1.x-t2.x,t1.y-t2.y);}
	double len(){return sqrt(x*x+y*y);}
	double sq(){return x*x+y*y;}
}p[Maxn],dir[Maxn];double dis[Maxn];
double C=0.0;

struct Dat{
	double l,r,a,b,c;
}f[Maxn<<4];int L;

struct HH{
	double pos;int v;
	HH(){pos=v=0.0;}
	HH(double _pos,int _v){pos=_pos;v=_v;}
	bool operator <(const HH &t)const{return fabs(pos-t.pos)<eps?v<t.v:pos<t.pos;}
}hh[Maxn<<4];

bool Judge(double lim){
	int cnt=0;
	rep(i,1,L){
		double a=f[i].a,b=f[i].b,c=f[i].c-lim,l=f[i].l,r=f[i].r;
		if(fabs(a)<eps){
			if(fabs(b)<eps){if(c<eps)hh[++cnt]=HH(l,1),hh[++cnt]=HH(r,-1);}
			else{
				double z=(-c)/b;
				if(b>0&&z>0)hh[++cnt]=HH(l,1),hh[++cnt]=HH(min(l+z,r),-1);
				else if(b<0&&l+z<r)hh[++cnt]=HH(max(0.0,l+z),1),hh[++cnt]=HH(r,-1);
			}
		}else{
			double z=b*b-4*a*c;if(z<0.0)continue;z=sqrt(z);
			double x=(-b-z)/(2*a),y=(-b+z)/(2*a);
			if(max(l+x,l)<min(r,l+y))hh[++cnt]=HH(max(l,l+x),1),hh[++cnt]=HH(min(r,l+y),-1);
		}
	}
	sort(hh+1,hh+cnt+1);int cur=0;
	rep(i,1,cnt){
		cur+=hh[i].v;
		if(cur>=m)return true;
	}
	return false;
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(n);rd(m);
	rep(i,1,n)scanf("%lf%lf",&p[i].x,&p[i].y);p[n+1]=p[1];
	rep(i,1,n){
		dir[i]=p[i+1]-p[i];dis[i]=dir[i].len();
		dir[i]=dir[i]/dis[i];
		C+=dis[i];
	}
	double lb=C/m,la=0.0;
	int pl=1,pr=1;
	while(lb+eps>dis[pr])lb-=dis[pr++];
	Point ed=p[pr]+dir[pr]*lb;
	lb=dis[pr]-lb;la=dis[1];
	int id=1;double cur=0.0,avr=C/m;
	Point st=p[1];
	while(cur+(1e-5)<C){
		double res=min(id*avr-cur,min(la,lb));
		Point dt=ed-st,dr=dir[pr]-dir[pl];
		f[++L]=(Dat){cur-(id-1)*avr,cur-(id-1)*avr+res,dr.sq(),2.0*(dr.x*dt.x+dr.y*dt.y),dt.sq()};
		cur+=res;if(cur+eps>id*avr)id++;
		st=st+(dir[pl]*res);ed=ed+(dir[pr]*res);
		if(res+eps>la){pl=pl%n+1;la=dis[pl];}else la-=res;
		if(res+eps>lb){pr=pr%n+1;lb=dis[pr];}else lb-=res;
	}
	double l=0.0,r=avr;
	per(i,60,1){
		double mid=(l+r)/2.0;
		if(Judge(mid*mid))r=mid;
		else l=mid;
	}
	printf("%.9lf\n",r);
	return 0;
}/*
4 2
0 0
0 1
1 1
1 0
*/