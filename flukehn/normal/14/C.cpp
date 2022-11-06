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
	bool operator==(const P&t)const{
		return !sgn(x-t.x)&&!sgn(y-t.y);
	}
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
istream& operator>>(istream &in,P<T> &t){
	in>>t.x>>t.y;
	return in;
}
int work(){
	P<long long> a[4][2];
	for(int i=0;i<4;++i){
		cin>>a[i][0]>>a[i][1];
		if(a[i][0].x!=a[i][1].x&&a[i][0].y!=a[i][1].y)return 0;
	}
	for(int i=0;i<3;++i){
		int j;
		for(j=i+1;j<4;++j)
			if(a[j][0]==a[i][1] || a[j][1] == a[i][1])break;
		if(j>3)return 0;
		if(a[j][1]==a[i][1])swap(a[j][0],a[j][1]);
		swap(a[i+1],a[j]);
		
	}
	if(!(a[0][0]==a[3][1]))return 0;
	for(int i=0;i<4;++i){
		auto x=a[i][0],y=a[i][1],z=a[(i+1)%4][1];
		if ((y-x).cha(z-x)==0) return 0;
	}
	return 1;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
#ifdef flukehn
	cin>>T;
#else
	T=1;
#endif
	while(T--){
		cout<<(work()?"YES":"NO")<<"\n";
	}
}