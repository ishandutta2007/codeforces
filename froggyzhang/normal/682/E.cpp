#include<bits/stdc++.h>
using namespace std;
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
	ll x,y;
	Point(ll _x=0,ll _y=0){x=_x,y=_y;}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);
	}	
	friend ll operator % (const Point &a,const Point &b){
		return a.x*b.y-a.y*b.x;
	}
	friend bool operator < (const Point &a,const Point &b){
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
	inline ll len(){return x*x+y*y;}
	void Output(){printf("%lld %lld\n",x,y);}
}LTL;
typedef vector<Point> poly;
poly p;
inline bool Left(Point a,Point b){
	return b%a>0;
}
inline bool Para(Point a,Point b){
	return a%b==0;
}
array<Point,3> ans;
ll mx;
inline ll Abs(ll x){return x>=0?x:-x;}
inline ll Area(Point a,Point b,Point c){
	return Abs((b-a)%(c-a));	
}
poly Convex(poly A){
	poly B;
	for(auto p:A){
		while(B.size()>1&&!Left(p-B[B.size()-2],B.back()-B[B.size()-2]))B.pop_back();
		B.push_back(p);	
	}	
	return B;
}
int main(){
	n=read();read();
	p.resize(n);
	for(int i=0;i<n;++i){
		p[i].x=read(),p[i].y=read();
	}
	LTL=*min_element(p.begin(),p.end());
	sort(p.begin(),p.end(),[&](Point a,Point b){a=a-LTL,b=b-LTL;return Para(a,b)?a.len()<b.len():!Left(a,b);});
	p=Convex(p);
	n=p.size();
	mx=-1;
	for(int i=0;i<n;++i){
		for(int j=(i+1)%n,k=(j+1)%n;j!=i;j=(j+1)%n){
			while(Area(p[i],p[j],p[(k+1)%n])>Area(p[i],p[j],p[k]))k=(k+1)%n;
			ll S=Area(p[i],p[j],p[k]);
			if(S>mx){
				mx=S;
				ans={p[i],p[j],p[k]};
			}
		}
	}
	for(int i=0;i<3;++i){
		(ans[i]+ans[(i+1)%3]-ans[(i+2)%3]).Output();	
	}
	return 0;
}