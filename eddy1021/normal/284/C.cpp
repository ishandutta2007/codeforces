#include <stdio.h>
#define N 200010
#define ll long long
ll getint(){
	ll x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c=='-' ) c=getchar(),tmp=-1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
ll bx[ N ] , dlt[ N ] , n , kd , a , d , bxtp , sum;
double ans;
int main(){
	n = getint(); bxtp = 1;
	while( n-- ){
		kd = getint();
		if( kd == 1 ){
			a = getint(); d = getint();
			sum += a * d; dlt[ a-1 ] += d;
		}else if( kd == 2 ){
			a = getint(); bx[ bxtp++ ] = a; sum += a;
		}else if( kd == 3 ){
			if( bxtp > 1 ){
				-- bxtp;
				if( dlt[ bxtp ] ){
					bx[ bxtp ] += dlt[ bxtp ];
					if( bxtp > 0 ) dlt[ bxtp-1 ] += dlt[ bxtp ];
					dlt[ bxtp ] = 0;
				}
				sum -= bx[ bxtp ];
			}
		}
		ans = sum;
		printf("%.20lf\n",ans/double(bxtp));
	}
}