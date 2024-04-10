#include <stdio.h>
long long x[3],y[3],x1,y1,x2,y2,ans;
int main(){
	for( int i=0;i<3;i++ ) scanf("%I64d%I64d",&x[i],&y[i]);
	x1 = x[1]-x[0]; y1 = y[1]-y[0];
	x2 = x[2]-x[1]; y2 = y[2]-y[1]; ans = x1*y2 - x2*y1;
	if( ans<0 ) puts("RIGHT");
	else if( ans==0 ) puts("TOWARDS");
	else puts("LEFT");
}