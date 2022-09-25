#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
typedef unsigned long long ull;
const double eps=1e-9;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,d1,d2,ans;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x,y=_y;}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend Point operator * (const Point &a,const double t){
		return Point(a.x*t,a.y*t);
	}
	inline double len(){
		return sqrt(x*x+y*y);
	}
}a[N],b[N];
double calc(Point a1,Point a2,Point b1,Point b2){
	double l=0,r=1,mn=1e18;
	while(r-l>eps){
		double ml=(l+l+r)/3.0;
		double mr=(l+r+r)/3.0;
		double dl=((a1+(a2-a1)*ml)-(b1+(b2-b1)*ml)).len();
		double dr=((a1+(a2-a1)*mr)-(b1+(b2-b1)*mr)).len();
		mn=min(mn,min(dl,dr));
		if(dl<=dr)r=mr;
		else l=ml;
	}	
	return mn;
}
int main(){
	n=read(),d1=read(),d2=read();
	for(int i=1;i<=n;++i){
		a[i].x=read(),a[i].y=read();
		b[i].x=read(),b[i].y=read();
	}
	int ok=1;
	if((a[1]-b[1]).len()<=d1){
		ok=0,++ans;
	}
	for(int i=2;i<=n;++i){
		auto Add = [&](double x,double y) -> void{
			if(fabs(x-y)<eps)return;
			if(x<d2&&y>=d2)ok=1;
			if(x>d1&&y<=d1&&ok)ok=0,++ans;
		};
		double l=(a[i-1]-b[i-1]).len();
		double mid=calc(a[i-1],a[i],b[i-1],b[i]);
		double r=(a[i]-b[i]).len();
		Add(l,mid);
		Add(mid,r);
	}
	printf("%d\n",ans);
	return 0;
}