#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,l,r,mid,lp,rp;
double ans,y,x1,x2,X,Y,L,R,x[N],a[N];
int main(){
	scanf("%lf%lf%lf",&y,&x1,&x2);
	scanf("%d",&n);
	rep(i,1,n*2)scanf("%lf",&x[i]);
	x[0]=-inf-1;x[n*2+1]=inf+1;
	rep(i,1,n)a[i*2+1]=a[i*2]=a[i*2-1]+(x[i*2]-x[i*2-1]);
	scanf("%d",&m);
	rep(i,1,m){
		scanf("%lf%lf",&X,&Y);
		L=x1+(X-x1)/(Y-y)*-y;
		R=x2+(X-x2)/(Y-y)*-y;
		l=0;r=n*2;mid=(l+r+1)/2;
		for(;l<r;mid=(l+r+1)/2)
			if(x[mid]>L)r=mid-1;else l=mid;lp=l;
		l=1;r=n*2+1;mid=(l+r)/2;
		for(;l<r;mid=(l+r)/2)
			if(x[mid]<R)l=mid+1;else r=mid;rp=l;
		ans=a[rp]-a[lp];
		if(lp&1)ans-=(L-x[lp]);
		if(!(rp&1))ans-=(x[rp]-R);
		printf("%.15lf\n",ans*(x2-x1)/(R-L));
	}
}