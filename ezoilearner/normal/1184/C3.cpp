#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

const double eps=1e-9;

int K,n,N;
#define Maxn 1005
#define Maxk 5

struct Point{
	double x,y;
	Point(){x=y=0.0;}
	friend Point operator +(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}
	friend Point operator *(Point a,double t){return Point(a.x*t,a.y*t);}
	friend Point operator *(Point a,Point b){return Point(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
	friend Point operator -(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
	Point(double _x,double _y){x=_x;y=_y;}
}p[4005];
double dist(Point a){return sqrt(a.x*a.x+a.y*a.y);}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}

vector<int> vec[4];
struct Cir{
	double x,y,r;
	Cir(){x=y=r=0.0;}
	Cir(double _x,double _y,double _r){x=_x;y=_y;r=_r;}
}cir[4];
mt19937 mt_rand(time(0));

typedef Point Vector;

Point Lineintersect(Point P,Vector v,Point Q,Vector w){
	Vector u = P-Q;
    double t = cross(w, u)/cross(v, w);
    return P+v*t;
}

bool calc(Point &a,Point &b,Point &c,Cir &d){
	if(cross(b-a,c-a)<eps)return false;
	Point tmp=Lineintersect((a+b)*0.5,(b-a)*Point(0,-1),(a+c)*0.5,(c-a)*Point(0,-1));
	d.x=tmp.x;d.y=tmp.y;d.r=dist(c-tmp);
	
	if(d.r<2.5e5||d.r>7.5e5)return false;
	if(d.x<-2e6||d.x>2e6)return false;
	if(d.y<-2e6||d.y>2e6)return false;
	return true;
}

void Judge(){
	rep(i,0,K-1)vec[i].clear();
	rep(i,1,N)vec[mt_rand()%K].push_back(i);
	rep(TT,1,400){
		rep(i,0,K-1){
			if(vec[i].size()<3)return;
			int t=vec[i].size();
			rep(j,0,2)swap(vec[i][j],vec[i][mt_rand()%t]);int gg=0;
			while(!calc(p[vec[i][0]],p[vec[i][1]],p[vec[i][2]],cir[i])){
				rep(j,0,2)swap(vec[i][j],vec[i][mt_rand()%t]);
				gg++;
				if(gg==10)break;
			}
			if(gg==10)return;
			vec[i].clear();
		}
		bool fl=true;
		rep(i,1,N){
			int c=-1;double d=1e9;
			rep(j,0,K-1){
				double t=abs(dist(p[i]-Point(cir[j].x,cir[j].y))-cir[j].r);
				if(t<=cir[j].r/5){
					if(c==-1||(t/cir[j].r)<d){
						c=j;d=t/cir[j].r;
					}
				}
			}
			if(c==-1)fl=false;
			else vec[c].push_back(i);
		}
		rep(i,0,K-1)
			if(vec[i].size()<n/3*2)fl=false;
		if(fl){
			rep(i,0,K-1)printf("%lf %lf %lf\n",cir[i].x,cir[i].y,cir[i].r);
			exit(0);
		}
	}
}

int main(){
//	freopen("input1-nix.txt","r",stdin);
	scanf("%d%d",&K,&n);N=0; 
	double x,y;
	rep(i,1,K*n){
		scanf("%lf%lf",&x,&y);
		if(mt_rand()%n<100)p[++N]=Point(x,y);
	}
	n=100;
	while(true)Judge();
	return 0;
}