#include<bits/stdc++.h>
using namespace std;
#define N 5005
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,p[N];
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x,y=_y;}
	Point operator -(const Point a){
		return Point(x-a.x,y-a.y);
	}
	friend ll operator *(const Point a,const Point b){
		return 1LL*a.x*b.x+1LL*a.y*b.y;
	}
}a[N];
inline bool ok(Point a,Point b){
	return a*b>0;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].x=read(),a[i].y=read();
	}
	p[1]=1,p[2]=2;
	for(int i=3;i<=n;++i){
		p[i]=i;
		for(int j=i-1;j>=2;--j){
			if(ok(a[p[j-1]]-a[p[j]],a[p[j+1]]-a[p[j]]))break;
			swap(p[j],p[j+1]);
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d ",p[i]);
	}
	printf("\n");
	return 0;
}