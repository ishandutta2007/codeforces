#include <stdio.h>
#define N 110
int bx[N],max,n,tmp;
int Max( int x , int y ){ return x>y?x:y; }
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int main(){
	n=getint();
	for( int i=0;i<n;i++ ) bx[i]=getint();
	for( int i=0;i<n;i++ ){
		tmp=bx[i]; max=Max(max,tmp);
		for( int j=i+1;j<n;j++ ){
			tmp^=bx[j]; max=Max(max,tmp);
		}
	}
	printf("%d\n",max);
}