#include<bits/stdc++.h>
using namespace std;
long long ax,ay,bx,by,sx,sy,t;
struct Point{
    long long x,y;
}a[105];
int n=0,ans=0;
long long ABS(long long x){
    return x<0?-x:x;
}
bool cmp(Point x,Point y){
    return ABS(x.x-sx)+ABS(x.y-sy)<ABS(y.x-sx)+ABS(y.y-sy);
}
int main(){
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&a[0].x,&a[0].y,&ax,&ay,&bx,&by,&sx,&sy,&t);
    for(n=1;max(a[n-1].x,a[n-1].y)<=20000000000000000ll;n++){
        a[n].x=a[n-1].x*ax+bx,a[n].y=a[n-1].y*ay+by;
    }
    n--;
    for(int l=0;l<=n;l++){
    	if(ABS(a[l].x-sx)+ABS(a[l].y-sy)>t)continue;
    	long long s,tt=0;
    	for(int r=l;r<=n;r++){
    		s=min(ABS(a[l].x-sx)+ABS(a[l].y-sy),ABS(a[r].x-sx)+ABS(a[r].y-sy));
    		s+=ABS(a[l].x-a[r].x)+ABS(a[l].y-a[r].y);
    		if(s<=t)ans=max(ans,r-l+1);
    		else break;
		}
	}
	printf("%d\n",ans);
}