#include<bits/stdc++.h>
using namespace std;
#define N 10010
typedef long long ll;
int n,ans[N];
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x,y=_y;}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend int operator % (const Point &a,const Point &b){
		return a.x*b.y-a.y*b.x;	
	}
	friend bool operator < (const Point &a,const Point &b){
		return a.x==b.x?a.y<b.y:a.x<b.x;	
	}
};
bool Left(Point a,Point b){
	return b%a>0;
}
struct Data{
	Point p;
	int id,col;
}a[N<<1];
void Solve(int l,int r){
	if(l>r)return;
	int z=min_element(a+l,a+r+1,[&](Data a,Data b){return a.p<b.p;})-a;
	swap(a[l],a[z]);
	sort(a+l+1,a+r+1,[&](Data x,Data y){return Left(y.p-a[l].p,x.p-a[l].p);});
	int jb=0,p=l+1;
	while(a[p].col==a[l].col||jb){
		jb+=a[p].col;
		++p;	
	}
	if(a[l].col==1)ans[a[l].id]=a[p].id;
	else ans[a[p].id]=a[l].id;
	Solve(l+1,p-1);
	Solve(p+1,r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		int x,y;
		cin>>x>>y;
		a[i]={Point(x,y),i,1};
	}
	for(int i=1;i<=n;++i){
		int x,y;
		cin>>x>>y;
		a[i+n]={Point(x,y),i,-1};
	}
	Solve(1,n<<1);
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}