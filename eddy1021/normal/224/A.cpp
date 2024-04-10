#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();	
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int gcd( int x , int y ){
	int r;
	while( y ) r=x%y,x=y,y=r;
	return x;
}
int main(){
	int a,b,c,t;
	while( scanf("%d",&a)==1 ){
		b = getint(); c = getint(); t = gcd(a,b);
		for( int i=t;i>=1;i-- )
			if( !(t%i) ){
				if( c == (a/i)*(b/i) ){
					printf("%d\n",4*(i+(a/i)+(b/i))); break;
				}
			}
	}
	return 0;
}