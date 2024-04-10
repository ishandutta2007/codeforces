#include <stdio.h>
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c == '-' ) c=getchar() , tmp = -1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
int n , x , sum;
int main(){
	n = getint(); x = getint();
	while( n -- ) sum += getint();
	if( sum < 0 ) sum *= -1;
	printf( "%d\n" , sum / x + ( sum % x != 0 ) );
}