#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
int main(){
	LL r,x1,y1,x2,y2;
	scanf("%lld %lld %lld %lld %lld",&r,&x1,&y1,&x2,&y2);
	if(x1==x2&&y1==y2){
		printf("%.12f %lld %.12f\n",x1+r/2.0,y1,r/2.0);
		return 0;
	}
	double dis =sqrt(sqr(x1-x2)+sqr(y1-y2));
	if(dis>=r){
		printf("%lld %lld %lld\n",x1,y1,r);
		return 0;
	}
	dis += r;
	dis/=2.0;
	double x=x1-x2,y=y1-y2;
	double unit=sqrt(sqr(x)+sqr(y));
	x/=unit;
	y/=unit;
//	printf("%.12lf %.12lf\n",x,y);
	double ansx=x2 + x*dis;
	double ansy=y2 + y*dis;
	printf("%.12f %.12f %.12f\n",ansx,ansy,dis);
}