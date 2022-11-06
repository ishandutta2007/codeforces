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

using E=P<long long>;
int is_rectangle(vector<E> &a){
	a=convex_hull(a);
	if(a.size()!=4)return 0;
	for(int i=0;i<4;++i){
		E u=a[(i+1)%4]-a[i];
		E v=a[(i+3)%4]-a[i];
		if(sgn(u.cha(v)-u.dist(E(0,0))*v.dist(E(0,0))))
			return 0;
	}
	return 1;
}
int is_square(vector<E> a){
	if(!is_rectangle(a))return 0;
	long long d=a[0].dis(a[1]);
	for(int i=1;i<4;++i)
		if(a[i].dis(a[(i+1)%4])!=d)
			return 0;
	return 1;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	vector<E> a(8);
	for(int i=0;i<8;++i)cin>>a[i].x>>a[i].y;
	for(int i=0;i<(1<<8);++i){
		if(__builtin_popcount(i)!=4)continue;
		vector<int> x,y;
		vector<E> u,v;
		for(int j=0;j<8;++j)
			if(i>>j&1){
				u.push_back(a[j]);
				x.push_back(j);
			}else{
				v.push_back(a[j]);
				y.push_back(j);
			}
		if(is_square(u)&&is_rectangle(v)){
			cout<<"YES\n";
			for(int i=0;i<4;++i)cout<<x[i]+1<<" \n"[i+1==4];
			for(int i=0;i<4;++i)cout<<y[i]+1<<" \n"[i+1==4];
			return 0;
		}
	}
	cout<<"NO\n";
}