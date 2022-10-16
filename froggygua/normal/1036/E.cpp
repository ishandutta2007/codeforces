#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>
using namespace std;
#define N 1234
#define y1 ysgh
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
ll ans;
ll Abs(ll x){
	return x>=0?x:-x;
}
struct Point{
	ll x,y;
	Point(ll _x=0,ll _y=0){x=_x,y=_y;}
	Point operator -(const Point b)const{
		return Point(x-b.x,y-b.y);
	}
	Point operator +(const Point b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator *(const ll d)const{
		return Point(x*d,y*d);
	}
	Point operator /(const ll d)const{
		return Point(x/d,y/d);
	} 
	ll operator %(const Point b)const{
		return x*b.y-y*b.x;
	}
	bool operator <(const Point b)const{
		return x==b.x?y<b.y:x<b.x;
	}
};
set<Point> s;
struct Line{
    Point p[2];
    Line(){} Line(Point a,Point b){p[0]=a,p[1]=b;}
    inline Point &operator [] (int i){
        return p[i];
    }
    inline Point v(){
        return p[1]-p[0];
    }
}a[N];
inline bool On(Point t,Line a){
	return t.x>=min(a[0].x,a[1].x)&&t.x<=max(a[0].x,a[1].x)&&t.y>=min(a[0].y,a[1].y)&&t.y<=max(a[0].y,a[1].y);
}
inline void Cross(Line a,Line b){
	if(a.v()%b.v()==0)return;
	ll s1=(b[0]-a[0])%(b[1]-a[0]);
	ll s2=a.v()%b.v();
	if(a.v().x*s1%s2||a.v().y*s1%s2)return ;
	Point t=a[0]+a.v()*s1/s2;
	if(On(t,a)&&On(t,b)){
		s.insert(t);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x1=read(),y1=read(),x2=read(),y2=read();
		a[i]=Line(Point(x1,y1),Point(x2,y2));
	}
	for(int i=1;i<=n;++i){
		ll A=Abs(a[i][0].x-a[i][1].x),B=Abs(a[i][0].y-a[i][1].y);
		ans+=__gcd(A,B)+1;
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			Cross(a[i],a[j]);
		}
		ans-=s.size();
		s.clear();
	}
	printf("%lld\n",ans);
	return 0;
}