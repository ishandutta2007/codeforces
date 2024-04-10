#include<bits/stdc++.h>
using namespace std;
#define N 2005
typedef long long ll;
int n;
ll ans;
inline ll C2(int n){
	return 1LL*n*(n-1)/2;
}	
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x,y=_y;}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend ll operator % (const Point &a,const Point &b){
		return 1LL*a.x*b.y-1LL*a.y*b.x;
	}
	bool Quad(){
		return y>0||(y==0&&x>0);	
	}
}a[N];
inline bool Left(Point a,Point b){
	return b%a>0;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=n;++i){
		vector<Point> p;
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			p.push_back(a[j]-a[i]);	
		}
		sort(p.begin(),p.end(),[&](Point a,Point b){
			return a.Quad()^b.Quad()?a.Quad()<b.Quad():Left(b,a);
		});
		#define nxt(x) (x+1)%p.size()
		for(int j=0,k=0;j<(int)p.size();++j){
			while(nxt(k)^j&&!Left(p[j],p[k]))k=nxt(k);
			int z=(k+p.size()-j)%p.size();
			ans+=C2(z-1)*C2(n-1-z);
		}
	}
	cout<<ans/2<<'\n';
	return 0;
}