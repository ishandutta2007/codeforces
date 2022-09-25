#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
int n,k;
double ans;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x,y=_y;}
	Point Normal(){
		int g=abs(__gcd(x,y));
		return Point(x/g,y/g);
	}
	ll dis(){
		return 1LL*x*x+1LL*y*y;	
	}
	friend bool operator < (const Point &a,const Point &b){
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
}p[N];
map<Point,vector<int> > mp;
vector<double> D;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;
		if(p[i].x|p[i].y)mp[p[i].Normal()].push_back(i);
	}
	D.push_back(0.0);
	for(auto [P,v]:mp){
		sort(v.begin(),v.end(),[&](int i,int j){return p[i].dis()>p[j].dis();});
		for(int i=0;i<min((int)v.size(),k/2);++i){
			D.push_back((k-2*i-1)*sqrt(p[v[i]].dis()));
		}
		double s=0;
		for(int i=(int)v.size()-1;i>=k/2;--i){
			double d=sqrt(p[v[i]].dis());
			D.push_back(d*(k-k/2*2-1)-2*s);
			s+=d;
		}
	}
	sort(D.begin(),D.end(),greater<double>());
	for(int i=0;i<k;++i)ans+=D[i];
	cout<<fixed<<setprecision(8)<<ans<<'\n';
	return 0;
}