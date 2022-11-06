#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200000
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define eps 1e-18
using namespace std;
int n,dz;long double l,r,m;
struct pr{long double x,y;}a[N];
bool cmp(pr x,pr y){return x.x<y.x;}
bool ok(long double R){
	long double l=-1e7,r=1e7,m=0;
	for(;r-l>R*eps;m=(l+r)/2){bool u=0;
		rep(i,1,n){
			if(a[i].x>=m)break;
			if(sqr(m-a[i].x)+sqr(R-a[i].y)>sqr(R)){u=1;break;}
		}
		if(u)r=m-eps;else l=m;
	}
	rep(i,1,n)if(sqr(l-a[i].x)+sqr(R-a[i].y)>sqr(R))return 0;return 1;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){double x1,x2;
		scanf("%lf%lf",&x1,&x2);
		a[i].x=x1;a[i].y=x2;
	}
	if(a[1].y>0)dz=1;else dz=-1,a[1].y*=-1;
	rep(i,2,n){a[i].y*=dz;
		if(a[i].y<0){printf("-1\n");return 0;}
		if(a[i].y/2>l)l=a[i].y/2;
	}
	sort(a+1,a+n+1,cmp);
	r=1e15;m=(l+r)/2;
	for(;r-l>l*eps;m=(l+r)/2)if(ok(m))r=m;else l=m+eps;
	printf("%.12lf",(double)l); 
}