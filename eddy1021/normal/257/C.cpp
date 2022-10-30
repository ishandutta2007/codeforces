#include <math.h>
#include <stdio.h>
#include <algorithm>
#define db double
#define N 100010
#define eps 0e-6
#define pi2 360.000000
const db pi = acos(-1.0);
db ts( db x , db y ){
	return atan2(y,x)*180.00000000000000000000000/pi;
}
db max( db x , db y ){ return x>y?x:y; }
db ag[N],ans,tmp,tx,ty; int n;
int main(){
	scanf("%d",&n); ans = -1.000000;
	for( int i=0;i<n;i++ ){
		scanf("%lf%lf",&tx,&ty);
		ag[i] = ts(tx,ty);
	}
	std::sort( ag , ag+n );
	for( int i=0;i<n;i++ ){
		tmp = ag[(i+1)%n] - ag[i] + pi2;
		tmp = fmod( tmp , pi2 );
		if( tmp > ans ) ans = tmp;
	}
	printf("%.18lf\n",ans>eps?pi2-ans:0);
}