#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n;
ll s[N];
double ans;
struct Point{
	double x,y;
	Point(double _x,double _y){x=_x,y=_y;} Point(){}
}p[N];
inline Point Rotate(ll x,ll y,double ang){
	return Point(cos(ang)*x-sin(ang)*y,sin(ang)*x+cos(ang)*y);
}
inline double Dis(const Point &a,const Point &b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline bool cmp1(Point a,Point b){return a.x<b.x;}
inline bool cmp2(Point a,Point b){return a.y<b.y;}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ans=2e18;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		s[i]=s[i-1]+x;
	}
	for(int T=1;T<=10;T++){
		double ang=rand();
		ang=0;
		for(int i=0;i<=n;i++){
			p[i]=Rotate(i,s[i],ang);
		}
		sort(p+1,p+n+1,T&1?cmp1:cmp2);
		for(int i=1;i<=n;i++){
			int to=min(n,i+50);
			for(int j=i+1;j<=to;j++){
				ans=min(ans,Dis(p[i],p[j]));
			}
		}
	}
	printf("%lld\n",(ll)(ans+0.1));
	return 0;
}