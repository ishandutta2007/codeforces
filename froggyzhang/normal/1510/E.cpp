#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
typedef long long ll;
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
int n;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);	
	}
	friend double operator % (const Point &a,const Point &b){
		return a.x*b.y-a.y*b.x;
	}
	friend bool operator == (const Point &a,const Point &b){
		return	fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps;
	}
	friend bool operator < (const Point &a,const Point &b){
		return	fabs(a.x-b.x)<eps?a.y+eps<b.y:a.x<b.x;
	}
}T;
typedef vector<Point> poly;
Point Center(poly A){
	double sx=0,sy=0,tot=0;
	for(int i=0;i<(int)A.size();++i){
		double S=A[i]%A[(i+1)%A.size()];
		sx+=(A[i].x+A[(i+1)%A.size()].x)/3.0*S;
		sy+=(A[i].y+A[(i+1)%A.size()].y)/3.0*S;
		tot+=S;
	}
	sx/=tot,sy/=tot;
	return Point(sx,sy);
}
double Area(poly A){
	double tot=0;
	for(int i=0;i<(int)A.size();++i){
		tot+=A[i]%A[(i+1)%A.size()];
	}
	return tot;
}
map<Point,int> mp[20][567];
int main(){
	n=read();
	scanf("%lf%lf",&T.x,&T.y);
	n>>=1;
	for(int i=0;i<(1<<n);++i){
		poly A(1);
		bool ok=true;
		int now=0;
		for(int j=0;j<n;++j){
			if(i>>j&1){
				++now;
			}
			else{
				--now;
				if(now<0){ok=false;break;}
			}
			A.emplace_back(j+1,now);
		}
		A.emplace_back(n,0);
		if(!ok)continue;
		reverse(A.begin(),A.end());
		mp[now][(int)round(Area(A))][Center(A)]=i;
	}
	for(int i=0;i<(1<<n);++i){
		poly A(1,Point(n<<1,0));
		bool ok=true;
		int now=0;
		for(int j=n-1;j>=0;--j){
			if(i>>j&1){
				--now;
				if(now<0){ok=false;break;}
			}
			else{
				++now;
			}
			A.emplace_back(n+j,now);
		}
		A.emplace_back(n,0);
		if(!ok)continue;
		int sr=round(Area(A));
		Point pr=Center(A);
		for(int sl=1;sl<=n*n;++sl){
			Point pl((T.x*(sl+sr)-sr*pr.x)/sl,(T.y*(sl+sr)-sr*pr.y)/sl);
			if(mp[now][sl].count(pl)){
				ll st=mp[now][sl][pl]|(1LL*i<<n);
				for(int j=0;j<n<<1;++j){
					putchar(st>>j&1?'(':')');
				}
				return 0;
			}
		}
	}
	return 0;
}