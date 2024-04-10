#include<bits/stdc++.h>
using namespace std;
#define N 303
typedef long long ll;
int n,m;
ll ans,dp[N][N][6];
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x,y=_y;}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);	
	}
	inline double ang(){return atan2(y,x);}
}p[N];
struct Edge{
	int x,y;
	double z;
}E[N*N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i^j)E[++m]={i,j,(p[j]-p[i]).ang()};
	sort(E+1,E+m+1,[&](Edge a,Edge b){return a.z<b.z;});
	for(int i=1;i<=m;++i){
		dp[E[i].x][E[i].y][1]=1;
		for(int j=1;j<=n;++j){
			for(int k=2;k<=5;++k){
				dp[j][E[i].y][k]+=dp[j][E[i].x][k-1];
			}
		}
	}
	for(int i=1;i<=n;++i)ans+=dp[i][i][5];
	cout<<ans<<'\n';
	return 0;
}