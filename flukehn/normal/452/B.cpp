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
	bool operator<(const P&t)const{
		return x!=t.x?x<t.x:y<t.y;
	}
	bool operator==(const P&t)const{
		return x==t.x&&y==t.y;
	}
};
using E=P<long long>;
#ifdef flukehn
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#else
#define dbg(x)
#endif
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<E> a;
	auto add=[&](int x,int y){
		if(x<0||x>n||y<0||y>m) return;
		a.emplace_back(x,y);
	};
	add(n,m);
	add(n-1,m);
	add(n,m-1);
	add(0,0);
	add(0,1);
	add(1,0);
	add(n,0);
	add(n,1);
	add(0,m);
	add(1,m);

	dbg(a.size());
	sort(a.begin(),a.end());
	a.resize(unique(a.begin(),a.end())-a.begin());
	dbg(a.size());
	vector<E> ans;
	double now=0;
	auto upd=[&](vector<E> b){
		double tmp=0;
		int m=b.size();
		if(m!=4)return;
		dbg("ok");
		for(int i=1;i<m;++i)
			tmp+=b[i].dist(b[i-1]);
		if(tmp>now)now=tmp,ans=b;
	};
	n=a.size();
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			for(int k=0;k<n;++k)
				for(int x=0;x<n;++x)
					if(set<int>{i,j,k,x}.size()==4)
						upd(vector<E>{a[i],a[j],a[k],a[x]});
	dbg(ans.size());
	for(int i=0;i<4;++i)cout<<ans[i].x<<" "<<ans[i].y<<"\n";
}