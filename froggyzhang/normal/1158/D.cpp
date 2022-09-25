#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
string opt;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x,y=_y;}
	friend ll operator % (const Point &a,const Point &b){
		return 1LL*a.x*b.y-1LL*a.y*b.x;
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
}p[N];
int n,vis[N];
inline bool Left(Point a,Point b){
	return b%a>0;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;
	}
	cin>>opt;
	opt+='.';
	int u=min_element(p+1,p+n+1,[&](Point a,Point b){return a.x==b.x?a.y<b.y:a.x<b.x;})-p;
	cout<<u<<' ';vis[u]=1;
	for(auto c:opt){
		int v=0;
		for(int i=1;i<=n;++i){
			if(vis[i])continue;
			if(!v||(Left(p[i]-p[u],p[v]-p[u])^(c=='L')))v=i;
		}
		cout<<(u=v)<<' ';vis[u]=1;
	}
	return 0;
}