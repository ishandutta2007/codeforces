#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
int n,m,id[N];
ll S;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x,y=_y;}
	friend Point operator + (const Point &a,const Point &b){
		return 	Point(a.x+b.x,a.y+b.y);
	}
	friend Point operator - (const Point &a,const Point &b){
		return 	Point(a.x-b.x,a.y-b.y);
	}
	friend ll operator % (const Point &a,const Point &b){
		return 1LL*a.x*b.y-1LL*a.y*b.x;
	}
}p[N];
struct Data{
	Point p;
	int u,v;	
}c[N*N];
inline bool Left(Point a,Point b){
	return b%a>0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>S;
	S<<=1;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;
		id[i]=i;
	}
	sort(p+1,p+n+1,[&](Point a,Point b){return a.x==b.x?a.y<b.y:a.x<b.x;});
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			c[++m]={p[j]-p[i],i,j};	
		}
	}
	sort(c+1,c+m+1,[&](Data a,Data b){return Left(b.p,a.p);});
	for(int i=1;i<=m;++i){
		int u=id[c[i].u],v=id[c[i].v];
		int l=1,r=u,ans=0;
		while(l<r){
			int mid=(l+r)>>1;
			if((p[mid]-p[u])%(p[v]-p[u])>=S){
				ans=mid,l=mid+1;
			}
			else{
				r=mid;
			}
		}
		if(ans&&(p[ans]-p[u])%(p[v]-p[u])==S){
			cout<<"Yes\n";
			cout<<p[ans].x<<' '<<p[ans].y<<'\n'<<p[u].x<<' '<<p[u].y<<'\n'<<p[v].x<<' '<<p[v].y<<'\n';
			return 0;	
		}
		swap(id[c[i].u],id[c[i].v]);
		swap(p[u],p[v]);
	}
	cout<<"No\n";
	return 0;
}