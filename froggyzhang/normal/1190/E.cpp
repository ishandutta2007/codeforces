#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-8;
int n,m;
struct Point{
	double x,y;
	Point(int _x=0,int _y=0){x=_x,y=_y;}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	inline double len(){
		return sqrt(x*x+y*y);
	}
}p[N];
struct Range{
	double l,r;	
}g[N];
int check(double x){
	for(int i=1;i<=n;++i){
		if(x>p[i].len())return INT_MAX;
		double t=acos(x/p[i].len());
		double d=atan2(p[i].y,p[i].x);
		g[i].l=d-t,g[i].r=d+t;
		if(g[i].r>PI)g[i].r-=2*PI,g[i].l-=2*PI;
	}
	sort(g+1,g+n+1,[&](Range a,Range b){return a.r<b.r;});
	for(int i=1;i<=n;++i){
		g[n+i]=g[i];
		g[n+i].l+=2*PI,g[n+i].r+=2*PI;
	}
	static int p[N],nxt[N],f[N][19];
	for(int i=1;i<=n+n;++i)p[i]=i;
	sort(p+1,p+n+n+1,[&](int i,int j){return g[i].l<g[j].l;});
	for(int i=n+n,j=n+n,mn=n+n+1;i>=1;--i){
		while(j>=1&&g[p[j]].l>=g[i].r){
			mn=min(mn,p[j]);
			--j;
		}
		nxt[i]=max(i+1,mn);
	}
	nxt[n+n+1]=n+n+1;
	for(int i=1;i<=n+n+1;++i){
		f[i][0]=nxt[i];
	}
	for(int j=1;j<=18;++j){
		for(int i=1;i<=n+n+1;++i){
			f[i][j]=f[f[i][j-1]][j-1];
		}	
	}
	int mn=n;
	for(int i=1;i<=n;++i){
		int tmp=1,u=i;
		for(int j=18;j>=0;--j){
			if(f[u][j]<i+n)u=f[u][j],tmp+=1<<j;
		}
		mn=min(mn,tmp);	
	}
	return mn;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(8);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;	
	}
	double l=0,r=2e5+eps;
	while(r-l>eps){
		double mid=(l+r)/2.0;
		if(check(mid)<=m){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout<<l<<'\n';
	return 0;
}