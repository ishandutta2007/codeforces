#include <stdio.h>
double a , b , c , d , ans;
int main(){
	scanf( "%lf%lf%lf%lf" , &a , &b , &c , &d );
	ans = a / ( b * ( 1.0 - ( b - a ) * ( d - c ) / ( b * d ) ) );
	printf( "%.15lf\n" , ans );
}