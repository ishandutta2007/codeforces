#include<bits/stdc++.h>
using namespace std;
#define EPS (1e-9)
using ld=double;
inline int sgn(ld x){
	return abs(x)<EPS?0:(x<0?-1:1);
}
inline int sgn(long long x){
	return !x?0:(x<0?-1:1);
}
template<class T>
struct P{
	T x,y;
	P(T x=0,T y=0):x(x),y(y){}
	P operator+(const P&t)const{return P(x+t.x,y+t.y);}
	P operator-(const P&t)const{return P(x-t.x,y-t.y);}
	P operator*(T s)const{return P(x*s,y*s);}
	P& operator+=(const P&t){return *this=P(x+t.x,y+t.y);}
	P& operator-=(const P&t){return *this=P(x-t.x,y-t.y);}
	P& operator*=(T s){return *this=P(x*s,y*s);}

	T operator*(const P&t)const{
		return x*t.x+y*t.y;
	}
	T cha(const P&t)const{
		return x*t.y-y*t.x;
	}
	T dis(const P&t)const{
		return (x-t.x)*(x-t.x)+(y-t.y)*(y-t.y);
	}
	ld dist(const P&t)const{
		return sqrt(this->dis(t));
	}
};
template<class T>
vector<P<T>> convex_hull(vector<P<T>> a){
	int n=a.size();
	for(int i=1;i<n;++i){
		int w=sgn(a[i].y-a[0].y);
		if(w<0||(!w&&sgn(a[i].x-a[0].x)<0)){
			swap(a[0],a[i]);	
		}
	}
	auto p=a[0];
	for(auto &e:a)e-=p;
	sort(a.begin()+1,a.end(),[](P<T> a,P<T> b){
		int w=sgn(a.cha(b));
		return w?(w>0):a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y;
	});
	vector<P<T>> b(n);
	int m=0;
	for(auto e:a){
		while(m>1&&sgn((b[m-1]-b[m-2]).cha(e-b[m-2]))<=0)--m;
		b[m++]=e;
	}
	b.resize(m);
	for(auto &e:b)e+=p;
	return b;
}
using E=P<double>;
double wk(E a,double r1,E b,double r2){
	double d=a.dist(b);
	if(d>r1+r2+EPS)return (d-r1-r2)*0.5;
	if(r1<r2)swap(r1,r2),swap(a,b);
	if(d+r2>r1) return .0;
	return (r1-d-r2)*.5;
	//(a.dist(b)-r1-r2)*.5
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	E a,b;
	double r1,r2;
	cin>>a.x>>a.y>>r1;
	cin>>b.x>>b.y>>r2;
	cout<<fixed<<setprecision(10)<<wk(a,r1,b,r2)<<endl;
}